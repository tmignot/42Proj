#ifndef  ENTITY_HPP
#define  ENTITY_HPP

#include <array>
#include <map>

#include "core/ComponentMask.hpp"

namespace NG {

	class Entity : public std::map<unsigned int, unsigned long> {

		private :

			static unsigned int	Count;

		public :

			Entity();
			~Entity();

			void Set(char*, unsigned long);
#ifdef SWIG
			%extend {
				const unsigned long& __getitem__(VALUE i) {
					assert(self->find(SYM2ID(i)) != self->end());
					return (*self)[SYM2ID(i)];
				}
			}
#endif
	};

}
#endif    /* ENTITY_HPP */
