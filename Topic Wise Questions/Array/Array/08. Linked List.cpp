//LINKED LIST
#include<bits/stdc++.h>
using namespace std;

/*--------------------------------------DRIVER FUNCTION ------------------------------------------*/
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*---------------------------------------------------------------------------------------*/
//57. LINKED LIST CYCLE                                                                {T.C = O(N), S.C = O(1)}
//APPROACH
//using floyd's cycle (algo = slow, fast pointers)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;;
            }
        }
        return false;
    }
};
/*
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/


//ALWAYS USE DUMMY NODE WHERE WE HAVE TO DISLINK OR DELETE THE NODE
//58. ADD 2 NUMBERS                                                                    {T.C = O(N), S.C = O(MAX(N,M)}
class Solution {
public:
    /* already reverse order have given in question
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while(curr){                                  //curr == curr != NULL
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        int carry = 0;
        ListNode *dummy = new ListNode(NULL);
        ListNode *temp = dummy;

        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* extra = new ListNode(sum % 10);
            temp->next = extra;
            temp = temp->next;
        }
        // return reverse(dummy->next);
        return dummy->next;                        //actual result
    }
};
/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/


//59. MERGE 2 SORTED LISTS                                                        {T.C = O(N), S.C = O(1)}
//APPROACH
//if list1 is empty return list2 & verse else insert in between by changing pointers
class Solution {
public:
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* curr1 = first;
        ListNode* next1 = first->next;
        ListNode* curr2 = second;
        ListNode* next2 = second->next;

        if(!first->next){
            first->next = second;
            return first;
        }

        while(next1 && curr2){
            if(curr2->val >= curr1->val && curr2->val <= next1->val){
                //insert in between 1 linkedlist
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                
                //update pointer
                curr1 = curr2;
                curr2 = next2;
            }else{
                //move forward
                curr1 = curr1->next;
                next1 = next1->next;

                if(!next1){
                    curr1->next = curr2;
                    return first;
                }
            }
        }
        return first;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        if(list1->val <= list2->val){
            return merge(list1, list2);
        }else{
            return merge(list2, list1);
        }
    }
};
/*
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//60. COPY LIST WITH RANDOM POINTERS                                                 {T.C = O(N), S.C = O(N)}
//APPROACH
//first copy the original ll to new ll then stores its value and random pontier in unordered map then with the help
//of map we put random pointer to new ll
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        Node* newHead = new Node(0);
        Node* newCurr = newHead;
        Node* curr = head;

        unordered_map<Node*, Node*>mp;
        //copying simple pointers or ll to new ll
        while(curr){
            Node* temp = new Node(curr->val);
            mp.insert({curr, temp});                        //{oldNode, newNode}

            newCurr->next = temp;
            newCurr = newCurr->next;
            curr = curr->next;  
        }

        //reset
        curr = head;
        newCurr = newHead->next;

        //copying random pointers
        while(curr){
            Node* random = curr->random;
            Node* newNode = mp[random];
            newCurr->random = newNode;

            newCurr = newCurr->next;
            curr = curr->next;
        }

        return newHead->next;
    }
};
/*
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/


//61a. REVERSE LINKED LIST                                                      {T.C = O(N), S.C = O(1)}
//APPROACH
//make 3 pointers prev, curr and next then points to its correct postions/node
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
/*
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/


//61b. REVERSE A LINKED LIST II                                                                  {T.C = O(N), S.C = O(1)}
//APPROACH
//divide in 3 subproblem first traverse till left then reverse left to right at last join remaining from right to last in ll
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        //move to before reversing position
        for(int i = 0 ; i < left-1 ; i++){
            temp = temp->next;
            curr = curr->next;
        }

        //from where we start reversing
        ListNode* subListed = curr;

        //same logic as reverse ll
        for(int i = 0 ; i < right-left+1 ; i++){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        //join the pieces (remaining node after {right-left+1} nodes)
        temp->next = prev;
        subListed->next = curr;

        return dummy->next;
    }
};
/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/


//62. REVERSE NODES IN K-GROUP                                                       {T.C = O(N), S.C = O(1)}
//APPROACH
//simple recursive solution first reverse k nodes then put recursion
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //if size is less then k then not reverse ll
        int sz = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            sz++;
        }
        //---------------------------------------------

        //base case
        if(!head || sz < k){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;
        //reverse 1 k elements
        while(curr && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        //after k elements lets recursion do its work
        if(forward){
            head->next = reverseKGroup(forward, k);         //point recursive ans to head->next
        }
        return prev;
    }
};
/*
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/


//63. REMOVE NTH NODE FROM END OF LIST                                                   {T.C = O(N), S.C = O(1)}
//APPROACH 
//remove nth last = len-n+1 from start (change the curr pointer to curr->next)
class Solution {
public:
    int len(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = len(head);
        //base case
        if(n == sz){ //remove first node
            ListNode* temp = head;
            head = head->next;
            delete temp;

            return head;
        }
        // int i = sz-n+1;                  //actual n from beginning
        int desired = sz-n;              //before n
        ListNode* curr = head;
        while(desired > 1){
            curr = curr->next;
            desired--;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }
};

//OPTIMIZED (SINGLE PASS ONLY)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(n--){
            fast = fast->next;                   //move fast until find n
        }
        if(!fast){
            return slow->next;                   //or head->next
        }

        while(fast->next){                        //move 1 step both (like a window)
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;           //remove nth node

        return head;
    }
};
/*
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/


//64. REMOVE DUPLICATES FROM SORTED LINKED LIST II                                     {T.C = O(N), S.C = O(1)}
//APPROACH
//make a dummy node (for dislinking the link) then untill a val is same remove pointers after that simple return dummy->next
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        while(head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head = head->next;
                    temp->next = head->next;                        //removing link
                }
            }else{
                temp = temp->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
/*
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/


//65. ROTATE LIST                                                                  {T.C = O(N), S.C = O(1)}
//APPROACH
//first find len of list then effective rotation (k % n) from start(k = n-k) traversal find new head and update it
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0){
            return head;
        }
        ListNode* curr = head;        
        int len = 1;                            // Initialize the length of the list.

        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }
        curr->next = head;

        k = k % len;                           //effective rotation
        k = len - k;

        
        while (k--) {                         // Traverse the list to find the new head after rotation.
            curr = curr->next;
        }

        // Update the head and break the circular connection to complete the rotation.
        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};
/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/


//66. PARTITION LIST                                                           {T.C = O(N), S.C = O(1)}
//APPROACH
//take 2 dummy nodes or list 1st list have have store smaller element then x 2nd list rest of element then return ll
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(head){
            if(head->val < x){
                l1->next = head;
                l1 = l1->next;
            }else{
                l2->next = head;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        l1->next = list2->next;                  //join 1 and 2 second list
        l2->next = NULL;                         //point last node to null

        return list1->next;                      //list1 = 0, list1->next = actual head
    }
};
/*
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
*/


