// 1189. Maximum Number of Balloons

#include <iostream>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> mapCharCnt; 
        const string str = "balloon";
        for (auto chara : str) {
            mapCharCnt.insert(make_pair(chara, 0));
        }

        for (auto chara : text) {
            if (mapCharCnt.find(chara) != mapCharCnt.end()) {
                ++mapCharCnt[chara]; 
            }
        }

        // there are two 'l's and 'o's in the string
        mapCharCnt['l'] /= 2; 
        mapCharCnt['o'] /= 2;

        int num = INT_MAX; 
        for (auto & ele : mapCharCnt) {
            if (ele.second < num) {
                num = ele.second; 
            }
        }

        return num; 
    }
};