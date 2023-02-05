#include <iostream>

/* problem check if a given number is prime or not. 
1 - 2,3 are prime
2- any number divisible by 2 and 3 is not a prime number
3- 5,7,11,13,17,19,23,29,31,..
    5,7         5,5+2
    11, 13      5+6, 5+6+2      
    17, 19      5+12, 5+12+2
    23          5+18 ---> 5+18+2 = 25 --> 5*5
    29,31       5+24, 5+24+2
    37,         5+30+2 + 5+30 = 5*7
    41,43       5+36, 5+36+2
*/


bool is_prime(long long unsigned num)
{
    if(num <= 3)
    {
        return (num > 1);
    }
    else if(num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }
    else
    {
        for(long long unsigned i {5}; i * i < num; i += 6 )
        {
            auto j = i + 2;
            if(num % i == 0 || num % j == 0)
            {
                return false;
            }
        }
    }
    return true;
}


/*

*/
long long unsigned find_largest_prime_number(long long unsigned upper_limit)
{
    for(auto i {upper_limit}; i > 1; --i)
    {
        if(is_prime(i))
        {
            return i;
        }
    }

    return 1;
}

int main()
{
    std::cout << "is 4361 a prime number? " <<std::boolalpha << is_prime(4361) << std::endl;
    std::cout << "largest prime number before 987654321 is: " << find_largest_prime_number(987654321) << std::endl;
    return 0;
}
