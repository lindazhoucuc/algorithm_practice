//
// Created by zhouxiaomin on 2021/05/22.
//
#include <iostream>
#include <stack>
using namespace  std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while(curr != nullptr) {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next== nullptr || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        ListNode* next = head;
        stack<ListNode*> st;
        while(next != nullptr) {
            for(int i = 0; i < k && next != nullptr; i++) {
                st.push(next);
                next = next->next;
            }
            if(st.size() < k)  return dummy.next;
            while(st.size() != 0) {
                ListNode* tmp = st.top();
                st.pop();
                curr->next = tmp;
                curr = curr->next;
            }
            curr->next = next;
        }
        return dummy.next;

    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup2(ListNode* head, int k) {
        if(head == nullptr)  return head;

        ListNode dummy(0);
        ListNode* curr = &dummy;
        curr->next = head;
        ListNode* next1 , *next2;
        int count = 1;
        while(head != nullptr) {
            if(count % k == 0) {
                next1= curr->next;
                next2 = head->next;
                curr->next = head;

                head->next = nullptr;
                reverse(next1);

                next1->next = next2;
                curr = head = next1;
            }
            head = head->next;
            count++;
        }
        return dummy.next;
    }
};


class SolutionLLF {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head, *next, *prev = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode *cur = &dummy;
        ListNode *next1, *next2;
        int i = 1;
        while (head) {
            if (i % k == 0) {
                next1 = cur->next;
                next2 = head->next;
                cur->next = head;

                head->next = nullptr;
                reverseList(next1);

                next1->next = next2;
                cur = head = next1;
            }
            head = head->next;
            i++;
        }
        return dummy.next;
    }
};

int main() {
    ListNode a = ListNode(1);
    ListNode b = ListNode(2);
    ListNode c = ListNode(3);
    ListNode d = ListNode(4);
    ListNode e = ListNode(5);
    ListNode f = ListNode(6);
    ListNode g = ListNode(7);
    ListNode h = ListNode(8);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    printList(&a);

    Solution slu;
    ListNode* res = slu.reverseKGroup2(&a, 3);
    printList(res);

}