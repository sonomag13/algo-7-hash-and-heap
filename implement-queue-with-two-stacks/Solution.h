/*
	40. Implement Queue by Two Stacks
	As the title described, you should only use two stacks to implement a queue's actions.

	The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.

	Both pop and top methods should return the value of first element.

	Example
	Example 1:

	Input:
	    push(1)
	    pop()    
	    push(2)
	    push(3)
	    top()    
	    pop()     
	Output:
	    1
	    2
	    2
	Example 2:

	Input:
	    push(1)
	    push(2)
	    push(2)
	    push(3)
	    push(4)
	    push(5)
	    push(6)
	    push(7)
	    push(1)
	Output:
	[]
	Challenge
	implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.

	Notice
	Suppose the queue is not empty when the pop() function is called.
 */

 class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
        
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        if (sk1.empty()) {
            transferStack(sk2, sk1); 
            sk2.push(element);
            transferStack(sk1, sk2); 
        }
        else {
            transferStack(sk1, sk2); 
            sk1.push(element);
            transferStack(sk2, sk1); 
        }
        
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int val; 
        if (!sk1.empty()) {
            val = sk1.top(); 
            sk1.pop(); 
        }
        if (!sk2.empty()) {
            val = sk2.top();
            sk2.pop();
        }
        return val; 
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        if (!sk1.empty()) {
            return sk1.top(); 
        }
        if (!sk2.empty()) {
            return sk2.top();
        }
    }
    
private:
    stack<int> sk1; 
    stack<int> sk2; 
    
    void transferStack(stack<int>& sourceStack, stack<int>& targetStack) {
        while (!sourceStack.empty()) {
            targetStack.push(sourceStack.top());
            sourceStack.pop(); 
        }
    }
    
    
};