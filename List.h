#pragma once

#include<vector>
#include<iostream>

using namespace std;
struct Node {
	int value;
	Node* next;
	Node(int v) : value(v), next(0) {}
};

class List {
private:
	int size;
	Node* head;
public:
	~List();
	List(const vector<int>& v);
	List(int* array, int array_size);
	int length() const { return size; };
	bool insert(int pos, int value);
	int find(int value);
	int remove(int value);
	bool split(int pos, List& new_list);
	void combine(List& append_list);
	void printAll();
};

List::~List() {
	Node* ptr1;
	Node* ptr2 = head;
	for (int i=0; i <size; ++i) {
		ptr1 = ptr2;
		ptr2 = ptr2->next;
		delete ptr1;
	}
}

List::List(const vector<int>& v) {
	size = v.size();
	head = new Node(v[0]);
	if (size == 1) return;
	Node* ptr = new Node(v[1]);
	head->next = ptr;
	for (int i = 2; i < size; ++i) {
		ptr->next = new Node(v[i]);
		ptr = ptr->next;
	}
}

List::List(int* array, int array_size) {
	size = array_size;
	head = new Node(array[0]);

	if (size == 1) return;
	Node* ptr = new Node(array[1]);
	head->next = ptr;
	for (int i = 2; i < size; ++i) {
		ptr->next = new Node(array[i]);
		ptr = ptr->next;
	}
}

bool List::insert(int pos, int value) {
	if (0 <= pos <= size) {
		Node* ptr = new Node(0);
		Node* sub_ptr = head;
		for (int i = 0; i < pos; ++i) {
			sub_ptr = sub_ptr->next;
		}
		ptr->value = sub_ptr->value;
		ptr->next = sub_ptr->next;
		sub_ptr->value = value;
		sub_ptr->next = ptr;
		++size;
		return true;
	}
	else return false;

}

int List::find(int value) {
	Node* ptr = head;
	for (int i = 0; i < size; ++i) {
		if (ptr->value == value) return i;
		ptr = ptr->next;
	}
	return -1;
}

int List::remove(int value) {	int cnt = 0;	Node* ptr1 = head->next;	Node* ptr2 = head;	for (int i = 1; i < size; ++i) {		if (ptr1->value == value) {			ptr2->next = ptr1->next;			Node* sub_ptr = ptr1;			ptr1 = ptr1->next;			delete sub_ptr;			++cnt;		}		else {			ptr1 = ptr1->next;			ptr2 = ptr2->next;		}	}	if (head->value == value) {		head->value = (head->next)->value;		head->next = (head->next)->next;		delete head->next;		++cnt;	}	size -= cnt;	return cnt;}bool List::split(int pos, List& new_list) {	if (0 <= pos < size) {		Node* ptr = head;		while (pos--) ptr = ptr->next;		Node* ptr1 = ptr;		vector<int> ivec;		for (int i = pos+1; i < size; ++i) {			ivec.push_back(ptr1->value);			ptr1->next;		}		ptr->next = 0;		size = pos + 1;		new_list = List(ivec);		return true;	}	else return false;}void List::combine(List& append_list) {	Node* ptr = head;	while (size--) ptr = ptr->next;	ptr->next = append_list.head;	size += append_list.size;}void List::printAll() {	Node* ptr = head;	for (int i = 0; i < size;++i) {		cout << ptr->value << " ";		ptr=ptr->next;	}	cout << endl;}