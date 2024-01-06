//GRAPH BFS
#include<bits/stdc++.h>
using namespace std;

//95. SNAKES AND LADDERS
/*
finding minimum steps for this we have to perfrom bfs 
*/
class Solution {
public:
    //bfs
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>>vis(n, vector<int>(n, 0));
        queue<int>q;
        q.push(1);
        vis[n-1][0] = 1;            //first step is already visited (1 place)
        int move = 0;

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                int frontNode = q.front();
                q.pop();

                if(frontNode == n*n){     //base case or breaking or stoping point
                    return move;
                }
                for(int j = 1 ; j <= 6 ; j++){
                    int nextCell = frontNode + j;
                    if(nextCell > n*n){
                        break;
                    }

                    int nextRow = n-1 - (nextCell - 1)/n;    //finding row formula
                    int nextCol = (nextCell-1) % n;          //finding col formula

                    if(nextRow % 2 == n % 2){
                        nextCol = n-nextCol-1;
                    }

                    if(!vis[nextRow][nextCol]){
                        vis[nextRow][nextCol] = 1;
                        if(board[nextRow][nextCol] != -1){
                            q.push(board[nextRow][nextCol]);
                        }else{
                            q.push(nextCell);         //board[r][c] or snack or ladder's value
                        }
                    }
                }
            }
            move++;
        }
        return -1;
    }
};
/*

Example 1:
Input: board = [[-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,35,-1,-1,13,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.

Example 2:
Input: board = [[-1,-1],[-1,3]]
Output: 1
*/


//96. MIIMUM GENETIC MUTATION
/*
create a set for storing unique strings and queue for bfs if with the each iteration the final node or string same as pervious return count of steps 
else return -1 
*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>vis;
        queue<string>q;
        q.push(startGene);
        vis.insert(startGene);
        int count = 0;
        
        while(!q.empty()){
            int n = q.size();           //update size of queue with each iteration
            for(int i = 0 ; i < n ; i++){
                string frontNode = q.front();
                q.pop();
                if(frontNode == endGene){
                    return count;
                }
                for(auto it : "ACGT"){
                    for(int j = 0 ; j < frontNode.size() ; j++){
                       string adjNode = frontNode;
                       adjNode[j] = it;
                       //not visited and also present in the bank
                       if(!vis.count(adjNode) && find(bank.begin(), bank.end(), adjNode) != bank.end()){
                           q.push(adjNode);
                           vis.insert(adjNode);
                       } 
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
/*
Example 1:
Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Example 2:
Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
*/


//97. WORD LADDER
/*
similar to above
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());      //insert all elements in set
        st.erase(beginWord);
        while(!q.empty()){
            pair<string,int> frontNode=q.front();
            string word=frontNode.first;
            int steps=frontNode.second;
            q.pop();

            //check for destination 
            if(word==endWord)
                return steps;
            for(int i=0;i<word.length();i++){
                char orig=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=orig;                                    // Revert back for the next iteration call
            }
        }
        return 0;                                                //Transformation not possible
    }
};
/*
Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/