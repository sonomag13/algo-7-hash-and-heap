/*
    692. Top K Frequent Words
    Given a non-empty list of words, return the k most frequent elements.

    Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

    Example 1:
    Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    Output: ["i", "love"]
    Explanation: "i" and "love" are the two most frequent words. Note that "i" comes before "love" due to a lower alphabetical order.
    
    Example 2:
    Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
    Output: ["the", "is", "sunny", "day"]
    Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
    
    Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.

    Follow up:
    Try to solve it in O(n log k) time and O(n) extra space.
 */

#include <vector>

using namespace std; 

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {                
        
        vector<string> result; 
        
        // use a hash map to count the appearance of words
        unordered_map<string, int> mapWordCnt;         
        for (auto word : words) {            
            if (mapWordCnt.find(word) == mapWordCnt.end()) {
                // word is not found
                mapWordCnt.insert(make_pair(word, 1));
            } 
            else {
                // word can be found
                mapWordCnt[word]++; 
            }                        
        }
        
        // map to priority queue
        auto comparator = [](const pair<string, int>& p1, const pair<string, int>& p2){
            // p1 has more counts
            if (p1.second > p2.second) {
                return true; 
            }            
            // p2 has more counts
            if (p1.second < p2.second) {
                return false; 
            }
            // same count such that compare alpabet by travsing the characters
            int i = 0; 
            while (i < min(p1.first.size(), p2.first.size())) {                
                if (p1.first[i] < p2.first[i]) {
                    return true; 
                }                
                if (p1.first[i] > p2.first[i]) {
                    return false; 
                }    
                i++; 
            }            
            /**
             * At this point, the shorter one of the p1 and p2 complated match 
             * with the long one of p1 and p2, e.g. "aaaa" and "aaaaaaaa". 
             * The shorter one should be in front. 
             **/ 
            if (p1.first.size() < p2.first.size()) {
                return true;
            }           
            else {
                return false; 
            }                        
        };
        
        // use a priority queue to maintain top k elements
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comparator)> priQueWordCnt(comparator);        
        for (auto ele : mapWordCnt) {
            priQueWordCnt.push(ele);
            if (priQueWordCnt.size() > k) {
                priQueWordCnt.pop(); 
            }
        }
        
        // priority queue to vector
        for (int i =0; i< k; ++i) {
            result.push_back(priQueWordCnt.top().first); 
            priQueWordCnt.pop();
        }        
        reverse(result.begin(), result.end()); 
        
        return result; 
        
    }
};