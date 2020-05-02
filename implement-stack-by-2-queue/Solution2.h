/*
    this solution is much slower
 */

class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        // write your code here
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop(); 
            }
        }
        else {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop(); 
            }
        }
    }

    /*
     * @return: nothing
     */
    void pop() {
        // write your code here
        if (q1.empty())
            return q2.pop();
        if (q2.empty())
            return q1.pop();
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        if (q1.empty())
            return q2.front();
        if (q2.empty())
            return q1.front();
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        // write your code here
        return q1.empty() && q2.empty(); 
    }
    
private:
    queue<int> q1;
    queue<int> q2; 
};