#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
vector<int> splitNumber(int num) {
    vector<int> digits;
    if (num == 0) {
        digits.push_back(0);
        return digits;
    }
    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }
    while (num > 0) {
        digits.push_back(num % 10);
        num = num / 10;
    }
    reverse(digits.begin(), digits.end());
    if (isNegative) {
        digits.insert(digits.begin(), -1);
    }
    return digits;
}


vector<int> splitArrayElements(vector<int>& arr) {
    vector<int> result;
    for (int num : arr) {
        vector<int> digits = splitNumber(num);
        result.insert(result.end(), digits.begin(), digits.end());
    }
    return result;
}


ListNode *createList(vector<int>& arr){
    
     vector<int> arr2 = splitArrayElements(arr);
    ListNode *head = new ListNode(0);
    ListNode *current = head;
    for(int i: arr2){
        current->next = new ListNode(i);
        current = current->next;
    }
    return head->next;
}

void printList(ListNode *head){
    for(ListNode *p = head; p!= nullptr; p = p->next){
        cout << p->val << ",";
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = l1, *q = l2, *c = head;
        int i = 0;
        while(p != nullptr || q != nullptr || i == 1){
            int x = (p != nullptr) ? p->val : 0;
            int y = (q !=  nullptr) ? q->val : 0;
            int sum = x + y + i;
            i = sum / 10; 
            int currentVal = sum % 10; 
            
            c->next = new ListNode(currentVal);
            c = c->next; 
            
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
            }
             return head->next;
        }
       

    
};





