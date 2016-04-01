class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n < 3)  return n;
        int c = 1;
        
        for(int i = 1; i < n; ++i, ++c)
        {
            if(nums[i] == nums[i - 1])
            {
                nums[c] = nums[i];
                ++i;
                ++c;
                while(i < n && nums[i] == nums[i - 1])   ++i;
                if(i == n)   return c;
            }
            nums[c] = nums[i];
        }
        return c;
        
        /*
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] != nums[c] || nums[i] != nums[c - 1]) 
            {
                ++c;
                nums[c] = nums[i];
            }
        }
        return c + 1;
        */
    }
};
