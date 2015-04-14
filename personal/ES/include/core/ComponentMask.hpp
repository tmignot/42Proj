#ifndef COMPONENT_MASK_HPP
#define COMPONENT_MASK_HPP

#include <array>
#include <string>

#ifndef N_COMPONENT
#define N_COMPONENT 10
#endif


namespace NG {

	typedef std::array<bool,N_COMPONENT> BitArray;

	class ComponentMask : public BitArray {

		public :

			ComponentMask();
			~ComponentMask();

			ComponentMask operator&(ComponentMask const & rhs) const;
			ComponentMask operator|(ComponentMask const & rhs) const;
			ComponentMask operator^(ComponentMask const & rhs) const;
			bool					operator==(ComponentMask const & rhs) const;
			std::string		ToString(void) const;
	};

}

#endif
