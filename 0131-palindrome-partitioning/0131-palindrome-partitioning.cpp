class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void backtrack(int start, string& s, vector<string>& current) {

        // Puri string partition ho gayi
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Check whether s[start...i] is palindrome
            if (!isPalindrome(s, start, i)) {
                continue;
            }

            // Choose
            current.push_back(s.substr(start, i - start + 1));

            // Explore
            backtrack(i + 1, s, current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> current;

        backtrack(0, s, current);

        return result;
    }
};