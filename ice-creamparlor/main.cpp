#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr) {

    vector<int> ret;

    unordered_map<int, int> mapValIdx;

    for (int i = 0; i < arr.size(); ++i) {

        int val = arr[i];
        int delta = m - val;

        if (mapValIdx.find(delta) != mapValIdx.end()) {
            ret.push_back(mapValIdx[delta] + 1);
            ret.push_back(i + 1);
            break;
        }
        else {
            mapValIdx.insert(make_pair(val, i));
        }

    }

    return ret;
}

int main() {

    int n = 9;
    vector<int> arr = {1, 3, 4, 6, 7, 9};

    vector<int> icecream = icecreamParlor(n, arr);

    assert(arr[icecream[0] - 1] + arr[icecream[1] - 1] == n);

    return 0;
}
