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
    void check(TreeNode * root,int sum,vector<int>&ans){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(sum);
        }
        check(root->left,sum,ans);
        check(root->right,sum,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        check(root,0,ans);
        bool flag=false;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==targetSum){
                flag=true;
                break;
            }
        }
        return flag;
    }
};