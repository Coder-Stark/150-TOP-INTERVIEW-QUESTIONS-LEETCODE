//MULTIDIMENSIONAL DP (DYNAMIC PROGRAMMING)
#include<bits/stdc++.h>
using namespace std;

//142. TRIANGLE                                                         {T.C = O(N*M), S.C = O(N*M)}
/*
create 2D dp , intialize row , col and col = vector[row].size() in recursive call we have only 2 option (i or i+1 col) store ans in dp
with current element + min(i, i+1 col) ans.
*/
class Solution {
public:
    int solveMem(vector<vector<int>>&triangle, vector<vector<int>>&dp, int row, int col){
        int n = triangle.size();
        //base case
        if(row >= n){
            return 0;
        }
        int m = triangle[row].size();
        if(col >= m){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        //step2 recursive call
        int take_i0 = solveMem(triangle, dp, row+1, col);      //taking col = i
        int take_i1 = solveMem(triangle, dp, row+1, col+1);    //taking col = i+1

        dp[row][col] = triangle[row][col] + min(take_i0, take_i1);   //add current element(triangle[row][col])
        return dp[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1)); 
        return solveMem(triangle, dp, 0, 0);                     //0 = row, 0 = col
    }
};
/*
Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
*/


//143. MINIMUM PATH SUM                                                        {T.C = O(N*M), S.C = O(N*M)}
/*
create 2D dp , intialize row , col and col = vector[0].size() in recursive call we have only 2 option (down(row+1) or right(col+1)) store ans in dp
with current element + min(down, right ) ans.
handle extra base case if reach to bottom right return grid[row][col]
*/
class Solution {
public:
    int solveMem(vector<vector<int>>&grid, vector<vector<int>>&dp, int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        //base case
        if(row >= n || col >= m){
            return 1e9;
        }
        if(row == n-1 && col == m-1){              //reach to bottom right
            return grid[row][col];
        }

        //step3 if ans already present return it
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        //step2 recursive call
        int down = solveMem(grid, dp, row+1, col);
        int right = solveMem(grid, dp, row, col+1);

        dp[row][col] = grid[row][col] + min(down, right);                  //add current element (grid[row][col])
        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //step1 create dp vector
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solveMem(grid, dp, 0, 0);                   //0 = row, 0 = col
    }
};
/*
Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/


//144. UNIQUE PATHS II                                                     {T.C = O(N*M), S.C = O(N*M)}
/*
create 2D dp , intialize row , col and col = vector[0].size() in recursive call we have only 2 option (down(row+1) or right(col+1)) store ans and return
it (shows total ways)
handle extra base case if reach to bottom right return grid[row][col] && vector[row][col] == 1(obstacle) return 0
*/
class Solution {
public:
    int solveMem(vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp, int row, int col){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //base case
        if(row >= n || row < 0 || col >= m || col < 0 || obstacleGrid[row][col] == 1){  //boundary cases
            return 0;
        }
        if(row == n-1 && col == m-1){              //reached required position
            return 1;
        }

        //step3 if ans already present return it
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        //step2 recursive call
        int down = solveMem(obstacleGrid, dp, row+1, col);
        int right = solveMem(obstacleGrid, dp, row, col+1);

        dp[row][col] = down + right;                                         //total ways
        return dp[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solveMem(obstacleGrid, dp, 0, 0);                //0 = row, 0 = col, 0 = count
    }
};
/*
Example 1:
Input: obstacleGrid = [[0,0,0],
                       [0,1,0],
                       [0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],
                       [0,0]]
Output: 1
*/


//145. LONGEST PALINDROMIC SUBSTRING
/*
Recursive approach                                                        {T.C = O(EXP), S.C = O(1)}
*/
class Solution {
public:
    bool solveMem(string &s, int i, int j){
        //base case
        if(i >= j){                       //i crosses j (palindrome)               
            return true;
        }

        if(s[i] == s[j]){
            return solveMem(s, i+1, j-1);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = INT_MIN;
        int startPoint = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(solveMem(s, i, j) == true){
                    if(j-i+1 > maxi){
                        maxi = j-i+1;
                        startPoint = i;
                    }
                }
            }
        }
        return s.substr(startPoint, maxi);             //substring(starting point , lenght of substring)
    }
};
/*
Recursio + Memoization                                                       {T.C = O(N^2*M), S.C = O(N^2)}
using 2 for loop finding each char palindrome's length and update it , at the end return s.substr(startPoint, j-i+1{length of curr string})
*/
class Solution {
public:
    bool solveMem(string &s, vector<vector<int>>&dp, int i, int j){
        //base case
        if(i >= j){                       //i crosses j (palindrome)               
            return 1;
        }
        
        //step3 if ans already present return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //step2 recursive call
        if(s[i] == s[j]){
            return dp[i][j] =  solveMem(s, dp, i+1, j-1);
        }
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = INT_MIN;
        int startPoint = 0;

        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(solveMem(s, dp, i, j) == true){
                    if(j-i+1 > maxi){
                        maxi = j-i+1;
                        startPoint = i;
                    }
                }
            }
        }
        return s.substr(startPoint, maxi);             //substring(starting point , lenght of substring)
    }
};
/*
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/


//146. INTERLEAVING STRING                                                {T.C = O(m*n*N), S.C = O(m*n*N)}
/*
Using 3D dp match each char of s1 and s2 with s3 , if char match move the particular index of matching string and s3 string , base case
if all index exhaust simultaneously then true, m+n != N gives false.
*/
class Solution {
public:
    bool solveMem(string &s1, string&s2, string&s3, vector<vector<vector<int>>>&dp, int i, int j, int k){
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        //base case
        if(m+n != N){                      //s3 = s1 + s2
            return false;
        }
        if(i == m && j == n && k == N){     //all strings exhaust simultaneously
            return true;
        }
        if(k >= N){                          // If 's3' is fully processed but 's1' and 's2' are not fully interleaved
            return false;
        }

        //step3 if ans already present return it
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        //step2 recursive call
        bool ans1 = false; 
        bool ans2 = false;
        if(s1[i] == s3[k]){                   //if s1 char match with s3 char, move i and k both
            ans1 = solveMem(s1, s2, s3, dp, i+1, j, k+1);
        }
        if(s2[j] == s3[k]){                   //if s2 char match with s3 char, move j and k both
            ans2 = solveMem(s1, s2, s3, dp, i, j+1, k+1);
        }

        return dp[i][j][k] = ans1 || ans2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1,vector<int>(N+1, -1) ));
        return solveMem(s1, s2, s3, dp, 0, 0, 0);          //0 = initial index of each string
    }
};
/*
Slightly Optimized Code                                                {T.C = O(M*N), S.C = O(M*N)}
we dont need to keep track of k we can use k => i+j all other is same and use 2D dp instead of 3D dp
*/
class Solution {
public:
    bool solveMem(string &s1, string&s2, string&s3, vector<vector<int>>&dp, int i, int j){
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        //base case
        if(m+n != N){                      //s3 = s1 + s2
            return false;
        }
        if(i == m && j == n && i+j == N){     //all strings exhaust simultaneously
            return true;
        }
        if(i+j >= N){                          // If 's3' is fully processed but 's1' and 's2' are not fully interleaved
            return false;
        }

        //step3 if ans already present return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //step2 recursive call
        bool ans1 = false; 
        bool ans2 = false;
        if(s1[i] == s3[i+j]){                   //if s1 char match with s3 char, move i 
            ans1 = solveMem(s1, s2, s3, dp, i+1, j);
        }
        if(s2[j] == s3[i+j]){                   //if s2 char match with s3 char, move j 
            ans2 = solveMem(s1, s2, s3, dp, i, j+1);
        }

        return dp[i][j] = ans1 || ans2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solveMem(s1, s2, s3, dp, 0, 0);          //0 = initial index of string s1 and s2
    }
};
/*
Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
*/


