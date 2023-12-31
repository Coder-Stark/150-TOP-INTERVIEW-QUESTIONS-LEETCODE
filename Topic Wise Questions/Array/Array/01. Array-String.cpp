//ARRAY/STRINGS
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
