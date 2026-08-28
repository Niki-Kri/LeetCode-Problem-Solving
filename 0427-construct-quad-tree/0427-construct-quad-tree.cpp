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
    Node* construct(vector<vector<int>>& grid) {
        return buildTree(grid, 0, 0, grid.size());
    }
    Node* buildTree(vector<vector<int>>& grid, int row, int col, int size) {
        bool allSame = true;
        int firstValue = grid[row][col];
        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (grid[i][j] != firstValue) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) break;
        }
        if (allSame) {
            bool nodeValue = (firstValue == 1);
            return new Node(nodeValue, true, NULL, NULL, NULL, NULL);
        }
        int halfSize = size / 2;
        Node* topLeft = buildTree(grid, row, col, halfSize);
        Node* topRight = buildTree(grid, row, col + halfSize, halfSize);
        Node* bottomLeft = buildTree(grid, row + halfSize, col, halfSize);
        Node* bottomRight = buildTree(grid, row + halfSize, col + halfSize, halfSize);
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};