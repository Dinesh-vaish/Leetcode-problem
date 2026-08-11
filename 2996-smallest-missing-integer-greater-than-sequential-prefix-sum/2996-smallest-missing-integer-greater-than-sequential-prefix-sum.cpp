class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum =nums[0];
        int maxsum=nums[0];
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]+1==nums[i+1]){
                sum += nums[i+1];
            }
            else{
                break;
        }}
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==sum)
            {
                sum += 1;
            }
        }
      return sum;
    }
};