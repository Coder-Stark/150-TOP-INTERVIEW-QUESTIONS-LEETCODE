//150 TOP INTERVIEW QUESTIONS (LEETCODE)
#include<bits/stdc++.h>
using namespace std;


//01. MERGE SORTED ARRAY                                                           {T.C = O(N), S.C = O(1)}
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = n+m-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];             //first fill last index(greater element)
                k--, i--;
            }else{
                nums1[k] = nums2[j];
                k--, j--;
            }
        }
        while(i >= 0){
            nums1[k] = nums1[i];
            k--, i--;
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            k--, j--;
        }
    }
};
/*
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
*/


//02. REMOVE ELEMENT                                                           {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != val){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};
/*
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/


//03. REMOVE DUPLICATES FROM SORTED ARRAY                                            {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[count-1]){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};
/*
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/


//04. REMOVE DUPLICATES FROM SORTED ARRAY II                                {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 2;
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        for(int i = 2 ; i < n ; i++){
            if(nums[i] != nums[count-2]){
                nums[count] = nums[i];
                count++;
            }

        }
        return count;
    }
};
/*
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/


//05. MAJORITY ELEMENT
//BRUTE FORCE (HASHMAP)                                                      {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        int x = n/2;
        for(auto it : mp){
            if(it.second > x){
                return it.first;
            }
        }
        return -1;
    }
};

//OPTIMIZED APPROACH
//MOORE VOTING ALGORITHM                                                         {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = 0;

        for(auto it : nums){
            if(count == 0){
                element = it;
            }
            if(it == element){
                count++;
            }else{
                count--;
            }
        }
        return element;
    }
};
/*
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/


//06. ROTATE ARRAY
//BRUTE FORCE                                                                  {T.C = O(N), S.C = O(N)}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k == 0){              //size = 0 or k = 0 / same index do nothing
            return;
        }
        vector<int>rotatedArray(n);
        k = k % n ;                        //if k > n then take modulo to match index
        for(int i = 0 ; i < n ; i++){
            rotatedArray[(i+k) % n] = nums[i];
        }
        nums = rotatedArray;              //copy vector in ans
    }
};

//OPTIMIZED APPROACH                                                        {T.C = O(N), S.C = O(1)}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;                         //if k > n then modulo for match index
                                                    //example 123456 , k = 3 => 456123
        reverse(nums.begin(), nums.begin()+(n-k));  //321456        
        reverse(nums.begin()+(n-k), nums.end());    //321654
        reverse(nums.begin(), nums.end());          //456123
    }
};
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/


//07. BEST TIME TO BUY AND SELL STOCK                                                   {T.C = O(N), S.C = O(1)}
//SINGLE DAY BUY AND SELL ON ANOTHER DAY
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
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/


//08. BEST TIME TO BUY AND SELL STOCK II                                           {T.C = O(N), S.C = O(1)}
//BUY AND SELL ON SINGLE DAY WITH ATMOST 1 HOLD
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
/*
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/


//09. JUMP GAME                                                                    {T.C = O(N), S.C = O(1)}
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int far = 0;                         //max jump from a curr index
        int curr = 0;                        //first index
        // int jumps = 0;

        for(int i = 0 ; i < n-1; i++){       //check till second last index
            far = max(far, i + nums[i]);
            if(curr == i){
                // jumps++;
                curr = far;
            }
        }
        if(curr < n-1){                     //coudnt reach to last index
            return false;
        }
        return true;                        //return jumps
    }
};
/*
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/


//10. JUMP GAME II                                                          {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int far = 0;                     //dist cover from curr index
        int curr = 0;
        int jumps = 0;
        

        for(int i = 0 ; i < n-1 ; i++){    //check till second last index
            far = max(far, i + nums[i]);
            if(curr == i){
                jumps++;
                curr = far;
            }
        }
        if(curr < n-1){
            return -1;
        }
        return jumps;
    }
};
/*
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/


//11. H-INDEX                                                                  {T.C = O(N*LOGN), S.C = O(1)}
//BRUTE FORCE(WORKING SOLUTION)
class Solution {
public:
/* h value for a particular index will be mininmum value of the difference between the total number of publications and i th index and number of number of citations of the ith index.*/
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, min(citations[i], (n-i)) );          
        }
        return ans;
    }
};

//OPTIMIZED APPROACH
//BUCKET SORT(FREQUENCY ARRAY)                                                  {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>bucket(n+1);

        for(int i = 0 ; i < n ; i++){
            if(citations[i] >= n){
                bucket[n]++;
            }else{
                bucket[citations[i]]++;
            }
        }

        int count = 0;
        for(int i = n ; i >= 0 ; i--){
            count += bucket[i];
            if(count >= i){
                return i;
            }
        }
        return 0;
    }
};
/*
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
*/


//12. INSERT DELETE GETRANDOM O(1)
class RandomizedSet {
    vector<int>v;                              //to store index
    unordered_map<int, int>mp;                      //<value, index>
public:
    RandomizedSet() {
        //no need
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }
        //insert it in a array/vector
        v.push_back(val);
        mp[val] = v.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)){                     //val not present in mp
            return false;
        }

        mp[v.back()] = mp[val];
        swap(v.back(), v[mp[val]]);
        v.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        return v[rand()% v.size()];
    }
};
/*
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
*/


//13. PRODUCT OF ARRAY EXCEPT ITSELF
//BRUTE FORCE APPROACH (NOT WORKING)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1);
        int totalProduct = 1;
        for(int i = 0 ; i < n; i++){
            totalProduct *= nums[i];
        }

        ans[0] = totalProduct/nums[0];
        for(int i = 1 ; i <= n ; i++){
            ans[i] = totalProduct/nums[i];
        }
        return ans;
    }
};
//OPTIMIZED APPROACH                                                               {T.C = O(N), S.C = O(1)/EXCEPT ANS}
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1);
        int leftProd = 1;                                //prefix
        for(int i = 0 ; i < n ; i++){
            ans[i] *= leftProd;
            leftProd *= nums[i];
            
        }
        int rightProd = 1;                              //suffix
        for(int i = n-1 ; i >= 0 ; i--){
            ans[i] *= rightProd;
            rightProd *= nums[i];
        }
        return ans;
    }
};
/*
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/


//14. GAS STATION                                                               {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalDiff = 0, n = gas.size(), fuel= 0, index = 0; // or cost.size() both same
        for(int i = 0 ; i < n ; i++){
            int diff = gas[i]-cost[i];
            totalDiff += diff;
            fuel += diff;
            if(fuel < 0){               //for next search
                index = i+1;
                fuel = 0;
            }
        }
        return totalDiff < 0 ? -1 : index;
    }
};
/*
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
*/


