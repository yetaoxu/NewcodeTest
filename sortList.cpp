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

ListNode *sortList(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *p = head;
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len ++;
    }
    ListNode *temp = new ListNode(0);
    temp->next = head;
    for (int interval = 1; interval <= len; interval *= 2) {
        ListNode *pre = temp;
        ListNode *first = temp->next;
        ListNode *second = temp->next;
        while (first != NULL || second != NULL) {
            int i = 0;
            while (i < interval && second != NULL) {
                second = second->next;
                i++;
            }
            int fvisit = 0, svisit = 0;
            while (fvisit < interval && svisit < interval && first != NULL && second != NULL) {
                if (first->val < second->val) {
                    pre->next = first;
                    pre = first;
                    first = first->next;
                    fvisit++;
                } else {
                    pre->next = second;
                    pre = second;
                    second = second->next;
                    svisit++;
                }
            }
            while (fvisit < interval && first != NULL) {
                pre->next = first;
                pre = first;
                first = first->next;
                fvisit++;
            }
            while (svisit < interval && second != NULL) {
                pre->next = second;
                pre = second;
                second = second->next;
                svisit++;
            }
            pre->next = second;
            first = second;
        }
    }
    ListNode *retResult = temp->next;
    delete temp;
    temp = NULL;
    return retResult;
}

int main() {
    ListNode *aa = new ListNode(2);
    ListNode *bb = new ListNode(1);
    aa->next = bb;
    aa->next->next = NULL;
    sortList(aa);
    return 0;
}