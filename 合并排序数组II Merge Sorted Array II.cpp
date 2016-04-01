class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        
        vector<int> res(m + n);
        int index = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0)
        {
            if(A[i] > B[j]) res[index--] = A[i--];
            else    res[index--] = B[j--];
        }
        
        while(i >= 0)   res[index--] = A[i--];
        while(j >= 0)   res[index--] = B[j--];
        return res;
    }
};
