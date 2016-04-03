class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        if(nums.empty())    return INT_MIN;
        int n = nums.size();
        int max_temp;
        int min_temp;
        int res = nums[0];
        int min_p = nums[0];
        int max_p = nums[0];
        for(int i = 1; i < n; ++i)
        {
            min_temp = min(nums[i], min(nums[i] * min_p, nums[i] * max_p));
            max_temp = max(nums[i], max(nums[i] * min_p, nums[i] * max_p));
            min_p = min_temp;
            max_p = max_temp;
            res = max(res, max_p);
        }
        return res;
    }
};
