#include "binary_search_tree.h"

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
    while (!temp->GetChildren().empty()) {
        if (temp->GetData() < data) {
            if (temp->GetChildren()[1] == nullptr) {
                temp->AddChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 1);
                return true;
            } else {
                temp = temp->GetChildren()[1];
            }
        } else if (temp->GetData() > data) {
            if (temp->GetChildren()[0] == nullptr) {
                temp->AddChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 0);
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
        temp->AddChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 1);
        return true;
    } else if (temp->GetData() > data) {
        temp->AddChild(new TreeNode<T>(data, BST_NUMBER_OF_CHILDREN), 0);
        return true;
    } else {
        // If temp->GetData() == data
        return false;
    }
}

template <typename T>
bool BinarySearchTree<T>::Remove(T data) {
    TreeNode<T>* parent = nullptr;
    TreeNode<T>* temp = this->root_;
    int index = -1;
    if (temp == nullptr) {
        return false;
    }
    while (!temp->GetChildren().empty()) {
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
                temp = temp->GetChildren()[index];
            }
        }
    }
    if (temp->GetData() == data) {
        deleteInPlace(temp, parent, index);
        return true;
    }
    return false;
}

template <typename T>
inline void deleteInPlace(TreeNode<T>* node_to_delete, TreeNode<T>* parent, int child_index) {
    TreeNode<T>* replacement = nullptr;
    TreeNode<T>* replacement_parent = nullptr;
    if (parent == nullptr) {
        // node_to_delete is the root of the tree
        replacement_parent = node_to_delete;
        replacement = node_to_delete->GetChildren()[0];
        if (replacement != nullptr) {
            while (replacement->GetChildren()[1] != nullptr) {
                replacement_parent = replacement;
                replacement = replacement->GetChildren()[1];
            }
            replacement_parent->AddChild(replacement->GetChildren()[0], 1);
            node_to_delete->SetData(replacement->GetData());
            delete replacement;
        } else {
            replacement = node_to_delete->GetChildren()[1];
            if (replacement != nullptr) {
                while (replacement->GetChildren()[0] != nullptr) {
                    replacement_parent = replacement;
                    replacement = replacement->GetChildren()[0];
                }
                replacement_parent->AddChild(replacement->GetChildren()[1], 0);
                node_to_delete->SetData(replacement->GetData());
                delete replacement;
            }
        }
    } else if (child_index == 0) {
        // Look for the greatest value in node_to_delete subtree
        replacement_parent = parent;
        replacement = node_to_delete;
        while (replacement->GetChildren()[1] != nullptr) {
            replacement_parent = replacement;
            replacement = replacement->GetChildren()[1];
        }
        replacement_parent->AddChild(replacement->GetChildren()[0], 1);
        node_to_delete->SetData(replacement->GetData());
        delete replacement;
    } else {
        // Look for the smallest value in node_to_delete subtree
        replacement_parent = parent;
        replacement = node_to_delete;
        while (replacement->GetChildren()[0] != nullptr) {
            replacement_parent = replacement;
            replacement = replacement->GetChildren()[0];
        }
        replacement_parent->AddChild(replacement->GetChildren()[1], 0);
        node_to_delete->SetData(replacement->GetData());
        delete replacement;
    }
}

template class BinarySearchTree<int>; // forward resolution for template type used in unit tests