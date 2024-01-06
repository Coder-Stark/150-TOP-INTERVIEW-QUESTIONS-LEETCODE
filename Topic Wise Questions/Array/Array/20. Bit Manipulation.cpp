//BIT MANIPULATION
#include<bits/stdc++.h>
using namespace std;

//125. ADD BINARY                                                               {T.C = O(N), S.C = O(N)}
/*
we traverse from the end of both digit by converting string first and extract carry from that and add to next element
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry){
            if(i >= 0){
                carry += a[i]-'0';
                i--;
            }
            if(j >= 0){
                carry += b[j]-'0';
                j--;
            }
            ans += carry%2 + '0';                     //add carry(string) to ans
            carry /= 2;                               //move carry to next position
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/


//126. REVERSE BITS                                                         {T.C = O(N), S.C = O(1)}
/*
we iterate from 1 to 32 (not 0) and first find the kth bit set if it is 1 then right shift overall ans and swap second last and second element
of element (eg) and take OR with ans then return ans.
*/
class Solution {
public:
    bool findKthBitSet(int k, uint32_t n){
        if( ((1 << (k-1)) & n) != 0 ){      //first reach to set bit( which is 1 by shifting then take AND if ans != 0 return true (1.1 = 1)
            return true;
        }
        return false;                       //(1.0 = 0)
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 1; i <= 32 ; i++){      //from 1 otherwise overflow
            if(findKthBitSet(i, n)){        //curr bit is 1
                ans = 1 << (32-i) | ans;    //second last to second position or vice versa  by shifting element and take OR (it accumulates the set bits in the reversed order.)
            }
        }
        return ans;
    }
};
/*

Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, 
so return 3221225471 which its binary representation is 10111111111111111111111111111111.
*/


//127. NUMBER OF 1 BITS                                                          {T.C = O(N), S.C = O(1)}
/*
if n is not equal to 0 then take and of n with 1 (1.1 = 1) and increase count then right shift or move to next position finally return ans.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count= 0;
        while(n != 0){
            if(n & 1){                       //1.1 = 1 and 1.0 = 0
                count++;
            }
            n = n>>1;                        //right shift or moving to next position
        }
        return count;
    }
};
/*
Example 1:
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
*/


//128. SINGLE NUMBER      (1 element appear once and other twice, find 1 elements which appears once)                                                {T.C = O(N), S.C = O(1)}
/*
xor of each element (1^1 = 0 and 1^0 = 1) so if the element is same of pairwise then it will cancel or and remaining element is ans.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {             //xor = different element != 0 else 0 
        int xorAns = 0;
        for(int i = 0 ; i < nums.size(); i++){
            xorAns = xorAns^nums[i];
        }
        return xorAns;
    }
};
/*
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
*/


//129a. SINGLE NUMBER II   (1 element appear once and other thrice , find 1 elements which appears once)
/*
brute force = use unordered map store all values in map and return whose count is 1.   {T.C = O(N*LOGN), S.C = O(N)}
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second == 1){
                return it.first;
            }
        }
        return -1;
    }
};
/*
optimized approach - bitwise                                                               {T.C = O(N), S.C = O(1)}
ex = [2 , 2, 2 , 3]
ones = 0  2  0  0  3(ans)
twos = 0  0  2  0  0
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;           //ones = stores element which repeating once and similary twos 
        
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};
/*
Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/


//129b. SINGLE NUMBER III  (2 elements appears once and other twice, find 2 elements which appears once)
//{T.C = O(N), S.C = O(1)}
/*
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0); // Initialize the answer vector with two elements

        int xorResult = 0;
        
        // Step 1: Get the XOR of all elements
        for (int num : nums) {
            xorResult ^= num;
        }
        
        // Step 2: Find the rightmost set bit
        int rightmostSetBit = 1;
        while ((rightmostSetBit & xorResult) == 0) {
            rightmostSetBit <<= 1;
        }
        
        // Step 3 & 4: Divide into two groups and XOR separately
        for (int num : nums) {
            if ((num & rightmostSetBit) == 0) {
                ans[0] ^= num; // XOR for the group where the bit is not set
            } else {
                ans[1] ^= num; // XOR for the group where the bit is set
            }
        }
        
        return ans;
    }
};
/*
Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]
*/


//130. BITWISE AND OF NUMBERS RANGE                                              {T.C = O(N), S.C = O(1)}
/*
I step:we iterate this loop till both number becomes equal;
II step:when both number become equal put c number of zeroes through left shift to find & of numbers;
*/
class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
       int c=0;
       while(l!=r)
       {
           l>>=1;
           r>>=1;
           c++;
       }
       return l<<c;
    }
};
/*
Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0
*/