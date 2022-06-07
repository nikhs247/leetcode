#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	// Time: O(m + n), m + n number of elements
	// Space: O(1)
	ListNode *p1 = nullptr, *c1 = list1, *p2 = nullptr, *c2 = list2;
	
	while(c1 && c2){
		if(c1->val < c2->val){
			p1 = c1;
			c1 = c1->next;
		} else {
			ListNode* next_c2 = c2->next;
			if(p1 == nullptr){
				c2->next = c1;
				p1 = c2;
				list1 = p1;
				c2 = next_c2;
				p2 = nullptr;
			} else{
				if(p2 != nullptr){
					p2->next = c2->next;   
				}
				p1->next = c2;
				c2->next = c1;
				p1 = c2;
				c2 = next_c2;
			}
		}
	}
	if(c2 != nullptr){
		if(p1 != nullptr)
			p1->next = c2;
		else
			list1 = list2;
	}
	return list1;
}

int main() {
	// Create linked list using ListNode and run
	// [1,2,4]
	// [1,3,4]

	// []
	// []

	// []
	// [0]
	return 0;
}