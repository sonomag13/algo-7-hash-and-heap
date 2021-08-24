/*
    523. Continuous Subarray Sum
    Medium

    Given an integer array nums and an integer k, return true if nums has a 
    continuous subarray of size at least two whose elements sum up to a 
    multiple of k, or false otherwise.

    An integer x is a multiple of k if there exists an integer n such that 
    x = n * k. 0 is always a multiple of k.


    Example 1:

    Input: nums = [23,2,4,6,7], k = 6
    Output: true
    Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.


    Example 2:

    Input: nums = [23,2,6,4,7], k = 6
    Output: true
    Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
    42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.


    Example 3:

    Input: nums = [23,2,6,4,7], k = 13
    Output: false
 */

#include <unordered_map>

using namespace std; 

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        /*  
            looking for subsum[i, j] % k = 0 where j > i
            
            but subsum[i, j] = sum[j] - sum[i]
            
            such that subsum[i, j]%k = (sum[j] - sum[i])%k = 0             
            
            i.e. sum[j]%k = sum[i]%k for j > i            
         */
        
        // key = remainder; val = index
        unordered_map<int, int> mapRemIdx;        
        /*
           Why do we need this insertion?  
           It is possible that sum[0, i]%k = rem, but shall we return true?            
           Not so quick~! If i = 0, tere is only 1 element in the sub-array
           
           This is why we pre-insert a dummy index -1 for rem = 0. 
           
           If i = 0 and rem[i] = 0, i - (-1) = 1
         */
        mapRemIdx.insert(make_pair(0, -1));
        
        int accuSum{0};
        for (int i = 0; i < nums.size(); ++i) {
            
            accuSum += nums[i];            
            int rem = accuSum%k;
            
            if (mapRemIdx.count(rem) > 0 && i - mapRemIdx[rem] > 1) {
                return true; 
            }
                        
            mapRemIdx.insert(make_pair(rem, i));
            int t = 0; 
        }        
        
        return false; 
        
    }
};