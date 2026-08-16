class Solution {
public:
    int ans = 0;

    unordered_set<int> cols;
    unordered_set<int> diag1;  // row - col
    unordered_set<int> diag2;  // row + col

    void backtrack(int row, int n) {

        // All queens placed
        if (row == n) {
            ans++;
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
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            backtrack(row + 1, n);

            // Backtrack
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    int totalNQueens(int n) {
        backtrack(0, n);
        return ans;
    }
};