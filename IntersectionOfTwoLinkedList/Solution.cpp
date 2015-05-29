
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int a = 0, b =0;
    ListNode *currentA = headA, *currentB = headB;
    while(currentA != NULL) {
      currentA = currentA->next;
      ++a;
    }

    while(currentB != NULL) {
      currentB = currentB->next;
      ++b;
    }
    
    currentA = headA;
    currentB = headB;

    if( a > b ) {
      int i = a - b;
      while( i > 0 ) {
        currentA = currentA->next;
        --i;
      }
    } else if( a < b ) {
      int i = b - a;
      while( i > 0 ) {
        currentB = currentB->next;
        --i;
      }
    }
    while ( currentA != NULL && currentB != NULL ) {
      if( currentA == currentB ) {
        return currentA;
      }
      currentA = currentA->next;
      currentB = currentB->next;
    }
    return NULL;
  }
};
