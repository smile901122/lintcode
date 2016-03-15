class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty())    return INT_MIN;
        int n = nums.size();
        int sum = nums[0];
        int max = nums[0];
        for(int i = 1; i < n; ++i)
        {
            if(sum < 0) sum = nums[i];
            else    sum += nums[i];
            
            if(max < sum)   max = sum;
        }
        return max;
    }
};
