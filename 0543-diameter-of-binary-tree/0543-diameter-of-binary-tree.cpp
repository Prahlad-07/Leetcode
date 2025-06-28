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
class Solution{
    int ans=0;
private:
    int solve(TreeNode *root, int res){
        if(root==NULL){
            return 0;
        }
        int left = solve(root->left,ans);
        int right = solve(root->right, ans);
        int temp = left+right;
        ans=max(ans,temp);
        return max(left,right)+1;
       

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
         solve(root,0);
         return ans;
        
    }
};