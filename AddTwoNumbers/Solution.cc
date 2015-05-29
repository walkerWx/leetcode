#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    int tmp = 0;
    ListNode *sum = l1;
    ListNode *borrow = l2;
    while (l1->next != NULL && l2->next != NULL) {
      tmp = l1->val;
      l1->val = (l1->val + l2->val + carry)%10;
      carry = (tmp + l2->val + carry)/10;
      l1 = l1->next;
      l2 = l2->next;
      print(sum);
    }

    if( l1->next == NULL && l2->next == NULL) {
      tmp = l1->val;
      l1->val = (l1->val + l2->val + carry)%10;
      carry = (tmp + l2->val + carry)/10;
      cout << carry << endl;
      if (carry == 0) {
        return sum;
      } else {
        l2->val = carry;
        l1->next = l2;
        return sum;
      }
    }

    if (l1->next == NULL) {
      tmp = l1->val;
      l1->val = (l1->val + l2->val + carry)%10;
      carry = (tmp + l2->val + carry)/10;
      if (carry == 0) {
        l1->next = l2->next;
        return sum;
      } else {
        l2 = l2->next;
        l1->next = l2;
        while (carry != 0 && l2->next != NULL) {
          tmp = l2->val;
          l2->val = (l2->val + carry)%10;
          carry = (tmp + carry)/10;
          l2 = l2->next;
        }
        if (carry == 0) {
          return sum;
        } else {
          tmp = l2->val;
          l2->val = (l2->val + carry)%10;
          carry = (tmp + carry)/10;
          if (carry == 0) {
            return sum;
          } else {
            l2->next = borrow;
            borrow->val = carry;
            borrow->next = NULL;
            return sum;
          }
        }
      }
    }

    if (l2->next == NULL) {
      tmp = l1->val;
      l1->val = (l1->val + l2->val + carry)%10;
      carry = (tmp + l2->val + carry)/10;
      if (carry == 0) {
        return sum;
      } else {
        l1 = l1->next;
        while (carry != 0 && l1->next != NULL) {
          tmp = l1->val;
          l1->val = (l1->val + carry)%10;
          carry = (tmp + carry)/10;
          l1 = l1->next;
        }
        if (carry == 0) {
          return sum;
        } else {
          tmp = l1->val;
          l1->val = (l1->val + carry)%10;
          carry = (tmp + carry)/10;
          if (carry == 0) {
            return sum;
          } else {
            l1->next = borrow;
            borrow->val = carry;
            borrow->next = NULL;
            return sum;
          }
        }
      }

    }

    
    return sum;
  }

  void print(ListNode *h) {
    while (h != NULL) {
      cout << h->val;
      h = h->next;
    }
    cout << endl;
  }
};

int main() {
  Solution s;
  ListNode ln1 = ListNode(1);
  ListNode ln2 = ListNode(9);
  ListNode ln3 = ListNode(8);
  ListNode ln4 = ListNode(8);
  ListNode ln5 = ListNode(3);
  ln2.next = &ln3;
  ListNode *l1 = &ln1;
  ListNode *l2 = &ln2;
  s.print(s.addTwoNumbers(l1,l2));
   
}

