#include "List.h"
Node::Node(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
}
void List::printList(List* list)
{
    Node* node = list->head;
    while(node != NULL)
    {
        std::cout<<"("<<node->getData()<<") -> ";
        node = node->getNext();
    }
    std::cout<<"NULL"<<std::endl;
}
void List::insertHead(List* list, int value)
{
    Node* new_node = new Node(value);
    Node* head = list->head;
    new_node->setNext(head);
    head = new_node;
}
void List::insertAfter(List* list,int key, int value)
{
    Node* new_node = new Node(value);
    Node* node = list->head;
    if(key == node->getData())
    {
        new_node->setNext(node->getNext());
        node->setNext(new_node);
        return;
    }
    while (node->getData() != key)
    {
        node = node->getNext();
        if(node == NULL)
            return;
    }
    new_node->setNext(node->getNext());
    node->setNext(new_node);
}
void List::insertTail(List* list, int key, int value)
{
    Node* new_node = new Node(value);
    Node* node = list->head;
    if(node == NULL)
    {
        node = new_node;
        return;
    }
    while(node->getNext() != NULL)
    {
        node = node->getNext();
    }
    node->setNext(new_node);
}
void List::deleteNode(List* list, int value)
{
    Node* node = list->head;
    Node* prev = NULL;
    if(node != NULL && node->getData() == value)
    {
        list->head = node->getNext();
        delete node;
        return;
    }
    else
    {
        while(node!=NULL && node->getData() != value)
        {
            prev = node;
            node = node->getNext();
        }
        if(node == NULL)
            return;
        prev->setNext(node->getNext());
        delete node;
    }
}
void List::deleteNodeRecursive(Node* head, int value)
{
    Node* node = head;
    if(head == NULL)
    {
        std::cout << "Element not present in the list\n";
        return;
    }
    if(head->getData() == value)
    {
        Node* tmp = head;
        head = head->getNext();
        delete tmp;
        return;
    }
    deleteNodeRecursive(head->getNext(),value);
}