#include <iostream>
#include <string>
#include <cmath>

/*
    3 digit
    1-->9
    0-->9
    0-->9
*/

void print_armstrong_only_3digits_number()
{
    for(int a {1}; a <= 9; ++a)
    {
        for(int b {0}; b <= 9; ++b)
        {
            for(int c {0}; c <= 9; ++c)
            {
                auto abc = a * 100 + b * 10 + c;
                auto arm = a * a * a + b * b * b + c * c * c;
                if(abc == arm) 
                {
                    std::cout << arm << '\n';
                } 
            }
        }
    }
}

/*
same problem but with upper limit

upper limit = 1598
make string = "1598"
we know the size of the string

*/

int ch2i(char ch)
{
    return ch - 48;
}

void print_armstrong_number(long long upper_limit)
{
   for(long long num {153}; num < upper_limit; ++num)
   {
        auto str_num = std::to_string(num);
        size_t s_size = str_num.size();
        int sum = 0;
        for(size_t s{0}; s < s_size; ++s)
        {
            auto i_tmp = ch2i(str_num[s]);
            sum += std::pow(i_tmp, s_size);
        }
        if(sum == num )
        {
            std::cout << num << '\n';
        }
   }   
}


int main()
{
    print_armstrong_only_3digits_number();
    std::cout << "===\n";
    print_armstrong_number(9999999);
    return 0;
}