/*
    560. Subarray Sum Equals K
    Medium

    Given an array of integers nums and an integer k, return the 
    total number of continuous subarrays whose sum equals to k.
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int counter{0}; 
        
        unordered_map<int, int> mapSumCnt; 
        mapSumCnt.insert(make_pair(0, 1)); 
        
        int sum{0}; 
        
        // sub sum = sum[n2] - sum[n1] where n2 > n1
        
        for (int i = 0; i < nums.size(); ++i) {
            
            sum += nums[i]; 
            
            // sum is sum[n1] and we need to find if there exist sum[n1] 
            // such that target = sum[n1] - sum[n2]
            int delta = sum - k; 
            if (mapSumCnt.find(delta) != mapSumCnt.end()) {
                counter += mapSumCnt[delta]; 
            }
            
            // sum is then treated as sum[n1] for the future iterations
            if (mapSumCnt.find(sum) != mapSumCnt.end()) {
                mapSumCnt[sum]++;
            }
            else {
                mapSumCnt.insert(make_pair(sum, 1));
            }            
        }        
        
        return counter;
    }
};