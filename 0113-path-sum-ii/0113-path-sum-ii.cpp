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
    void check(TreeNode* root,int sum,vector<vector<int>>&ans,vector<int>&curr){
        if(root==NULL){
            return;
        }
        sum-=root->val;
        curr.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==0){
                ans.push_back(curr);
            }
        }
        check(root->left,sum,ans,curr);
        
        check(root->right,sum,ans,curr);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        check(root,targetSum,ans,curr);
        return ans;
    }
};