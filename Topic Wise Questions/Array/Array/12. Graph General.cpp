//GRAPH GENERAL
#include<bits/stdc++.h>
using namespace std;

//89. NUMBER OF ISLANDS                                                         {T.C = O(N*M), S.C = O(N*M)}
//APPROACH
//Use BFS to mark the connected components All the connected 1s will be a part of single island
class Solution {
public:
    void bfs(vector<vector<char>>&grid, vector<vector<int>>&vis, int i, int j , int n , int m){
        vis[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i, j});
        
        while(!q.empty()){
            auto frontNode = q.front();
            int row = frontNode.first;
            int col = frontNode.second;
            q.pop();

            //all 4 possible directions
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = { 0, 1, 0, -1};
            //traverse in the neighbour and mark if it is island
            for(int i = 0 ; i < 4 ; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j  = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(grid, vis, i, j, n, m);
                }
            }
        }
        return count;
    }
};
/*
Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/


//90. SURROUNDED REGIONS                                                   {T.C = O(N*M), S.C = O(1)}
//APPROACH
//reverse solution of number of islands in which we find the group rether then we solve the boudary cases and with attach
//boundary 'O' convert to '#' and another '0' with 'X'.
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';

        // Traverse all 4 directions
        dfs(board, i - 1, j, n, m);
        dfs(board, i + 1, j, n, m);
        dfs(board, i, j - 1, n, m);
        dfs(board, i, j + 1, n, m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Handle edge case of empty board
        if (n == 0){
            return;  
        }  

        // Moving over first and last columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, n, m);
            }
            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1, n, m);
            }
        }

        // Moving over first and last rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, n, m);
            }
            if (board[n - 1][j] == 'O') {
                dfs(board, n - 1, j, n, m);
            }
        }

        // Convert remaining 'O's to 'X' and revert '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
/*
Example 1:
Input: board = [["X","X","X","X"],
                ["X","O","O","X"],
                ["X","X","O","X"],
                ["X","O","X","X"]]
Output:     [["X","X","X","X"],
             ["X","X","X","X"],
             ["X","X","X","X"],
             ["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:
Input: board = [["X"]]
Output: [["X"]]
*/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
//91. CLONE A GRAPH                                                                 {T.C = O(V+E), S.C = O(V)}
//APPROACH
/*
The code defines a Solution class with a cloneGraph function that performs a depth-first search (DFS) to create 
a deep copy of a graph represented by nodes and their neighbors, utilizing a visited array to track visited nodes.
*/
class Solution {
public:
    void dfs(Node* node, vector<Node*>&vis, Node* copy){
        vis[copy->val] = copy;
        for(auto it : node->neighbors){                  //traverse in adjacency list
            if(!vis[it->val]){
                Node* newNode = new Node(it->val);
                copy->neighbors.push_back(newNode);
                dfs(it, vis, newNode);
            }else{
                copy->neighbors.push_back(vis[it->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        //base case
        if(node == NULL){
            return NULL;
        }

        vector<Node* > vis(1000, NULL);
        Node* copy = new Node(node->val);
        dfs(node, vis, copy);

        return copy;
    }
};
/*
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
*/


//92. EVALUATE DIVISION
//APPROACH
/*
the question is looks like a simple graph traversal with weight first we create graph(adj list) of equations resolve 
queries by creating visited set for each traversal and do dfs
*/
class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, double &ans, double prod, unordered_set<string>&vis){
        if(vis.find(src) != vis.end()){
            return;
        }
        vis.insert(src);       //mark visited
        if(src == dst){
            ans = prod;
            return;
        }
        for(auto it : adj[src]){
            string v = it.first;
            double val = it.second;
            dfs(adj, v, dst, ans, prod*val, vis);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //similar question to graph with with weight or graph traversal
        int n = equations.size();

        //create adjacency list
        // unordered_map<int, int>mp;
        unordered_map<string, vector<pair<string, double>>>adj;
        for(int i = 0 ; i < n ; i++){
            string u = equations[i][0];       //"a"
            string v = equations[i][1];       //"b"
            double val = values[i];            //2

            adj[u].push_back({v, val});     //a/b
            adj[v].push_back({u, 1.0/val}); //b/a
        }

        vector<double>result;

        for(auto it : queries){
            string src = it[0];
            string dst = it[1];

            double ans = -1.0;
            double prod = 1.0;


            if(adj.find(src) != adj.end()){
                unordered_set<string>vis;                 //vis set created each time 
                dfs(adj, src, dst, ans, prod, vis);
            }
            result.push_back(ans);
        }
        return result;
    }
};
/*
Example 1:
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0

Example 2:
Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
*/


//93. COURSE SCHEDULE
/*
detect the cycle in a graph by using dfs if cycle present return false else true or traverse graph without getting any cycle
*/
class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, int node){
        vis[node] = 1; // Mark the node as currently being visited
        for(auto it : adj[node]){
            if(vis[it] == 1){
                return true;
            }
            else if(vis[it] == 0 && dfs(adj, vis, ans, it)){ // If a cycle is detected downstream
                return true;
            }
        }
        vis[node] = 2; // Mark the node as visited and not part of a cycle
        ans.push_back(node); // Include in the valid course order
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list and initialize visited array
        vector<vector<int>> adj(numCourses);

        // Building adjacency list
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<int> ans;
        vector<int> vis(numCourses, 0);   // 0 for unvisited, 1 for visiting, 2 for visited

        // Perform DFS on all nodes to check for cycles
        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0 && dfs(adj, vis, ans, i) ){
                return false; // Cycle detected, cannot finish courses
            }
        }
        
        // If no cycle detected, return true (courses can be finished)
        return true;
    }
};
/*
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 */


//94. COURSE SCHEDULE II
/*
detect the cycle in a graph by using dfs if cycle present return empty vector else true or traverse graph and not getting any cycle
then store in vector and return it
*/
class Solution {
    bool dfs(vector<vector<int>>&adj, vector<int>&ans, vector<int>&vis, int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 1){
                return true;
            }else if(vis[it] == 0 && dfs(adj, ans, vis, it)){
                return true;
            }
        }
        vis[node] = 2;               //mark as completely visited
        ans.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        //create adjacency list
        vector<vector<int>>adj(numCourses);
        for(int i = 0 ; i < n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            // adj[v].push_back(u);               //reverse push according to question 2nd depends on 1s to arrow should be reverse
            adj[u].push_back(v);             
        }

        vector<int>ans;
        vector<int>vis(numCourses, 0);   //initialize with 0
        for(int i = 0 ; i < numCourses ; i++){
            if(vis[i] == 0 && dfs(adj, ans, vis, i)){
                return {};                   //return empty vector for present cycle (can not be schedule)
            }
        }
        // reverse(ans.begin(), ans.end());   //ensuring that the second course (prerequisite) points to the first course in the adjacency list.
        return ans;
    }
};
/*
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
*/