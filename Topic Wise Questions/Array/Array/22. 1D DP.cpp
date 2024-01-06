//1D DP (DYNAMIC PROGRAMMING)
#include<bits/stdc++.h>
using namespace std;

//137. CLIMBING STAIRS                                                     {T.C = O(N), S.C = O(N)}
/*
simply use dp with memoization handle base case then if dp have already ans then return it then call for dp with n-1 and n-2 steps and add it.
*/
class Solution {
public:
    int solveMem(vector<int>&dp, int n){
        //base case
        if(n == 0 || n == 1){           //for 0 and 1 we have 1 step only
            return 1;
        }

        //step3 if ans already present return it
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 recursive call
        dp[n] = solveMem(dp, n-1) + solveMem(dp, n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        //step1 create a dp vector 
        vector<int>dp(n+1, -1);
        return solveMem(dp, n);
    }
};
/*
Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/


//138. HOUSE ROBBER                                                     {T.C =  O(N), S.C = O(N)}
/*
we have to traverse from the last to find rob when adjacent element is include and exclude and return max of it by storing in dp
*/
class Solution {
public:
    int solveMem(vector<int>&nums,int n, vector<int>&dp){
        //base case
        if(n < 0){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 recursive call
        int incl = nums[n] + solveMem(nums,n-2, dp);         //adjacent element cant include
        int excl = 0 + solveMem(nums, n-1, dp);

        dp[n] = max(incl, excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //step1 create a dp vector
        vector<int>dp(n+1, -1);
        return solveMem(nums, n-1, dp);                      //traverse from last element (n-1)
    }
};
/*
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/


//139. WORD BREAK                                                         {T.C = O(N*M{size of string}), S.C = O(N)}
/*
first we store all dictionary words in a unordered set then solve with recursion + memoization , first check base case if index = s.size()
return true, then if ans already present return it , then we take temp string and iterate string S and put 1 by 1 char in this temp simultaneously
match the word (temp) with set and increase current index.
*/
class Solution {
public:
    bool solveMem(int index , string s, unordered_set<string>&st, vector<int>&dp){
        //base case
        if(index == s.size()){
            return true;
        }

        //step3 if ans already present return it
        if(dp[index] != -1){
            return dp[index];
        }

        //step2 recursive call
        string temp;
        for(int i = index ; i < s.size() ; i++){
            temp += s[i];
            if(st.find(temp) != st.end()){
                if(solveMem(i+1, s, st, dp)){
                    return dp[index] = true;
                }
            }
        }
        dp[index] = false;
        return dp[index];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        int n = s.size();
        //step1 create a dp vector
        vector<int>dp(n+1, -1);
        for(auto it : wordDict){
            st.insert(it);
        }
        return solveMem(0, s, st, dp);            //0 = initial index
    }
};
/*
Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/


//140a. COIN CHANGE
/*
{T.C = O(EXP), S.C = O(1)}
Brute force = using simple recursion handle base case , initialize ans with INT_MAX(finding minimum ans) iterate through coins , if 
amount-coins[i] >= 0 make recursive call and return min ans.
*/
class Solution {
public:
    int solve(vector<int>&coins, int amount){
        //base case
        if(amount == 0){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = 0 ; i < coins.size() ; i++){
            if(amount-coins[i] >= 0){
                // ans = min(ans, solve(coins, amount-coins[i])+1);
                ans = min(ans + 0LL, solve(coins, amount-coins[i])+1LL); //LL for handle overflow

            }
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
Recursion + Memoization
new way of using dp
*/
class Solution {
public:
    int dp[10010];                                                           //1
    int solve(vector<int>&coins, int amount){
        //base case
        if(amount == 0){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[amount] != -1){                                                //2
            return dp[amount];
        }

        //step2 recursive call
        int ans = INT_MAX;
        for(int i = 0 ; i < coins.size() ; i++){
            if(amount-coins[i] >= 0){
                // ans = min(ans, solve(coins, amount-coins[i])+1);
                ans = min(ans + 0LL, solve(coins, amount-coins[i])+1LL); //LL for handle overflow

            }
        }
        return dp[amount] = ans;                                             //3
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));                                          //4
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
general way
*/
class Solution {
public:
    int solve(vector<int>&coins, int amount, vector<int>&dp){
        //base case
        if(amount == 0){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[amount] != -1){
            return dp[amount];
        }

        //step2 recursive call
        int ans = INT_MAX;
        for(int i = 0 ; i < coins.size() ; i++){
            if(amount-coins[i] >= 0){
                // ans = min(ans, solve(coins, amount-coins[i])+1);
                ans = min(ans + 0LL, solve(coins, amount-coins[i], dp)+1LL); //LL for handle overflow

            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        //step1 create a dp vector
        vector<int>dp(amount+1, -1);                                             //the changing variable is amount not coins
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
*/


//140b. COIN CHANGE II                                                      {T.C = O(N), S.C = O(N*N)}
/*
use recursion + memoization , use 2D dp changing(index, amount) 
*/
class Solution {
public:
    int solveMem(vector<int>&coins, int amount, vector<vector<int>>&dp, int index){
        //base case
        if(amount == 0){            //if amount 0 means nothing take (1 possible nothing take way)
            return 1;                 
        }
        if(amount < 0 || index >= coins.size()){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        //step2 recursive call
        int incl = solveMem(coins, amount-coins[index], dp, index);        //keeping index same , we can use the coin again.
        int excl = solveMem(coins, amount , dp, index+1);

        dp[index][amount] = incl + excl;                      //total ways (incl + excl)
        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return solveMem(coins, amount, dp, 0);                 //0 = initial index
    }
};
/*
Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
*/


//141. LONGEST INCREASING SUBSEQUENCE                                           {T.C = O(N*LOGN), S.C = O(N)}
/*
use binary search for optimization 
*/
class Solution {
public:
    int solveOptimal(vector<int>&nums, int n){
        //base case
        if(n == 0){
            return 0;
        }
        
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i = 1 ; i < n ; i++){            //from second element(index = 1)
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                //find index of just big element
                int index = lower_bound(ans.begin(), ans.end() , nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solveOptimal(nums, n);       
    }
};
/*
Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/