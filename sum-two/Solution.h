/*
    56. Two Sum

    Given an array of integers, find two numbers such that they add up to a specific target number.

    The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.

    Example
    Example1:
    numbers=[2, 7, 11, 15], target=9
    return [0, 1]
    Example2:
    numbers=[15, 2, 7, 11], target=9
    return [1, 2]
    Challenge
    Either of the following solutions are acceptable:

    O(n) Space, O(nlogn) Time
    O(n) Space, O(n) Time
    Notice
    You may assume that each input would have exactly one solution
 */

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        vector<int> result;
        
        /**
         * hash map to store the previous calculation
         * - key: numbers[idx]
         * - val: idx
         */
        unordered_map<int, int> mapDeltaIdx; 
        
        for (int i = 0; i < numbers.size(); ++i) {
            
            int num = numbers[i]; 
            
            int delta = target - num; 
            
            if (mapDeltaIdx.find(delta) != mapDeltaIdx.end()) {
                /**
                 * delta is found
                 * in this case, the delta = one of the key in the map, 
                 * i.e. key (or delta) + number[i] = target
                 */ 
                result.push_back(mapDeltaIdx[delta]); 
                result.push_back(i); 
                return result;
            }
            else {
                // delta is not found, so that insert the delta into the map
                mapDeltaIdx.insert(make_pair(num, i)); 
            }
        }
        
        return result; 
        
    }
};