class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n < 2)   return;
        int i = 0;
        while(i < n - 1)
        {
            if(nums[i] > nums[i + 1])   break;
            ++i;
        }
        if(i == n - 1)  return;
        reverse(nums.begin(), nums.begin() + i + 1);
        reverse(nums.begin() + i + 1, nums.end());
        reverse(nums.begin(), nums.end());
        return;
    }
};
