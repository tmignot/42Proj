#include "core/Event.hpp"
#include <iostream>

namespace NG {

	std::map<unsigned int,Event*> Events;
	std::vector<unsigned int>			RemovedEvents;

	unsigned int Event::Count(0);

	Event::Event(std::vector<EventCondition*> c, VALUE cb) {
		id = Count++;
		Conditions = c;
		Callback = cb;
		std::vector<EventCondition*>::iterator it;
		for (it = Conditions.begin(); it != Conditions.end(); ++it) {
			(*it)->event = this;
			Systems[(*it)->system]->AddListener(*it);
		}
		Events[id] = this;
	}

	Event::~Event() {
		std::vector<EventCondition*>::iterator it;
		for (it = Conditions.begin(); it != Conditions.end(); ++it) {
			Systems[(*it)->system]->RemoveListener(*it);
			delete *it;
		}
		Conditions.clear();
	}

	bool	Event::Call(std::vector<int> states) {
		ID CallSymbol = rb_intern("call");
		VALUE states_array[states.size()];
		for (int i = 0; i < states.size(); ++i) {
			states_array[i] = INT2NUM(states[i]);
		}
		VALUE r_states = rb_ary_new4(states.size(), states_array);
		VALUE rret = rb_funcall(Callback, CallSymbol, 1, r_states);
		return (rret == Qtrue ? true : false);
	}

	void	Event::Check(void) {
		std::vector<EventCondition*>::iterator it;
		std::vector<int> param;
		param.reserve(Conditions.size());
		for (it = Conditions.begin(); it != Conditions.end(); ++it) {
			param.push_back(Systems[(*it)->system]->GetState((*it)->param));
		}
		if (!Call(param)) {
			RemovedEvents.push_back(id);
		}
	}
}
