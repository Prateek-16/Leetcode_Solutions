/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool allSame(vector<vector<int>>& grid , int i , int j , int w ){
        for(int x = i ; x < i + w ; x++){
            for(int y = j ; y < j + w ; y++){
                if(grid[x][y] != grid[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    Node* construct(vector<vector<int>>&grid , int i , int j , int w){
        if(allSame(grid , i , j , w)){
            return new Node(grid[i][j] == 1 ? true : false , true);
        }
        Node* topLeft = construct(grid , i , j , w / 2);
        Node* topRight = construct(grid , i , j + w / 2 , w / 2);
        Node* bottomLeft = construct(grid , i + w / 2 , j , w / 2);
        Node* bottomRight = construct(grid , i + w / 2 , j + w/ 2 , w / 2);
        
        return new Node(true , false , topLeft , topRight , bottomLeft , bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int i = 0;  //row co-or
        int j = 0;  //col co-or
        int w = grid.size();    //length of grid
        
        return construct(grid, i , j , w);
    }
};