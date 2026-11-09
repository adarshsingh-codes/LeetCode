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
    int check(TreeNode* root,long long targetSum,int&ans){
        if(root==NULL){
            return ans;
        }
        targetSum-=root->val;
        if(targetSum==0){
            ans++;           
        }
        check(root->left,targetSum,ans);
        check(root->right,targetSum,ans);
        return ans;
    }
    void allpath(TreeNode* root,long long targetSum,int& ans){
        if(root==NULL){
            return;
        }
        check(root,targetSum,ans);
        allpath(root->left,targetSum,ans);
        allpath(root->right,targetSum,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        allpath(root,targetSum,ans);
        return ans;
    }
};