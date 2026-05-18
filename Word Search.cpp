class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        
        // Entire word matched
        if(index == word.size()) {
            return true;
        }

        // Boundary + character mismatch check
        if(r < 0 || c < 0 || r >= board.size() || 
           c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // Store current character
        char temp = board[r][c];

        // Mark visited
        board[r][c] = '#';

        // Explore 4 directions
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();

        // Try starting from every cell
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};