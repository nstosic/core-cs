#include "abstract_tree.h"

template <typename T>
TreeNode<T>* AbstractTree<T>::GetRoot() const {
    return this->root_;
}