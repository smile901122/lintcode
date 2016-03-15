class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty())    return INT_MAX;
        int sum = nums[0];
        int min = sum;
        int n = nums.size();
        //该问题类似于最大和的子数组
        //最大和子数组是当当前和<0时抛弃该当前和
        //本题为当前值和>0时抛弃当前和
        for(int i = 1; i < n; ++i)
        {
            if(sum > 0)    sum = nums[i];
            else    sum += nums[i];
            
            if(sum < min)   min = sum;
        }
        return min;
    }
};
