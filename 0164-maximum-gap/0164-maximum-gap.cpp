class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 0;

        // Minimum possible maximum gap
        int gap = (mx - mn + n - 2) / (n - 1);

        int bucketCount = (mx - mn) / gap + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        for (int num : nums) {
            int idx = (num - mn) / gap;

            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
        }

        int ans = 0;
        int prev = mn;

        for (int i = 0; i < bucketCount; i++) {

            if (bucketMin[i] == INT_MAX)
                continue;

            ans = max(ans, bucketMin[i] - prev);

            prev = bucketMax[i];
        }

        return ans;
    }
};