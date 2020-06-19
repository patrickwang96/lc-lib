# Tree 总结

## 树的遍历

如果要遍历一颗树，最常见的算法是DFS和BFS。BFS很明显，是从上向下每一层遍历。

DFS的话根据左子节点，右子节点，自己的不同顺序分出来三种不同的遍历方式。分别为：**先序遍历**，**中序遍历**和**后序遍历**。英文名称为**preorder traversal**, **inorder traversal** and **postorder traversal**。

### 先/中/后序遍历

先序遍历的顺序为： 中，左，右。
中序遍历的顺序为： 左，中，右。
后序遍历的顺序为： 左，右，中。

递归遍历的代码模版：

```cpp
void preOrder(TreeNode *root) 
{
    if (root != NULL) {
        cout << root->val << "\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}
```

树的DFS遍历相关的题有：
- [94 Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal)
- [98 Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
- [100 Same Tree](https://leetcode.com/problems/same-tree/)
- [101 Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
- [105 Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)
- [106 Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal)
- [108 Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [110 Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
- [144 Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
- [145 Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal)


### BFS 遍历Tree

通过BFS得到树深度的模版代码：

```cpp
int check_depth(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    int counter = 0;
    q.push(root);
        
    while (!q.empty()) {
        int n = q.size();
        counter ++;
        for (int i = 0; i < n; i++) {
            auto node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    
    }   
    return counter;
}
```


- [102 Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal)
- [103 Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal)
- [104 Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree)
- [107 Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii)
- [199 Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view)
- [111 Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)