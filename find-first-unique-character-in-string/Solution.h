
/*
    209. First Unique Character in a String
    Find the first unique character in a given string. You can assume that there is at least one unique character in the string.

    Example
    Example 1:
        Input: "abaccdeff"
        Output:  'b'
        
        Explanation:
        There is only one 'b' and it is the first one.


    Example 2:
        Input: "aabccd"
        Output:  'b'
        
        Explanation:
        'b' is the first one.
 */
 
class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here
        map<char, int> myHash; 
        for (int i = 0; i < str.length(); ++i) {
            char curChar = str[i]; 
            if (myHash.find(curChar) == myHash.end()) {
                myHash[curChar] = 1; 
            }
            else {
                myHash[curChar]++; 
            }
        }
        
        for (auto ele : myHash) {
            if (ele.second == 1) 
                return ele.first; 
        }
    }
};