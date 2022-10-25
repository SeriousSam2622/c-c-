class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int rep=-1;
        for (int i=0; i<nums.size(); i++) 
        {
            int current=abs(nums[i]);
            if (nums[current] < 0) 
            {
                rep = current;
                break;
            }
            nums[current] *= -1;
        }
        for (auto& num : nums)
            num = abs(num);
        
        return rep;
        
    }
};
