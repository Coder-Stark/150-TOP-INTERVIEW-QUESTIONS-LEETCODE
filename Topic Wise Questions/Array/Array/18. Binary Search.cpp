//BINARY SEARCH
#include<bits/stdc++.h>
using namespace std;

//114. SEARCH INSERT POSITION                                          {T.C = O(LOGN), S.C = O(1)}
/*
simple binary search if element is in vector other wise handle boundry case and after that return low or start value
because at the breaking point start will show the exact position of insert.
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        
        if(target > nums[end]){
            return end+1;                             //last + 1 index or new element
        }
        while(start <= end){  
            int mid = (start + end)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{ //(nums[mid] > target)
                end = mid-1;
            }
        }
        return start;                                //return low or start because after breaking loop it will show correct position to insert
    }
};
/*
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/


//115. SEARCH A 2D MATRIX                                              {T.C = O(LOG(M*N)), S.C = O(1)}
/*
finding element in matrix by converting 2D to 1D representation by row index = mid/col and col index = mid%col then apply
simple binary search.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col-1;

        while(start <= end){
            int mid = start + (end-start)/2;               //same as (start + end)/2

            int element = matrix[mid/col][mid%col];       //mid/col = compute row index   and  [mid%col] = compute col index

            if(element == target){
                return true;
            }else if(element < target){
                start = mid + 1;
            }
            else{  //(element > target)
                end = mid -1;
            }

        }
        return false;
    }
};
/*
Example 1:
Input: matrix = [[1 ,3 ,5 ,7],
                 [10,11,16,20],
                 [23,30,34,60]], 
                 target = 3
Output: true

Example 2:
Input: matrix = [[1 ,3 ,5, 7],
                 [10,11,16,20],
                 [23,30,34,60]], 
                 target = 13
Output: false
*/


//116. FIND PEAK ELEMENT                                                  
//BRUTE FORCE                                                     {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};
/*OPTIMIZED APPROACH (BINARY SEARCH)                                {T.C = O(LOGN), S.C = O(1)}
search for peak we have to check adjacent element (nums[mid] < nums[mid+1]) then peak may be in right side else
peak in left side after breaking loop return start or low index.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[mid] < nums[mid+1]){              //peak may be in right side
                start = mid+1;
            }else{ //(nums[mid] > nums[start])        //peak may be in left side
                end = mid;
            }
        }
        return start;
    }
};
/*
Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/


//117. SEARCH IN ROTATED SORTED ARRAY                                      {T.C = O(LOGN), S.C = O(1)}
/*
in rotated sorted array this is confirms that 1 part must be sorted(left or right) so we have to check for both part.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0; 
        int end = n-1;

        while(start <= end){                  //is equal to for last element case
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[start] <= nums[mid]){              //left part is sorted
                if(nums[start] <= target && target <= nums[mid]){   //check between left range (nums[start] to nums[mid])
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }else{ //(nums[start] > nums[mid])        //right part is sorted
                if(nums[end] >= target && target >= nums[mid]){    //check between right range (nums[mid] to nums[end])
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
            
        }
        return -1;
    }
};
/*
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/


//118. FIND FIRST AND LAST POSITION OF ELEMENT IN SORTED ARRAY                       {T.C = O(LOGN), S.C = O(1)}
/*
using 2 binary searches separately and find first and last occurance index
*/
class Solution {
public:
    int findFirst(vector<int>&nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int first = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                first = mid;
                end = mid-1;                                //left half
            }else if(nums[mid] < target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return first;
    }
    int findLast(vector<int>&nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int last = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                last = mid;
                start = mid+1;                 //right half
            }else if(nums[mid] < target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};
/*
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/


//119. FIND MINIMUM IN ROTATED SORTED ARRAY                                        {T.C = O(LOGN), S.C = O(1)}
/*
check base case if not rotated but sorted array then return first element other wise apply binary search at last return nums[start] 
after breaking loop condition.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            // If the array is not rotated (sorted in ascending order), return the first element
            if (nums[start] < nums[end]) {
                return nums[start];
            }

            int mid = start + (end - start) / 2;

            if (nums[start] > nums[mid]) {   // Minimum element lies in the left half
                end = mid;
            } else {                         // Minimum element lies in the right half
                start = mid + 1;
            }
        }

        return nums[start];                  // the minimum element is at nums[start]
    }
};
/*
Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/


//120. MEDIAN OF TWO SORTED ARRAYS                                               {T.C = O(LOGN), S.C = O(1)}
/*
divide the two arrays in 6 parts cut1, cut2, left1, left2, right1, right2 accrodingly and use binary search
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n2 < n1){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0 , high = n1;
        
        while(low <= high){
            int cut1 = (low+high)/2;
            int cut2 = ((n1+n2+1)/2) - cut1;
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1){
                if((n1+n2) % 2 == 0){            //even
                    return (max(left1, left2) + min(right1, right2))/2.0;
                }
                else{                            //odd
                    return max(left1, left2);
                }
            }
            else if(left1 > left2){
                high = cut1-1;                   //move left
            }
            else{
                low = cut1+1;                    //move right
            }
        }
        return 0.0;        
    }
};
/*
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/