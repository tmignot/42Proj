#ifndef  WINDOW_HPP
#define  WINDOW_HPP

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <core/log.hpp>

namespace NG {

	std::vector<Window*>	windows;

	class Window
	{

		private:

			Window(void);
			virtual ~Window(void);
			
		public:

			int							x, y, width, height;
			SDL_Window			*sdlWindow;
			SDL_GL_Context	glContext;

			static unsigned int Window*	create(int, int, int, int);
			static unsigned int Window* create(glm::vec4);

	};
}

#endif    /* WINDOW_HPP */
