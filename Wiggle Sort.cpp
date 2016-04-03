class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        /*
        for(int i = 1; i < nums.size(); ++i)
        {
            // 需要交换的情况：奇数时nums[i] < nums[i - 1]或偶数时nums[i] > nums[i - 1]
            if((i % 2 == 1 && nums[i] < nums[i-1]) || (i % 2 == 0 && nums[i] > nums[i-1]))
            {
                swap(nums[i], nums[i-1]);
            }
        }
        */
        //method2:
        //sorting the numbers, then start from the second number, swap nums[i] and nums[i-1]
        sort(nums.begin(), nums.end());
        // 将数组中一对一对交换
        for(int i = 2; i < nums.size(); i += 2)
        {
            swap(nums[i], nums[i-1]);
        }
    }
};
