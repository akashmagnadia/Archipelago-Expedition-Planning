#ifndef amagna2Proj6_h
#define amagna2Proj6_h

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

class MyNode
{
private:
	int nextToIsland;
	char* filename;
	MyNode* next;
	MyNode* num;

public:
	MyNode(int v1);
	MyNode(char* file);
	MyNode(int v1, MyNode* n);

	void setNextToIsland(int e);
	void setFile(char* file);
	char* getFile();
	int getNextToIsland();
	void setNext(MyNode* n);
	MyNode* pushNode(MyNode* head, int v1);
	MyNode* getNext();
	MyNode* insert();
};

class MyList
{
private:
	MyNode* head;
	bool visited;

public:
	MyList();
	~MyList();

	void show();
	void insert(int v1);
	void remove(int v1);
	void insertFile(char* file);
	void removeFile(char* file);
	bool containsFile(char* file);
	void removeAllFile();
	void removeAll();
	bool contains(int v2);
	void setVisited(bool TF);
	bool getVisited();
	void setEmpty();
	MyNode* top();
};

#endif