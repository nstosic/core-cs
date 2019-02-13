#include "tree_node.h"

template <typename T>
TreeNode<T>::TreeNode(T data, int number_of_children) {
    this->data_ = data;
    this->children_ = std::vector(number_of_children);
}

template <typename T>
TreeNode<T>::~TreeNode() {}

template <typename T>
const T& TreeNode<T>::GetData() const {
    return this->data_;
}

template <typename T>
void TreeNode<T>::SetData(T data) {
    this->data_ = data;
}

template <typename T>
int TreeNode<T>::GetNumberOfChildren() const {
    return children_.size();
}

template <typename T>
int TreeNode<T>::GetMaximumNumberOfChildren() const {
    return this->children_.capacity();
}

template <typename T>
const std::vector<TreeNode<T>> TreeNode<T>::GetChildren() const {
    return this->children_;
}

template <typename T>
bool TreeNode<T>::AddChild(TreeNode<T> child) {
    if (this->children_.size() < this->children_.capacity()) {
        this->children_.push_back(child);
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::AddChild(TreeNode<T> child, int index) {
    if (this->children_.size() < this->children_.capacity() && index < this->children_.capacity()) {
        this->children_.insert(index, child);
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::RemoveChild(int index) {
    if (index < this.children_.size() && this.children_[index] != nullptr) {
        this->children[i] = nullptr;
        return true;
    }
    return false;
}