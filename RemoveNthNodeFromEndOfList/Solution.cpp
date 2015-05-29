#include <iostream>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x) , next(NULL) {}
};

class Solution {
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p = head;
    ListNode *q = head;
    for (int i = 0; i < n; ++i) {
      p = p->next;
    }
    if (p == NULL) {
      // remove head
      return head->next;
    }
    while (p->next != NULL) {
      p = p->next;
      q = q->next;
    }
    q->next = q->next->next;
    return head;
  }
};
