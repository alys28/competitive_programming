#include <bits/stdc++.h>
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
    
        TreeNode* getRightMostNode(TreeNode* root){
            TreeNode* curr = root;
            TreeNode* parent = root;
            while (curr->right != nullptr){
                parent = curr;
                curr = curr->right;
            }
            if (curr->val == root->val){
                return curr;
            } else {
                parent->right = curr->left;
                curr->left = nullptr;
                return curr;
            }
    
        }
        TreeNode* helper1(TreeNode *root, int key){
            if (root == nullptr){
                return nullptr;
            }
            else if (root->val != key){
                root->left = helper1(root->left, key);
                root->right = helper1(root->right, key);
                return root;
            } else {
                // root needs to be deleted
                if (root->left == nullptr){
                    return root->right;
                } else {
                    TreeNode* newRoot = getRightMostNode(root->left);
                    newRoot->right = root->right;
                    if (newRoot->val != root->left->val){
                        newRoot->left = root->left;
                    }
                    delete root;
                    return newRoot;
                }
            }
        }
        TreeNode* deleteNode(TreeNode* root, int key) {
            return helper1(root, key);
        }
    };