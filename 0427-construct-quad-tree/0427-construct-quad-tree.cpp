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
    Node* solve(vector<vector<int>>& grid, int x1, int y1, int length){
        if(length == 1){
            return new Node(grid[x1][y1], true);
        }
        Node* topleft = solve(grid, x1, y1, length/2);
        Node* topright = solve(grid, x1, y1+length/2, length/2);
        Node* bottomright = solve(grid, x1+length/2, y1+length/2, length/2);
        Node* bottomleft = solve(grid, x1+length/2, y1, length/2);
        
        if(topleft->isLeaf && topright ->isLeaf && bottomleft ->isLeaf && bottomright ->isLeaf &&topleft ->val == topright->val && topright->val == bottomleft->val && bottomleft->val == bottomright->val){
            return new Node(topleft->val, true);
        }
        return new Node(false, false, topleft, topright, bottomleft, bottomright);
    }
    
    Node* construct(vector<vector<int>>&grid){
        return solve(grid, 0, 0, grid.size());
    }
    
};