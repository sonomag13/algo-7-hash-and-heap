// LeetCode 128. Longest Consecutive Sequence
// Medium

#include <unordered_map>
#include <vector>

using namespace std; 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // key = number; val = length of the sequence led by key
        unordered_map<int, int> mapValLen; 
        
        for (auto num : nums) {
            
            if (mapValLen.count(num)) {
                // do not care duplicated numbers
                continue; 
            }
            
            int leftNeighbor = num - 1;
            int leftLength = 0;             
            if (mapValLen.count(leftNeighbor)) {
                // num has the left neighbor
                // in the hash table, the left neighbor correlates to the 
                // max length of the sequence that the left neighbor belong to
                leftLength = mapValLen[leftNeighbor];
            }
            
            int rightNeighbor = num + 1; 
            int rightLength = 0;
            if (mapValLen.count(rightNeighbor)) {
                // num has the right neighbor; 
                // in the hash table, the right neighbor correlates to the 
                // max length of the sequence that the right neighbor belong to
                rightLength = mapValLen[rightNeighbor];
            }
            
            // if there is no neighbor, the length is 1
            int totalLength = leftLength + 1 + rightLength;
            
            // the trick of this problem is, we only need to update two ends in the map
            // 
            if (leftLength && rightLength) {
                // num is a bridge between left and right
                int leftSeqStart = num - leftLength;
                mapValLen[leftSeqStart] = totalLength;  // update the left most entry
                                                        // and no deed to update the value in the middle

                int rightSeqEnd = num + rightLength;
                mapValLen[rightSeqEnd] = totalLength;  // like wise
            }
            if (leftLength) {
                // only left neighbors
                mapValLen[num - leftLength] = totalLength;
                mapValLen.insert(make_pair(num, totalLength));
            }
            else {
                // only right neighbors
                mapValLen[num + rightLength] = totalLength;
                mapValLen.insert(make_pair(num, totalLength));
            }            
        }
        
        int maxLen = 0; 
        for (auto & ele : mapValLen) {
            maxLen = max(maxLen, ele.second);
        }
        
        return maxLen; 
    }    
};