//TRIE
#include<bits/stdc++.h>
using namespace std;

//98.  IMPLEMENT TRIE (PREFIX TREE)                                       {T.C = O(N + N), S.C = O(N*M {no. of word , lenghth of word})}
/*
//trie's main functions = insert, search, delete
//first we have to create a struct (isEndOfWord, child array)
//second we have to write function for creating new node for an trie
//initialize trieNode with root
//write for insert and with some upgradation search and startswith fucntion made
*/
class Trie {
public:
    struct trieNode{                   //basic requirement of trie is endofword and child
        bool isEndOfWord;
        trieNode *child[26];
    };

    trieNode *getNode(){              //for making newnode in trie
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;     //endofword should be false for new node
        for(int i = 0 ; i < 26 ; i++){
            newNode->child[i] = NULL;     //creating empty vector
        }
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    //if we create insert then search and and starts with is just slight updation of code

    void insert(string word) {  //apple
        trieNode* crawler = root;             //crawler work as iterator
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){
                crawler->child[idx] = getNode();  //'a'
            }
            crawler = crawler->child[idx];       //move forward
        }
        crawler->isEndOfWord = true;      //'e' reach end
    }
    
    bool search(string word) {  //'apple'
        trieNode* crawler = root;             //crawler work as iterator
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){    //character in the word being searched for doesn't exist in the trie
                return false;
            }
            crawler = crawler->child[idx];       //move forward
        }
        if(crawler != NULL && crawler->isEndOfWord == true){  //'e'
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) { //'app'
        trieNode* crawler = root;             //crawler work as iterator
        int i = 0;
        for(i = 0 ; i < prefix.length() ; i++){    //same as search just word => prefix
            char ch = prefix[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){    //character in the word being searched for doesn't exist in the trie
                return false;
            }
            crawler = crawler->child[idx];       //move forward
        }
        if(i == prefix.length()){
            return true;
        }
        return false;
    }
};
/*
Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/


//99. DESIGN ADD AND SEARCH WORDS DATA STRUCTURE                                       {T.C = O(N + N), S.C = O(N*M {no. of word , lenghth of word})}
/*
same approach as above but slightly differnce because in this '.' dot char may be include so that we have to handle seperatly
*/
class WordDictionary {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* child[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;
        for(int i = 0 ; i < 26 ; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }  

    trieNode* root;

    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        trieNode* crawler = root;
        for(int i = 0 ; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(crawler->child[idx] == NULL){
                crawler->child[idx] = getNode();
            }
            crawler = crawler->child[idx];
        }
        crawler->isEndOfWord = true;
    }
    
    bool searchHelper(string &word, int index, trieNode* crawler){
        //base case
        if(index == word.length()){
            if(crawler != NULL && crawler->isEndOfWord == true){
                return true;
            }
            return false;
        }

        if(word[index] == '.'){
            for(int i = 0 ; i  < 26 ; i++){
                if(crawler->child[i] != NULL && searchHelper(word, index+1, crawler->child[i])){
                    return true;
                }
            }
            return false;
        }else{
            int idx = word[index]-'a';
            if(crawler->child[idx] == NULL){
                return false;
            }
            return searchHelper(word, index+1, crawler->child[idx]);
        }
    }
    bool search(string word) {
        trieNode* crawler = root;
        return searchHelper(word, 0, crawler);            //0 = index
    }
};
/*
Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
*/


//100a. WORD SEARCH                                                         {T.C = O(N*M*4*L), S.C = O(N*M)}
/*
simple dfs , start from 0th postion and keep a letter constant search word in all directions
*/
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int i, int j, vector<vector<bool>>& visited) {
        // Base case: Entire word found
        if (idx == word.length()) {
            return true;
        }

        // Boundary check and character match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[idx]) {
            return false;
        }

        // Mark cell as visited
        visited[i][j] = true;

        // Check in all 4 directions
        bool found = dfs(board, word, idx + 1, i + 1, j, visited) ||
                     dfs(board, word, idx + 1, i - 1, j, visited) ||
                     dfs(board, word, idx + 1, i, j + 1, visited) ||
                     dfs(board, word, idx + 1, i, j - 1, visited);

        // Mark cell as unvisited after exploration
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        // Initialize a visited matrix to track visited positions
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
Example 1:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "ABCCED"
Output: true
Example 2:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "SEE"
Output: true
*/


//100b. WORD SEARCH II                                                               {T.C = O(N*M*4^L), S.C = O(N*M)}
/*
we cant use simple dfs like above it will increase the time compelxity so that's why we use trie so that we can traverse only once
*/
class Solution {
public:
    //global ans vector
    vector<string> result;

    vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};
    struct trieNode{
        bool isEndOfWord;
        string word;
        trieNode *child[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        newNode->word = "";
        for(int i = 0 ; i < 26 ; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string word){
        trieNode* crawler = root;                  //iterator
        for(int i = 0 ; i < word.length() ; i++){
            int idx = word[i]-'a';
            if(crawler->child[idx] == NULL){
                crawler->child[idx] = getNode();
            }
            crawler = crawler->child[idx];         //move forward
        }
        crawler->isEndOfWord = true;
        crawler->word = word;
    }

void search(vector<vector<char>>& board, trieNode* root, int i, int j){

    //base case
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '$' || root->child[board[i][j] - 'a'] == NULL){
        return;
    }
    int idx = board[i][j] - 'a';
    root = root->child[idx];       //move forward

    if(root->isEndOfWord == true){
        result.push_back(root->word);
        root->isEndOfWord = false; // Marking the word as found
    }
    char temp = board[i][j];       //store current charcter
    board[i][j] = '$';             //mark visited

    //explore all 4 directions
    for(auto p : directions){         //p = pair {{-1, 0}, ...}
        int new_i = i + p.first;
        int new_j = j + p.second;
        search(board, root, new_i, new_j);
    }
    board[i][j] = temp; //reset the board cell to its original character
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        int col = board[0].size();

        //create root
        trieNode* root = getNode();

        //insert word in trie
        for(auto it : words){
            insert(root, it);
        }      

        //traverse in grid (only once)
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int idx = board[i][j] - 'a';
                if(root->child[idx] != NULL){
                    search(board, root, i, j);       //after finding word push in vector (result)
                }
            }
        }
        return result;
    }
};
/*
Example 1:
Input: board = [["o","a","a","n"],
                ["e","t","a","e"],
                ["i","h","k","r"],
                ["i","f","l","v"]], 
                words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],
                ["c","d"]], 
                words = ["abcb"]
Output: []
*/