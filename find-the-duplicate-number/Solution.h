// LeetCode 287. Find the Duplicate Number
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        /**
         * It is trivial if we can use std::set or std::unordered_map
         * 
         * We use vector as the hash table, where the index is the key. 
         * 
         * Importantly:
         * - there is no zero in the numbers as all the numbers are in [1, n]
         * - there is only one duplicated number
         * 
         * We use 0th element as the space to temporarily host a number, and 
         * move the number to the index it should be, e.g. if val = 2, then
         * move the vale ot nums[val]
         * 
         * There are two cases:
         * 1. nums[val] != val, s.t. we move val to nums[val], and move the value in 
         *    nums[val] to nums[0]
         * 2. nums[val] == val, s.t. the duplicate if found
         * 
         * This method is effectively sort the array
         **/
        
        while (nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        
        return nums[0];
        
    }
};