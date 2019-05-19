#include "amagna2Proj6.h"

MyList::MyList() {
	head = NULL;
}

void MyList::show() {
	MyNode* temp = head;
	if (temp == NULL) {
		cout << "No bridge to any other island";
	}

	while (temp != NULL) {
		cout << temp->getNextToIsland();
		if (temp->getNext() != NULL) {
			cout << "-->";
		}
		temp = temp->getNext();
	}

	cout << endl;
}

void MyList::insert(int x) {
	MyNode* temp = new MyNode(x);

	//insert at the beginning
	temp->setNext(head);;
	head = temp;
}

void MyList::remove(int x) {
	MyNode* current = head;
	MyNode* previous = NULL;

	while ((current != NULL) && (current->getNextToIsland() != x)) {
		previous = current;
		current = current->getNext();
	}

	if (current == NULL) {
		return; //target value is not in the list
	}

	if (previous == NULL) { //target value is first one in the list
		head = current->getNext();
		delete current;
	}
	else {
		previous->setNext(current->getNext());
		delete current;
	}
}

void MyList::insertFile(char* file) {
	MyNode* temp = new MyNode(file);

	temp->setNext(head);
	head = temp;
}

void MyList::removeFile(char* File) {
	MyNode* temp = head;

	if (temp->getFile() == File) {
		head = head->getNext();
		delete temp;
		return;
	}

	while (temp->getNext() != NULL) {
		if (temp->getNext()->getFile() == File) {
			MyNode* node = temp->getNext();
			temp->setNext(node->getNext());
			delete node;
			return;
		}
		temp = temp->getNext();
	}
}

bool MyList::containsFile(char* File) {
	MyNode* temp = this->head;
	while (temp != NULL) {
		if (strcmp(temp->getFile(), File) == 0) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

void MyList::removeAllFile() {
	MyNode* temp = head;

	while (temp != NULL) {
		MyNode* temp2 = temp;
		temp = temp->getNext();
		delete temp2;
	}
	head = NULL;
}

void MyList::removeAll() {
	MyNode* temp = head;

	while (temp != NULL) {
		MyNode* temp2 = temp;
		temp = temp->getNext();
		delete temp2;
	}
	head = NULL;
}

bool MyList::contains(int x) {
	MyNode* temp = head;
	while (temp != NULL) {
		if (temp->getNextToIsland() == x) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

void MyList::setVisited(bool x) {
	visited = x;
}

bool MyList::getVisited() {
	return visited;
}

void MyList::setEmpty() {
	head = NULL;
}

MyList::~MyList() {
	removeAll();
	removeAllFile();
}

MyNode::MyNode(int x) {
	nextToIsland= x;
	next = NULL;
}

MyNode::MyNode(char* file) {
	filename = file;
	next = NULL;
}

MyNode::MyNode(int x, MyNode* n) {
	nextToIsland= x;
	next = n;
}

void MyNode::setNextToIsland(int x) {
	nextToIsland= x;
}

int MyNode::getNextToIsland() {
	return nextToIsland;
}

void MyNode::setFile(char* file)
{
	filename = file;
}

char* MyNode::getFile()
{
	return filename;
}

void MyNode::setNext(MyNode* n)
{
	next = n;
}

MyNode* MyNode::getNext() {
	return next;
}

MyNode* MyNode::pushNode(MyNode* head, int x) {
	MyNode* temp = new MyNode(x);

	if (head == NULL) {
		head = temp;
	}
	else {
		MyNode* temp2 = head;
		while (temp2->getNext() != NULL) {
			temp2 = temp2->getNext();
		}
		temp2->setNext(temp);
	}
	return head;
}

MyNode* MyList::top() {
	if (head == NULL) {
		return NULL;
	}
	return head;
}