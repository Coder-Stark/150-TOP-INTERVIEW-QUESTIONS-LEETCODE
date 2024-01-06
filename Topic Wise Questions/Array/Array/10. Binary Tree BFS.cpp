//BINARY TREE BFS
#include<bits/stdc++.h>
using namespace std;

//82. BINARY TREE RIGHT SIDE VIEW                                            {T.C = O(N), S.C = O(N)}
//APPROACH
//take a ans vector and when level == vector.size() push root->data in ans and make recursive call (NRL)
class Solution {
public:
    void solve(TreeNode* root, vector<int>&ans, int level){
        //base case
        if(!root){
            return;
        }

        //NRL        (for right view)  //for left view (NLR)
        if(level == ans.size()){                   //if level reach ends then change the level and push root->data in vector
            ans.push_back(root->val);           
        }
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root, ans, 0);                      //0 == initial level
        return ans;
    }
};
/*
Input:
       1
    /    \
   3      2
Output: 1 2
*/


//83. AVERAGE OF LEVELS IN BINARY TREE                                    {T.C = O(N), S.C = O(N)}
//APPROACH
//using dfs(level order traversal) traverse the each node level wise , store node->val in ans vector then find average
//by using row or sum / no. of row or sum 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            double n = q.size(), row = 0;
            for(int i = 0 ; i < n ; i++){
                TreeNode* temp = q.front();
                q.pop();
                row += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(row/n);
        }
        return ans;
    }
};
/*
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Example 2:
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]*/


//84a. BINARY TREE LEVEL ORDER TRAVERSAL                                {T.C = O(N), S.C = O(N)}
//APPROACH
//perform dfs (level order traversal using queue)
class Solution {
public:
    vector<int>levelOrder(TreeNode* root) {
        vector<int>ans;
        //base case
        if(!root){
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(root->val);
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }
        return ans;
    }
};
/*
Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60
*/


//84b. BINARY TREE LEVEL ORDER TRAVERSAL                                {T.C = O(N), S.C = O(N)}
//APPROACH
//in this we have to return vector of vector for each level so slightly modification and in the while loop insert an
//for loop for traverse each level individually
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        //base case
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int>lvlNodes;
            for(int i = 0 ; i < lvlSize ; i++){
                TreeNode* temp = q.front();
                q.pop();
                lvlNodes.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(lvlNodes);
        }
        return ans;
    }
};
/*
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]
*/


//85. BINARY TREE ZIGZAG LEVEL ORDER TRAVERSAL                                      {T.C = O(N), S.C = O(N)}
//APPROACH
//using level order traversal just take an bool parameter when traverse 1 level reverse then reverse traversal row wise
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        //base case
        if(!root){
            return ans;
        }

        bool leftToRight = true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int>lvlNodes;
            for(int i = 0 ; i < lvlSize ; i++){
                TreeNode* temp = q.front();
                q.pop();
                //normal insert and reverse insert
                int idx = leftToRight ? i : lvlSize - i - 1;
                lvlNodes.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            //level direction change
            if(!leftToRight){
                reverse(lvlNodes.begin(), lvlNodes.end());
            }
            ans.push_back(lvlNodes);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
/*
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]
*/