//15. CANDY                                                                    {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1){
            return n;
        }
        vector<int>ans(n, 1);
        //left traversal
        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1] + 1;
            }
        }
        //right traversal
        for(int i = n-1 ; i > 0 ; i--){
            if(ratings[i] < ratings[i-1]){
                ans[i-1] = max(ans[i] + 1, ans[i-1]);         //compares both cases 
            }
        }
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            res += ans[i];
        }
        return res;
    }
};
/*
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
*/


//16. TRAPPING RAIN WATER                                                        {T.C = O(N), S.C =  O(1)}
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, leftMax = 0, rightMax = 0;
        int res = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > leftMax){
                    leftMax = height[left];
                }else{
                    res += leftMax - height[left];
                }
                left++;
            }else{
                if(height[right] > rightMax){
                    rightMax = height[right];
                }else{
                    res += rightMax - height[right];
                }
                right--;
            }
        }
        return res;
    }
};
/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
*/


//21. REVERSE WORDS IN A STRING                                                 {T.C = O(N^2), S.C = O(N)}
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;
        int i = 0;
        while(i < n){
            while(i < n && s[i] == ' '){               //continue beginning spaces
                i++;
            }
            if(i >= n){
                break;
            }
            int j = i+1;                              //just next space's word
            while(j < n && s[j] != ' '){              //word encounter
                j++;
            }
            string sub = s.substr(i, j-i);            //find substring = substr(initial, lenght (substring))
            if(ans.empty()){
                ans = sub;
            }else{
                ans = sub + " " + ans;                //reverse push 
            }
            i = j+1;
        }
        return ans;
    }
};
/*
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
*/


//22. ZIGZAG CONVERSION                                                        {T.C = O(N), S.C = O(N)}
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows);                      //for storing pattern
        if(numRows == 1){
            return s;
        }
        bool flag = false;
        int i = 0;
        for(auto ch : s){
            ans[i] += ch;
            if(i == 0 || i == numRows-1){                 //switching direction up <-> down
                flag = !flag;
            }
            if(flag){
                i++;
            }else{
                i--;
            }
        }
        string zigzag = "";
        // for(int i = 0 ; i < ans.size() ; i++){
        //     zigzag += ans[i];
        // }
        for(auto it : ans){
            zigzag += it;
        }
        return zigzag;
    }
};
/*
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/


//23. FIND THE INDEX OF THE FIRST OCCURANCE IN A STRING
//BRUTE FORCE (STL)
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

//WITHOUT STL APPROACH                                                             {T.C = O(N), S.C = O(M)}
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        for(int i = 0 ; i < n-m+1 ; i++){              //no need to till last, check till from that where a valid substr can be made
            if(haystack[i] == needle[0]){
                string sub = haystack.substr(i, needle.length());     //substr(initial, length)
                if(sub == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};
/*
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/


//24. TEXT JUSTIFICATION                                                          {T.C = O(N), S.C = O(N)}
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n = words.size();
        int i = 0;
        while(i < n){
            int lineLen = words[i].size();
            int j = i+1;
            while(j < n && lineLen + words[j].size() + (j-i) <= maxWidth){          //keep adding words untill line exceeds maxWidth
                lineLen += words[j].size();
                j++;
            }
            int numOfWords = j-i;
            int numOfSpace = maxWidth - lineLen;
            //for constructing justified line
            string line;
            //handle only 1 word or last word
            if(numOfWords == 1 || j == n){
                line = words[i];
                for(int k = i+1 ; k < j ; k++){
                    line += ' ' + words[k];
                }
                line += string(maxWidth-line.size(), ' ');    // Add spaces to reach maxWidth.
            }else{
                int spaceBwWords = numOfSpace / (numOfWords - 1);
                int extraSpace = numOfSpace % (numOfWords-1);

                line = words[i];
                for(int k = i+1; k < j ; k++){
                    line += string(spaceBwWords, ' ');
                    if(extraSpace > 0){
                        line += ' ';                         // Add extra space if available.
                        extraSpace--;
                    }
                    line += words[k];
                }
            }
            ans.push_back(line);
            i = j;                                          // Move to the next set of words.
        }
        return ans;
    }
};
/*
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
*/


//25. VALID PALINDROME 
//BRUTE FORCE APPROACH                                                                     {T.C = O(N), S.C = O(N)}
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string ans;
        for(int i = 0 ; i < n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = tolower(s[i]);
            }
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                ans += s[i];
            }else{
                continue;
            }
        }
        int m = ans.size();
        for(int i = 0 ; i < m/2; i++){
            if(ans[i] != ans[(m-1)-i]){
                return false;
            }
        }
        return true;
    }
};

//USING TWO POINTERS                                                         {T.C = O(N), S.C = O(1)}
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(!isalnum(s[i])){
                i++;
            }
            else if(!isalnum(s[j])){
                j--;
            }else{
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return true;
    }
};
/*
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/


//26. IS SUBSEQUENCE                                                                {T.C = O(N), S.C = O(N)}
class Solution {
public:
    bool isSubsequence(string s, string t) {
        string ans;
        int i = 0;
        int k = 0;
        int n = t.size();
        int m = s.size();
        while(k < n && i < m){
            if(s[i] == t[k]){
                ans += s[i];
                i++;
            }
            k++;
        }
        // if(ans == s){
        //     return true;
        // }
        // return false;
        return ans == s;
    }
};

//OPTIMIZED APPROACH                                                             {T.C = O(N), S.C = O(1)}
class Solution {
public:
    bool isSubsequence(string s, string t) {
        string ans;
        int i = 0;
        int k = 0;
        int n = t.size();
        int m = s.size();
        while(k < n && i < m){
            if(s[i] == t[k]){
                i++;
            }
            k++;
        }
        return i == s.size();
    }
};
/*
Input: s = "abc", t = "ahbgdc"
Output: true
*/


//27. TWO SUM II - INPUT ARRAY IS SORTED
//BRUTE FORCE                                                                   {T.C = O(N^2), S.C = O(N^2)}
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int sum = numbers[i] + numbers[j];
                if(sum == target){
                    return {i+1, j+1};                 //for 1 based indexing
                }
            }
        }
        return {};                                     //if answer not found
    }
};

