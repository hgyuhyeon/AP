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
    Node* quadTree(vector<vector<int>>& grid, int rs, int re, int cs, int ce) {
        if (rs > re || cs > ce) return NULL;
        
        bool isLeaf = true;
        for (int i = rs; i <= re; i++) {
            for (int j = cs; j <= ce; j++) {
                if (grid[i][j] != grid[rs][cs]) {
                    isLeaf = false;
                    break;
                }
            }
        }

        if (isLeaf) return new Node(grid[rs][cs], true);

        Node* tl = quadTree(grid, rs, (rs+re)/2, cs, (cs+ce)/2);
        Node* tr = quadTree(grid, rs, (rs+re)/2, (cs+ce)/2+1, ce);
        Node* bl = quadTree(grid, (rs+re)/2+1, re, cs, (cs+ce)/2);
        Node* br = quadTree(grid, (rs+re)/2+1, re, (cs+ce)/2+1, ce);
        return new Node(true, false, tl, tr, bl, br);
    }

    Node* construct(vector<vector<int>>& grid) {
        return quadTree(grid, 0, grid.size()-1, 0, grid.size()-1);
    }
};