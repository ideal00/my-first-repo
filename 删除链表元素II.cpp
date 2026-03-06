#include <iostream>
#include <vector>
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

// 释放链表内存

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 空链表或只有一个节点，无重复可删
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 1. 创建哑节点，指向真实头节点（核心：解决头节点删除问题）
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        // 2. 遍历指针从哑节点开始（cur始终指向"无重复的最后一个节点"）
        ListNode *cur = dummy;

        // 3. 遍历条件：至少有两个节点可比较
        while (cur->next != nullptr && cur->next->next != nullptr) {
            // 发现重复值
            if (cur->next->val == cur->next->next->val) {
                int dup_val = cur->next->val; // 记录重复值
                // 批量删除所有等于dup_val的节点
                while (cur->next != nullptr && cur->next->val == dup_val) {
                    ListNode *toDelete = cur->next; // 要删除的节点
                    cur->next = cur->next->next;    // 跳过该节点（修改链表指向）
                    delete toDelete;                // 释放内存
                }
            } else {
                // 无重复，指针后移
                cur = cur->next;
            }
        }

        // 4. 取出新头节点，释放哑节点
        ListNode *new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};

int main() {
    vector<int> arr = {1,1,1,2,3,3,4}; // 测试用例
    ListNode *head = createList(arr);
  
    Solution solution;
    ListNode *result = solution.deleteDuplicates(head);
    printList(result); // 输出：2

    return 0;
}