#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>

/*
s = cbaebabacd
p = abc

1- make frequcey and sliding window vectors

 f: a b c d e f g h i j k l m n o p q r s t u v w x y z
    1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 w: a b c d e f g h i j k l m n o p q r s t u v w x y z
    1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2- check if f and w are the same? (here yes) if yes push back the index 0
3- find other answers ;
    3-1- go through the s put two cursor one in i = 0 and another in i + p
    3-2- update the frequency and sliding window vector
    3-3 check if they are the same? if yes add index to the answer vector

*/

std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::vector<int> ans;
    auto s_size = s.size();
    auto p_size = p.size();

    // size of the string is lesser than the size of the query string
    // obviously we cannot find the substring of the query string in the string
    if(s_size < p_size)
    {
        return {-1}; // return negative index
    }

    // initialize frequncy and sliding windows matrix with;
    std::vector v_freq(26, 0); //  only english lowercase letter are allowed
    std::vector v_win(26,0);

    // update the frequency and sliding windows vectors by std::string
    for(unsigned i {0}; i < p_size; ++i)
    {
        v_freq[p[i] - 'a']++;
        v_win[s[i] -  'a']++;
    }

    // check if the s and p are the same if yes return index 0
    if(v_freq == v_win)  
    {
        ans.push_back(0);
    }

    for(unsigned i {0}; i < s_size - p_size; ++i)
    {
        //update
        v_win[s[i] - 'a']--; // remove the first character in s
        v_win[s[i + p_size] - 'a']++; // and move the sliding windows

        std::copy(v_win.begin(), v_win.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::copy(v_freq.begin(), v_freq.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl << std::endl;

        // check
        if(v_win == v_freq)
        {
            ans.push_back(i + 1);
        }
    }




    return ans;
}

int main()
{
    std::string s("cbaebabacd");
    std::string p("abcd");

    auto v = findAnagrams(s, p);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}