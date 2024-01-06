//MATRIX
#include<bits/stdc++.h>
using namespace std;

//34. VALID SUDOKU                                                               {T.C = O(1), S.C = O(1)}
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for(int i = 0 ; i < 9 ; i++){                    //i == row, j == col
            for(int j = 0 ; j < 9 ; j++){
                int boxIndex = (i/3)*3 + j/3;
                if(board[i][j] != '.'){
                    string row = "r" + to_string(i) + board[i][j];
                    string col = "c" + to_string(j) + board[i][j];
                    string box = "b" + to_string(boxIndex) + board[i][j];
                    //already string is present in set
                    if(st.count(row) || st.count(col) || st.count(box)){
                        return false;
                    }
                    st.insert(row);
                    st.insert(col);
                    st.insert(box);
                }
            }
        }
        return true;
    }
};
/*
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
*/


//35. SPIRAL MATRIX                                                            {T.C = O(N*M), S.C = O(N)}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int>ans;
        int r = matrix.size();
        int c = matrix[0].size();
        
        int left = 0;
        int right = c-1;                                   //r = mat.size() , c = mat[0].size();
        int top = 0;
        int bottom = r-1;
        
        //flow of traversal == right->bottom->left->top
        while(left <= right && top <= bottom){
            //right
            for(int i = left ; i <= right ; i++ ){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //bottom
            for(int i = top ; i <= bottom ; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //left
            if(top <= bottom){                                 //extra check
                for(int i = right ; i >= left ; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                
            }

            //top
            if(left <= right){                                  //extra check
                for(int i = bottom ; i >= top ; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
/*
Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/


//36. ROTATE IMAGE (90 DEGREE)                                                 {T.C = O(N^2), S.C = O(1)}
//APPROACH
// 1. TRANSPOSE MATRIX , 2. REVERSE ROWS ELEMENTS
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //transpose of matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){            //j from i not 0
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse each row
        for(int i = 0 ; i < n ; i++){
            int left = 0;
            int right = n-1;
            while(left < right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};
/*
Input: matrix = [[5,1,9,11]
                ,[2,4,8,10],
                 [13,3,6,7],
                 [15,14,12,16]]
Output: [[15,13,2,5]
       ,[14,3,4,1],
        [12,6,8,9],
        [16,7,10,11]]
*/


//37. SET MATRIX ZEROES
//APRROACH 1(BRUTE FORCE)                                                        {T.C = O(N^3), S.C = O(N^2)}
//use 2d matrix store ans in this then copy element in original matrix 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>vis = matrix;

        //row 0
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < n ; k++){
                        vis[k][j] = 0;
                    }
                }
            }
        }

        //col 0
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0 ; k < m ; k++){
                        vis[i][k] = 0;
                    }
                }
            }
        }

        //now copy visited matrix to actual matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = vis[i][j];
            }
        }
    }
};
//APPROACH 2(using 2 single vectors)                                              {T.C = O(N^2), S.C = O(N)}
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n+1, 0);
        vector<int>col(m+1, 0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(row[i] || col[j]){                //if row or col updated(to 1)
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//OPTIMIZED                                                                 {T.C = O(N^2), S.C = O(1)}
/*
Input: matrix = [
                 [1,1,1],
                 [1,0,1],
                 [1,1,1]
                ]
Output: [
         [1,0,1]
        ,[0,0,0],
         [1,0,1]
        ]
*/


//38. GAME OF LIFE                                                          {T.C = O(N*M), S.C = O(1)}
//APPROACH
//store all cordinates in array then check 4 cases according to quesiton
class Solution {
public:
    bool isValidNbr(int x, int y , vector<vector<int>>&board){
        return ( (x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size()) );
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        //all 8 coordinates
        int delRow[8] = {0, 1, 0, -1, 1, 1, -1, -1};
        int delCol[8] = {1, 0, -1, 0, -1, 1, 1, -1};

        for(int row = 0; row < n ; row++){
            for(int col = 0; col < m ; col++){
                int countNbr = 0;

                for(int i = 0 ; i < 8 ; i++){
                    int currRow = row + delRow[i];
                    int currCol = col + delCol[i];
                    
                    if(isValidNbr(currRow, currCol, board) && abs(board[currRow][currCol]) == 1){
                        countNbr++;
                    }
                }
                if(board[row][col] == 1 && (countNbr < 2 || countNbr > 3)){
                    board[row][col] = -1;
                }else if(board[row][col] == 0 && countNbr == 3){
                    board[row][col] = 2;
                }
            }
        } 

        for(int row = 0 ; row < n ; row++){
            for(int col = 0; col < m ; col++){
                if(board[row][col] >= 1){
                    board[row][col] = 1;
                }else{
                    board[row][col] = 0;
                }
            }
        }       
    }
};
/*
Input: board = [
                [0,1,0],
                [0,0,1],
                [1,1,1],
                [0,0,0]
               ]
Output: [ 
         [0,0,0],
         [1,0,1],
         [0,1,1],
         [0,1,0]
        ]
*/