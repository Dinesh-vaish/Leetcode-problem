class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, vector<int>& nums, vector<int>& current) {

        // Every current is a valid subset
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate elements at same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Choose
            current.push_back(nums[i]);

            // Explore
            backtrack(i + 1, nums, current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> current;

        backtrack(0, nums, current);

        return result;
    }
};