#ifndef TREE_H
#define TREE_H
#include "tree_node.h"

template <typename T>
class AbstractTree {
protected:
    TreeNode<T>* root_;
public:
    AbstractTree();
    AbstractTree(TreeNode<T>* root);
    ~AbstractTree() = default;
    virtual TreeNode<T>* Search(T data) const = 0;
    virtual bool Insert(T data) = 0;
    virtual bool Remove(T data) = 0;
    TreeNode<T>* GetRoot() const;
};

#endif