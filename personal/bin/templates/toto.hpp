#ifndef  TEST_HPP
#define  TEST_HPP

class Test
{

	private:

	protected:

	public:
		Test(void);
		Test(Test const & src);
		Test	&operator=(Test const &);

		virtual ~Test(void);
};


#endif  /* TEST_HPP */
