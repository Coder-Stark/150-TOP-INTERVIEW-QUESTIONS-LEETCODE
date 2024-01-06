//HEAP
#include<bits/stdc++.h>
using namespace std;

//121. KTH LARGEST ELEMENT IN AN ARRAY                                {T.C = O(N*LOGK), S.C = O(K)}
/*
use minHeap for finding kth max element because at the end minHeap.top is the kth largest element.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //creating min heap (kth largest element on top of minHeap others node are greater then k)
        priority_queue<int, vector<int>, greater<int>>minHeap;

        //put first k elements to min heap
        for(int i = 0 ; i < k ; i++){
            minHeap.push(nums[i]);
        }

        //for rest of elements
        for(int i = k ; i < nums.size() ; i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
/*
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/


//122. IPO                                                                  {T.C = O(N*LOGN), S.C = O(N)}
/*
store profits and capitals in pair in vector then sort this vector according to there capital then create a maxHeap
and push element in heap if the current capital is less then w (total capital) after that add current element to w 
that is final answer after pop from heap.
*/
class Solution {
public:
    static bool cmp(pair<int, int>&a, pair<int,int> &b){  //static allows you to use it without an object of the class.
        return a.second < b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>>projects;
        for(int i = 0 ; i < n ; i++){
            projects.push_back({profits[i], capital[i]});
        }
        sort(projects.begin(), projects.end(), cmp); //acending order of capital
        priority_queue<int>pq;    //maxHeap
        int i = 0;
        while(k--){
            while(i < n && projects[i].second <= w){
                pq.push(projects[i].first);
                i++;
            }
            if(!pq.empty()){            //current element add to w it is the final answer
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
/*
Example 1:
Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

Example 2:
Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
*/


//123. FIND K PAIRS WITH SMALLEST SUMS                                                 {T.C = O(N*M*LOGK), S.C = O(N*M)}
/*
brute force approach - make maxheap of {sum, {i, j}} first put first k pairs then match the sum with top element sum and update pq accordingly
after that break(sorted so right side is always greater) pull element of maxheap and put in ans vector
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>>ans;
        int n1 = nums1.size();
        int n2 = nums2.size();

        //{sum, {i, j}}
        priority_queue<pair<int, pair<int, int>>>pq;    //maxHeap
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum, {i, j}});
                }else if(pq.top().first > sum){           //current sum less then till that sum
                    pq.pop();
                    pq.push({sum, {i, j}});
                }else{
                    break;
                }
            }
        }

        while(!pq.empty()){            //pop element and push into ans vector
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i], nums2[j]});
        }
        return ans;
    }
};
/*
Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
*/


//124. FIND MEDIAN FROM DATA STREAM
/*
Brute force = traverse -> sort -> insert again -> sort                                      //T.C = O(N*NLOGN), S.C =  O(N)
Optimized approach
using 2 heaps first half (maxheap) second half (minHeap) for even take top of both and return mean if odd then return top of first (we take
first maxheap is greater always)
*/
class MedianFinder {
public:
    priority_queue<int>leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>>rightMinHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.size() == 0 || num < leftMaxHeap.top()){       //insert in left side 
            leftMaxHeap.push(num);
        }else{
            rightMinHeap.push(num);
        }

        //maintain left and right heap (left should be greater element if one extra)
        if(abs((int)leftMaxHeap.size() - (int)rightMinHeap.size()) > 1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }else if(leftMaxHeap.size() < rightMinHeap.size()){          //left should be greater always
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }   
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()){               //even
            return (leftMaxHeap.top()+rightMinHeap.top()) / 2.0;
        }                                                      
        return leftMaxHeap.top()/1.0;                                //odd               
    }
};
/*
Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]
Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/
