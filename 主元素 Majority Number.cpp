class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int count = 0;
        int target;
        for(int i = 0; i < n; ++i)
        {
            if(count == 0)  
            {
                target = nums[i];
                ++count;
            }
            else if(nums[i] == target) ++count;
            else --count;
        }
        //if(count == 0)，则无超过一半的字符，则wrong
        //需要复查
        count = 0;
        for(auto i : nums)
        {
            if(target == i) ++count;
        }
        if(count >= (n + 1) / 2)   return target;
    }
};