//OPTIMIZED APPROACH                                                                {T.C = O(N), S.C = O(1)}
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;

        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                return {i+1, j+1};
            }else if(sum < target){
                i++;
            }else{
                j--;
            }
        }
        return {};                                        //if answer not found
    }
};
/*
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/


//28. CONTAINER WITH MOST WATER                                                  {T.C = O(N), S.C = O(1)}
//SIMILAR TO TRAPPING WATER BUT NOT SAME
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxWaterArea = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            int width = right-left;
            int currWaterArea = h * width; 
            maxWaterArea = max(maxWaterArea, currWaterArea);
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxWaterArea;
    }
};
/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/


//29. 3 SUM                                                                   {T.C = O(N^2), S.C = O(N^2)}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        set<vector<int>>s;                          //for storing unique value
        int l, r;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < n-2 ; i++){                                           //3 SUM = n-2 , 4 sum (2 for loop {n-3 then n-2})
            l = i+1;
            r = n-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};
/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/


//30.a SLIDING WINDOW MAXIMUM
//BRUTE FORCE  (TLE)                                                                     {T.C = O(N^2), S.C = O(N)}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0 ; i <= n-k ; i++){
            int maxi = INT_MIN;
            for(int j = i ; j < i+k ; j++){
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

//OPTIMIZED APPROACH USING DEQUEUE                                                 {T.C = O(N), S.C = O(N)}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;                        //store ans in decreasing order
        //for first window
        for(int i = 0 ; i < k ; i++){
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        //for all next windows
        for(int i = k ; i < n ; i++){
            //remove previous element
            if(dq.front() == nums[i-k]){
                dq.pop_front();
            }

            //same as above
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());                  //push all top elements
        }
        return ans;
    }
};
/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 */


//30. MINIMUM SIZE SUBARRAY SUM                                                   {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int mini = INT_MAX;                          //lenght of window
        while(j < n){
            sum += nums[j];                          //calculation
            while(sum >= target){
                mini = min(mini, j-i+1);             //calculation
                sum -= nums[i];                      //slide window
                i++;
            }
            j++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};
/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/


//31.  LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS                         {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int maxi = 0;
        unordered_set<char>unSt;                 //for store unique element
        while(j < n){
            if(unSt.count(s[j]) == 0){
                unSt.insert(s[j]);
                maxi = max(maxi, j-i+1);         //max size window
                j++;
            }else{ //st.count(st[j] != 0)
                while(unSt.count(s[j]) != 0){
                    unSt.erase(s[i]);
                    i++;
                }
            }
        }
        return maxi;
    }
};
/*
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


//32. SUBSTRING WITH CONCATENATION OF ALL WORDS                                      {T.C = O(N*M), S.C = O(N)}
//COPY PASTE
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size();   // Number of words
        int m = words[0].size(); // Length of each word
        int len = n * m;        // Total length of all words
        unordered_map<string, int> mp;

        // Count the frequency of each word
        for (const string& word : words) {
            mp[word]++;
        }

        if (len > s.size()) {
            return ans;
        }

        for (int i = 0; i < m; i++) {
            unordered_map<string, int> mp2;
            int left = i;

            for (int j = i; j <= s.size() - m; j += m) { // Changed i to j here
                string temp = s.substr(j, m);

                if (mp.find(temp) != mp.end()) {
                    mp2[temp]++;
                    while (mp2[temp] > mp[temp]) {
                        mp2[s.substr(left, m)]--;
                        left += m;
                    }

                    if (j - left + m == len) {
                        ans.push_back(left);
                        mp2[s.substr(left, m)]--;
                        left += m;
                    }
                } else {
                    mp2.clear();
                    left = j + m;
                }
            }
        }
        return ans;
    }
};
/*
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.
*/


//33. MINIMUM WINDOW SUBSTRING                                                 {T.C = O(N), S.C = O(N)}
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minLen = INT_MAX;
        unordered_map<char, int>mp;                 //store small string chars in map
        for(auto it : t){
            mp[it]++;
        }
        int count = mp.size();
        int i = 0, j = 0, start = 0;
        while(j < n ){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count--;
                }
            }
            if(count == 0){                    //curr window contains all char of t
                while(count == 0){             //shrinking window
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                            if(j-i+1 < minLen){
                                minLen = j-i+1;
                                start = i;             //search for new window
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        return minLen == INT_MAX ? "": s.substr(start, minLen);
    }
};
/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/


//34. VALID SUDOKU                                                               {T.C = O(1), S.C = O(1)}
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for(int i = 0 ; i < 9 ; i++){                    //i == row, j == col
            for(int j = 0 ; j < 9 ; j++){
                int boxIndex = (i/3)*3 + j/3;
                if(board[i][j] != '.'){
                    string row = "r" + to_string(i) + board[i][j];
                    string col = "c" + to_string(j) + board[i][j];
                    string box = "b" + to_string(boxIndex) + board[i][j];
                    //already string is present in set
                    if(st.count(row) || st.count(col) || st.count(box)){
                        return false;
                    }
                    st.insert(row);
                    st.insert(col);
                    st.insert(box);
                }
            }
        }
        return true;
    }
};
/*
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
*/


