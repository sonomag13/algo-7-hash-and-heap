// LeetCode 295. Find Median from Data Stream

#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // insert a number into a heap. We should like to keep the size of the max heap
        // smaller (by one number) or equal to the min heap
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        
        // rebalance the size of the heaps
        if (maxHeap.size() - minHeap.size() == 2) {
            // in this case the size of two heap are equal to each other
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size()) {
            // the size of the min heap is larger than max heap by 1 number
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }        
        
    }
    
    double findMedian() {
        
        double median; 
        
        if (maxHeap.size() > minHeap.size()) {
            // the max heap is larger 
            median = static_cast<double>(maxHeap.top());
        }
        else {          
            // min heap and max heap has the same size
            median =  static_cast<double>(maxHeap.top() + minHeap.top())/2.0;
        }
        
        return median; 
    }
    
private:    
    priority_queue<int, vector<int>, greater<int>> minHeap;     
    priority_queue<int, vector<int>, less<int>> maxHeap; 
    
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */