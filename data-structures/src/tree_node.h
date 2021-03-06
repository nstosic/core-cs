#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <vector>

template <typename T>
class TreeNode {
private:
    T data_;
    unsigned int maximum_number_of_children_;
    TreeNode<T>** children_;
public:
    TreeNode<T>(T data, unsigned int number_of_children);
    ~TreeNode<T>() = default;
    const T& GetData() const;
    void SetData(T data);
    unsigned int GetNumberOfChildren() const;
    unsigned int GetMaximumNumberOfChildren() const;
    TreeNode<T>** GetChildren() const;
    bool AddChild(TreeNode<T>* node);
    bool SetChild(TreeNode<T>* node, unsigned int index);
    bool RemoveChild(unsigned int index);
};

#endif