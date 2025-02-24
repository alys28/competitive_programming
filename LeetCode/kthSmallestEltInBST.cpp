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
        int val = -1;
        void helper(TreeNode* root, int k, int &idx){
            if (root == nullptr){
                return;
            } else {
                helper(root->left,k, idx);
                // cout << root << " " << idx << " " << endl;
                ++idx;
                if (idx == k){
                    val = root->val;
                } else if (idx < k){
                    helper(root->right, k, idx);
                }
            }
        }
        int kthSmallest(TreeNode* root, int k) {
            int idx = 0;
            helper(root, k, idx);
            return val;
        }
    };