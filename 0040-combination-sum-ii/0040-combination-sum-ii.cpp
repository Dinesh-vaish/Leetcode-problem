class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, vector<int>& candidates,
                   vector<int>& current, int total, int target) {

        if (total == target) {
            result.push_back(current);
            return;
        }

        if (total > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Duplicate combinations avoid
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            current.push_back(candidates[i]);

            // i + 1 because element can be used only once
            backtrack(i + 1, candidates, current,
                      total + candidates[i], target);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;

        backtrack(0, candidates, current, 0, target);

        return result;
    }
};