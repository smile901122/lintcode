class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> l_max(n);
        vector<int> l_min(n);
        vector<int> r_max(n);
        vector<int> r_min(n);
        
        int sum;
        int i;
        
        l_max[0] = sum = nums[0];
        for (i = 1; i < n; ++i) {
            if(sum < 0) sum = nums[i];
            else sum += nums[i];
            l_max[i] = max(l_max[i - 1], sum);
        }
        
        l_min[0] = sum = nums[0];
        for (i = 1; i < n; ++i) {
            if(sum > 0) sum = nums[i];
            else sum += nums[i];
            l_min[i] = min(l_min[i - 1], sum);
        }
        
        r_max[n - 1] = sum = nums[n - 1];
        for (i = n - 2; i >= 0; --i) {
            if(sum < 0) sum = nums[i];
            else sum += nums[i];
            r_max[i] = max(r_max[i + 1], sum);
        }
        
        r_min[n - 1] = sum = nums[n - 1];
        for (i = n - 2; i >= 0; --i) {
            if(sum > 0) sum = nums[i];
            else sum += nums[i];
            r_min[i] = min(r_min[i + 1], sum);
        }
        
        int diff = INT_MIN;
        for (i = 0; i < n - 1; ++i) 
        {
            diff = max(diff, abs(l_max[i] - r_min[i + 1]));
            diff = max(diff, abs(l_min[i] - r_max[i + 1]));
        }
        return diff;
    }
};
