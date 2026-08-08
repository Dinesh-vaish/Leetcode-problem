class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans;
        
        // last[j] = word1 me word2[j] ko match karne
        // ke liye latest possible index
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Right se matching positions find karo
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // Agar exact matching possible nahi hai,
        // tab bhi ek character change kar sakte hain.
        bool canChange = true;

        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Direct match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Ek character ko change karne ka chance
            else if (canChange &&
                     (j == m - 1 || i < last[j + 1])) {

                ans.push_back(i);
                j++;
                canChange = false;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};