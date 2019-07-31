#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <stdio.h>
#include <iostream>
#include <QFileDialog>

using namespace std;
struct Node{
    QString Data;
    Node *Next;
    Node *Prev;
};

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    Node *Insert(Node *pred, QString Data);
    void Delete(Node *p);
    Node *Search(QString Key);
    void Edit(Node *p,QString NewData);
    Node *First;

};

#endif // DOUBLYLINKEDLIST_H
