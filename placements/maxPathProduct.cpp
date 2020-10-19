public class BinaryTree_Product {
 
	int result = Integer.MIN_VALUE;
 
	public Integer[] maxProductWithThisNode(TreeNode node) {
		Integer min, max;
		if (node.val < -1) {
			min = node.val;
			max = null;
		} else if (node.val >= -1 && node.val <= 0) {
			min = null;
			max = null;
		} else if (node.val > 0 && node.val <= 1) {
			min = null;
			max = null;
		} else {
			min = null;
			max = node.val;
		}
		if (node.left == null && node.right == null) {
			result = Math.max(node.val, result);
			return new Integer[] { min, max };
		}
 
		Integer[] left = null;
		if (node.left != null) {
			left = maxProductWithThisNode(node.left);
			if (left[0] != null) {
				int num = left[0] * node.val;
				if (num < 0) {
					min = min == null ? num : Math.min(num, min);
				} else {
					max = max == null ? num : Math.max(num, max);
				}
			}
			if (left[1] != null) {
				int num = left[1] * node.val;
				if (num < 0) {
					min = min == null ? num : Math.min(num, min);
				} else {
					max = max == null ? num : Math.max(num, max);
				}
			}
		}
		Integer[] right = null;
		if (node.right != null) {
			right = maxProductWithThisNode(node.right);
			if (right[0] != null) {
				int num = right[0] * node.val;
				if (num < 0) {
					min = min == null ? num : Math.min(num, min);
				} else {
					max = max == null ? num : Math.max(num, max);
				}
			}
			if (right[1] != null) {
				int num = right[1] * node.val;
				if (num < 0) {
					min = min == null ? num : Math.min(num, min);
				} else {
					max = max == null ? num : Math.max(num, max);
				}
			}
		}
		if (node.left == null || node.right == null) {
			if (max != null) {
				result = Math.max(result, max);
			}
		} else {
			if (node.val < 0) {
				if (left[0] != null && right[1] != null) {
					result = Math.max(result, node.val * left[0] * right[1]);
				}
				if (left[1] != null && right[0] != null) {
					result = Math.max(result, node.val * left[1] * right[0]);
				}
			} else {
				if (left[0] != null && right[0] != null) {
					result = Math.max(result, node.val * left[0] * right[0]);
				}
				if (left[1] != null && right[1] != null) {
					result = Math.max(result, node.val * left[1] * right[1]);
				}
			}
		}
		return new Integer[] { min, max };
	}
 
	public int maxProduct(TreeNode root) {
		if (root == null) {
			return 0;
		}
		maxProductWithThisNode(root);
		return result;
	}
 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryTree_Product b = new BinaryTree_Product();
		TreeNode root = new TreeNode(3);
		root.left = new TreeNode(-2);
		root.right = new TreeNode(4);
		root.left.left = new TreeNode(5);
		root.left.right = new TreeNode(0);
		root.left.right.left = new TreeNode(1);
		root.right.left = new TreeNode(-2);
		root.right.right = new TreeNode(2);
		System.out.println(b.maxProduct(root));
	}
 
}