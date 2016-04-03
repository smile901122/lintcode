class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        //if(A.size() == 0 || B.size() == 0)  return 0;
        int count = 0;
        for(int m = 0; m < A.size(); ++m)
        {
            for(int n = 0; n < B.size(); ++n)
            {
                if(A[m] == B[n])
                {
                    int i = 1;
                    while(m + i < A.size() && n + i < B.size() && A[m + i] == B[n + i])
                    {
                        ++i;
                    }
                    if(i > count)   count = i;
                }
            }
        }
        return count;
    }
};
