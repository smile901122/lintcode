class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if(A.empty() || m < 1)  return 0;
        vector<bool> bp(m + 1, false);
        
        bp[0] = true;
        int n = A.size();
        
        for (int i = 0; i < n; ++i) 
        {
            for (int j = m; j >= A[i]; --j) 
            {
                if (bp[j - A[i]])   bp[j] = true;
            }
        }
        int k = m;
        while (!bp[k]) {
            --k;
        }
        return k;
    }
};
