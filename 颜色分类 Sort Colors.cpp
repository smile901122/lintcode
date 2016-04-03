class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        
        //method 1
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j)
        {
            while(i <= j && nums[i] == 0) ++i;
            while(i <= j && nums[j] != 0) --j;
            if(i < j)
            {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        i = ++j;
        j = nums.size() - 1;
        while(i <= j)
        {
            while(i <= j && nums[i] == 1) ++i;
            while(i <= j && nums[j] == 2) --j;
            if(i < j)
            {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        
        /*
        //method 2
        auto &a = nums;
        int n = a.size();
        vector<int> c(3, 0);
        int i;
        for (i = 0; i < n; ++i) {
            ++c[a[i]];
        }
        int j, k = 0;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < c[i]; ++j) {
                a[k++] = i;
            }
        }
        */
    }
};
