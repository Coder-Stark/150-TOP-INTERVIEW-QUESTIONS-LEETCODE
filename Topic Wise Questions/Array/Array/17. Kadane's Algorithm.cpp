//KADANE'S ALGORITHM
#include<bits/stdc++.h>
using namespace std;

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