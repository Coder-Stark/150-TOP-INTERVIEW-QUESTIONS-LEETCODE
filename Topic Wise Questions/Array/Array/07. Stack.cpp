//STACK
#include<bits/stdc++.h>
using namespace std;

//52. VAILID PARENTHESIS                                                                    {T.C = O(N), S.C = O(N)}
class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            //check also is st is not empty otherwise run time error
            else if( !st.empty() && ( (ch == ')' && st.top() == '(' ) || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[') ) ){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
/*
Input: s = "()[]{}"
Output: true
*/


//53. SIMPLIFY PATH                                                              {T.C = O(N), S.C = O(N)}
//APPROACH
//take a stack and res string traverse string check for following condition
/*
The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the 
*/
//remember res poped element is reverse answer so  (/+st.top()+res)
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;

        for(int i = 0 ; i < path.size() ; i++){
            if(path[i] == '/'){
                continue;
            }
            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(!st.empty()){
                    st.pop();   
                }
            }else{
                st.push(temp);
            }
        }
        while(!st.empty()){
            res = '/'+ st.top()+ res;
            st.pop();
        }

        if(res.size() == 0){
            return "/";
        }
        return res;
    }
};
/*
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
*/


//54. MIN STACK                                                                             {T.C = O(1), S.C = O(N)}
//APPROACH
/*
Initialize two stacks, arr to store the actual elements and min_arr to store the minimum elements.
When pushing an element from the stack:
Push the element into the arr stack.
Check if the min_arr stack is not empty. If it is, simply push the element into the min_arr stack.
If the min_arr stack is not empty, calculate the minimum between the current element and the top of the min_arr stack and 
push the minimum value into the min_arr stack. This ensures that min_arr always contains the minimum value for the stack.

When popping an element from the stack:
Pop the element from both the arr and min_arr stacks. This maintains the consistency of the two stacks.

To get the top element of the stack, simply return the top element from the arr stack.

To get the minimum value of the stack, return the top element from the min_arr stack. This provides a constant time operation for retrieving the minimum.
*/
class MinStack {
public:
    stack<int>s, b;                      //s = stores original elements, b = stores minimum elements
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(!b.empty()){
            val = min(val, b.top());
        }
        b.push(val);
    }
    
    void pop() {                                     //for maintaining consistancy pop from both
        s.pop();
        b.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return b.top();
    }
};
/*
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/


//55. EVALUATE REVERSE POLISH NOTATION                                                 {T.C = O(N), S.C = O(N)}
//APPROACH
//simple implement postfix operation 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i : tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int op2 = st.top();                        //in postfix first pop element = op2
                st.pop();
                int op1 = st.top();
                st.pop();

                if(i == "+"){
                    st.push(op1 + op2);
                }
                if(i == "-"){
                    st.push(op1 - op2);
                }
                if(i == "*"){
                    st.push(op1 * op2);
                }
                if(i == "/"){
                    st.push(op1 / op2);
                }
            }else{
                int data = stoi(i);                            //string to integer
                st.push(data);
            }
        }
        return st.top();
    }
};
/*
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


//56. BASIC CALCULATOR                                                              {T.C = O(N), S.C = O(N)}
//APPROACH
//take 2 stacks (1 = integer, 2 = sign), now calculate ans
class Solution {
public:
int calculate(string s) {
            
    int value = 0;                // Current integer value
    int res = 0;                // Running result
    int sign = 1;
    stack<int> st;              // Stores intermediate results
    stack<int> stSign;          // Stores signs

    
    for(char c : s){
        if(c >= '0' && c <= '9'){
            value = value* 10 + (c-'0');
        }else if(c == '+'){
            res += sign * value;
            value = 0;
            sign = 1;
        }else if(c == '-'){
            res += sign * value;
            value = 0;
            sign = -1;
        }else if(c == '('){
            st.push(res);
            stSign.push(sign);

            res = 0; 
            sign = 1; 
        }else if(c == ')'){
            res += sign * value;
            res *= stSign.top(); stSign.pop();
            res += st.top(); st.pop();
            value = 0; 

        }
    }
    return res + sign * value;
}
};
/*
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/