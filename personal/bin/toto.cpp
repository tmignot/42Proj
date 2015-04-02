#include  "MesDeux.hpp"

MesDeux::MesDeux(void) : MaPremiere() {}

MesDeux::MesDeux(MesDeux const& rhs) : MaPremiere() {
	*this = rhs;
}

MesDeux&	operator=(MesDeux const&){
}

~MesDeux::MesDeux(void) {}
