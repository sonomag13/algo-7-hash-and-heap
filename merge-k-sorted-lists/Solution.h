/*
104. Merge K Sorted Lists
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Example
Example 1:
    Input:   [2->4->null,null,-1->null]
    Output:  -1->2->4->null

Example 2:
    Input: [2->6->null,5->null,7->null]
    Output:  2->5->6->7->null
  */

#include <iostream>
#include <vector>

using namespace std; 

// Definition of ListNode
class ListNode {
public:
int val;
ListNode *next;
ListNode(int val) {
    this->val = val;
    this->next = NULL;
    }
};

class Good_Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto head = new ListNode(0);                 
        auto curr{head}; 
        
        auto comp = [] (const ListNode* node1, const ListNode* node2) {
            return node1->val > node2->val; 
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp); 
        
        for (auto node : lists) {
            if (node) {
                pq.push(node); 
            }
        }
        
        // BFS
        while (!pq.empty()) {            
            curr->next = pq.top();
            pq.pop();
            curr = curr->next; 
            
            if (curr->next) {
                pq.push(curr->next); 
            }
        }
        
        return head->next; 
        
    }
};

// this is a really inefficidnt solution
class Inefficient_Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        
        ListNode* headNode{NULL};
        ListNode* previousNode{NULL}; 
        size_t numNullptr{0};
        size_t listSize{lists.size()}; 
        
        while (numNullptr != listSize) {
            
            int minVal{INT_MAX}; 
            int idxMinVal{-1}; 
            
            numNullptr = 0; 
            
            for (size_t i = 0; i < listSize; ++i) {
            
                ListNode* currentNode = lists[i]; 
            
                if (currentNode == NULL) {
                    numNullptr++; 
                }
                else {
                    if (currentNode->val < minVal) {
                        minVal = currentNode->val;
                        idxMinVal = i; 
                    }
                }
            }
            
            if (idxMinVal != -1) {
                if (headNode == NULL) {
                    headNode = lists[idxMinVal]; 
                    previousNode = headNode; 
                    lists[idxMinVal] = lists[idxMinVal]->next;
                }
                else {
                    previousNode->next = lists[idxMinVal]; 
                    previousNode = previousNode->next; 
                    lists[idxMinVal] = lists[idxMinVal]->next;    
                }
            }
        }
    
        return headNode; 
    }
};

