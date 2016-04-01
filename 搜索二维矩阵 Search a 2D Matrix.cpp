class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty()) return false;
        int start = 0;
        int m = matrix.size();
        int n = matrix.front().size();
        int end = m * n - 1;
        int middle;
        int value;
        while(start <= end)
        {
            middle = (start + end) / 2;
            value = matrix[middle / n][middle % n];
            if(value == target) return true;
            else if(value > target) end = middle - 1;
            else    start = middle + 1;
        }
        return false;
    }
};
