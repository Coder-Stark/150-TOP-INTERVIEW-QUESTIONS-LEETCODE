//DIVIDE AND CONQUER
#include<bits/stdc++.h>
using namespace std;

//108. CONVERT SORTED ARRAY TO BINARY SEARCH TREE                                    {T.C = O(N), S.C = O(N)}               
/*
first finds the mid element and make it root node then create a left and right subtree (vector) then make recursive call
root's left = leftsubtree , root's right = rightsubtree and finally retiurn root
*/
class Solution {
public:
    TreeNode* solve(vector<int>&nums){
        //base case
        if(nums.empty()){
            return NULL;
        }

        int mid = nums.size()/2;
        
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int>leftSubTree(nums.begin(), nums.begin() + mid);
        vector<int>rightSubTree(nums.begin()+mid+1, nums.end());

        root->left = solve(leftSubTree);
        root->right = solve(rightSubTree);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums);
    }
};
/*
Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
*/


//109. SORT LIST
/*
//BRUTE FORCE APPROACH                                                      {T.C = O(N*LOGN), S.C = O(N)}
first convert list to vector then sort the vector and again convert vector to list
*/
class Solution {
public:
    ListNode* ArrToLl(vector<int>&ans){
        int n = ans.size();
        if(n == 0){
            return NULL;
        }

        ListNode* head = new ListNode(ans[0]);                  //initialize head with first element of array
        ListNode* curr = head;

        for(int i = 1 ; i < n ; i++){                          //start with 2nd element (1st is head)
            curr->next = new ListNode(ans[i]);
            curr = curr->next;
        }
        return head;
    }
    void llToArr(ListNode* head, vector<int>&ans){
        ListNode* temp = head;
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
    }
    ListNode* sortList(ListNode* head) {
        vector<int>ans;
        llToArr(head, ans);
        sort(ans.begin(), ans.end());
        return ArrToLl(ans);
    }
};

//ANOTHER APPROACH (MERGE SORT)                                              {T.C = O(N*LOGN), S.C = O(1)}
/*
1. Using 2pointer / fast-slow pointer find the middle node of the list.
2. Now call mergeSort for 2 halves.
3. Merge the Sort List (divide and conqueror Approach)
*/
class Solution {
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* p1 = l1; 
        ListNode* p2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* p3 = dummyNode;
        //if both list is nonempty
        while(p1 && p2){
            if(p1->val < p2->val){
                p3->next = p1;
                p1 = p1->next;
            }else{ //p1->val >= p2->val
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;                                //move p3 for both above cases
        }
        while(p1){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while(p2){
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        return dummyNode->next;                          //original starts from next of dummy node
    }
    ListNode* sortList(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL){
            return head;                                    
        }
        //finding mid element
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;

        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;                          //end of a first left half (list divided)

        ListNode* l1 = sortList(head);              //left half
        ListNode* l2 = sortList(slow);              //right half

        return mergeList(l1, l2);
    }
};
/*
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
//110. CONSTRUCT QUAD TREE                                                   {T.C = O(N^2*LOGN), S.C = O(LOGN)}
/*
first check if the node is leaf node then directly return node if not then we have to make 4 recursive call for each quadrant.
*/
class Solution {
public:
    bool isAllSame(vector<vector<int>>&grid, int x, int y, int n){
        int val = grid[x][y];

        for(int i = x ; i < x+n ; i++){            //i < x + n and j < y + n is used to iterate over a specific quadrant within the larger grid.
            for(int j = y ; j < y+n ; j++){
                if(grid[i][j] != val){
                    return false;
                }
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>>&grid, int x , int y, int n){
        if(isAllSame(grid, x, y, n)){
            return new Node(grid[x][y], true);                 //element, true = leafFound(stop)
        }else{
            Node* root = new Node(1, false);                   //1 = anything you want , false (not leaf)
 
            root->topLeft = solve(grid, x, y, n/2);             //n/2 we making half grid every recursive call
            root->topRight = solve(grid, x, y+n/2, n/2);
            root->bottomLeft = solve(grid, x+n/2, y, n/2);
            root->bottomRight = solve(grid, x+n/2, y+n/2, n/2);
            
            return root;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid, 0, 0, n);                 //0 = starting row, 0 = starting col
    }
};
/*
Example 1:
Input: grid = [[0,1],
               [1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represents False and 1 represents True in the photo representing the Quad-Tree.

Example 2:
Input: grid = [[1,1,1,1,0,0,0,0],
               [1,1,1,1,0,0,0,0],
               [1,1,1,1,1,1,1,1],
               [1,1,1,1,1,1,1,1],
               [1,1,1,1,0,0,0,0],
               [1,1,1,1,0,0,0,0],
               [1,1,1,1,0,0,0,0],
               [1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
*/


//111. MERGE K SORTED LINKED LIST                                               {T.C = O(N*LOGN), S.C = O(1)}
/*
put first element of each list in minheap it will always pop out minimum element and we have to store this into vector or ll
*/
class compare{
public:
    bool operator()(ListNode* a, ListNode* b){
       return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyNode = new ListNode(NULL);
        ListNode* temp = dummyNode;

        priority_queue<ListNode* , vector<ListNode*>, compare>minHeap;

        //put first element of each lists(k elements)
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i]){
                minHeap.push(lists[i]);
            }
        }

        while(!minHeap.empty()){
            auto topNode = minHeap.top();
            minHeap.pop();
            temp->next = topNode;              
            temp = temp->next;
            if(topNode->next){
                minHeap.push(topNode->next);
            }
        }
        return dummyNode->next;
    }
};
/*
Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []
Example 3:
*/