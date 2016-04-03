class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        if(nums.empty())    return nums;
        vector<int> res;
        const int size = nums.size();
        vector<pair<int, int> > sum_index(size + 1);
        for(int i = 0; i < size; ++i)
        {
            sum_index[i + 1].first = sum_index[i].first + nums[i];
            sum_index[i + 1].second = i + 1;
        }
        sort(sum_index.begin(), sum_index.end());
        
        int min_diff = INT_MAX;
        int closest_index = 1;
        for(int i = 1; i < size + 1; ++i)
        {
            int sum_diff = sum_index[i].first - sum_index[i - 1].first;
            if(min_diff > sum_diff)
            {
                min_diff = sum_diff;
                closest_index = i;
            }
        }
        
        int left = min(sum_index[closest_index - 1].second, sum_index[closest_index].second);
        int right = max(sum_index[closest_index - 1].second, sum_index[closest_index].second) - 1;
        res.push_back(left);
        res.push_back(right);
        
        return res;
    }
};
