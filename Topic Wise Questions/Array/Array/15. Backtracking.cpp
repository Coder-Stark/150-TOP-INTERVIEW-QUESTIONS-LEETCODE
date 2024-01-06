//BACKTRACKING
#include<bits/stdc++.h>
using namespace std;

//BACKTRACKING = POSSIBLE / PERMUTATIONS / COMBINATIONS / SUBSETS ETC.
/*
STEP  1. DO SOMETHING OR EXPLORE 
STEP  2. EXPLORE
STEP  3. REVERT STEP-1 AND FURTHER EXPLORE*/
//101. LETTER COMBINATIONS OF A PHONE NUMBER                                           {T.C = O(4^N), S.C = O(M)}
/*
using backtracking approach and try all combination for each digit's string (4 max char) and popup element for back track
*/
class Solution {
private : 
    void solve(string digits , string output , vector<string> &ans , string mapping[], int index){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';      //char to number
        string value = mapping[number];

        for(int i = 0 ; i <  value.length() ; i++){
            output.push_back(value[i]);
            solve(digits ,output , ans , mapping, index+1);
            output.pop_back();                //to backtrack and explore other combos
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";

        if(digits.length() == 0){
            return ans;
        }

        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits , output , ans , mapping, 0);         //0 = starting index
        return ans;
    }
};
/*
Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/


//102. COMBINATIONS                                                                {T.C = O(nCk), S.C = O(K)}
/*
store temp vector then push in ans vector after we explore each each value of k with take and non take 
*/
class Solution {
public: 
    void solve(int n, int k , vector<vector<int>>&ans, vector<int>&temp, int i){
        //base case
        if(k == 0){       //all combination taken
            ans.push_back(temp);
            return;
        }
        if(i > n){
            return;
        }
        //take and not take particular value
        temp.push_back(i);
        solve(n, k-1, ans, temp, i+1);               //take and explore rest
        temp.pop_back();
        solve(n, k, ans, temp, i+1);                 //not take and explore rest
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;                    //store temporary ans
        solve(n, k, ans, temp, 1);          //1 = range [1, n]
        return ans;
    }
};
/*
Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
*/


//103. PERMUTATIONS                                                                 {T.C = O(N*N!), S.C = O(N)}
/*
we requried a for loop to traverse from 0 index and used vector to keep track the number is used or not
*/
class Solution {
public:
    void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>&temp, vector<bool>&used){
        int n = nums.size();
        //base case
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0 ; i < n ; i++){
            if(!used[i]){
                temp.push_back(nums[i]);
                used[i] = true;

                solve(nums, ans, temp, used); 

                temp.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>used(n, false);
        solve(nums, ans, temp, used);                //0 = index not neccessary because we have to start 0 always
        return ans;
    }
};
//ANOTHER APPROACH
class Solution {
private:
    void solve(vector<int> nums  , int index , vector<vector<int>> &ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i = index ; i < nums.size() ; i++){
            swap(nums[index], nums[i]);
            solve(nums , index+1 , ans);
            
            //backtracking
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums , index , ans);
        return ans;
    }
};
/*
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/


//104. COMBINATION SUM                                                              {T.C = O(EXP), S.C = O(EXP)}
/*
store temp vector then push in ans vector after we explore each value of candidates[i] with take(subtract from target sum) and non take 
*/
class Solution {
public:
    void solve(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&temp, int idx){
        //base case
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = idx ; i < candidates.size(); i++){
            if(candidates[i] <= target){                          //until the target is smaller then temp array sum 
                temp.push_back(candidates[i]);
                solve(candidates, target-candidates[i], ans, temp, i);
                temp.pop_back();                        //backtrack
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates, target, ans, temp, 0);         //0 = starting index
        return ans;
    }
};
/*
Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
*/


//105a. N-QUEENS                                                                      {T.C = O(N! OR EXP), S.C = O(N^2)}
/*
first we check each col internally check row if both not attacked then move to another col and move further 
conditions must be followed :
1. every row must have 1 queen
2. every col must hanve 1 queen
3. none have been attack by any other (diagonlly attack can also happen)
*/
class Solution {
public:
    //check only 3 directions because we are filling from left to right
    /*
        ^
        \      //left-up diagonal
        <- Q     //left row or same row
        /      //left-down diagonal
        V
    */
    bool isSafe(int col , int row, vector<string>&board, int n){
        //left-up diagonal
        int x = row;
        int y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x--;
        }

        //left row or same row
        x = row, y = col;               //reinitialize
        while( y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }

        //left-down diagonal
        x = row, y = col;               //reinitialize
        while(x < n && y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x++;
        }
        
        return true;
    }
    void solve(int n, vector<vector<string>>&ans, vector<string>&board, int col){
        //base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(col, row, board, n)){
                board[row][col] = 'Q';
                solve(n, ans, board, col+1);
                board[row][col] = '.';                 //backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        solve(n, ans, board, 0);                        //0 = initial column
        return ans;
    }
};
/*

Example 1:
Input: n = 4
Output: [
        [".Q..",
          "...Q",
         "Q...",
         "..Q."],

         ["..Q.",
         "Q...",
         "...Q",
         ".Q.."]
        ]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]
*/


//105b. N-QUEENS II                                                             {T.C = O(N! OR EXP), S.C = O(N^2)}
/*
same as above just right size of ans vector
*/
class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        //left-Up diagonal attack
        int x = row, y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--, y--;
        }

        //left side row or same row
        x = row, y = col;
        while(y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }

        //left-Down diagonal attack
        x = row, y = col;
        while(x < n && y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x++, y--;
        }

        return true;
    }
    void solve(int n, vector<vector<string>>&ans, vector<string>&board, int col){
        //base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(n, ans, board, col+1);
                board[row][col] = '.';              //backtrack
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        solve(n, ans, board, 0);                     //0 = initial column
        return ans.size();
    }
};
/*
Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1
*/


//106. GENERATE PARANTEHSIS
/*
take a temp empty string and push the "(" if opening bracket is smaller then number and push ")" 
if closing bracket is smaller then opening bracket 
*/
class Solution {
public:
    void solve(int n, vector<string>&ans, string temp, int opBr, int clBr){  //temp should be pass by value not by refence
        //base case
        if(temp.length() == n*2){                        //n*2 = pairs (opening + closing)
            ans.push_back(temp);
            return;
        }

        if(opBr < n){
            solve(n, ans, temp +"(", opBr+1, clBr);
        }
        if(clBr < opBr){
            solve(n, ans, temp + ")", opBr, clBr+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp = "";
        solve(n, ans, temp, 0, 0);            //0 = opening bracket, 0 = closing bracket
        return ans;
    }
};
/*
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/


//same as 100a
//107. WORD SEARCH                                                         {T.C = O(N*M*4*L), S.C = O(N*M)}
/*
simple dfs , start from 0th postion and keep a letter constant search word in all directions
*/
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int i, int j, vector<vector<bool>>& visited) {
        // Base case: Entire word found
        if (idx == word.length()) {
            return true;
        }

        // Boundary check and character match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[idx]) {
            return false;
        }

        // Mark cell as visited
        visited[i][j] = true;

        // Check in all 4 directions
        bool found = dfs(board, word, idx + 1, i + 1, j, visited) ||
                     dfs(board, word, idx + 1, i - 1, j, visited) ||
                     dfs(board, word, idx + 1, i, j + 1, visited) ||
                     dfs(board, word, idx + 1, i, j - 1, visited);

        // Mark cell as unvisited after exploration
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        // Initialize a visited matrix to track visited positions
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
Example 1:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "ABCCED"
Output: true
Example 2:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "SEE"
Output: true
*/