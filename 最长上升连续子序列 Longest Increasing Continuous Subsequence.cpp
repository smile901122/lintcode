class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        if(A.empty())   return 0;
        int n = A.size();
        
        int max = 1;
        int count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(A[i] > A[i - 1])  ++count;
            else    count = 1;
            if(count > max)  max = count;
        }
        
        count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(A[i] < A[i - 1])  ++count;
            else    count = 1;
            if(count > max)  max = count;
        }
        
        return max;
    }
};
