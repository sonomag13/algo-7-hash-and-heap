// 1570. Dot Product of Two Sparse Vectors

#include <vector>
#include <unordered_map>

using namespace std; 

class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                mapIdxVal.insert(make_pair(i, nums[i]));
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {

        int sum = 0; 

        for (auto & ele : mapIdxVal) {
            size_t idx = ele.first; 
            if (vec.mapIdxVal.find(idx) != vec.mapIdxVal.end()) {
                sum += ele.second * vec.mapIdxVal[idx]; 
            }
        }
        
        return sum; 
    }

private: 
    unordered_map<size_t, int> mapIdxVal; 
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);