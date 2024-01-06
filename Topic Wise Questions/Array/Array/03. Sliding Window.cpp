//SLIDING WINDOW
#include<bits/stdc++.h>
using namespace std;


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