class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();

        vector<vector<int> > ret(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) //注意初始化
        {
            if (obstacleGrid[i][0])     break;
            else    ret[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) 
        {
            if (obstacleGrid[0][i])     break;
            else    ret[0][i] = 1;
        }

        for (int i = 1; i < m; ++i) 
        {
            for (int j = 1; j < n; ++j) 
            {
                if (obstacleGrid[i][j]) 
                    ret[i][j] = 0;
                else 
                    ret[i][j] = ret[i -1][j] + ret[i][j - 1];
            }
        }

        return ret[m - 1][n - 1];
    }
};
