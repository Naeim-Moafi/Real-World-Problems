#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>


std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    std::unordered_multimap<int,int> umm_int_int;
    std::unordered_map<int,int> um_int_int;
    bool f_find = false;
    for(int i{0} ; i < nums.size(); ++i)
    {
        um_int_int.insert(std::make_pair(nums[i], i));
        umm_int_int.insert(std::make_pair(nums[i], i));
    }

    for(int i{0} ; i < nums.size(); ++i)
    {
        auto c = target - nums[i];
        //std::cout << um_int_int[c] << std::endl;
        if(c == nums[i])
        {
            // if(umm_int_int.contains(c))
            if(auto it = umm_int_int.find(c); it != umm_int_int.end())
            {
                auto [start, end] = umm_int_int.equal_range(nums[i]);
                for (auto iter { start }; iter != end; ++iter)
                {
                    if(iter->second != i)
                    {
                        return {i, iter->second};
                    }
                }
            }
        }
         else
         {
            if(auto it = um_int_int.find(c); it != um_int_int.end())
            {
                return {um_int_int[nums[i]], um_int_int[c]};
            }
        }
    }

    return {-1, -1};
}

std::vector<int> twoSum2(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> um_int_int;
       
        for(int i = 0; i < nums.size(); i++)
        {
            int c = target - nums[i];
            if(auto it = um_int_int.find(c); it == um_int_int.end())
                um_int_int[nums[i]] = i;
            else
                return {um_int_int[c], i};
        }
 
        return {-1, -1};
    }

int main()
{
    std::vector<int> v{3,3};
    auto v2 = twoSum(v, 6);
    auto v3 = twoSum2(v,6);
    std::cout << "[" << v2[0] << ", " <<  v2[1] << "]" <<std::endl;
    std::cout << "[" << v3[0] << ", " <<  v3[1] << "]" <<std::endl;
    return 0;
}

