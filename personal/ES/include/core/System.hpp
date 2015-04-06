#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "core/Component.hpp"
#include "core/Channel.hpp"
#include "core/Event.hpp"
#include "core/Timer.hpp"
#include <thread>

namespace NG {

	class ASystem {

		public :

			unsigned int		ID;

		protected :

			static unsigned int	Count;

			ComponentMask									RequiredComponents;
			std::vector<unsigned int>			Entities;
			std::map<unsigned int, std::vector<unsigned int>> BoundEvents; 

			ASystem(ComponentMask);
			virtual ~ASystem();

			bool	RegisterEntity(unsigned int);
			void	BindEvent(unsigned int entity, 
											unsigned int type);

	};

	template<class T>
		class System : public ASystem {

			public :

				typedef BaseEvent<T>				Event;
				typedef BaseChannel<Event>	Channel;

			private :

				bool					Run;
				bool					Paused;
				unsigned int	Fps;
				Timer					TimeController;
				Channel				InputChannel;
				
				std::thread							Thread;
				std::mutex							Mutex;
				std::mutex							LockMutex;
				std::condition_variable	Condition;

			public :

				System(ComponentMask requirements, unsigned int fps) 
					: ASystem(requirements),
						Run(true),
						Paused(false),
						Fps(fps),
						TimeController(Fps),
						Thread(Loop)
				{
					TimeController.Start();
				}

				virtual ~System() {
					Mutex.lock();
					Run = false;
					Mutex.unlock();
					Thread.join();
				}

				void		Loop() {
					OnInit();

					T *input;
					bool run, paused;
					run = paused = true;
					while (run) {
						if (Mutex.try_lock()) {
							run = Run;
							paused = Pause;
							Mutex.unlock();
						}
						if (run) {
							if (paused) {
								OnPause();
								std::unique_lock<std::mutex> lock(LockMutex);
								Condition.wait(lock);
								OnResume();
							}
							while ((input = Input.Poll())) {
								OnInput(input);
								delete input;
							}
							OnUpdate();
							Sleep();
						}
					}
					OnStop();
				}

				void		Sleep() {
					if (Fps) {
						TimeController.Stop();
						TimeController.Wait();
					}						
					else {
						std::unique_lock<std::mutex> lock(InputChannel.InputMutex);
						InputChannel.Condition.wait(lock);
					}
				}

				void		Pause() {
					Mutex.lock();
					Paused = true;
					Mutex.unlock();
				}

				void		Resume() {
					Mutex.lock();
					if (Paused) {
						Paused = false;
						std::unique_lock<std::mutex> lock(LockMutex);
						Condition.notify_one();
					}
					Mutex.unlock();
				}

				void		Input(T* input) {
					InputChannel.Peep(input);
				}

				virtual void OnInit() = 0;
				virtual void OnUpdate() = 0;
				virtual void OnPause() = 0;
				virtual void OnResume() = 0;
				virtual void OnStop() = 0;
				virtual void OnInput(T) = 0;
		};
}

#endif
