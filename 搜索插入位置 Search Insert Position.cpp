class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0)  return 0;
        if(A[0] >= target)  return 0;
        int start = 0;
        int end = A.size()-1;
        while(start <= end)
        {
            int median = (start + end) / 2;
            if(A[median] == target)  return median;
            else if(A[median] > target) end = median-1;
            else start = median + 1;
        }
        return start;
    }
};
