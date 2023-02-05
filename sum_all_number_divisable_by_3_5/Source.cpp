#include <format>
#include <iostream>
#include <type_traits>

long long sum(uint32_t init, uint32_t upper_limit)
{
	long long sum_ = 0;
	for (uint32_t i{ init }; i < upper_limit; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum_ += i;
		}
	}
	return sum_;
}


int main()
{
	// get the initial number and upper limit
	uint32_t init = 0, upper_limit = 0;
	std::cout << "please enter the init and upper limit for sum calculation (separate them with " " and press enter)\n";
	std::cin >> init >> upper_limit;
	std::cout << sum(init, upper_limit) << std::endl;

	return EXIT_SUCCESS;
}
