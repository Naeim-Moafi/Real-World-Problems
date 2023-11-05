#include <iostream>

/*
amicable numbers:
if sum of the proper devisor  of a number is equal that of the other number, these two numbers are called amicable
284 -->  1,2,4,71,142 = 220
220 --> 1,2,4,5,10,11,20,22,44,55,110 = 284
*/

long long sum_proper_divisor(long long const num)
{
    std::cout <<std::endl;
    int result = 1;
    for(long long i {2}; i*i < num; ++i)
    {
        if(num % i == 0)
        {
            result += (i == num / i) ? i : (i + num / i);
        }
    }
    std::cout <<std::endl;
    return result;
}

void print_amicable_num(long long upper_limit)
{
    for(long long num{4}; num < upper_limit; ++num)
    {
        auto sum1 = sum_proper_divisor(num);
        if(sum1 < upper_limit)
        {
            auto sum2 = sum_proper_divisor(sum1);
            if(num == sum2 && num != sum1 && num < sum1)
            {
                std::cout << "[" <<num << ", " << sum1 << "]\n";
            }
        }
    }
}

int main()
{
    std::cout << "sum of the proper divisor of the 220: " << sum_proper_divisor(220) << std::endl;
    std::cout << "sum of the proper divisor of the 284: " << sum_proper_divisor(284) << std::endl;
    std::cout << "amicable numbers lesser than 999999:\n";
    // print_amicable_num(999999);

    return 0;
}