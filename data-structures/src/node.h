#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T> *next;
public:
    Node(T data);
    ~Node();
    void setData(T data);
    void setNext(Node<T>* next);
    void setNext(T data);
};

#endif