class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        if(A.empty() || m < 1)  return 0;
        vector<int> bp(m + 1, -1);
        int n = A.size();
        
        bp[0] = 0;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = m; j >= A[i]; --j) 
            {
                if (bp[j - A[i]] >= 0) 
                    bp[j] = max(bp[j], bp[j - A[i]] + V[i]);
            }
        }
        int res = 0;
        for (auto val : bp) {
            res = max(res, val);
        }
        return res;
    }
};
