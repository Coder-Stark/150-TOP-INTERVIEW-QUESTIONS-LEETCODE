//BINARY SEARCH TREE (BST)
#include<bits/stdc++.h>
using namespace std;

//86. MINIMUM ABSOLUTE DIFFERENCE IN BST                                            {T.C = O(N), S.C = O(H)}
//APPROACH
//Store preVal first then find minDiff by subtracting each preVal to current value.
class Solution {
public:
    void solve(TreeNode* root, int &mini, int &preVal){
        //base case
        if(!root){
            return;
        }
        //LNR      //BST
        solve(root->left, mini, preVal);

        if(preVal != -1){
            mini = min(mini, root->val - preVal);
        }
        preVal = root->val;
        
        solve(root->right, mini, preVal);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int preVal = -1;
        solve(root, mini, preVal);
        return mini;
    }
};
/*
Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
*/


//87. KTH SMALLEST ELEMENT IN A BST                                             {T.C = O(N), S.C = O(N)}
//APPROACH
//first store all nodes in a vector by Inorder traversal (sorted in BST) then find kth smalleste element (k-1){1 based indexing}
class Solution {
public:
    void solve(TreeNode* root, vector<int>&v){
        //base case
        if(!root){
            return;
        }
        //LNR
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        solve(root, v);
        return v[k - 1] ;                        //-1 for 1 based indexing
    }
};
/*
Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
*/


//88. VALIDATE BINARY SEARCH TREE                                              {T.C = O(N), S.C = O(H)}
//APPROACH
//write base condition then root->left->val < root->val < root->right->val recursively
class Solution {
public:
    bool bst(TreeNode* root, long long mini, long long maxi){ // Using long long to cover the edge case of INT_MIN and INT_MAX
        //base case
        if(!root){
            return true;
        }
        if(root->val <= mini || root->val >= maxi){
            return false;
        }
        return bst(root->left, mini, root->val) && bst(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        return bst(root, LLONG_MIN, LLONG_MAX); // Using LLONG_MIN and LLONG_MAX for initial minimum and maximum values
    }
};
/*
Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/