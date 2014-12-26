#include<iostream>
using namespace std;
struct ListNode{
	int data;
	ListNode *next;
	ListNode(){
		data = 0;
		next = NULL;
	}
	ListNode(int value){
		data = value;
		next = NULL;
	}
	// Adds node at the end
	ListNode(int value, ListNode *nextList){
		data = value;
		this->next = nextList;
	}
};

void printList(ListNode *list){
	for (ListNode *iter = list; iter != NULL; iter = iter->next){
		cout<<iter->data<<" ";
	}
}

// Recursive Reverse
// Given a head node of a list and reverses it recursively 
void reverse(ListNode **head){
	if(*head == NULL){
		return;
	}
	ListNode *first = *head;
	ListNode *rest = (*head)->next;
	if(rest == NULL){
		return;
	}
	// Recursively call reverse passing in rest as reference
	reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

void append(ListNode *head, ListNode *node){
	if(head == NULL){
		head = node;
	}
	ListNode *curr_node = head;
	while(curr_node->next != NULL){
		curr_node = curr_node->next;
	}
	curr_node->next = node;
}

void insertAfter(ListNode *nth_node, ListNode *node){
	if(nth_node == NULL){
		return;
	}
	node->next = nth_node->next;
	nth_node->next = node;
}

void deleteNthNode(ListNode **head, int n){
	if(*head == NULL){
		cout<<"list is empty";
		return;
	}
	ListNode *node;
	if(n == 1){
		node = *head;
		*head = (*head)->next;
		delete node;
	}
	else{
		int count = 1;
		ListNode *prev_node = NULL;
		node = *head;
		while(count < n){
			if(node == NULL){
				cout<<"n ("<<n<<") exceeds the size of list";
				return;
			}
			prev_node = node;
			node = node->next;
			count++;
		}
		prev_node->next = node->next;
		node->next = NULL;
		delete node;
	}
}

int length(ListNode *head){
	int size = 0;
	while(head != NULL){
		head = head->next;
		size++;
	}
	return size;
}

int getNthData(ListNode *head, int n){
	ListNode *curr_node = head;
	if (head == NULL){
		cout<<"List is Empty";
		return -1;
	}
	int count = 1;
	while(count<n){
		curr_node = curr_node->next;
		if(curr_node == NULL){
			cout<<"List size less than "<<n;
			return -1;
		}
		count++;
	}
	return curr_node->data;
}

int getMiddleElement(ListNode *head){
	if(head == NULL){
		cout<<"List is empty";
		return -1;
	}
	ListNode *fast_ptr = head;
	ListNode *slow_ptr = head;
	while(fast_ptr->next != NULL && fast_ptr->next->next != NULL){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}
	return slow_ptr->data;
}

void deleteList(ListNode **head){
	ListNode *curr_node = *head;
	ListNode *prev_node = NULL;
	while(curr_node != NULL){
		prev_node = curr_node;
		curr_node = curr_node->next;
		prev_node->next = NULL;
		delete(prev_node);
	}
	*head = NULL;
}

int count(ListNode *head, int element){
	int times = 0;
	ListNode *node = head;
	while(node != NULL){
		if(node->data == element){
			times++;
		}
		node = node->next;
	}
	return times;
}

// Driver Program for the above functions
int main(){
	ListNode *node, *node1;
	node = new ListNode(1);
	node1 = new ListNode(2, node);
	node = node1;
	node = new ListNode(3, node);
	insertAfter(node1, new ListNode(5));
	append(node, new ListNode(8));
	printList(node);
	reverse(&node);
	cout<<"\n";
	printList(node);
	deleteNthNode(&node, 3);
	printList(node);
	deleteNthNode(&node, 8);
	cout<<length(node)<<endl;
	cout<<getNthData(node,4)<<endl;
	cout<<"middle Element="<<getMiddleElement(node)<<endl;
	cout<<count(node,80);
	return 0;
}