//MATH
#include<bits/stdc++.h>
using namespace std;

//131. PALINDROME NUMBER                                                    {T.C = O(N), S.C = O(N)}
/*
Brute Force = convert int to string then use 2 pointers (start , end) and match starting and ending element if it is same (true) else false
*/
class Solution {
public:
    bool isPalindrome(int x) {
        string temp = to_string(x);
        int n = temp.size();
        int i = 0;
        int j = n-1;
        while(i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }
};
/*
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/


//132. PLUS ONE                                                         {T.C = O(N), S.C = O(1)}
/*
Traverse from backward if digit != 9 then simply increase the digit and return it , other wise set digit[i] == 0 and finally insert 1 
at beggining when all digit is 99..
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        //traverse from backward
        for(int i = n-1 ; i >= 0 ; i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;                       //if we find digit = 9 then put 0 and move forward
        }
        digits.insert(digits.begin(), 1);        //when all are 9 and need to extra place to add 1
        return digits;
    }
};
/*
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
*/


//133. FACTORIAL TRAILING ZEROES                                               {T.C = O(LOG(5)N), S.C = O(1)}
/*
zeroes are made only with (2*5) we have to keep count of both but actually 2 count is always greater
then 5 so we have to take only min count(5) by keep dividing and adding count to ans
eg = n = 150 
ans = (150/5 == 30) + (30/5 == 6) + (6/5 == 1) ==> 37 
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n/5 > 0){
            ans += n/5;
            n = n/5;
        }
        return ans;
    }
};
/*
Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
*/


//134. SQRT(X)                                                                   {T.C = O(LOGN), S.C = O(1)}
/*
using binary search sqare = mid*mid if square == n return mid else use binary search (square < n) start = mid+1 else end = mid-1
*/
class Solution {
public:
    int mySqrt(int n){
        int s = 0;
        int e = n;
        long long int ans = -1;

        while(s <= e){
            long long int mid = s + (e - s)/2;
            long long int square = mid * mid;
            if(square == n){
                return mid;
            }
            else if (square < n){
                ans = mid;
                s = mid + 1;
            }
            else{//(square > n)
                e = mid - 1;
            }
        }
        return ans;
    }
};
/*
Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/


//135. POW(X, N)                                                          {T.C = O(LOGN), S.C = O(1)}
/*
basically we have different cases to handle 1. if n == 0 return 1, 2. if n is negative then make recursive call of reciprocal and pass
negative n, 3. if n is even divide in 2 parts and pass n/2 , 4. odd then x* even condition 
*/
class Solution {
public:
    double solve(double x, long n){
        //base case
        if(n == 0){                        //2^0 = 1
            return 1;
        }
        if(n < 0){                         //2-1 = 1/2  
            return solve(1/x, -n);
        }
        if(n % 2 == 0){                   //2^8 = 2*2^4
            return solve(x*x , n/2);
        }else{
            return x*solve(x*x, (n-1)/2); //2^9 = 2*(2*2^4)
        }
    }
    double myPow(double x, int n) {
        return solve(x, (long)n);
    }
};
/*
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/


//136. MAX POINTS ON A LINE                             
/*
{T.C = O(N^3), S.C = O(1)}
Brute force = using simple math first find slope of first two point and then check with another point if slope is equal then increase count
and return it.
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi = 0;
        int n = points.size();
        //base case
        if(n == 1){
            return 1;
        }

        for(int i = 0 ; i < n ; i++){           //1st point
            for(int j = i+1 ; j < n ; j++){     //2nd point
                int count = 2;
                int dx = points[j][0] - points[i][0];  //(x2-x1)
                int dy = points[j][1] - points[i][1];  //(y2-y1)
                //we can use dy/dx and compare with dy_/dx_ but (/) is costly so we use dy*dx_ == dy_*dx
                for(int k = 0 ; k < n ; k++){   //3rd point
                    if(k != i && k != j){       //3rd point should not be same to 1st or 2nd
                        int dx_ = points[k][0] - points[i][0];  //or point[j][0]   //(x3-x1) or (x3-x2)
                        int dy_ = points[k][1] - points[i][1];  //(y3-y1)
                        if(dy*dx_ == dy_*dx){
                            count++;
                        }
                    }
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
/*
{T.C = O(N^2), S.C = O(N)}
Optimized approach = we find theta for each point and store theta, count in map and return max count
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi = 0;
        int n = points.size();
        //base case
        if(n == 1){
            return 1;
        }

        for(int i = 0 ; i < n ; i++){           //1st point
            unordered_map<double, int>mp;       //(theta, count)
            for(int j = 0 ; j < n ; j++){      //2nd point
                if(j == i){                    //if same point then continue 
                    continue;
                }
                int dx = points[j][0] - points[i][0];  //(x2-x1)
                int dy = points[j][1] - points[i][1];  //(y2-y1)

                double theta = atan2(dy, dx);       //theta = tan-1(dy/dx)
                mp[theta]++;
            }
            for(auto it : mp){
                maxi = max(maxi, it.second+1);         //+1 for current point
            }
        }
        return maxi;
    }
};
/*
Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
*/