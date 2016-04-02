class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        vector<vector<int> > &a = triangle;
        for(int i = a.size() - 2; i >= 0; --i)
        {
            for(int j = 0; j <= i; ++j)
            {
                a[i][j] += min(a[i + 1][j], a[i + 1][j + 1]);
            }
        }
        return a[0][0];
    }
};
