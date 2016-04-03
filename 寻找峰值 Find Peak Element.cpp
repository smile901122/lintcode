class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if (A.size() == 0) return -1;

        int l = 0, r = A.size() - 1;
        while (l + 1 < r) 
        {
            int mid = l + (r - l) / 2;
            
            if (A[mid] < A[mid - 1]) 
                r = mid;
            else if (A[mid] < A[mid + 1]) 
                l = mid;
            else 
                return mid;
        }

        int mid = A[l] > A[r] ? l : r;
        return mid;
    }
};