//147. EDIT DISTANCE                                                      {T.C = O(N*M), S.C = O(N*M)}
/*
First check base cases then if word1[i] == word[j] then move both pointers else perform insert(i, j+1{add}),
delete(i+1{skip}, j), replace operations(i+1, j+1).
*/
class Solution {
public:
    int solveMem(string &word1, string &word2, vector<vector<int>>& dp, int i, int j) {
        int m = word1.length();
        int n = word2.length();

        // Base case
        if (i == m) {                      //string1 is fully traversed now rest(n-j length is ans)
            return n - j;
        }
        if (j == n) {                      //string2 is fully traversed now rest(m-i length is ans)
            return m - i;
        }

        // If answer already present, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;
        // Recursive call
        if (word1[i] == word2[j]) {
            mini = solveMem(word1, word2, dp, i + 1, j + 1);
        } else { // Min of insert, delete, replace
            int insertOp = solveMem(word1, word2, dp, i, j + 1);   //It increments the index j of word2 while keeping the index i of word1 the same
            int deleteOp = solveMem(word1, word2, dp, i + 1, j);   //It increments the index i of word1 while keeping the index j of word2 the same
            int replacOp = solveMem(word1, word2, dp, i + 1, j + 1);//It increments the index i of word1 as well as index j of word2

            mini = 1 + min({insertOp, deleteOp, replacOp});
        }

        return dp[i][j] = mini;
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // Create dp vector
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solveMem(word1, word2, dp, 0, 0);
    }
};
/*
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/


//148, 149. BUY AND SELL STOCKS PROBLEMS (ALL TYPES)
//1. BUY ON ONE DAY SELL ON ANOTHER DAY                                       {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxPft = 0;

        for(int i = 1 ; i < prices.size() ; i++){
            int profit = prices[i] - mini;
            maxPft = max(maxPft, profit);
            mini = min(mini, prices[i]);                //for updating mini element
        }
        return maxPft;
    }
};
/*
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/


//2. BUY/SELL ON SAME DAY WITH HOLIDING ATMOST 1 STOCK AT A TIME             {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int solveMem(vector<int>&prices, int idx, int buy, vector<vector<int>>&dp){
        //base case
        if(idx == prices.size()){
            return 0;
        }
        
        //step3 if answer exist return it
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        int profit = 0;
        if(buy){          //buy == 1  allowed
            int buyKaro = -prices[idx] + solveMem(prices, idx+1, 0, dp);        //0 for next buy / buy not allowed 
            int skipKaro = 0 + solveMem(prices, idx+1, 1, dp);
            profit = max(buyKaro, skipKaro);
        }else{            //buy == 0   not allowed
            int sellKaro = +prices[idx] + solveMem(prices, idx+1, 1, dp);       //1 for next buy / buy allowed
            int skipKaro = 0 + solveMem(prices, idx+1, 0, dp);
            profit = max(sellKaro, skipKaro);
        }

        //step2 store ans in dp
        dp[idx][buy] = profit;
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n =  prices.size();
        //step1 create a dp vector
        vector<vector<int>>dp(n, vector<int>(2, -1));          //col = 0 or 1
        return solveMem(prices, 0, 1, dp);                     //0 = index, 1 = buy(allowed{bool value})
    }
};


//3. BUY/SELL ON SAME DAY WITH HOLIDING ATMOST 2 STOCK AT A TIME             {T.C = O(N), S.C = O(N)}
//RECURSION + MEMOIZATION
class Solution {
public:
    int solveMem(vector<int>&prices, int index, int buy, int limit ,vector<vector<vector<int>>>&dp){
        //base case
        int n = prices.size();
        if(index == n || limit == 0){
            return 0;
        }

        //step-3 if ans already present print it
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }

        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(prices, index+1, 0, limit, dp);
            int skipKaro = 0 + solveMem(prices, index+1, 1, limit, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solveMem(prices, index+1, 1, limit-1, dp);
            int skipKaro = 0 + solveMem(prices, index+1, 0, limit, dp);
            profit = max(sellKaro , skipKaro);
        }

        //step-2 store ans in dp
        dp[index][buy][limit] = profit;
        return dp[index][buy][limit];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //step-1 create dp vector
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2, vector<int>(3, -1)));      //row = n , col = 2  , entry (limit) = 3 (at most 2 = 0 , 1 , 2)
        return solveMem(prices, 0, 1, 2, dp);                  //index = 0 , buy = 1, limit = 2
    }
};
/*
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
*/


