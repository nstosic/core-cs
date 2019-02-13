#include "abstract_tree.h"

template <typename T>
AbstractTree<T>::AbstractTree() : AbstractTree<T>(nullptr) {}

template <typename T>
AbstractTree<T>::AbstractTree(TreeNode<T>* root) {
    this->root_ = root;
}

template <typename T>
TreeNode<T>* AbstractTree<T>::GetRoot() const {
    return this->root_;
}

template class AbstractTree<int>; // forward resolution for template type used in unit tests