/*
    612. K Closest Points
    Given some points and an origin point in two-dimensional space, find k points which are nearest to the origin.
    Return these points sorted by distance, if they are same in distance, sorted by the x-axis, and if they are same in the x-axis, sorted by y-axis.

    Example
    Example 1:

    Input: points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3 
    Output: [[1,1],[2,5],[4,4]]
    Example 2:

    Input: points = [[0,0],[0,9]], origin = [3, 1], k = 1
    Output: [[0,0]]
 */

// solution for LintCode

#pragma once 

#include <algorithm>
#include <queue>
#include <vector>

#include "DataStructure.h"


using namespace std; 

Point globalOrigin;
 
int calcDistance(const Point& P) {
    return (P.x - globalOrigin.x) * (P.x - globalOrigin.x) + (P.y - globalOrigin.y) * (P.y - globalOrigin.y);
}
  
struct comparator {
    bool operator() (const Point& P1, const Point& P2) const {
        int delta{calcDistance(P1) - calcDistance(P2)}; 
        if (delta == 0) {
            delta = P1.x - P2.x; 
        }
        if (delta == 0) {
            delta = P1.y - P2.y; 
        }
        return delta < 0; 
    }
};

class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        globalOrigin = Point(origin.x, origin.y); 
        priority_queue<Point, vector<Point>, comparator> priQueue; 
        vector<Point> result; 
        
        for (auto val : points) {
            priQueue.push(val); 
            if (priQueue.size() > k) {
                priQueue.pop(); 
            }
        }
        
        while (!priQueue.empty()) {
            result.push_back(priQueue.top());
            priQueue.pop(); 
        }
        
        reverse(result.begin(), result.end());
        
        return result; 
    }
    
};