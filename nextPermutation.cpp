class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=0;
        for(int i=1;i<nums.size();i++)
            if(nums[i-1]<nums[i])
                index=i;
        if(index>0)
        {
            int i=nums.size()-1;
            while(i>(index-1) && nums[index-1]>=nums[i])
                i--;
            swap(nums[index-1],nums[i]);
        }
        sort(nums.begin()+index,nums.end());
    }
};