#include <algorithm>
#include "core/System.hpp"

namespace NG {

	std::map<unsigned int, ASystem*>	Systems;

	unsigned int ASystem::Count(0);

	ASystem::ASystem(unsigned int fps) :
		id(Count++),
		Run(true),
		Paused(false),
		Fps(fps),
		TimeController(Fps)
	{
		Systems[id] = this;
		if (fps) {
			TimeController.Start();
			Thread = new std::thread(&NG::ASystem::Loop, this);
		}
	}

	ASystem::~ASystem() {
		Mutex.lock();
		Run = false;
		Mutex.unlock();
		Thread->join();
		delete Thread;
	}

	void ASystem::Loop() {
		OnInit();

		bool run, paused;
		run = paused = true;
		while (run) {
			if (Mutex.try_lock()) {
				run = Run;
				paused = Paused;
				Mutex.unlock();
			}
			if (run) {
				if (paused) {
					OnPause();
					std::unique_lock<std::mutex> lock(LockMutex);
					Condition.wait(lock);
					OnResume();
				}
				OnUpdate();
				Sleep();
			}
		}
		OnStop();
	}

	void ASystem::Sleep() {
		if (Fps) {
			TimeController.Stop();
			TimeController.Wait();
		}
		else Pause();
	}

	void ASystem::Pause() {
		Mutex.lock();
		Paused = true;
		Mutex.unlock();
	}

	void ASystem::Resume() {
		Mutex.lock();
		if (Paused) {
			Paused = false;
			std::unique_lock<std::mutex> lock(LockMutex);
			Condition.notify_one();
		}
		Mutex.unlock();
	}

	void ASystem::Watch(unsigned int component) {
		std::vector<unsigned int>::iterator it;
		Mutex.lock();
		it = std::find(Watched.begin(), Watched.end(), component);
		if (it == Watched.end())
			Watched.push_back(component);
		Mutex.unlock();
	}

	void ASystem::Ignore(unsigned int component) {
		std::vector<unsigned int>::iterator it;
		Mutex.lock();
		it = std::find(Watched.begin(), Watched.end(), component);
		if (it != Watched.end())
			Watched.erase(it);
		Mutex.unlock();
	}

	void ASystem::StateChanged(unsigned int component) {
		std::vector<EventCondition*>::iterator it;
		if (Listeners.find(component) != Listeners.end()) {
			it = Listeners[component].begin();
			for (; it != Listeners[component].end(); ++it) {
				(*it)->event->Check();
			}
		}
	}

	void ASystem::AddListener(EventCondition* condition) {
		Mutex.lock();
		for (int i = 0; i < condition->param.size(); ++i) {
			Listeners[condition->param[i]].push_back(condition);
		}
		Mutex.unlock();
	}

	void ASystem::RemoveListener(EventCondition* condition) {
		Mutex.lock();
		for (int i = 0; i < condition->param.size(); ++i) {
			std::vector<EventCondition*>::iterator it;
			it = std::find(Listeners[condition->param[i]].begin(),
										 Listeners[condition->param[i]].end(),
										 condition);
			if (it != Listeners[condition->param[i]].end())
				Listeners[condition->param[i]].erase(it);
		}
	}
}
