/*
544. Top k Largest Numbers
Given an integer array, find the top k largest numbers in it.

Example
Example1

Input: [3, 10, 1000, -99, 4, 100] and k = 3
Output: [1000, 100, 10]
Example2

Input: [8, 7, 6, 5, 4, 3, 2, 1] and k = 5
Output: [8, 7, 6, 5, 4]
 */

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        priority_queue<int> priQueue1;
        vector<int> result; 
        for (auto val : nums) {
            priQueue1.push(val); 
        }
        for (int i = 0; i < k; ++i) {
            result.push_back(priQueue1.top());
            priQueue1.pop();
        }
        return result;
    }
};