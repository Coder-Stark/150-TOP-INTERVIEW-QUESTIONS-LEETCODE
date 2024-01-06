//HASHMAP
#include<bits/stdc++.h>
using namespace std;

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