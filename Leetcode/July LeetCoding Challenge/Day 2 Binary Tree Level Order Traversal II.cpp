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
    map<int, vector<int>>soln;
    void dfs(TreeNode* cur, int level){
        if(cur == NULL)return;
        dfs(cur->left,level+1);
        dfs(cur->right,level+1);
        soln[level].push_back(cur->val);
        return;
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root,0);
        vector<vector<int>>ret(soln.size());
        for(auto i:soln){
            for(auto j:i.second){
                ret[ret.size()-i.first-1].push_back(j);
            }
        }
        return ret;
    }
};