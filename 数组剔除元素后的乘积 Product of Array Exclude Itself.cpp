class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        
        //method 1
        int n = nums.size();
        vector<long long> res(n);
        long long temp = 1;
        for(int i = 0; i < n; ++i)
        {
            res[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for(int i = n - 1; i >= 0; --i)
        {
            res[i] *= temp;
            temp *= nums[i];
        }
        return res;
        
        /*
        //method 2
        int n = nums.size();
        vector<long long> productPos;
        vector<long long> productNeg;
        vector<long long> B;
        productPos.push_back(1);
        productNeg.push_back(1);
        for(int i = 1; i < n; ++i)
        {
            productPos.push_back(productPos[i-1] * nums[i-1]);
            productNeg.push_back(productNeg[i-1] * nums[n-i]);
        }
        for(int j = 0; j < n; ++j)
        {
            B.push_back(productPos[j] * productNeg[n-1-j]);
        }
        return B;
        */
    }
};
