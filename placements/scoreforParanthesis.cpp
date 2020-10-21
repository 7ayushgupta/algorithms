// C++ program to find the score of 
// parentheses using Tree 

#include <iostream> 
#include <vector> 

using namespace std; 

// Customized tree class or struct, 
// contains all required methods. 
class TreeNode { 
	TreeNode* parent = NULL; 
	vector<TreeNode*> children; 

public: 
	// Function to add a child into 
	// the list of children 
	void addChild(TreeNode* node) 
	{ 
		children.push_back(node); 
	} 

	// Function to change the parent 
	// pointer to the node passed 
	void setParent(TreeNode* node) 
	{ 
		parent = node; 
	} 

	// Function to return the parent 
	// of the current node 
	TreeNode* getParent() 
	{ 
		return parent; 
	} 

	// Function to compute the score recursively. 
	int computeScore() 
	{ 

		// Base case 
		if (children.size() == 0) 
			return 1; 

		int res = 0; 

		// Adds scores of all children 
		for (TreeNode* curr : children) 
			res += curr->computeScore(); 

		if (parent == NULL) 
			return res; 
		else
			return 2 * res; 
	} 
}; 

// Function to create the tree structure 
TreeNode* computeTree(string s) 
{ 

	TreeNode* current = new TreeNode(); 
	TreeNode* root = current; 

	// Creating a node for every "()" 
	for (int i = 0; i < s.size(); i++) { 

		// If we find "(" we add a node as 
		// a child 
		if (s[i] == '(') { 
			TreeNode* child = new TreeNode(); 
			child->setParent(current); 
			current->addChild(child); 
			current = child; 
		} 

		// On finding ")" which confirms that 
		// a pair is closed, we go back 
		// to the parent 
		else { 

			current = current->getParent(); 
		} 
	} 
	return root; 
} 

// Driver code 
int main() 
{ 
	string s = "(()(()))"; 

	// Generating the tree 
	TreeNode* root = computeTree(s); 

	// Computing the score 
	cout << root->computeScore(); 
	return 0; 
} 


class Solution(object):
    def scoreOfParentheses(self, S):
        ans = bal = 0
        for i, x in enumerate(S):
            if x == '(':
                bal += 1
            else:
                bal -= 1
                if S[i-1] == '(':
                    ans += 1 << bal
        return ans