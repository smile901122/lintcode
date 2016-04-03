class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int a1 = 0, a2 = 0;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; ++i)
        {
            if(c1 == 0 || a1 == nums[i])
            {
                a1 = nums[i];
                ++c1;
            }
            else if(c2 == 0 || a2 == nums[i])
            {
                a2 = nums[i];
                ++c2;
            }
            else
            {
                --c1;
                --c2;
            }
        }
        c1 = c2 =0;
        for(int i = 0; i < n; ++i)
        {
            if(a1 == nums[i])   ++c1;
            else if(a2 == nums[i])  ++c2;
        }
        return c1 > c2 ? a1 : a2;
    }
};
