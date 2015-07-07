#ifndef WINDOW_COMPONENT_HPP
#define WINDOW_COMPONENT_HPP

#include <SDL2/SDL.h>
#include "core/Component.hpp"

namespace NG {

	class WindowComponentData : public ComponentData {
		public:

			SDL_Window*			Window;
			SDL_GLContext		GlContext;
			int							X, Y, W, H;
			std::string			Title;
			unsigned int		Flags;

			WindowComponentData();
			WindowComponentData(std::string, int, int);
			WindowComponentData(std::string, int, int, int, int);
			~WindowComponentData();
	};

#ifdef SWIG
	%template(WindowComponent) Component<WindowComponentData>;
#endif
}

#endif
