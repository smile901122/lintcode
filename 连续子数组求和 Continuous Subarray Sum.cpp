class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        
        vector<int> res(2);
        int sum = 0;
        int max = INT_MIN;
        int index = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            if(sum < 0)
            {
                sum = A[i];
                index = i;
            }
            else    sum += A[i];
            
            if(sum > max)   
            {
                max = sum;
                res[0] = index;
                res[1] = i;
            }
        }
        return res;
        
        /*
        int n = A.size();
        int ll;
        int sum;
        int msum;
        
        ll = 0;
        msum = A[0];
        int i;
        for (i = 1; i < n; ++i) {
            if (A[i] > msum) {
                msum = A[i];
                ll = i;
            }
        }
        vector<int> ans;
        if (msum <= 0) {
            ans.push_back(ll);
            ans.push_back(ll);
            return ans;
        }
        
        int mll, mrr;
        ll = 0;
        msum = sum = 0;
        for (i = 0; i < n; ++i) {
            sum += A[i];
            if (sum < 0) {
                sum = 0;
                ll = i + 1;
            }
            if (sum > msum) {
                msum = sum;
                mll = ll;
                mrr = i;
            }
        }
        ans.push_back(mll);
        ans.push_back(mrr);
        return ans;
        */
    }
};
