//
// Created by luther on 9/26/20.
//

/**
 * in this header we use lambda function to override the comparator
 */

#pragma once

#include <algorithm>
#include <queue>
#include <vector>

#include "DataStructure.h"

using namespace std;

class Solution2 {
public:
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        vector<Point> result;
        this->origin = Point(origin.x, origin.y);

        // define the compare
        auto compare = [this](const Point& p1, const Point& p2) {
            int delta = this->calcDist(p1) - this->calcDist(p2);
            if (delta == 0) {
                delta = p1.x - p2.x;
            }
            if (delta == 0) {
                delta = p1.y - p2.y;
            }
            return delta < 0;
        };

        priority_queue<Point, vector<Point>, decltype(compare)> pq(compare);

        for (size_t i = 0; i < points.size(); i++) {
            pq.push(points[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // convert the queue to vector
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

private:
    Point origin;
    int calcDist(const Point& p) {
        return (p.x - this->origin.x) * (p.x - this->origin.x) + (p.y - this->origin.y) * (p.y - this->origin.y);
    }

};