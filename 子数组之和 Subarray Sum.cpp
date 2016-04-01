class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        /*
        vector<int> result;
        int sum;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum = 0;
            for(int j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                if(sum == 0)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
        */
        
        vector<int> res(2,-1);
        if(nums.empty())    return res;
        int n = nums.size();
        unordered_map<int, int> sum_map;
        int sum = 0;
        for (int i = 0; i < n; ++i) 
        {
            sum += nums[i];
            if (sum == 0) 
            {
                res[0] = 0;
                res[1] = i;
                return res;
            }
            if (sum_map.find(sum) != sum_map.end()) 
            {
                res[0] = sum_map[sum] + 1;
                res[1] = i;
                return res;
            }
            sum_map[sum] = i;
        }
        return res;
        
    }
};
