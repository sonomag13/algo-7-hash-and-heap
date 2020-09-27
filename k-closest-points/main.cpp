#include <iostream>
#include <vector>

#include "DataStructure.h"
#include "Solution.h"
#include "Solution2.h"

int main() {
    int k = 5;
    Point origin(0, 0);
    vector<Point> vecPoints;
    for (int i = 10; i >= 1; --i) {
        vecPoints.push_back(Point(i, i));
    }

    Solution2 solution2;
    vector<Point> result = solution2.kClosest(vecPoints, origin, k);

    for (auto pt : result) {
        cout << "x = " << pt.x << " and y = " << pt.y << endl;
    }

}