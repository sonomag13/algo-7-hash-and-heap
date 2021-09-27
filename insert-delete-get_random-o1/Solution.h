// LeetCode 380. Insert Delete GetRandom O(1)
// Medium

#include <vector>

using namespace std; 

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if (mapValIdx.find(val) != mapValIdx.end()) {
            return false; 
        }
        
        arr.push_back(val);
        mapValIdx.insert(make_pair(val, arr.size() - 1));
        return true; 
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mapValIdx.find(val) == mapValIdx.end()) {
            return false; 
        }
        
        int idx2remove = mapValIdx[val];
        int lastIdx = mapValIdx.size() - 1; 
        int lastVal = arr[lastIdx]; 
        
        swap(arr[idx2remove], arr[lastIdx]);
        mapValIdx[lastVal] = idx2remove; 
        
        arr.pop_back(); // the value to remove is now at the last of the array
        mapValIdx.erase(val); // remove the val from the map
        
        return true;         
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randIdx = rand() % arr.size(); 
        return arr[randIdx]; 
    }
    
private:
    vector<int> arr; 
    unordered_map<int, int> mapValIdx; 
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */