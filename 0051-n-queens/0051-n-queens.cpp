class Solution {
public:
    vector<vector<string>> ans;

    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    void backtrack(int row, int n, vector<string>& board) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            // Check if position is safe
            if (cols.count(col) ||
                diag1.count(row - col) ||
                diag2.count(row + col)) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';

            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            // Move to next row
            backtrack(row + 1, n, board);

            // Backtrack
            board[row][col] = '.';

            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(
            n,
            string(n, '.')
        );

        backtrack(0, n, board);

        return ans;
    }
};