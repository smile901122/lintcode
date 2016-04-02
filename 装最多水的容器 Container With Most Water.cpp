class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int n = heights.size();
        int max = 0;
        if(n < 2)   return max;
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            int area = min(heights[left], heights[right]) * (right - left);
            if(area > max)  max = area;
            if(heights[left] < heights[right])  ++left;
            else --right;
        }
        return max;
    }
};
