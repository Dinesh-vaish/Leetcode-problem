class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {

        // Word complete ho gaya
        if (index == word.size()) {
            return true;
        }

        // Boundary check
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Character match nahi karta
        if (board[row][col] != word[index]) {
            return false;
        }

        // Current cell ko visited mark karo
        char temp = board[row][col];
        board[row][col] = '#';

        // 4 directions
        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // Undo
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};