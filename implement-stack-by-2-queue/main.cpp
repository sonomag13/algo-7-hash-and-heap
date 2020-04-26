/*
    494. Implement Stack by Two Queues
    Implement a stack by two queues. The queue is first in first out (FIFO). That means you can not directly pop the last element in a queue.

    Example
    Example 1:

    Input:
    push(1)
    pop()
    push(2)
    isEmpty() // return false
    top() // return 2
    pop()
    isEmpty() // return true
    Example 2:

    Input:
    isEmpty()
 */

#include "Solution.h"
#include <iostream>

using namespace std;

int main() {

    Stack solution;

    solution.push(1);
    solution.push(2);
    solution.pop();

    int topVal = solution.top();

    cout << "top val = " << topVal << endl;

    return 0;
}
