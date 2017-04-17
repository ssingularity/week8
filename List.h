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

int List::remove(int value) {