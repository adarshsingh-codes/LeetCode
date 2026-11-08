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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        int maxSum=INT_MIN;
        int level=1;
        int ans=1;
        queue<TreeNode*>q;
        q.push(root);
        int sum;
        while(!q.empty()){
            int size=q.size();
            sum=0;
            while(size--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                sum+=temp->val;
            }
            if(sum>maxSum){
                maxSum=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};