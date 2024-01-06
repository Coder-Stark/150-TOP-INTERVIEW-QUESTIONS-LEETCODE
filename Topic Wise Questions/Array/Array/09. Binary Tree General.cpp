//BINARY TREE GENERAL
#include<bits/stdc++.h>
using namespace std;

/*--------------------------------DRIVER FUNCTION ---------------------------------*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*-------------------------------------------------------------------------------------------------------*/
//68. MAXIMUM DEPTH OF BINARY TREE                                               {T.C = O(N), S.C = O(H)}
//APPROACH
//apply dfs(LRN = postorder traversal) find left & right node depht + 1 for add current level
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(!root){
            return 0;
        }

        //LRN
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int ans = max(left, right) + 1;                  //1 = current level (add)

        return ans;
    }
};
/*
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
*/ 


//69. SAME TREE                                                        {T.C = O(N), S.C = O(H)}
//APPROACH
//simple check base condition and same value and after that call recursion to check is same tree or not
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if(!p && !q){                                //if both null
            return true;
        }
        if(!p || !q){                               //if only one null
            return false;
        }
        if(p->val != q->val){                      //if data is different
            return false;
        }

        //left and right call by recursion
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
/*
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/


//70. INVERT BINARY TREES                                                  {T.C = O(N), S.C = O(N)}
//APPROACH
//using level order traversal traverse then swap left and right children
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        //base case
        if(!root){
            return root;
        }

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            //swap left and right children
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            //right then left for invert binary tree
            if(curr->right){
                q.push(curr->right);
            }
            if(curr->left){
                q.push(curr->left);
            }
        }
        return root;
    }
};

//APPROACH                                                                {T.C = O(N), S.C = O(H)}
//using recursion first swap elements then traverse left and right subtree through recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
/*
Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]
*/


//71. SYMMETRIC TREE                                                     {T.C =  O(N), S.C = O(H)}
//APPROACH
//check if null then true then check val is same then isMiror function by recursion checks symmetric or not
//similar to 69 quesition
class Solution {
public:
    bool isMirror(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        return p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left);   
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return isMirror(root->left, root->right);
    }
};
/*
Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false*/


//72. CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL                {T.C = O(N), S.C = O(N)}
class Solution {
public:
    TreeNode*f(int &i,int l,int h,vector<int>&pre,unordered_map<int,int>&mp)
    {
        if(l>h) return NULL;
        int id=mp[pre[i]];
        if(id<l || id>h) return NULL;
        TreeNode*root=new TreeNode(pre[i]);
        i++;
        root->left=f(i,l,id-1,pre,mp);
        root->right=f(i,id+1,h,pre,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[in[i]]=i;
        int i=0;
        return f(i,0,n-1,pre,mp);
    }
};
/*
Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/



//73. CONSTRUCT BINARY TREE FROM POSTORDER AND INORDER TRAVERSAL                {T.C = O(N), S.C = O(N)}
class Solution {
public:
    TreeNode* solve(vector<int>&in, int is, int ie, vector<int>&po, int ps, int pe, unordered_map<int, int>&mp){
        //base case
        if(is > ie || ps > pe){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(po[pe]);      //in postorder traversing from postend index

        int inRoot = mp[po[pe]];
        int numsLeft = inRoot-is;                //no. of element in left or right subtree

        root->left = solve(in, is, inRoot-1, po, ps, ps+numsLeft-1, mp);
        root->right = solve(in, inRoot+1, ie, po, ps+numsLeft, pe-1, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();            //same as postorder size
        if(n != postorder.size()){
            return NULL;
        }
        unordered_map<int, int>mp;

        //store indexes of inorder in map
        for(int i = 0 ; i < n  ; i++){
            mp[inorder[i]] = i;
        }

        return solve(inorder, 0, n-1, postorder, 0, n-1, mp);
    }
};
/*
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
*/


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
//74. POPULATING NEXT RIGHT POINTERS IN EACH NODE II                        {T.C = O(N), S.C = O(N)}
class Solution {
public:
    Node* connect(Node* root) {
        //base case
        if(!root){
            return root;                     //return root or null
        }
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<Node*> v(n, 0);
            for(int i = 0 ; i < n ; i++){              //LOT(level order traversal)
                Node* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                v[i] = temp;
            }
            for(int i = 0 ; i < n-1; i++){                    //move till second last element cause last element points to null
                v[i]->next = v[i+1];
            }
            v[n-1]->next = NULL;
        }
        return root;
    }
};
/*
Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Example 2:
Input: root = []
Output: []
*/


