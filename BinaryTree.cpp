#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    private: TreeNode* sol(vector<int>& preorder, vector<int>& inorder, int start , int end, int& index){
                 if(start > end)
                     return NULL;
                 int rootVal = preorder[index];
                 int i = start; 
                 for(i;i<=end;i++){
                     if(inorder[i] == rootVal)
                         break;
                 }
                 index++;
                 TreeNode* root = new TreeNode(rootVal); 
                 root->left = sol(preorder,inorder,start,i-1,index);
                 root->right = sol(preorder,inorder,i+1,end,index);
                 return root;
             }

             void solution(TreeNode* root, vector<vector<int>>& ans, int level){
                 if(root == nullptr)
                     return ;

                 if(ans.size() <= level)
                     ans.push_back({});

                 solution(root->right,ans,level+1);
                 solution(root->left,ans,level+1);
                 ans[level].push_back(root->val);
             }
             void findpath(TreeNode* root, int target, vector<vector<int>>& ans, vector<int> tmp){
                 if( root == NULL || target < root->val )
                     return ;

                 tmp.push_back(root->val);
                 target -= root->val;

                 if(target == 0){
                     if(root->left == nullptr && root->right == nullptr)
                         ans.push_back(tmp);
                     else
                         return;
                 }

                 findpath(root->left,target, ans,tmp);
                 findpath(root->right,target, ans,tmp);

                 return ;
             }

             void solution2(TreeNode* root, vector<vector<TreeNode*>>& ans, int level){
                 if(root == nullptr)
                     return ;

                 if(ans.size() <= level)
                     ans.push_back({});

                 solution2(root->left,ans,level+1);
                 solution2(root->right,ans,level+1);
                 ans[level].push_back(root);
             }

             TreeNode* connect(TreeNode* root) {
                 vector<vector<TreeNode*>> ans;
                 solution2(root,ans,0);

                 for(vector<TreeNode*> i: ans){
                     int tmpSize = i.size() - 1;
                     for(int j=0;j<tmpSize;j++){
                         if( j ==  tmpSize)
                             i[j]->next = nullptr;
                         else
                             i[j]->next = i[j+1];
                         cout<<i[j]->val<<" Next => "<<i[j]->next->val<<endl;
                     }
                     cout<<"END +++++"<<endl;
                 }
                 return  root;
             }

    public: vector<vector<int>> levelOrderBottom(TreeNode* root) {
                vector<vector<int>> ans;
                //solution(root,ans,0);
               // reverse(ans.begin(),ans,end());
                return ans;
            }

            void buildTree(vector<int>& preorder, vector<int>& inorder, int target) {
                int index= 0;
                TreeNode* root  = sol(preorder,inorder,0,preorder.size()-1,index);
                connect(root);
            }
            

};

int main(){
    int size; cin>>size; 
    vector<int> preorder;
    while(size--){
        int num; cin>>num;
        preorder.push_back(num);
    }

    cin>>size; 
    vector<int> inorder;
    while(size--){
        int num; cin>>num;
        inorder.push_back(num);
    }
    int target ; cin>>target;

    Solution sol;
    sol.buildTree(preorder,inorder,target);
    return 0;
}
