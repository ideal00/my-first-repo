#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        for(ListNode *p = list1, *q = list2; p != nullptr || q != nullptr;){
            if(p == nullptr){
                current->next = q ;
                return head->next;
            }
            if(q == nullptr){
                current->next = p;
                return head->next;
            }
            if(p->val < q->val){
                current->next = p;
                current = current->next;
                p = p->next;
            }else if(p->val > q->val){
                current->next = q;
                current = current->next;
                q = q->next;
            }else{
                current->next = p;
                current = current->next;
                p = p->next;
                current->next = q;
                current = current->next;
                q = q->next;
            }
        }
        return head->next;
    }
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

int main(){
    int arr1[] = {1,2,4};
    int arr2[] = {1,3,4};
    ListNode *list1 = createList(arr1, 3);
    ListNode *list2 = createList(arr2, 3);
    Solution solution;
    ListNode *result = solution.mergeTwoLists(list1, list2);
    printList(result);
}