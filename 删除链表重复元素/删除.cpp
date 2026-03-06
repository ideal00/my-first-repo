#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *createList(int arr[],int size){
    ListNode *head = new ListNode(0);
    ListNode *current = head;
    for(int i = 0; i < size; i++){
        current->next = new ListNode(arr[i]);
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
      
        ListNode *p = head;
        while(p != nullptr && p->next != nullptr) {
            if(p->next->val == p->val){
                ListNode *temp = p->next;
                p->next = p->next->next; 
                delete temp; 
            } else {
                p = p->next; 
            }
        }
        
        return head; 
    } 
};
    