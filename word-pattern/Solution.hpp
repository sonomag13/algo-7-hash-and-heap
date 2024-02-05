// LeetCode 290 Word Pattern

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int left=0;
        int right=0;
        vector<string> vecStr; 
        while (right < s.length()) {
            if (s[right] == ' ') {
                vecStr.push_back(s.substr(left, right - left));
                left = right + 1; 
                right = left; 
            }
            ++right; 
        }
        if (right > s.length() - 1) {
            right = s.length() - 1; 
        }
        vecStr.push_back(s.substr(left, right)); 

        // for (auto & str : vecStr) {
        //     cout << str << ' ';
        // }

        if (vecStr.size() != pattern.length()) {
            cout << "size does not match" << endl;
            return false; 
        }

        unordered_map<char, string> mapCharStr;
        unordered_map<string, char> mapStrChar;

        for (int i = 0; i < pattern.length(); ++i) {
            string curStr = vecStr[i];
            char curChar = pattern[i]; 

            bool cond1 = mapCharStr.find(curChar) == mapCharStr.end();
            bool cond2 = mapStrChar.find(curStr) == mapStrChar.end();
            if (cond1 && cond2) {
                mapCharStr.insert(make_pair(curChar, curStr));
                mapStrChar.insert(make_pair(curStr, curChar));
            }

            if (!cond1) {
                if (mapCharStr[curChar] != curStr) { 
                    return false; 
                }
            }

            if (!cond2) {
                if (mapStrChar[curStr] != curChar) {
                    return false; 
                }
            }
            
        }

        return true; 
    }
};