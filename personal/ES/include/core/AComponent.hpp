#ifndef ACOMPONENT_HPP
#define ACOMPONENT_HPP

namespace NG {

	class AComponent {

		public :

			unsigned int id;
			static unsigned int				Count;

		protected :

			AComponent();
			virtual ~AComponent();
	};
}

#endif