//35. SPIRAL MATRIX                                                            {T.C = O(N*M), S.C = O(N)}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int>ans;
        int r = matrix.size();
        int c = matrix[0].size();
        
        int left = 0;
        int right = c-1;                                   //r = mat.size() , c = mat[0].size();
        int top = 0;
        int bottom = r-1;
        
        //flow of traversal == right->bottom->left->top
        while(left <= right && top <= bottom){
            //right
            for(int i = left ; i <= right ; i++ ){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //bottom
            for(int i = top ; i <= bottom ; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //left
            if(top <= bottom){                                 //extra check
                for(int i = right ; i >= left ; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                
            }

            //top
            if(left <= right){                                  //extra check
                for(int i = bottom ; i >= top ; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
/*
Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/


//36. ROTATE IMAGE (90 DEGREE)                                                 {T.C = O(N^2), S.C = O(1)}
//APPROACH
// 1. TRANSPOSE MATRIX , 2. REVERSE ROWS ELEMENTS
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //transpose of matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){            //j from i not 0
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse each row
        for(int i = 0 ; i < n ; i++){
            int left = 0;
            int right = n-1;
            while(left < right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};
/*
Input: matrix = [[5,1,9,11]
                ,[2,4,8,10],
                 [13,3,6,7],
                 [15,14,12,16]]
Output: [[15,13,2,5]
       ,[14,3,4,1],
        [12,6,8,9],
        [16,7,10,11]]
*/


//37. SET MATRIX ZEROES
//APRROACH 1(BRUTE FORCE)                                                        {T.C = O(N^3), S.C = O(N^2)}
//use 2d matrix store ans in this then copy element in original matrix 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>vis = matrix;

        //row 0
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < n ; k++){
                        vis[k][j] = 0;
                    }
                }
            }
        }

        //col 0
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0 ; k < m ; k++){
                        vis[i][k] = 0;
                    }
                }
            }
        }

        //now copy visited matrix to actual matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = vis[i][j];
            }
        }
    }
};
//APPROACH 2(using 2 single vectors)                                              {T.C = O(N^2), S.C = O(N)}
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n+1, 0);
        vector<int>col(m+1, 0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(row[i] || col[j]){                //if row or col updated(to 1)
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//OPTIMIZED                                                                 {T.C = O(N^2), S.C = O(1)}
/*
Input: matrix = [
                 [1,1,1],
                 [1,0,1],
                 [1,1,1]
                ]
Output: [
         [1,0,1]
        ,[0,0,0],
         [1,0,1]
        ]
*/


//38. GAME OF LIFE                                                          {T.C = O(N*M), S.C = O(1)}
//APPROACH
//store all cordinates in array then check 4 cases according to quesiton
class Solution {
public:
    bool isValidNbr(int x, int y , vector<vector<int>>&board){
        return ( (x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size()) );
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        //all 8 coordinates
        int delRow[8] = {0, 1, 0, -1, 1, 1, -1, -1};
        int delCol[8] = {1, 0, -1, 0, -1, 1, 1, -1};

        for(int row = 0; row < n ; row++){
            for(int col = 0; col < m ; col++){
                int countNbr = 0;

                for(int i = 0 ; i < 8 ; i++){
                    int currRow = row + delRow[i];
                    int currCol = col + delCol[i];
                    
                    if(isValidNbr(currRow, currCol, board) && abs(board[currRow][currCol]) == 1){
                        countNbr++;
                    }
                }
                if(board[row][col] == 1 && (countNbr < 2 || countNbr > 3)){
                    board[row][col] = -1;
                }else if(board[row][col] == 0 && countNbr == 3){
                    board[row][col] = 2;
                }
            }
        } 

        for(int row = 0 ; row < n ; row++){
            for(int col = 0; col < m ; col++){
                if(board[row][col] >= 1){
                    board[row][col] = 1;
                }else{
                    board[row][col] = 0;
                }
            }
        }       
    }
};
/*
Input: board = [
                [0,1,0],
                [0,0,1],
                [1,1,1],
                [0,0,0]
               ]
Output: [ 
         [0,0,0],
         [1,0,1],
         [0,1,1],
         [0,1,0]
        ]
*/


//39. RANSOME NOTE
//APPROACH 1
//USING UNORDERED MAP / HASH MAP                                       {T.C = O(N), S.C = O(N)}
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp;
        for(auto ch : magazine){
            mp[ch]++;
        }
        for(auto ch : ransomNote){
            if(mp.find(ch) != mp.end() && mp[ch] > 0){
                mp[ch]--;                      // Decrement the count of the character
            } else {
                return false;                  // Not enough characters in the magazine
            }
        }
        return true;                           // All characters in ransomNote can be constructed
    }
};

//APPROACH 2(OPTIMIZED)
//using constant size vector                                          {T.C = O(N), S.C = O(1)}
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>v(26);

        for(auto ch : magazine){
            v[ch-97]++;
        }
        for(auto ch : ransomNote){
            v[ch-97]--;
        }
        
        for(auto it : v){
            if(it < 0){
                return false;
            }
        }
        return true;
    }
};
/*
Input: ransomNote = "aa", magazine = "aab"
Output: true
*/


//40. ISOMORPHIC STRINGS                                                         {T.C = O(N), S.C = O(N)}
//APPROACH
//first fill map (check already present char & replace char) then check correct mapping
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_set<int>st;

        //base case
        if(s.length() != t.length()){
            return false;
        }

        for(int i = 0 ; i < s.length() ; i++){
            if(mp.find(s[i]) == mp.end()){            //if original is not already present in map / fill map
                if(st.find(t[i]) == st.end()){        //replacement char also not present
                    mp[s[i]] = t[i];                  //mapping original->replacement
                    st.insert(t[i]);
                }else{
                    return false;
                }
            }else{  //mp.find(s[i] != mp.end())      //orginal is already present in map
                if(mp[s[i]] != t[i]){                //check valid mapping
                    return false;
                }                       
            } 
        }
        return true;
    }
};
/*
Input: s = "egg", t = "add"
Output: true
*/


//41. WORD PATTERN                                                                 {T.C = O(N+M), S.C = O(N+M)}
//APPROACH
//first divide long string into string array then map each char to string then check for valid mapping 
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        string temp = "";
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ' '){
                v.push_back(temp);
                temp = "";                            //reset temp string
            }else{
                temp += s[i];
            }
        }
        v.push_back(temp);

        //base case
        if(pattern.length() != v.size()){
            return false;
        }

        unordered_map<char ,string>mp;
        unordered_set<string>st;

        for(int i = 0 ; i < pattern.length() ; i++){
            if(mp.find(pattern[i]) == mp.end()){          //if original is not present in map
                if(st.find(v[i]) == st.end()){            //replace char(string) is also not present
                    mp[pattern[i]] = v[i];                //mapping pattern->s
                    st.insert(v[i]);                      
                }else{
                    return false;
                }
            }else{//mp.find(pattern[i]) != mp.end()       //if original is present in map
                if(mp[pattern[i]] != v[i]){               //check for valid mapping
                    return false;
                }
            }
        }
        return true;
    }
};
/*
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
*/


//42. VALID ANAGRAM                                    
//BRUTE FORCE                                                                  {T.C = O(N*LOGN), S.C = O(1)}
//sort both string then if string match return true else false
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//OPTIMIZED APPROACH                                                           {T.C = O(N), S.C = O(N)}
//using unordered map first store 1st string char in mp then remove according to second string if 
//mp char count is zero then true else false
class Solution {
public:
    bool isAnagram(string s, string t) {
        //base case
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int>mp;
        for(auto ch : s){
            mp[ch]++;
        }

        for(int i = 0 ; i < t.size() ; i++){
            mp[t[i]]--;
        }
        /*
        or
        for(auto ch : t){
            mp[ch]--;
        }
        */
        
        for(auto it : mp){                                   //traversal map for count each char
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};
/*
Input: s = "anagram", t = "nagaram"
Output: true
*/


//43. GROUP ANAGRAMS                                                         {T.C = O(N*M*LOGM), S.C = O(N*M)}
//APPROACH                                                                   
//create map (anagram, vector of anagram) sort the string then group all sorted anagram togther
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;               //{anagram, group of anagram}

        for(auto it : strs){
            string temp = it;
            sort(it.begin(), it.end());   
            mp[it].push_back(temp);                            //push all anagram together in 1 mapping
        }
        //put map's string vector(mp.second) into vector
        for(auto it : mp){
            ans.push_back(it.second);
        }   
        return ans;
    }
};
/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/


