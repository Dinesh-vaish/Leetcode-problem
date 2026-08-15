class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zerocnt =0;
        int n = nums.size();
        int total = 0;
        for(int x:nums)
        {
            total ^=x;
            if(x==0) zerocnt++;
        }
        if(total !=0) return n;
        if(zerocnt==n) return 0;
        else return n-1;
    }
};