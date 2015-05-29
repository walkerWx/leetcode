#include<iostream>

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(): val(0), next(NULL) {}
};

class Solution{
public:
  ListNode *insertionSortList(ListNode *head){
    ListNode *small;
	ListNode *large;
	ListNode *current = head->next;
	while(current != NULL){
	  if(current->val <= head->val){
	    head->next = current->next;
		current->next = head;
		ListNode *tmp = head;
		head = current;
		current = tmp->next;
		continue;
	  } 
	  else{
	    small = head;
	    large = head->next;
	    while(large != current){
		  if(small->val <= current->val && large->val >= current->val){
		    ListNode *tmp = current;
			current = current->next;
			small->next = tmp;
			tmp->next = large;
			break;
		  }
		  small = small->next;
		  large = large->next;
	    }
		current = current->next;
	  }
	}
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
