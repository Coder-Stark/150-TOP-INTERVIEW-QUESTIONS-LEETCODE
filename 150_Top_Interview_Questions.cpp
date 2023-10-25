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
                                                    //example 123456 , k = 2 => 456123
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