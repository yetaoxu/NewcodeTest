//
// Created by xuyetao on 2020/4/20.
//
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *h = new ListNode(-1);
    ListNode *p = head;
    h->next = head;
    while (p->next != NULL) {
        if (p->val <= p->next->val) {
            p = p->next;
        }
        else {
            ListNode *temp = p->next;
            ListNode *q = h;
            p->next = p->next->next;
            while (q->next->val < temp->val) {
                q = q->next;
            }
            temp->next = q->next;
            q->next = temp;
        }
    }
    return h->next;
}

int main() {
    ListNode *aa = new ListNode(2);
    ListNode *bb = new ListNode(1);
    aa->next = bb;
    aa->next->next = NULL;
    insertionSortList(aa);
    return 0;
}
