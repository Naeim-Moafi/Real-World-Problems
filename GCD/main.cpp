#include <iostream>
#include "gcd.h"

int main()
{
	// get number from user
	unsigned a, b;
	solution s;
	std::cout << "please write the number and separate them with space\n";
	std::cin >> a >> b;
	std::cout << s.gcd(a, b) << std::endl;

	return EXIT_SUCCESS;
}
