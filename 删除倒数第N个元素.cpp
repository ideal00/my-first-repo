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

ListNode *createList(vector<int>& arr) {
    ListNode *head = new ListNode(0); // 临时哑节点，简化创建
    ListNode *current = head;
    for (int i : arr) {
        if (i >= -100 && i <= 100) {
            current->next = new ListNode(i);
            current = current->next;
        } else {
            cout << "输入的数字不合法，请输入-100到100之间的数字。\n" << endl;
            // 释放已创建节点，避免内存泄漏
            ListNode *p = head->next;
            while (p) {
                ListNode *temp = p;
                p = p->next;
                delete temp;
            }
            delete head;
            return nullptr;
        }
    }
    ListNode *realHead = head->next;
    delete head; // 释放临时哑节点
    return realHead;
}


void printList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val;
        if (p->next != nullptr) {
            cout << ",";
        }
        p = p->next;
    }
    cout << endl;
}


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0); // 创建哑节点
        dummy->next = head;
        ListNode *ft = dummy;
        int length = 1;
        while(head->next != nullptr) {
            length++;
            head = head->next;
        }
        int target = length - n;
        for (int i = 0; i < target; i++) {
            ft = ft->next;
        }// ft指向前一个节点
        ListNode *temp = ft->next; // 待删除节点
        ft->next = ft->next->next; // 删除节点
        delete temp; 
        ListNode *newHead = dummy->next; // 获取新的头节点
        delete dummy; // 释放哑节点
        return newHead;
    }
};