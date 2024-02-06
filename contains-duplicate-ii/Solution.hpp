// 219 Contains duplicate II

#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        /**
         * key = num and val = the index of the last appearance of num in nums
         * 
         * for a given num, we record only the index of its last appearance, say i1. 
         * If it shows again at i2. 
         * If i2 - i1 > k, there is no way that i2 - any appearance of num in nums 
         * can be less than k. 
         */ 
        unordered_map<int, int> mapNumLastIdx; 

        for (int curIdx = 0; curIdx < nums.size(); ++curIdx) {
            
            int key = nums[curIdx];

            if (mapNumLastIdx.find(key) == mapNumLastIdx.end()) {
                mapNumLastIdx.insert(make_pair(key, curIdx));
                continue; 
            }

            int lastIdx = mapNumLastIdx[key]; 
            if (curIdx - lastIdx <= k) {
                return true; 
            }

            mapNumLastIdx[key] = curIdx;
        }

        return false; 
    }
};