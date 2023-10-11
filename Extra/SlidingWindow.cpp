//SLIDING WINDOWS QUESTIONS (Aditya Veram)

#include<bits/stdc++.h>
using namespace std;

//01. MAX SUM SUBARRAY OF SIZE K                                                    {T.C = O(N), S.C = O(1)}
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i = 0, j = 0;
        long maxi = INT_MIN;
        long sum = 0;
        while(j < N){
            sum += Arr[j];                       //calculation
            
            if(j-i+1 < K){                       //j-i+1 = window size
                j++;
            }else if(j-i+1 == K){
                maxi = max(maxi, sum);           //calculation
                sum -= Arr[i];                   //slide window
                i++;
                j++;
            }
        }
        return maxi;
    }
};
/*
Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
*/


//02. FIRST NEGATIVE INTEGER IN EVERY WINDOW OF SIZE K                              {T.C = O(N), S.C = O(N)}
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    int i = 0, j = 0;
    vector<long long>ans;
    vector<long long>storeNegative;
    
    while(j < N){
        if(A[j] < 0){
            storeNegative.push_back(A[j]);           //calculation
        }
        if(j-i+1 < K){
            j++;
        }else if(j-i+1 == K){
            if(storeNegative.empty()){               //calculation
                ans.push_back(0);
            }else{
                ans.push_back(storeNegative[0]);
                if(A[i] < 0){
                    storeNegative.erase(storeNegative.begin());       //slide window
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
/*
Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
*/


//MINIMUM WINDOW SUBSTRING                                                 {T.C = O(N), S.C = O(N)}
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
