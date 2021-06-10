#ifndef NODE_H
#define NODE_H
 
#include <iostream>
 
using namespace std;
 
class Node{
    public:
        Node();
        Node(int);
        ~Node();
        void delete_all();
        void print();
        void setNext(Node *);
        void setElement(int);
        Node* getNext()const;
        int getElement()const;
    private:
        Node *next;
        int element;
};

Node::Node(int _element)
{
    element = _element;
    next = NULL;
}

void Node::print()
{

    cout << element << "-> ";
}
void Node::setNext(Node *_next){
    next = _next;
}
void Node::setElement(int _element){
    element = _element;
}
Node* Node::getNext()const{
    return next;
}
int Node::getElement()const{
    return element;
}
Node::~Node() {}
 
#endif // NODE_H