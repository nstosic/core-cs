#include "binary_search_tree.h"
#include <assert.h>

template <typename T>
TreeNode<T>* BinarySearchTree<T>::Search(T data) const {
    TreeNode<T>* temp = this->root_;
    while (temp != nullptr && temp->GetData() != data) {
        if (temp->GetData() > data) {
            temp = temp->GetChildren()[0];
        } else {
            temp = temp->GetChildren()[1];
        }
    }
    return temp;
}

template <typename T>
bool BinarySearchTree<T>::Insert(T data) {
    TreeNode<T>* temp = this->root_;
    if (temp == nullptr) {
        this->root_ = new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN);
        return true;
    }
    while (temp->GetNumberOfChildren() != 0) {
        if (temp->GetData() < data) {
            if (temp->GetChildren()[1] == nullptr) {
                temp->SetChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 1);
                return true;
            } else {
                temp = temp->GetChildren()[1];
            }
        } else if (temp->GetData() > data) {
            if (temp->GetChildren()[0] == nullptr) {
                temp->SetChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 0);
                return true;
            } else {
                temp = temp->GetChildren()[0];
            }
        } else {
            // If temp->GetData() == data
            return false;
        }
    }
    if (temp->GetData() < data) {
        temp->SetChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 1);
        return true;
    } else if (temp->GetData() > data) {
        temp->SetChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 0);
        return true;
    } else {
        // If temp->GetData() == data
        return false;
    }
}

template <typename T>
bool BinarySearchTree<T>::Remove(T data) {
    if (this->root_ == nullptr) {
        return false;
    }
    if (this->root_->GetData() == data && this->root_->GetNumberOfChildren() == 0) {
        delete this->root_;
        this->root_ = nullptr;
        return true;
    }
    TreeNode<T>* parent = nullptr;
    TreeNode<T>* temp = this->root_;
    unsigned int index = 2;
    while (temp->GetNumberOfChildren() != 0) {
        if (temp->GetData() == data) {
            break;
        } else {
            if (temp->GetData() < data) {
                index = 1;
            } else {
                index = 0;
            }
            if (temp->GetChildren()[index] == nullptr) {
                return false;
            } else {
                parent = temp;
                temp = temp->GetChildren()[index];
            }
        }
    }
    if (temp->GetData() == data) {
        internalDelete(temp, parent, index);
        return true;
    }
    return false;
}

template <typename T>
inline void internalDelete(TreeNode<T>* node_to_delete, TreeNode<T>* parent, unsigned int child_index) {
    if (node_to_delete->GetNumberOfChildren() == 0) {
        // Case #1: Node that needs to be deleted has no children
        parent->SetChild(nullptr, child_index);
        delete node_to_delete;
    } else if (node_to_delete->GetNumberOfChildren() == 1) {
        // Case #2: Node that needs to be deleted has one child
        if (parent == nullptr) {
            // Node being deleted is the root of the tree
            parent = node_to_delete;
            if (node_to_delete->GetChildren()[0] != nullptr) {
                node_to_delete = node_to_delete->GetChildren()[0];
            } else {
                node_to_delete = node_to_delete->GetChildren()[1];
            }
            parent->SetData(node_to_delete->GetData());
            parent->SetChild(node_to_delete->GetChildren()[0], 0);
            parent->SetChild(node_to_delete->GetChildren()[1], 1);
            delete node_to_delete;
        } else {
            if (node_to_delete->GetChildren()[0] != nullptr) {
                parent->SetChild(node_to_delete->GetChildren()[0], child_index);
            } else {
                parent->SetChild(node_to_delete->GetChildren()[1], child_index);
            }
            delete node_to_delete;
        }
    } else {
        // Case #3: Node that needs to be deleted has both children
        TreeNode<T>* inorder_successor = node_to_delete->GetChildren()[1];
        TreeNode<T>* inorder_successor_parent = node_to_delete;
        unsigned int parent_index = 1;
        while (inorder_successor->GetChildren()[0] != nullptr) {
            inorder_successor_parent = inorder_successor;
            inorder_successor = inorder_successor->GetChildren()[0];
            parent_index = 0;
        }
        inorder_successor_parent->SetChild(inorder_successor->GetChildren()[1], parent_index);
        if (parent != nullptr) {
            parent->SetChild(inorder_successor, child_index);
            inorder_successor->SetChild(node_to_delete->GetChildren()[0], 0);
            inorder_successor->SetChild(node_to_delete->GetChildren()[1], 1);
            delete node_to_delete;
        } else {
            node_to_delete->SetData(inorder_successor->GetData());
            delete inorder_successor;
        }
    }
}

template class BinarySearchTree<int>; // forward resolution for template type used in unit tests