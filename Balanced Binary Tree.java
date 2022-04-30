/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    public int isBalanced(TreeNode root) {
        if(root == null || root.left==null&&root.right==null)
            return 1;
        int maxleft = maxDepth(root.left);
        int maxright = maxDepth(root.right);
        if(maxleft - maxright > 1 || maxleft - maxright < -1)
            return 0;
        int xl = isBalanced(root.left);
        int xr = isBalanced(root.right);
        if(xl == 1 && xr == 1)
            return 1;
        return 0;
    }
    public int maxDepth(TreeNode node){
        if(node == null)
            return 0;
        if(node.left == null && node.right == null)
            return 1;
        int maxleft = maxDepth(node.left);
        int maxright = maxDepth(node.right);
        return Math.max(maxleft, maxright) + 1;
    }
}
