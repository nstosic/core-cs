#ifndef DOUBLE_LINKED_NODE_H
#define DOUBLE_LINKED_NODE_H

template <typename T>
class DoubleLinkedNode {
private:
    T data_;
    DoubleLinkedNode<T>* next_;
    DoubleLinkedNode<T>* prev_;
public:
    DoubleLinkedNode(T data);
    DoubleLinkedNode(T data, DoubleLinkedNode<T>* next, DoubleLinkedNode<T>* prev);
    ~DoubleLinkedNode() = default;
    void setData(T data);
    T getData() const;
    void setNext(DoubleLinkedNode<T>* next);
    DoubleLinkedNode<T>* getNext() const;
    void setPrev(DoubleLinkedNode<T>* prev);
    DoubleLinkedNode<T>* getPrev() const;
};

#endif