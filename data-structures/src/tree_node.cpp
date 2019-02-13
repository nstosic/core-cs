#include "tree_node.h"

template <typename T>
TreeNode<T>::TreeNode(T data, unsigned int number_of_children) {
    this->data_ = data;
    this->maximum_number_of_children = number_of_children;
    this->children_ = std::vector<TreeNode<T>*>(number_of_children);
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
unsigned int TreeNode<T>::GetNumberOfChildren() const {
    return (unsigned int)this->children_.size();
}

template <typename T>
unsigned int TreeNode<T>::GetMaximumNumberOfChildren() const {
    return maximum_number_of_children;
}

template <typename T>
const std::vector<TreeNode<T>*> TreeNode<T>::GetChildren() const {
    return this->children_;
}

template <typename T>
bool TreeNode<T>::AddChild(TreeNode<T>* child) {
    if (this->children_.size() < maximum_number_of_children) {
        this->children_.push_back(child);
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::AddChild(TreeNode<T>* child, unsigned int index) {
    if (index < maximum_number_of_children) {
        this->children_[index] = child;
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::RemoveChild(unsigned int index) {
    if (index < this->children_.size() && this->children_[index] != nullptr) {
        this->children_[index] = nullptr;
        return true;
    }
    return false;
}

template class TreeNode<int>; // forward resolution for template type used in unit tests