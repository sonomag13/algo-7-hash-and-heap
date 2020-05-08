/*
	4. Ugly Number II	
	Ugly number is a number that only have prime factors 2, 3 and 5.

	Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

	Example
	Example 1:

	Input: 9
	Output: 10
	Example 2:

	Input: 1
	Output: 1
	Challenge
	O(n log n) or O(n) time.

	Notice
	Note that 1 is typically treated as an ugly number.
  */

class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        static vector<int> nums{1}; 
        static int i2{0}, i3{0}, i5{0}; 
        
        while (nums.size() < n) {
            int next2 = nums[i2] * 2;
            int next3 = nums[i3] * 3;
            int next5 = nums[i5] * 5; 
            int next = min(next2, min(next3, next5)); 
            if (next2 == next) {
                i2++;
            }
            if (next3 == next) {
                i3++;
            }
            if (next5 == next) {
                i5++; 
            }
            nums.push_back(next); 
        }
        
        return nums[n - 1];
    }
};