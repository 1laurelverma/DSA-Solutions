/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int inorder(struct TreeNode *root, int low, int high,int sum) {
    if(root == NULL)
        sum += 0;
    else
    {
        sum = inorder(root -> left, low, high,sum);
        if(root -> val >= low && root -> val <= high) 
            sum += root -> val;
        sum = inorder(root -> right, low, high,sum);
    }
    return sum;
}

int rangeSumBST(struct TreeNode* root, int low, int high){
    int sum =0;
    sum = inorder(root, low, high,sum);
    return sum;
}
