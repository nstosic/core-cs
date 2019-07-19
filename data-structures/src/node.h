#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data_;
    Node<T> *next_;
public:
    Node(T t);
    void SetData(T t);
    T GetData() const;
    void SetNext(Node<T>* node);
    void SetNext(T t);
    Node<T>* GetNext() const;
};

template <typename T>
bool operator==(const Node<T>& lhs, const Node<T>& rhs);
template <typename T>
bool operator!=(const Node<T>& lhs, const Node<T>& rhs);

#endif