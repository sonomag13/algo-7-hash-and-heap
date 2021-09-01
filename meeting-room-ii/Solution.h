// LeetCode 253. Meeting Rooms II

#include <algorithm>
#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int result = 1;
        
        typedef vector<int> intl; 
        
        // sort the intervals
        auto comp1 = [] (const intl & intl1, const intl & intl2) {
            return intl1[0] < intl2[0];
        };
        sort(intervals.begin(), intervals.end(), comp1); 
        
        // insert the intervals one by one
        auto comp2 = [] (const intl & intl1, const intl & intl2) {
            // need a min heap on the ending time
            return intl1[1] > intl2[1]; 
        };
        priority_queue<intl, vector<intl>, decltype(comp2)> pqIntl(comp2);
        
        pqIntl.push(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            intl newMeeting = intervals[i];
            intl topMeeting = pqIntl.top();
            pqIntl.pop();
            
            if (newMeeting[0] >= topMeeting[1]) {
                // no need to add a room, but need to extend the end time of the top meeting
                topMeeting[1] = newMeeting[1];
            }
            else {
                pqIntl.push(newMeeting);
                result++;
            }
            
            pqIntl.push(topMeeting);
        }
        
        return result; 
        
    }
};