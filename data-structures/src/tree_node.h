#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <vector>

template <typename T>
class TreeNode {
private:
    T data_;
    unsigned int maximum_number_of_children;
    std::vector<TreeNode<T>*> children_;
public:
    TreeNode<T>(T data, unsigned int number_of_children);
    ~TreeNode<T>();
    const T& GetData() const;
    void SetData(T data);
    unsigned int GetNumberOfChildren() const;
    unsigned int GetMaximumNumberOfChildren() const;
    const std::vector<TreeNode<T>*> GetChildren() const;
    bool AddChild(TreeNode<T>* node);
    bool AddChild(TreeNode<T>* node, unsigned int index);
    bool RemoveChild(unsigned int index);
};

#endif