//67. LRU CACHE                                                            {T.C = O(1), S.C = O(CAP)}
//APPROACH
//The LRUCache class uses a doubly linked list and a hash map to implement a fixed-size cache, allowing for efficient O(1)
//retrieval and insertion of key-value pairs while maintaining the least recently used (LRU) item at the tail of the list. 
//When the cache reaches its capacity, it removes the LRU item to accommodate new entries.
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);  // Head sentinel node with minimum values
    Node* tail = new Node(-1, -1);  // Tail sentinel node with minimum values

    int cap;                        // Maximum capacity of the cache
    unordered_map<int, Node*> mp;   // A map to store key-node pairs for quick access

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;           // Initialize the linked list with head and tail sentinels
        tail->prev = head;
    }

    // Function to delete a specific node from the linked list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // Function to add a new node to the front of the linked list
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    // Get the value for a given key and move the corresponding node to the front
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* ansNode = mp[key];
            int ans = ansNode->val;

            deleteNode(ansNode);
            addNode(ansNode);

            mp[key] = head->next;  // Update the map with the new position of the node
            return ans;
        }
        return -1;  // Key not found in the cache
    }

    // Put a new key-value pair in the cache, possibly removing the least recently used item
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* curr = mp[key];
            deleteNode(curr);  // Remove the existing node from its current position
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);  // Remove the least recently used item
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));  // Add the new node to the front
        mp[key] = head->next;           // Update the map with the new position of the node
    }
};
/*
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/