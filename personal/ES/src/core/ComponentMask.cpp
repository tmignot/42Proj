#include <sstream>
#include "core/ComponentMask.hpp"

namespace NG {

	ComponentMask::ComponentMask() : std::array<bool,N_COMPONENT>() {}
	ComponentMask::~ComponentMask() {}

	ComponentMask ComponentMask::operator&(ComponentMask const & rhs) const
	{
		ComponentMask ret;
		for (size_t i = 0; i < N_COMPONENT; ++i) {
			ret[i] = (*this)[i] & rhs[i];
		}
		return ret;
	}

	ComponentMask ComponentMask::operator|(ComponentMask const & rhs) const
	{
		ComponentMask ret;
		for (size_t i = 0; i < N_COMPONENT; ++i) {
			ret[i] = (*this)[i] | rhs[i];
		}
		return ret;
	}

	ComponentMask ComponentMask::operator^(ComponentMask const & rhs) const
	{
		ComponentMask ret;
		for (size_t i = 0; i < N_COMPONENT; ++i) {
			ret[i] = (*this)[i] ^ rhs[i];
		}
		return ret;
	}

	bool ComponentMask::operator==(ComponentMask const & rhs) const
	{
		for (size_t i = 0; i < N_COMPONENT; ++i) {
			if ((*this)[i] != rhs[i])
				return false;
		}
		return true;
	}

	std::string	ComponentMask::ToString(void) const
	{
		std::ostringstream o;
		for (size_t i = 0; i < N_COMPONENT; ++i) {
			o << ((*this)[i]) ? 1 : 0;
		}
		return o.str();
	}
}
