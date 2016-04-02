class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        const int target = 0;
        int n = nums.size();
        for(int i = 0; i < n-2; ++i) 
        {
            if(i > 0 && nums[i] == nums[i-1])    continue;
            int j = i+1;
            int k = n-1;
            while (j < k) 
            {
                if (nums[i] + nums[j] + nums[k] < target) 
                {
                    ++j;
                    while(nums[j] == nums[j - 1] && j < k)  ++j;
                } 
                else if (nums[i] + nums[j] + nums[k] > target) 
                {
                    --k;
                    while(nums[k] == nums[k + 1] && j < k)  --k;
                } 
                else 
                {
                    result.push_back({ nums[i], nums[j], nums[k] });
                    ++j;
                    --k;
                    while(nums[j] == nums[j - 1] && nums[k] == nums[k + 1] && j < k) ++j;
                }
            }
        }
        return result;
    }
};
