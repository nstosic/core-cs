#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T> *next;
public:
    Node(T t);
    ~Node();
    void setData(T t);
    T getData() const;
    void setNext(Node<T>* node);
    void setNext(T t);
    Node<T>* getNext() const;
};

#endif