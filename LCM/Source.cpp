#include <format>
#include <iostream>

unsigned gcd(unsigned const a, unsigned const b)
{
	return b == 0 ? a : gcd(b, a % b);
}

unsigned lcm(unsigned const a, unsigned const b)
{
	auto g = gcd(a, b);
	return g ? (a * (b / g)) : 0;
}


int main()
{
	//getting a and b from the users
	unsigned a, b;
	std::cout << "please enter two number for calculatin least common multiplier\n";
	std::cin >> a >> b;
	std::cout << lcm(a, b);
}
