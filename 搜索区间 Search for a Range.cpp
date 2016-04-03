class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> result = {-1, -1};
        if(A.empty())    return result;
        int l = -1, r = A.size();
        while(l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if(A[mid] < target) l = mid;
            else    r = mid;
        }
        if(r < A.size() && A[r] == target)    result[0] = r;
        else    return result;
        r = A.size();
        while(l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if(A[mid] > target) r = mid;
            else    l = mid;
        }
        result[1] = r - 1;
        return result;
    }
};
