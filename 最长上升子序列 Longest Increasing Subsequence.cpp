class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(nums.empty())    return 0;
        vector<int> v;
        int res;
        v.push_back(nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] >= v.back())
            {
                v.push_back(nums[i]);
                continue;
            }
            
            auto j = lower_bound(v.begin(), v.end(), nums[i]);  //返回的是迭代器
            *j = nums[i];
        }
        res = v.size();
        return res;
    }
};
