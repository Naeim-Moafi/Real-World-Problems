#include "func.h"

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    double median = 0.0;
    std::vector<int> v_merged;
    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(v_merged));

    int mid = v_merged.size() / 2;
    if (v_merged.size() % 2 == 0)
    {
        median = static_cast<double>(v_merged[mid] + v_merged[mid - 1]) / 2;
    }
    else
    {
        median = v_merged[mid];
    }
    return median;
}
