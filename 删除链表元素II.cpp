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

ListNode *createList(vector<int>& arr){
    ListNode *head = new ListNode(0);
    ListNode *current = head;
    for(int i: arr){
        if(i <= 100 && i>= -100){
            current->next = new ListNode(i);
        current = current->next;
    }else{
        cout << "输入的数字不合法，请输入-100到100之间的数字。\n" << endl;
        return nullptr;
        
    }
    
    }return head->next;
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
                if(p->next->val != p->val){
                    ListNode *temp = p->next;
                    p->val = p->next->val;
                p->next = p->next->next; 
                delete temp; 
                }else if(p->next == nullptr && head->val == p->val ){
                    ListNode *temp = p;
                    p = p->next; 
                    delete temp;
            }else if(p->next == nullptr){
                ListNode *q = head;
                while(q->val  == p->val){
                    ListNode *temp = q;
                    q = q->next; 
                    delete temp;
                }
            }
            } else {
                p = p->next; 
            }
        }
        
        return head; 
    }
};

int main(){
    vector<int> arr = {1,1,2,3,3};
    ListNode *head = createList(arr);
    Solution solution;
    ListNode *result = solution.deleteDuplicates(head);
    printList(result);
}