//4. BUY/SELL ON SAME DAY WITH HOLIDING ATMOST K(TRANSACTION) STOCK AT A TIME             {T.C = O(N*K), S.C = O(N*K)}
//RECURSION + MEMOIZATION
class Solution {
public:
    int solveMem(vector<int>&prices, int index, int operationNo, int k , vector<vector<int>>&dp){
        int n = prices.size();
        if(index == n || operationNo == 2*k){
            return 0;
        }
        
        //step-3 if ans already present return it
        if(dp[index][operationNo] != -1){
            return dp[index][operationNo];
        }
        int profit = 0;
        if(operationNo % 2 == 0){                            //even = buy allow
            int buyKaro = -prices[index] + solveMem(prices, index+1, operationNo+1, k, dp);
            int skipKaro = 0 + solveMem(prices, index+1, operationNo, k, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{                                                //odd = sell allow
            int sellKaro = +prices[index] + solveMem(prices, index+1, operationNo+1, k, dp);
            int skipKaro = 0 + solveMem(prices, index+1, operationNo , k, dp);
            profit = max(sellKaro, skipKaro);
        }

        //step-2 store ans in dp
        dp[index][operationNo] = profit;
        return dp[index][operationNo];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //step-1 create dp vector
        vector<vector<int>>dp(n, vector<int>(2*k, -1));             //col = operation = 2*k
        return solveMem(prices, 0, 0, k, dp);                         //index = 0, operationNo = 0
    }
};
/*
Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/


//5. BEST TIME TO BUY AND SELL STOCK WITH COOLDOWN                     {T.C = O(N), S.C = O(N)}
/*
Use simple recursion + memoization function code and take bool buy(true) variable and initial index(0), in solveMem func
if(buy == true) then we have two choice buy(mark next buy{false} and i+1) or skip(mark as it is true and i+1) similarly for
if(buy != false(sell)) then we have 2 choice sell(mark next buy true and i+2{cooldown period}) or skip(mark next buy false and i+1) store
max value of both and return it. 
*/
class Solution {
public:
    int solveMem(vector<int>&prices, vector<vector<int>>&dp, bool buy, int i){
        //base case
        if(i >= prices.size()){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int ans = 0;
        if(buy){
            int buyKaro = -prices[i] + solveMem(prices, dp, false, i+1);    //SP-CP = PROFIT {-CP + SP = PROFIT}
            int skipKaro = 0 + solveMem(prices, dp, true, i+1);
            ans = max(buyKaro, skipKaro);
        }else{  //sell
            int sellKaro = +prices[i] + solveMem(prices, dp, true, i+2);       //cooldown period (i+2)
            int skipKaro = 0 + solveMem(prices, dp, false, i+1);
            ans = max(sellKaro, skipKaro);
        }

        //step2 store ans in dp
        dp[i][buy] = ans;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solveMem(prices, dp, true, 0);               //0 = initial index
    }
};
/*
Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0
*/


//6. BEST TIME TO BUY AND SELL STOCK WITH TRANSACTION FEE                {T.C = O(N), S.C = O(N)}
/*
Use simple recursion + memoization function code and take bool buy(true) variable and initial index(0), in solveMem func
if(buy == true) then we have two choice buy(mark next buy{false} and i+1) or skip(mark as it is true and i+1) similarly for
if(buy != false(sell)) then we have 2 choice sell(mark next buy true and i+1) - fee(reduces after selling) 
or skip(mark next buy false and i+1) store max value of both and return it. 
*/
class Solution {
public:
    int solveMem(vector<int>&prices, int fee, vector<vector<int>>&dp, bool buy, int i){
        //base case
        if(i >= prices.size()){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int ans = 0;
        if(buy){
            int buyKaro = - prices[i] + solveMem(prices, fee, dp, false, i+1);    //after buying totalPrice will reduce
            int skipKaro = 0 + solveMem(prices, fee, dp, true, i+1);
            ans = max(buyKaro, skipKaro);
        }else{   //sell
            int sellKaro = +prices[i] + solveMem(prices, fee, dp, true, i+1) - fee; //after selling totalPrice will increase with pay(minus) small fee
            int skipKaro = 0 + solveMem(prices, fee, dp, false, i+1);
            ans = max(sellKaro, skipKaro);
        }

        //step2 store ans in dp
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));    //{fee, buy}  // col(2) is always fixed
        return solveMem(prices, fee, dp, true, 0);             //true = buy(first), 0 = initial index
    }
};
/*
Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
*/


//150. MAXIMAL SQUARE                                                {T.C = O(N*M), S.C = O(N*M)}
/*
traverse the matrix and move right, down, diag find min ways for finding square then choose square which include max 1's
*/
class Solution {
public:
    int solveMem(vector<vector<char>>&matrix, vector<vector<int>>&dp,int &maxi, int row, int col){
        int n = matrix.size();
        int m = matrix[0].size();
        //base case
        if(row >= n || col >= m){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        //step2 recursive call
        int right = solveMem(matrix, dp, maxi, row, col+1);
        int down = solveMem(matrix, dp, maxi, row+1, col);
        int diag = solveMem(matrix, dp, maxi, row+1, col+1);

        if(matrix[row][col] == '1'){
            dp[row][col] = 1 + min({right, down, diag});    //These positions represent the three directions that can extend the square containing '1's. Adding 1 represents the current cell itself, making it a square.
            maxi = max(maxi, dp[row][col]);
            return dp[row][col];
        }

        return 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        solveMem(matrix, dp, maxi, 0, 0);                    //0 = row, 0 = col

        return maxi*maxi;                                    //area = maxi * maxi

    }
};
/*
Example 1:
Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],
                 ["1","0"]]
Output: 1
*/