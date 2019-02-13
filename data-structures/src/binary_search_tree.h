#ifndef BST_H
#define BST_H

#include "abstract_tree.h"

#define BST_NUMBER_OF_CHILDREN 2

template <typename T>
class BinarySearchTree : public AbstractTree {
public:
    TreeNode<T>* Search(T data) const;
    bool Insert(T data);
    bool Remove(T data);
};

#endif