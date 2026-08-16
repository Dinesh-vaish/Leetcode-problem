class Solution {
public:

    bool backtrack(int index, vector<int>& nums,
                   vector<int>& bucket, int target) {

        // Saare elements use ho gaye
        if (index == nums.size()) {
            return true;
        }

        for (int i = 0; i < bucket.size(); i++) {

            // Current number ko bucket mein add karo
            if (bucket[i] + nums[index] > target) {
                continue;
            }

            bucket[i] += nums[index];

            // Next element
            if (backtrack(index + 1, nums, bucket, target)) {
                return true;
            }

            // Undo
            bucket[i] -= nums[index];

            // Empty buckets ko baar-baar try karne ki zarurat nahi
            if (bucket[i] == 0) {
                break;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int total = 0;

        for (int x : nums) {
            total += x;
        }

        // Total sum k se divisible nahi hai
        if (total % k != 0) {
            return false;
        }

        int target = total / k;

        vector<int> bucket(k, 0);

        // Large elements pehle try karna optimization hai
        sort(nums.rbegin(), nums.rend());

        return backtrack(0, nums, bucket, target);
    }
};