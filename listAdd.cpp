#include<iostream>
using namespace std;
struct ListNode{
	int data;
	ListNode *next;
	ListNode(){
		data = 0;
		next = NULL;
	}
	ListNode(int val){
		data = val;
		next = NULL;
	}
	ListNode(int val, ListNode *nextNodes){
		data = val;
		next = nextNodes;
	}
};