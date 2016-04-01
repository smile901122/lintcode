class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        if(nums.empty())    return 0;
        int length = nums.size();
        return quickSelect(nums, 0, length - 1, (length - 1) / 2);
    }
private:
    int quickSelect(vector<int> &a, int l, int r, int k)
    {
        if(l == r)  return a[k];
        
        int pivot = a[l];
        int i = l + 1;
        int j = r;
        
        while(i <= j)
        {
            while(i <= j && a[i] < pivot)   ++i;
            while(i <= j && a[j] > pivot)   --j;
            if(i <= j)
            {
                swap(a[i++], a[j--]);
            }
        }
        swap(a[j], a[l]);
        if(j == k)  return a[k];
        else if(j < k)  return quickSelect(a, j + 1, r, k);
        else    return quickSelect(a, l, j - 1, k);
    }
};