//44. TWO SUM 
//BRUTE FORCE APPROACH                                                          {T.C = O(N^2), S.C = O(1)}
//using 2 for loop iterate vector and return index
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1; j < n ; j++){
                if(nums[i]+nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//OPTIMIZED APPROACH                                                            {T.C = O(N), S.C = O(N)}
//using unordered map first store vector in map then find its complement is present or not if present just return 
//mp index of complement and original i index
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mp;

        //find the complement
        for(int i = 0 ; i < n  ; i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }
            mp[nums[i]] = i;                         //mapping complement->i
        }
        return {};
    }
};
/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/


//45. HAPPY NUMBER                                                               {T.C = O(LOGN), S.C = O(LOGN)}
//APPROACH
//run infinite loop store sum in set (unique elements only) if duplicate entry return false else find sum = 1 then true
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(true){                                         //infinite loop
            int sum = 0;
            while(n != 0){
                sum += pow(n%10 , 2);
                n = n/10;                                        //extract digit next operation on rest of digits
            }

            if(sum == 1){
                return true;
            }

            n = sum;               //update number
            if(st.find(n) != st.end()){                     //set have already present (infinit loop)
                return false;
            }
            st.insert(n);
        }
    }
};
/*
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/


//46. CONTAINS NUMBER II
//BRUTE FORCE                                                                    {T.C = O(N^2), S.C = O(1)}
//use 2 for loop and match condition(nums[i] == nums[j] and abs(i - j) <= k) according to question
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(nums[i] == nums[j] && abs(i-j) <= k){
                    return true;
                }
            }
        }
        return false;
    }
};

//OPTIMIZED APPROACH                                                            {T.C = O(N), S.C = O(N)}
//using unordered map 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0 ; i < n ; i++){
            if(mp.count(nums[i])){                            //duplicate element found
                if(abs(i-mp[nums[i]]) <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;                                   //mapping element with index
        }
        return false;
    }
};
/*
Input: nums = [1,2,3,1], k = 3
Output: true
*/


//47. LONGEST CONSECUTIVE SEQUENCE                                         {T.C = O(N), S.C = O(N)}
//APPROACH
//use set to store unique ans then search first for previous element if found then move forward if not then search
//for next consecutive  number 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;

        for(auto it : nums){
            st.insert(it);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(st.find(nums[i]-1) == st.end()){              //previous element not found
                int j = nums[i]+1;                           //next element
                while(st.find(j) != st.end()){               //search for next consecutive element
                    j++;
                }
                ans = max(ans, j-nums[i]);                    //longest consecutive length
            }
        }
        return ans;
    }
};
/*
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/


//48. SUMMARY RANGES                                                       {T.C = O(N), S.C = O(N)}
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;

        string temp = "";

        int i = 0, j = 0;
        for(i = 0 ; i < n ; i++){
            j = i;             //i is used to keep track of the beginning of a potential range, and j is used to find the end of that range while iterating through the consecutive numbers. 
            while(j + 1 < n && nums[j+1] == nums[j] + 1){
                j++;
            }
            if(j > i){
                temp += to_string(nums[i]);
                temp += "->";
                temp += to_string(nums[j]);
            }else{
                temp += to_string(nums[i]);
            }

            ans.push_back(temp);
            temp = "";
            i = j;                                       //move i to j for fresh start (next range)
        }
        return ans;
    }
};
/*
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
*/


//49. MERGE INTERVALS                                                                           {T.C = O(N*LOGN), S.C = O(N)}                                                      
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;                //stores final merged intervals ans
        //base case
        if(intervals.size() == 0){
            return ans;
        }
        //sort the intervals
        sort(intervals.begin(), intervals.end());
        vector<int>tempInterval = intervals[0];           //store temprory answer
        for(auto i : intervals){
            if(i[0] <= tempInterval[1]){
                tempInterval[1] = max(i[1], tempInterval[1]);
            }
            else{
                ans.push_back(tempInterval);
                tempInterval = i;
            }
        }
        ans.push_back(tempInterval);
        
        return ans;
    }
};
/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/


//50. INSERT INTERVALS                                                                       {T.C = O(N), S.C = O(N)}
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = intervals.size();
        int i = 0;

        //insert all intervals which is less then new interval in ans
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        //merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        //insert rest of element
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
/*
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/


//51. MINIMUM NUMBER OF ARROWS TO BURST BALLOONS                                                     {T.C = O(N*LOGN), S.C = O(1)}
bool comp(vector<int>&a, vector<int>&b){
    return a[1] < b[1];                         
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //base case
        if(points.size() == 0){
            return 0;
        }
        sort(points.begin(), points.end(), comp);     //sort on the basis of upper bound of each interval

        int arrow = 1;                                   //1 arrow always required to burst 1 or > ballon
        int end = points[0][1];                          //upper bound 1st interval

        for(int i = 1 ; i < points.size() ; i++){
            if(points[i][0] > end){                     //lower bound of interval  > end
                arrow++;
                end = points[i][1];
            }
        }
        return arrow;
    }
};
/*
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
*/


//52. VAILID PARENTHESIS                                                                    {T.C = O(N), S.C = O(N)}
class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            //check also is st is not empty otherwise run time error
            else if( !st.empty() && ( (ch == ')' && st.top() == '(' ) || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[') ) ){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
/*
Input: s = "()[]{}"
Output: true
*/


//53. SIMPLIFY PATH                                                              {T.C = O(N), S.C = O(N)}
//APPROACH
//take a stack and res string traverse string check for following condition
/*
The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the 
*/
//remember res poped element is reverse answer so  (/+st.top()+res)
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;

        for(int i = 0 ; i < path.size() ; i++){
            if(path[i] == '/'){
                continue;
            }
            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(!st.empty()){
                    st.pop();   
                }
            }else{
                st.push(temp);
            }
        }
        while(!st.empty()){
            res = '/'+ st.top()+ res;
            st.pop();
        }

        if(res.size() == 0){
            return "/";
        }
        return res;
    }
};
/*
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
*/


