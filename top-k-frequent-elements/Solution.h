/*
    347. Top K Frequent Elements
    Medium

    Given an integer array nums and an integer k, return the k most
    frequent elements. You may return the answer in any order.

    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Example 2:
    Input: nums = [1], k = 1
    Output: [1]
 */

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // use a hash map to count the frequency of each number
        unordered_map<int, int> mapNumFreq;

        for (auto num : nums) {
            if (mapNumFreq.find(num) == mapNumFreq.end()) {
                mapNumFreq.insert(make_pair(num, 1));
            }
            else {
                mapNumFreq[num]++;
            }
        }

        auto comp = [] (const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pqNumFreq(comp);

        for (auto& ele : mapNumFreq) {
            pqNumFreq.push(ele);
            if (pqNumFreq.size() > k) {
                pqNumFreq.pop();
            }
        }

        vector<int> result;

        for(int i = 0; i < k; ++i) {
            result.push_back(pqNumFreq.top().first);
            pqNumFreq.pop();
        }

        return result;

    }
};