/*
    155. Min Stack
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
    
    Example 1:

    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]

    Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    

    Constraints:
    Methods pop, top and getMin operations will always be called on non-empty stacks.
 */

#include <stack>

using namespace std; 

class MinStack {
public:    
    MinStack() = default; 
    
    void push(int x) {
        _dataStack.push(x);        
        if (_minStack.empty() || x <= _minStack.top()) {
            /**
             * The only tricky part of this problem is the case where we push
             * multiple minimum value into the stack, where we consider the condition
             * 
             *                  x <= _minStack.top()
             * 
             * In this case, the min data has been pushed into the data stack for multiple
             * times. 
             * 
             * On the contrary if we use 
             * 
             *                  x < _minStack.top()
             * 
             * as the condition, the min value will appear in the min stack for only once. 
             * When we pop the min element for multiple times from the data stack, we do not 
             * have multiple min values to pop in the min stack
             **/
            _minStack.push(x); 
        }
    }
    
    void pop() {
        if (_dataStack.top() == _minStack.top()) {
            _dataStack.pop();
            _minStack.pop();
        }
        else {
            _dataStack.pop();
        }
    }
    
    int top() {
        return _dataStack.top();
    }
    
    int getMin() {
        return _minStack.top();
    }
    
private:
    stack<int> _dataStack; 
    stack<int> _minStack; 
    
}; 