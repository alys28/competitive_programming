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
        vector<TreeNode*> arr;
        void traverse(TreeNode* root){
            if (root != nullptr){
                traverse(root->left);
                arr.push_back(root);
                traverse(root->right);
            }
        }
        void recoverTree(TreeNode* root) {
            traverse(root);
            TreeNode *first = nullptr;
            TreeNode *middle = nullptr;
            TreeNode *second = nullptr;
            for (int i = 0; i < arr.size(); ++i){
                if (i != 0 && arr[i]->val < arr[i-1]->val){
                    if (!first){
                        first = arr[i-1];
                        middle = arr[i];
                    } else {
                        second = arr[i];
                    }
                }
            }
            if (first && second){
                swap(first->val, second->val);
                
            } else if (first && middle) {
                swap(first->val, middle->val);
            }
        }
    };