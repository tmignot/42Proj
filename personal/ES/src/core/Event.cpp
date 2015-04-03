#include "core/Event.hpp"

NG::AEvent::AEvent(unsigned int type, unsigned int emitterID)
	: Type(type), EmitterID(emitterID)
{}

NG::AEvent::~AEvent() {}

NG::EventData::EventData() {}
NG::EventData::~EventData() {}
