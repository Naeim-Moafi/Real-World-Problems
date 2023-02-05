#include <iostream>
#include <filesystem>
#include "func.h"


int main()
{
    std::vector<int> a{ 1,3 };
    std::vector<int> b{ 2 };
    std::vector<int> c{ 2,4 };
    
    std::cout << findMedianSortedArrays(a, b) << '\n';
    
    std::cout << findMedianSortedArrays(a, c);
    
    return 0;
}