//54. MIN STACK                                                                             {T.C = O(1), S.C = O(N)}
//APPROACH
/*
Initialize two stacks, arr to store the actual elements and min_arr to store the minimum elements.
When pushing an element from the stack:
Push the element into the arr stack.
Check if the min_arr stack is not empty. If it is, simply push the element into the min_arr stack.
If the min_arr stack is not empty, calculate the minimum between the current element and the top of the min_arr stack and 
push the minimum value into the min_arr stack. This ensures that min_arr always contains the minimum value for the stack.

When popping an element from the stack:
Pop the element from both the arr and min_arr stacks. This maintains the consistency of the two stacks.

To get the top element of the stack, simply return the top element from the arr stack.

To get the minimum value of the stack, return the top element from the min_arr stack. This provides a constant time operation for retrieving the minimum.
*/
class MinStack {
public:
    stack<int>s, b;                      //s = stores original elements, b = stores minimum elements
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(!b.empty()){
            val = min(val, b.top());
        }
        b.push(val);
    }
    
    void pop() {                                     //for maintaining consistancy pop from both
        s.pop();
        b.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return b.top();
    }
};
/*
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/


//55. EVALUATE REVERSE POLISH NOTATION                                                 {T.C = O(N), S.C = O(N)}
//APPROACH
//simple implement postfix operation 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i : tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int op2 = st.top();                        //in postfix first pop element = op2
                st.pop();
                int op1 = st.top();
                st.pop();

                if(i == "+"){
                    st.push(op1 + op2);
                }
                if(i == "-"){
                    st.push(op1 - op2);
                }
                if(i == "*"){
                    st.push(op1 * op2);
                }
                if(i == "/"){
                    st.push(op1 / op2);
                }
            }else{
                int data = stoi(i);                            //string to integer
                st.push(data);
            }
        }
        return st.top();
    }
};
/*
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


//56. BASIC CALCULATOR                                                              {T.C = O(N), S.C = O(N)}
//APPROACH
//take 2 stacks (1 = integer, 2 = sign), now calculate ans
class Solution {
public:
int calculate(string s) {
            
    int value = 0;                // Current integer value
    int res = 0;                // Running result
    int sign = 1;
    stack<int> st;              // Stores intermediate results
    stack<int> stSign;          // Stores signs

    
    for(char c : s){
        if(c >= '0' && c <= '9'){
            value = value* 10 + (c-'0');
        }else if(c == '+'){
            res += sign * value;
            value = 0;
            sign = 1;
        }else if(c == '-'){
            res += sign * value;
            value = 0;
            sign = -1;
        }else if(c == '('){
            st.push(res);
            stSign.push(sign);

            res = 0; 
            sign = 1; 
        }else if(c == ')'){
            res += sign * value;
            res *= stSign.top(); stSign.pop();
            res += st.top(); st.pop();
            value = 0; 

        }
    }
    return res + sign * value;
}
};
/*
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//57. LINKED LIST CYCLE                                                                {T.C = O(N), S.C = O(1)}
//APPROACH
//using floyd's cycle (algo = slow, fast pointers)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;;
            }
        }
        return false;
    }
};
/*
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/


//ALWAYS USE DUMMY NODE WHERE WE HAVE TO DISLINK OR DELETE THE NODE
//58. ADD 2 NUMBERS                                                                    {T.C = O(N), S.C = O(MAX(N,M)}
class Solution {
public:
    /* already reverse order have given in question
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while(curr){                                  //curr == curr != NULL
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        int carry = 0;
        ListNode *dummy = new ListNode(NULL);
        ListNode *temp = dummy;

        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* extra = new ListNode(sum % 10);
            temp->next = extra;
            temp = temp->next;
        }
        // return reverse(dummy->next);
        return dummy->next;                        //actual result
    }
};
/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/


//59. MERGE 2 SORTED LISTS                                                        {T.C = O(N), S.C = O(1)}
//APPROACH
//if list1 is empty return list2 & verse else insert in between by changing pointers
class Solution {
public:
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* curr1 = first;
        ListNode* next1 = first->next;
        ListNode* curr2 = second;
        ListNode* next2 = second->next;

        if(!first->next){
            first->next = second;
            return first;
        }

        while(next1 && curr2){
            if(curr2->val >= curr1->val && curr2->val <= next1->val){
                //insert in between 1 linkedlist
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                
                //update pointer
                curr1 = curr2;
                curr2 = next2;
            }else{
                //move forward
                curr1 = curr1->next;
                next1 = next1->next;

                if(!next1){
                    curr1->next = curr2;
                    return first;
                }
            }
        }
        return first;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        if(list1->val <= list2->val){
            return merge(list1, list2);
        }else{
            return merge(list2, list1);
        }
    }
};
/*
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//60. COPY LIST WITH RANDOM POINTERS                                                 {T.C = O(N), S.C = O(N)}
//APPROACH
//first copy the original ll to new ll then stores its value and random pontier in unordered map then with the help
//of map we put random pointer to new ll
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        Node* newHead = new Node(0);
        Node* newCurr = newHead;
        Node* curr = head;

        unordered_map<Node*, Node*>mp;
        //copying simple pointers or ll to new ll
        while(curr){
            Node* temp = new Node(curr->val);
            mp.insert({curr, temp});                        //{oldNode, newNode}

            newCurr->next = temp;
            newCurr = newCurr->next;
            curr = curr->next;  
        }

        //reset
        curr = head;
        newCurr = newHead->next;

        //copying random pointers
        while(curr){
            Node* random = curr->random;
            Node* newNode = mp[random];
            newCurr->random = newNode;

            newCurr = newCurr->next;
            curr = curr->next;
        }

        return newHead->next;
    }
};
/*
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/


//61a. REVERSE LINKED LIST                                                      {T.C = O(N), S.C = O(1)}
//APPROACH
//make 3 pointers prev, curr and next then points to its correct postions/node
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
/*
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/


//61b. REVERSE A LINKED LIST II                                                                  {T.C = O(N), S.C = O(1)}
//APPROACH
//divide in 3 subproblem first traverse till left then reverse left to right at last join remaining from right to last in ll
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        //move to before reversing position
        for(int i = 0 ; i < left-1 ; i++){
            temp = temp->next;
            curr = curr->next;
        }

        //from where we start reversing
        ListNode* subListed = curr;

        //same logic as reverse ll
        for(int i = 0 ; i < right-left+1 ; i++){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        //join the pieces (remaining node after {right-left+1} nodes)
        temp->next = prev;
        subListed->next = curr;

        return dummy->next;
    }
};
/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/


//62. REVERSE NODES IN K-GROUP                                                       {T.C = O(N), S.C = O(1)}
//APPROACH
//simple recursive solution first reverse k nodes then put recursion
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //if size is less then k then not reverse ll
        int sz = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            sz++;
        }
        //---------------------------------------------

        //base case
        if(!head || sz < k){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;
        //reverse 1 k elements
        while(curr && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        //after k elements lets recursion do its work
        if(forward){
            head->next = reverseKGroup(forward, k);         //point recursive ans to head->next
        }
        return prev;
    }
};
/*
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/


//63. REMOVE NTH NODE FROM END OF LIST                                                   {T.C = O(N), S.C = O(1)}
//APPROACH 
//remove nth last = len-n+1 from start (change the curr pointer to curr->next)
class Solution {
public:
    int len(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = len(head);
        //base case
        if(n == sz){ //remove first node
            ListNode* temp = head;
            head = head->next;
            delete temp;

            return head;
        }
        // int i = sz-n+1;                  //actual n from beginning
        int desired = sz-n;              //before n
        ListNode* curr = head;
        while(desired > 1){
            curr = curr->next;
            desired--;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }
};

//OPTIMIZED (SINGLE PASS ONLY)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(n--){
            fast = fast->next;                   //move fast until find n
        }
        if(!fast){
            return slow->next;                   //or head->next
        }

        while(fast->next){                        //move 1 step both (like a window)
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;           //remove nth node

        return head;
    }
};
/*
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/


//64. REMOVE DUPLICATES FROM SORTED LINKED LIST II                                     {T.C = O(N), S.C = O(1)}
//APPROACH
//make a dummy node (for dislinking the link) then untill a val is same remove pointers after that simple return dummy->next
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        while(head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head = head->next;
                    temp->next = head->next;                        //removing link
                }
            }else{
                temp = temp->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
/*
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/


//65. ROTATE LIST                                                                  {T.C = O(N), S.C = O(1)}
//APPROACH
//first find len of list then effective rotation (k % n) from start(k = n-k) traversal find new head and update it
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0){
            return head;
        }
        ListNode* curr = head;        
        int len = 1;                            // Initialize the length of the list.

        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }
        curr->next = head;

        k = k % len;                           //effective rotation
        k = len - k;

        
        while (k--) {                         // Traverse the list to find the new head after rotation.
            curr = curr->next;
        }

        // Update the head and break the circular connection to complete the rotation.
        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};
/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/


//66. PARTITION LIST                                                           {T.C = O(N), S.C = O(1)}
//APPROACH
//take 2 dummy nodes or list 1st list have have store smaller element then x 2nd list rest of element then return ll
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(head){
            if(head->val < x){
                l1->next = head;
                l1 = l1->next;
            }else{
                l2->next = head;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        l1->next = list2->next;                  //join 1 and 2 second list
        l2->next = NULL;                         //point last node to null

        return list1->next;                      //list1 = 0, list1->next = actual head
    }
};
/*
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
*/


