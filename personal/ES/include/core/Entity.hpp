#ifndef  ENTITY_HPP
#define  ENTITY_HPP

#include "core/Component.hpp"

namespace NG {

	class Entity {

		private :

			static unsigned int	count;

		public :

			unsigned int		ID;
			ComponentMask		components;

			Entity();
			~Entity();
	};
}
#endif    /* ENTITY_HPP */
