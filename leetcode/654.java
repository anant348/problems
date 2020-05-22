class Solution {
  public TreeNode constructMaximumBinaryTree(int[] nums) {
    Stack<TreeNode> s = new Stack<TreeNode>();
    TreeNode root = null;
    for (int n : nums) {
      TreeNode t = new TreeNode(n);
      while (!s.empty() && s.peek().val < n)
        s.pop();
      if (s.empty()) {
        t.left = root;
        root = t;
      } else {
        TreeNode x = s.peek();
        TreeNode temp = x.right;
        x.right = t;
        t.left = temp;
      }
      s.push(t);
    }
    return root;
  }
}
