#include "tree_node.h"

template <typename T>
TreeNode<T>::TreeNode(T data, unsigned int number_of_children) {
    this->data_ = data;
    this->maximum_number_of_children_ = number_of_children;
    this->children_ = new TreeNode<T>*[this->maximum_number_of_children_];
    std::fill_n(this->children_, this->maximum_number_of_children_, nullptr);
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
    unsigned int size = 0;
    unsigned int index = 0;
    while (index < this->maximum_number_of_children_) {
        if (this->children_[index] != nullptr) {
            size++;
        }
        index++;
    }
    return size;
}

template <typename T>
unsigned int TreeNode<T>::GetMaximumNumberOfChildren() const {
    return this->maximum_number_of_children_;
}

template <typename T>
TreeNode<T>** TreeNode<T>::GetChildren() const {
    return this->children_;
}

template <typename T>
bool TreeNode<T>::AddChild(TreeNode<T>* child) {
    if (this->GetNumberOfChildren() < this->maximum_number_of_children_) {
        this->children_[this->GetNumberOfChildren()] = child;
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::AddChild(TreeNode<T>* child, unsigned int index) {
    if (this->GetNumberOfChildren() < this->maximum_number_of_children_ && index < this->maximum_number_of_children_) {
        this->children_[index] = child;
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::RemoveChild(unsigned int index) {
    if (index < this->GetNumberOfChildren() && this->children_[index] != nullptr) {
        this->children_[index] = nullptr;
        return true;
    }
    return false;
}

template class TreeNode<int>; // forward resolution for template type used in unit tests