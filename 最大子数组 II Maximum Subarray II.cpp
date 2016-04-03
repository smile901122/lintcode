class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        
        int n = nums.size();
        vector<int> l(n);
        vector<int> r(n);
        
        int sum;
        int i;
        
        l[0] = sum = nums[0];
        for (i = 1; i < n; ++i) {
            if(sum < 0) sum = nums[i];
            else sum += nums[i];
            l[i] = max(l[i - 1], sum);
        }
        
        r[n - 1] = sum = nums[n - 1];
        for (i = n - 2; i >= 0; --i) {
            if(sum < 0) sum = nums[i];
            else sum += nums[i];
            r[i] = max(r[i + 1], sum);
        }
        
        sum = l[0] + r[1];
        for (i = 1; i < n - 1; ++i) {
            sum = max(sum, l[i] + r[i + 1]);
        }
        return sum;
    }
};
