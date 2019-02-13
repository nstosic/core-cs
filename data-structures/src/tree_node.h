#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <vector>

template <typename T>
class TreeNode {
private:
    T data_;
    std::vector<TreeNode<T>*> children_;
public:
    TreeNode<T>(T data, int number_of_children);
    ~TreeNode<T>();
    const T& GetData() const;
    void SetData(T data);
    int GetNumberOfChildren() const;
    int GetMaximumNumberOfChildren() const;
    const std::vector<TreeNode<T>*> GetChildren() const;
    bool AddChild(TreeNode<T> node);
    bool AddChild(TreeNode<T> node, int index);
    bool RemoveChild(int index);
};

#endif