//67. LRU CACHE                                                            {T.C = O(1), S.C = O(CAP)}
//APPROACH
//The LRUCache class uses a doubly linked list and a hash map to implement a fixed-size cache, allowing for efficient O(1)
//retrieval and insertion of key-value pairs while maintaining the least recently used (LRU) item at the tail of the list. 
//When the cache reaches its capacity, it removes the LRU item to accommodate new entries.
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);  // Head sentinel node with minimum values
    Node* tail = new Node(-1, -1);  // Tail sentinel node with minimum values

    int cap;                        // Maximum capacity of the cache
    unordered_map<int, Node*> mp;   // A map to store key-node pairs for quick access

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;           // Initialize the linked list with head and tail sentinels
        tail->prev = head;
    }

    // Function to delete a specific node from the linked list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // Function to add a new node to the front of the linked list
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    // Get the value for a given key and move the corresponding node to the front
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* ansNode = mp[key];
            int ans = ansNode->val;

            deleteNode(ansNode);
            addNode(ansNode);

            mp[key] = head->next;  // Update the map with the new position of the node
            return ans;
        }
        return -1;  // Key not found in the cache
    }

    // Put a new key-value pair in the cache, possibly removing the least recently used item
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* curr = mp[key];
            deleteNode(curr);  // Remove the existing node from its current position
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);  // Remove the least recently used item
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));  // Add the new node to the front
        mp[key] = head->next;           // Update the map with the new position of the node
    }
};
/*
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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


//95. SNAKES AND LADDERS
/*
finding minimum steps for this we have to perfrom bfs 
*/
class Solution {
public:
    //bfs
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>>vis(n, vector<int>(n, 0));
        queue<int>q;
        q.push(1);
        vis[n-1][0] = 1;            //first step is already visited (1 place)
        int move = 0;

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                int frontNode = q.front();
                q.pop();

                if(frontNode == n*n){     //base case or breaking or stoping point
                    return move;
                }
                for(int j = 1 ; j <= 6 ; j++){
                    int nextCell = frontNode + j;
                    if(nextCell > n*n){
                        break;
                    }

                    int nextRow = n-1 - (nextCell - 1)/n;    //finding row formula
                    int nextCol = (nextCell-1) % n;          //finding col formula

                    if(nextRow % 2 == n % 2){
                        nextCol = n-nextCol-1;
                    }

                    if(!vis[nextRow][nextCol]){
                        vis[nextRow][nextCol] = 1;
                        if(board[nextRow][nextCol] != -1){
                            q.push(board[nextRow][nextCol]);
                        }else{
                            q.push(nextCell);         //board[r][c] or snack or ladder's value
                        }
                    }
                }
            }
            move++;
        }
        return -1;
    }
};
/*

Example 1:
Input: board = [[-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,35,-1,-1,13,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.

Example 2:
Input: board = [[-1,-1],[-1,3]]
Output: 1
*/


//96. MIIMUM GENETIC MUTATION
/*
create a set for storing unique strings and queue for bfs if with the each iteration the final node or string same as pervious return count of steps 
else return -1 
*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>vis;
        queue<string>q;
        q.push(startGene);
        vis.insert(startGene);
        int count = 0;
        
        while(!q.empty()){
            int n = q.size();           //update size of queue with each iteration
            for(int i = 0 ; i < n ; i++){
                string frontNode = q.front();
                q.pop();
                if(frontNode == endGene){
                    return count;
                }
                for(auto it : "ACGT"){
                    for(int j = 0 ; j < frontNode.size() ; j++){
                       string adjNode = frontNode;
                       adjNode[j] = it;
                       //not visited and also present in the bank
                       if(!vis.count(adjNode) && find(bank.begin(), bank.end(), adjNode) != bank.end()){
                           q.push(adjNode);
                           vis.insert(adjNode);
                       } 
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
/*
Example 1:
Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Example 2:
Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
*/


//97. WORD LADDER
/*
similar to above
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());      //insert all elements in set
        st.erase(beginWord);
        while(!q.empty()){
            pair<string,int> frontNode=q.front();
            string word=frontNode.first;
            int steps=frontNode.second;
            q.pop();

            //check for destination 
            if(word==endWord)
                return steps;
            for(int i=0;i<word.length();i++){
                char orig=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=orig;                                    // Revert back for the next iteration call
            }
        }
        return 0;                                                //Transformation not possible
    }
};
/*
Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/


//98.  IMPLEMENT TRIE (PREFIX TREE)                                       {T.C = O(N + N), S.C = O(N*M {no. of word , lenghth of word})}
/*
//trie's main functions = insert, search, delete
//first we have to create a struct (isEndOfWord, child array)
//second we have to write function for creating new node for an trie
//initialize trieNode with root
//write for insert and with some upgradation search and startswith fucntion made
*/
class Trie {
public:
    struct trieNode{                   //basic requirement of trie is endofword and child
        bool isEndOfWord;
        trieNode *child[26];
    };

