#ifndef LIST_H
#define LIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "node.h"

using namespace std;
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        void insert(int);
        void remove(int);
        void print();
        friend ostream& operator << (ostream &, const LinkedList &);
    private:
        Node *m_head;
        int size;
};



LinkedList::LinkedList()
{
    size = 0;
    m_head = NULL;
}

void LinkedList::insert(int _element)
{
    Node *new_node = new Node (_element);
    Node *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } 
    else {
        if (m_head->getElement() > _element) {
            new_node->setNext(m_head);
            m_head = new_node;
        } else {
            while ((temp->getNext() != NULL) && (temp->getNext()->getElement() < _element)) {
                temp = temp->getNext();
            }
            new_node->setNext(temp->getNext());
            temp->setNext(new_node) ;
        }
    }
    size++;
}

void LinkedList::remove(int pos)
{
    Node *temp = m_head;
    Node *temp1 = temp->getNext();
 
    if (pos < 0 || pos > size) {
        cout << "Fuera de rango " << endl;
    } 
    else if (pos == 0) {
        m_head = temp->getNext();
    } 
    else {
        for (int i = 1; i <= pos; i++) {
            if (i == pos) {
                Node *aux_node = temp1;
                temp->setNext(temp1->getNext());
                delete aux_node;
                size--;
            }
            temp = temp->getNext();
            temp1 = temp1->getNext();
        }
    }
}
 

void LinkedList::print()
{
    Node *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } 
    else {
        while (temp) {
            temp->print();
            temp = temp->getNext();
        }
    }
    cout << endl;
}

LinkedList::~LinkedList() {}

ostream& operator << (ostream &out, const LinkedList &p){
    Node *a = p.m_head;
    out<<"[";
    out<<a->getElement()<<" ";
    for(int i=0;i<p.size-1;i++){
        a = a->getNext();
        out<< a->getElement() << " ";
    }
    out<<"]";
    out<<endl;
    return out;
}

#endif // LIST_H