/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

/* 解题思路：

二叉搜索树关键的性质是根节点的值大于左子树所有节点的值，小于右子树所有节点的值，且左子树和右子树也同样为二叉搜索树。因此在生成所有可行的二叉搜索树的时候，假设当前序列长度为 nn，如果我们枚举根节点的值为 ii，那么根据二叉搜索树的性质我们可以知道左子树的节点值的集合为 [1 \ldots i-1][1…i−1]，右子树的节点值的集合为 [i+1 \ldots n][i+1…n]。而左子树和右子树的生成相较于原问题是一个序列长度缩小的子问题，因此我们可以想到用递归的方法来解决这道题目。

我们定义 generateTrees(start, end) 函数表示当前值的集合为 [\textit{start},\textit{end}][start,end]，返回序列 [\textit{start},\textit{end}][start,end] 生成的所有可行的二叉搜索树。按照上文的思路，我们考虑枚举 [\textit{start},\textit{end}][start,end] 中的值 ii 为当前二叉搜索树的根，那么序列划分为了 [\textit{start},i-1][start,i−1] 和 [i+1,\textit{end}][i+1,end] 两部分。我们递归调用这两部分，即 generateTrees(start, i - 1) 和 generateTrees(i + 1, end)，获得所有可行的左子树和可行的右子树，那么最后一步我们只要从可行左子树集合中选一棵，再从可行右子树集合中选一棵拼接到根节点上，并将生成的二叉搜索树放入答案数组即可。

递归的入口即为 generateTrees(1, n)，出口为当 \textit{start}>\textit{end}start>end 的时候，当前二叉搜索树为空，返回空节点即可。

*/


// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return { nullptr };
        }
        vector<TreeNode*> allTrees;
        // 枚举可行根节点
        for (int i = start; i <= end; i++) {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto& left : leftTrees) {
                for (auto& right : rightTrees) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }
};
// @lc code=end

