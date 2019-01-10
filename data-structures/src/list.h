#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename T>
class List {
private:
    Node<T>* head;
public:
    List();
    ~List();
    Node<T>* getHead() const;
    void add(Node<T>* node);
    void add(T node);
    bool isEmpty() const;
    int size() const;
};

#endif