//TWO POINTERS
#include<bits/stdc++.h>
using namespace std;

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
