#include <format>
#include <iostream>
#include <type_traits>
#include <concepts>

template <std::integral I>
I sum_proper_divisor(I const number)
{
	I result = 1;
	for (int i{ 2 }; i * i <= number; ++i)
	{
		if (number % i == 0)
		{
			result += (i == number / i) ? i : (i + number / i);
		}
	}

	return result;
}


template<std::integral I>
void print_abundant(I const upper_limit)
{
	for (int number{ 10 }; number <= upper_limit; ++number)
	{
		auto sum = sum_proper_divisor(number);
		if (sum > number)
		{
			std::cout << std::format("number: {}, sum: {}, abundant: {}\n", number, sum, sum - number);
		}
	}
}


int main()
{
	std::cout << "please enter your integer upper limit\n";
	int int_limit;
	std::cin >> int_limit;
	print_abundant(int_limit);

	std::cout << "please enter your long upper limit\n";
	int long_limit;
	std::cin >> long_limit;
	print_abundant(long_limit);



	return EXIT_SUCCESS;
}
