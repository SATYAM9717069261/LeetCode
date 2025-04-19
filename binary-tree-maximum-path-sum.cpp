#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    private:
        int findPath(TreeNode* root, int& maxSum) {
            if (root== nullptr)
                return 0;
            int left= findPath(root->left, maxSum);
            int right = findPath(root->right, maxSum);
            maxSum = max({
                    maxSum,root->val +left 
                    ,root->val + right
                    ,root->val+left+right,root->val 
                    });
            return max( { max(left, right) + root->val, root->val});
        }

    public:
        int maxPathSum(TreeNode* root) {
            int maxSum = INT_MIN;
            int sumOnRoot = findPath(root, maxSum);
            return max(maxSum,sumOnRoot);
        }
};

TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != "null") {
            current->left = new TreeNode(stoi(arr[i]));
            q.push(current->left);
        }
        i++;
        if (i < arr.size() && arr[i] != "null") {
            current->right = new TreeNode(stoi(arr[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}
int main(){
   string input;
    getline(cin, input);
    vector<string> arr;
    stringstream ss(input);
    string temp;
    
    while (ss >> temp) 
        arr.push_back(temp);
    

    TreeNode* root = buildTree(arr);

    Solution sol;
    sol.maxPathSum(root);

    return 0;
}
