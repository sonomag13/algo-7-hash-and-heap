// 205 Isomorphic Strings

#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false; 
        }

        unordered_map<char, char> st;  // key = s and val = t
        unordered_map<char, char> ts;  // key = t and val = s

        for (int i = 0; i < s.length(); ++i) {
            char cs = s[i];
            char ct = t[i]; 

            if (st.find(cs) == st.end() && ts.find(ct) == ts.end()) {
                // characters cs and ct have never been visited
                st.insert(make_pair(cs, ct));
                ts.insert(make_pair(ct, cs)); 
            }

            if (st.find(cs) != st.end()) {
                if (st[cs] == ct) {
                    continue; 
                }
                else {
                    return false; 
                }
            }

            if (ts.find(ct) != ts.end()) {
                if (ts[ct] == cs) {
                    continue; 
                }
                else {
                    return false;
                }
            }

        }

        return true; 
    }
};