    trieNode *getNode(){              //for making newnode in trie
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;     //endofword should be false for new node
        for(int i = 0 ; i < 26 ; i++){
            newNode->child[i] = NULL;     //creating empty vector
        }
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    //if we create insert then search and and starts with is just slight updation of code

    void insert(string word) {  //apple
        trieNode* crawler = root;             //crawler work as iterator
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){
                crawler->child[idx] = getNode();  //'a'
            }
            crawler = crawler->child[idx];       //move forward
        }
        crawler->isEndOfWord = true;      //'e' reach end
    }
    
    bool search(string word) {  //'apple'
        trieNode* crawler = root;             //crawler work as iterator
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){    //character in the word being searched for doesn't exist in the trie
                return false;
            }
            crawler = crawler->child[idx];       //move forward
        }
        if(crawler != NULL && crawler->isEndOfWord == true){  //'e'
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) { //'app'
        trieNode* crawler = root;             //crawler work as iterator
        int i = 0;
        for(i = 0 ; i < prefix.length() ; i++){    //same as search just word => prefix
            char ch = prefix[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){    //character in the word being searched for doesn't exist in the trie
                return false;
            }
            crawler = crawler->child[idx];       //move forward
        }
        if(i == prefix.length()){
            return true;
        }
        return false;
    }
};
/*
Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/


//99. DESIGN ADD AND SEARCH WORDS DATA STRUCTURE                                       {T.C = O(N + N), S.C = O(N*M {no. of word , lenghth of word})}
/*
same approach as above but slightly differnce because in this '.' dot char may be include so that we have to handle seperatly
*/
class WordDictionary {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* child[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;
        for(int i = 0 ; i < 26 ; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }  

    trieNode* root;

    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        trieNode* crawler = root;
        for(int i = 0 ; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(crawler->child[idx] == NULL){
                crawler->child[idx] = getNode();
            }
            crawler = crawler->child[idx];
        }
        crawler->isEndOfWord = true;
    }
    
    bool searchHelper(string &word, int index, trieNode* crawler){
        //base case
        if(index == word.length()){
            if(crawler != NULL && crawler->isEndOfWord == true){
                return true;
            }
            return false;
        }

        if(word[index] == '.'){
            for(int i = 0 ; i  < 26 ; i++){
                if(crawler->child[i] != NULL && searchHelper(word, index+1, crawler->child[i])){
                    return true;
                }
            }
            return false;
        }else{
            int idx = word[index]-'a';
            if(crawler->child[idx] == NULL){
                return false;
            }
            return searchHelper(word, index+1, crawler->child[idx]);
        }
    }
    bool search(string word) {
        trieNode* crawler = root;
        return searchHelper(word, 0, crawler);            //0 = index
    }
};
/*
Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
*/


//100a. WORD SEARCH                                                         {T.C = O(N*M*4*L), S.C = O(N*M)}
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


//100b. WORD SEARCH II                                                               {T.C = O(N*M*4^L), S.C = O(N*M)}
/*
we cant use simple dfs like above it will increase the time compelxity so that's why we use trie so that we can traverse only once
*/
class Solution {
public:
    //global ans vector
    vector<string> result;

    vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};
    struct trieNode{
        bool isEndOfWord;
        string word;
        trieNode *child[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        newNode->word = "";
        for(int i = 0 ; i < 26 ; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string word){
        trieNode* crawler = root;                  //iterator
        for(int i = 0 ; i < word.length() ; i++){
            int idx = word[i]-'a';
            if(crawler->child[idx] == NULL){
                crawler->child[idx] = getNode();
            }
            crawler = crawler->child[idx];         //move forward
        }
        crawler->isEndOfWord = true;
        crawler->word = word;
    }

void search(vector<vector<char>>& board, trieNode* root, int i, int j){

    //base case
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '$' || root->child[board[i][j] - 'a'] == NULL){
        return;
    }
    int idx = board[i][j] - 'a';
    root = root->child[idx];       //move forward

    if(root->isEndOfWord == true){
        result.push_back(root->word);
        root->isEndOfWord = false; // Marking the word as found
    }
    char temp = board[i][j];       //store current charcter
    board[i][j] = '$';             //mark visited

    //explore all 4 directions
    for(auto p : directions){         //p = pair {{-1, 0}, ...}
        int new_i = i + p.first;
        int new_j = j + p.second;
        search(board, root, new_i, new_j);
    }
    board[i][j] = temp; //reset the board cell to its original character
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        int col = board[0].size();

        //create root
        trieNode* root = getNode();

        //insert word in trie
        for(auto it : words){
            insert(root, it);
        }      

        //traverse in grid (only once)
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int idx = board[i][j] - 'a';
                if(root->child[idx] != NULL){
                    search(board, root, i, j);       //after finding word push in vector (result)
                }
            }
        }
        return result;
    }
};
/*
Example 1:
Input: board = [["o","a","a","n"],
                ["e","t","a","e"],
                ["i","h","k","r"],
                ["i","f","l","v"]], 
                words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],
                ["c","d"]], 
                words = ["abcb"]
Output: []
*/


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


//112. MAXIMUM SUBARRAY (KADANE'S ALGORITHM)                                     {T.C = O(N), S.C = O(1)}
/*
initialize sum and maxi traverse array with adding sum and store max(sum, maxi) if sum < 0 put sum = 0 after that return maxi
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;               
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0){                        //necessary condition for kadane's algo
                sum = 0;
            }
        }
        return maxi;
    }
};
/*
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/


//113. MAXIMUM SUM CIRCULAR SUBARRAY
/*
finding 2 types of sum 
1. maxi = maximum continuous subarray sum (kadane's algo simple)
2. totalSum-mini = maximum circular subarray sum (reverse kadane's algo for mini)
max of 1 or 2
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0, sum2 = 0;
        int maxi = INT_MIN, mini = INT_MAX;               
        int totalSum = 0;

        for(int i = 0 ; i < n ; i++){
            totalSum += nums[i];

            sum1 += nums[i];
            maxi = max(maxi, sum1);        //straight maxsubarray sum
            if(sum1 < 0){
                sum1 = 0;
            }

            sum2 += nums[i];
            mini = min(mini, sum2);
            if(sum2 > 0){                   //reverse of above (kadane's algo)
                sum2 = 0;
            }
        }

        if(totalSum == mini){          //if all negative
            return maxi;                    //represents the maximum single element among the negative numbers
        }
        return max(maxi, totalSum-mini);    //(continuous max subarray sum , circular maxisubarray sum )
    }
};
/*
Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
*/