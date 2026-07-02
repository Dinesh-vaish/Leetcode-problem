class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int mind = 0;
        int maxd = nums.back() - nums.front();

        while (mind < maxd) {
            int mid = mind + (maxd - mind) / 2;

            if (countPairs(nums, mid) < k)
                mind = mid + 1;
            else
                maxd = mid;
        }

        return mind;
    }

    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > mid)
                left++;

            count += right - left;
        }

        return count;
    }
};