//75. FLATTEN BINARY TREE TO LINKED LIST                              {T.C = O(N), S.C = O(1)}
//APPROACH
//using moris traversal (S.C = o(1))
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* predecessor = curr->left;        //first left then extream right 
                while(predecessor->right){
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;       //set virtual pointer
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
/*
Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
*/


//76. PATH SUM                                                    {T.C = O(N), S.C = O(H)}
//APPROACH 
//simple recursion 
class Solution {
public:
    bool totalSum(TreeNode* root, int targetSum, int currSum){
        if(!root->left && !root->right){
            if(targetSum == (currSum + root->val)){
                return true;
            }
            return false;
        }
        if(root->left){
            if(totalSum(root->left, targetSum, currSum + targetSum)){
                return true;
            }
        }
        if(root->right){
            if(totalSum(root->right, targetSum, currSum + targetSum)){
                return true;
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        if(!root){
            return false;
        }
        return totalSum(root, targetSum, currSum);
    }
};
/*
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
*/


//77. SUM ROOT TO LEAF NUMBERS                                                   {T.C = O(N), S.C = O(H)}
//APPROACH
//first take sum of leaf node then traverse left and right subtree after that n/10 for backtracking
class Solution {
public:
    void solve(TreeNode* root, int &sum , int &num){
        //base case
        if(!root){
            return;
        }

        //leaf node
        if(!root->left && !root->right){
            sum += root->val + num*10;            //multiplied by 10 to shift its digits to the left
            return;
        }
        num = num*10 + root->val;                  //continuous updating num
        solve(root->left, sum, num);
        solve(root->right, sum, num);
        num /= 10;                            //to backtrack and explore other branches.

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;
        solve(root, sum, num);
        return sum;
    }
};
/*
Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/


//78. BINARY TREE MAXIMUM PATH SUM                                               {T.C = O(N), S.C = O(H)}
//APPROACH
//take a maxi integer, base case if !root return 0, calculate maximum path sum for left and right subtree take update maxi (left+right+root->val)
//return max(left, right) + root->val
class Solution {
public:
    int solve(TreeNode* root, int &maxi){
        //base case
        if(!root){
            return 0;
        }
        int left = max(0, solve(root->left, maxi));   // Calculate the maximum path sum for the left and right subtrees
        int right = max(0, solve(root->right, maxi));
        maxi = max(maxi, left+right+root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};
/*
Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/


//79. BINARY SEARCH TREE ITERATOR                                                  {T.C = O(1), S.C = O(H)}
class BSTIterator {
    stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
        //push all left node in the stack
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* currNode = st.top();
        st.pop();
        if(currNode->right){             // If the current node has a right subtree, explore its leftmost path
            TreeNode* temp = currNode->right;
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
        }
        return currNode->val;
    }
    
    bool hasNext() {
        if(!st.empty()){
            return true;
        }
        return false;
    }
};
/*

Example 1:
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]
Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
*/


//80. COUNT COMPLETE TREE NODES                                                    {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        //LRN
        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return left + right + 1;                    //1 = node element
    }
};
/*
Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0
*/


//81. LOWEST COMMON ANCESTOR OF A BST                                                {T.C = O(N), S.C = O(H)}
//APPROACH
//apply recursiove call for left and right subtree if from both side is not null that is the answer else conditions below
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root){
            return NULL;
        }
        if((root->val == p->val) || (root->val == q->val)){      //ownself is an ancestor
            return root;
        }

        //LRN
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        if(leftAns && rightAns){                                //both left and right call not null (thats the lca answer)
            return root;
        }
        else if(!leftAns && rightAns){
            return rightAns;
        }
        else if(leftAns && !rightAns){
            return leftAns;
        }
        else{  //!leftAns && !rightAns
            return NULL;
        }
    }
};
/*
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/
