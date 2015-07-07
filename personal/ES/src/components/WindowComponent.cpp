#include "components/WindowComponent.hpp"

namespace NG {
	
	WindowComponentData::WindowComponentData() :
		ComponentData(),
		Window(NULL),
		GlContext(0),
		X(SDL_WINDOWPOS_UNDEFINED), 
		Y(SDL_WINDOWPOS_UNDEFINED), 
		W(1024), H(768),
		Title(std::string("NGine")),
		Flags(SDL_WINDOW_OPENGL)
	{}

	WindowComponentData::~WindowComponentData() {}

}
