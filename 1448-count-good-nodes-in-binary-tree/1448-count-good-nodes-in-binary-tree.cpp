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
    int check(TreeNode* root,int maxi,int& count){
        if(root==NULL){
            return 0;
        }   
        if(root->val>=maxi){
            count++;
        }
        maxi=max(maxi,root->val);
        check(root->left,maxi,count);
        check(root->right,maxi,count);
        return count;
    }
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        int count=0;
        check(root,maxi,count);
        return count;
    }
};