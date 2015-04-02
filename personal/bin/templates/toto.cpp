#include  "TestTemplate.hpp"

TestTemplate::TestTemplate(void) : ParentClass() {}

TestTemplate::TestTemplate(TestTemplate const& rhs) : ParentClass() {
	*this = rhs;
}

TestTemplate&	operator=(TestTemplate const&){
}

virtual ~TestTemplate::TestTemplate(void) {}
