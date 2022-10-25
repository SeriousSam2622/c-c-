class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size(), sum=0, max=nums[0];
        for (auto it : nums)
        {
            sum = sum + it;
            if(sum>max)
                max=sum;
            if(sum<0)
                sum=0;
        }
        return max;
    }
};
