class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.empty())   return -1;
        int l = 0;
        int r = A.size() - 1;
        while(l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if(A[mid] == target)    return mid;
            
            if(A[l] < A[mid])
            {
                if(A[l] <= target && target < A[mid])    r = mid - 1;
                else    l = mid + 1;
            }
            else
            {
                if(A[mid] < target && target <= A[r])    l = mid + 1;
                else    r = mid - 1;
            }
        }
        if(A[l] == target)  return l;
        if(A[r] == target)  return r;
        return -1;
    }
};
