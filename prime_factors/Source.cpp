#include <algorithm>
#include <format>
#include <iostream>
#include <iterator>
#include <vector>

using ull = unsigned long long;
using v_ull = std::vector<ull>;

v_ull prime_factors(ull n)
{
	v_ull v;
	while (n % 2 == 0)
	{
		v.push_back(2);
		n = n / 2;
	}
	for (ull i{ 3 }; i * i <= n; i+=2)
	{
		while (n % i == 0)
		{
			v.push_back(i);
			n = n / i;
		}
	}

	if (n > 2)
	{
		v.push_back(n);
	}

	return v;
}


int main()
{
	std::cout << "number: ";
	ull number;
	std::cin >> number;
	auto v = prime_factors(number);
	std::cout << std::format("{} = ", number);
	std::copy(v.begin(), v.end() - 1, std::ostream_iterator<ull>(std::cout, "x"));
	std::cout <<*(v.end()-1) << std::endl;

	return EXIT_SUCCESS;
}
