class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        /*
        //解法1：时间复杂度O(n),空间复杂度O(n)
        int res = 0;
        const int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 1; i < n; ++i)
        {
            left[i] = max(left[i - 1], heights[i - 1]);
            right[n - 1 - i] = max(right[n - i], heights[n - i]);
        }
        for(int i = 1; i < n - 1; ++i)
        {
            int h = min(left[i], right[i]);
            if(h > heights[i])
                res += h - heights[i]; 
        }
        return res;
        */
        //解法2：时间复杂度O(n),空间复杂度O(n)
        int max = 0;
        const int n = heights.size();
        int res = 0;
        for(int i = 0; i < n; ++i)
            if(heights[i] > heights[max])   max = i;
        for(int peak = 0, i = 0; i < max; ++i)
        {
            if(heights[i] > peak)   peak = heights[i];
            res += peak - heights[i];
        }
        for(int peak = 0, i = n - 1; i > max; --i)
        {
            if(heights[i] > peak)   peak = heights[i];
            res += peak - heights[i];
        }
        return res;
    }
};
