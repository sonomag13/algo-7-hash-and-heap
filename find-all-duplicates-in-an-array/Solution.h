// LeetCode 442. Find All Duplicates in an Array
// Medium

#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> result;
        
        unordered_map<int, int> mapNumCnt;
        
        for (auto val : nums) {
            if (mapNumCnt.find(val) == mapNumCnt.end()) {
                mapNumCnt.insert(make_pair(val, 1));
            }
            else {
                mapNumCnt[val]++;
            }
        }
        
        for (auto & ele : mapNumCnt) {
            
            if (ele.second == 2) {
                result.push_back(ele.first);
            }            
        }        
        
        return result;        
        
    }
};

class Solution2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> result; 
        
        sort(nums.begin(), nums.end()); 
        
        int i = 0; 
        
        while (i < nums.size() - 1) {
            int cnt = 1;
            if (nums[i] == nums[i + 1]) {
                cnt++;
                i++;
            }
            if (cnt == 2) {
                result.push_back(nums[i]); 
            }
            i++; 
        }        
        
        return result; 
        
    }
};