#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


/*
prime factors of a given number
 
2 --> while num % 2 == 0; n = n/2;

+++++++
3 --> while num%3 == 0; n = n/3

5

7

** 9 already checked by 3

11

13

** already cheched by 3 and 5 

17 .....
++++++ --> we can start from i = 3 and i += 2 till we reach the sqrt(num)

check if n is greater that the smallest prime number 2 if yes add it as final factor
*/


std::vector<unsigned long long> find_prime_factors(unsigned long long num)
{
    std::vector<unsigned long long> v_factors;

    while(num % 2 == 0)
    {
        v_factors.push_back(2);
        num /= 2;
    }

    for(unsigned long long i {3}; i * i < num; i += 2)
    {
        while(num % i == 0)
        {
            v_factors.push_back(i);
            num /= i;
        }
    }

    if(num > 2)
    {
        v_factors.push_back(num);
    }

    //sorting the v_factors
    std::sort(v_factors.begin(), v_factors.end());

    return v_factors;
}

int main()
{

    auto ans = find_prime_factors(165);
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<unsigned long long>(std::cout, " "));
    std::cout << '\n';

    return 0;
}
