// 383. Ransom Note

#include <iostream>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, size_t> mapCharCount; 

        for (auto ch : magazine) {
            if (mapCharCount.find(ch) == mapCharCount.end()) {
                mapCharCount.insert(make_pair(ch, 1));
            }
            else {
                ++mapCharCount[ch]; 
            }
        }

        for (auto ch : ransomNote) {
            if (mapCharCount.find(ch) == mapCharCount.end()) {
                return false; 
            }
            if (mapCharCount[ch] == 0) {
                return false; 
            }
            --mapCharCount[ch];
        }
        
        return true; 
    }
};