#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *ptr1 = head, *ptr2 = head;
	int ptr1sz = 1;
	int ptr2sz = 1;
	while(true){
		if(ptr2 == nullptr){
			ptr2sz--;
			break;
		}
		if(ptr2->next == nullptr){
			break;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		ptr1sz++;
		ptr2sz += 2;
	}
	
	if(ptr2sz == 1)
		return nullptr;
	
	int del_loc = ptr2sz - n + 1;
	ListNode *curr = nullptr;
	int start, stop = del_loc - 1;
	if(del_loc > ptr1sz){
		start = ptr1sz;
		curr = ptr1;
	} else {
		start = 1;
		curr = head;
	}
	for(int i = start; i < stop; i++)
		curr = curr->next;
	if(curr == head && del_loc == 1)
		head = curr->next;
	else
		curr -> next = curr -> next -> next;
	return head;
}

int main() {
	// Make linked list and run the above function
	return 0;
}