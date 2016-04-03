class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        
        if(nums.size() == 0) return 0;
        int i = 0;
        int j = nums.size()-1;
        while(i < j)
        {
            while(nums[i] < k && i<j)  ++i;
            while(nums[j] >= k && i<j) --j;
            if(i < j)
                swap(nums[i],nums[j]);
        }
        if(i == nums.size()-1)    return nums.size();
        if(nums[i] < k) ++i;
        return i;
        
        /*
        if(nums.size() == 0) return 0;
        int j = 0;
        for(int i = 0;i < nums.size(); ++i)
        {
            if(nums[i] < k) 
            {
                swap(nums[i],nums[j]);
                ++j;
            }
        }
        return j;
        */


    }
};
