//
// Created by strobe on 4/25/20.
//

#pragma once

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    /*
        @param x: An integer
        @return: nothing
     */
    void push(int x) {
        // write your code here
        qPrimary.push(x);
        cnt++;
    }

    // @return: nothing
    void pop() {
        // write your code here
        while (!qPrimary.empty()) {
            if (cnt > 1)
                qTemp.push(qPrimary.front());
            qPrimary.pop();
            cnt--;
        }
        while (!qTemp.empty()) {
            qPrimary.push(qTemp.front());
            qTemp.pop();
            cnt++;
        }
    }

    // @return: An integer
    int top() {
        int topVal;
        while (!qPrimary.empty()) {
            if (cnt == 1) {
                topVal = qPrimary.front();
            }
            qTemp.push(qPrimary.front());
            qPrimary.pop();
            cnt--;
        }
        while (!qTemp.empty()) {
            qPrimary.push(qTemp.front());
            qTemp.pop();
            cnt++;
        }
        return topVal;
    }

    // @return: True if the stack is empty
    bool isEmpty() {
        // write your code here
        return cnt == 0;
    }

private:
    queue<int> qPrimary;
    queue<int> qTemp;
    int cnt{0};
};
