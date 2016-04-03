class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if(A.empty())   return false;
        int l = 0;
        int r = A.size() - 1;
        
        while(l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if(A[mid] == target)    return true;
            
            while(A[l] == A[r]) ++l;
            if(A[l] < A[mid])
            {
                if(A[l] <= target && target < A[mid])   r = mid - 1;
                else    l = mid + 1;
            }
            else if(A[l] > A[mid])
            {
                if(A[mid] < target && target <= A[r])   l = mid + 1;
                else    r = mid - 1;
            }
            else
            {
                while(l + 1 < r && A[l + 1] == A[l])    ++l;
                //++l;
            }
        }
        if(A[l] == target)  return true;
        if(A[r] == target)  return true;
        return false;
    }
};
