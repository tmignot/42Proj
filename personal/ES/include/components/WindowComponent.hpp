#ifndef WINDOW_COMPONENT_HPP
#define WINDOW_COMPONENT_HPP

#include "core/components.hpp"

namespace NG {

	class WindowComponentData : public ComponentData {
		public:

			SDL_Window*			Window;
			SDL_GL_Context	GlContext;
			int							X, Y, W, H;
			std::string			Title;
			unsigned int		Flags

			WindowComponentData();
			WindowComponentData(std::string, int, int);
			WindowComponentData(std::string, int, int, int, int);
			~WindowComponentData();

	};
}

#endif
