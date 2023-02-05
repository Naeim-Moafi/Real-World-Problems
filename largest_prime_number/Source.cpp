#include <format>
#include <iostream>

bool is_prime(size_t num)
{
	//check if the number is 2 or 3
	if (num <= 3) { return num > 1; }
	else if (num % 2 == 0 || num % 3 == 0)
	{// checking if it is divisible with 2 or 3
		return false;
	}
	else
	{// check for others start from a = 5 and b = a+2 and a+=6 till a rich the sqrt of the num
		for (int a{ 5 }; a * a < num; a += 6)
		{
			auto b = a + 2;
			if (num % a == 0 || num % b == 0) return false;
		}
	}

	return true;
}


int main()
{
	//std::cout << std::boolalpha << is_prime(61);
	int limit = 0;
	std::cout << "Enter the upper limit: ";
	std::cin >> limit;
	for (int i{ limit }; i > 1; --i)
	{
		if (is_prime(i)) {
			std::cout << "largest prime number is: " << i << std::endl; 
			break;
		}
	}

	return EXIT_SUCCESS;
}
