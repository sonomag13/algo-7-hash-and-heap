//
// Created by Lu Gao on 8/30/21.
//

#include <iostream>
#include <vector>

#include "Solution.h"

using namespace std;

int main() {

    vector<int> nums{1, 1, 1, 2, 2, 2, 2, 3, 3, 4};

    Solution solution;

    vector<int> result = solution.topKFrequent(nums, 3);

    for (auto val : result) {
        cout << val << endl;
    }

    return 0;
}