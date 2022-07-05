#ifndef SINGLY_LINKED_LIST_LIST_H
#define SINGLY_LINKED_LIST_LIST_H
#include <iostream>

class Node {
private:
    int data;
    Node* next;
public:
    int getData(){return this->data;}
    Node* getNext(){return this->next;}
    void setNext(Node* m_next){this->next = m_next;}
    Node(int value);
};

class List{
private:
    Node* head;
public:
    void printList(List* list);
    List():head(NULL){}
    void insertHead(List* list, int value);
    void insertTail(List* list, int key, int value);
    void insertAfter(List* list,int key, int value);
    void deleteNode(List* list, int value);
    void deleteNodeRecursive(Node* head, int value);
};
#endif //SINGLY_LINKED_LIST_LIST_H
