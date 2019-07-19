#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename T>
class List {
private:
    Node<T>* head_;
public:
    List();
    ~List();
    Node<T>* GetHead() const;
    void Add(Node<T>* node);
    void Add(T node);
    bool IsEmpty() const;
    int Size() const;
};

template <typename T>
bool operator==(const List<T>& lhs, const List<T>& rhs);

#endif