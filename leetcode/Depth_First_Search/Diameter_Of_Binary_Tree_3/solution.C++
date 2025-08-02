/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
int maxdiameter=0;
int helper(TreeNode* node){
if(!node)return 0;
int leftmax=helper(node->left);
int rightmax=helper(node->right);
maxdiameter=max(maxdiameter,leftmax+rightmax);
return 1+max(leftmax,rightmax);
}
int diameterOfBinaryTree(TreeNode* root) {
helper(root);
return maxdiameter;
};