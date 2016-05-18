#include<iostream>

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(): val(0), next(NULL) {}
  ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
  ListNode *insertionSortList(ListNode *head){
    ListNode *dummy = new ListNode(0);

    while (head != NULL) {
      ListNode *temp = dummy;
      ListNode *next = head->next;
      while (temp->next != NULL && temp->next->val < head->val) {
        temp = temp->next;
      }
      head->next = temp->next;
      temp->next = head;
      head = next;
    }
    return dummy->next;
  }
  void showList(ListNode *head){
    while(head != NULL){
	  cout << head->val << " ";
	  head = head->next;
	}
	cout << endl;
  }
};

int main(){
  Solution s;
  const size_t size = 10;
  ListNode list[size];
  for(int i = 0; i != size - 1; ++i){
    list[i].val = size - i;
	list[i].next = &list[i+1];
  } 
  list[size-1].val = 1;
  list[size-1].next = NULL;
  ListNode *head = s.insertionSortList(list);
  s.showList(head);
}
