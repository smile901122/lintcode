class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        /*
        int num = 1 << n;
        int i = 0;
        while(i < num)
        {
            res.push_back((i >> 1) ^ i);    //  (i>>1)^i
            ++i;
        }
        return res;
        */
        //method 2
        if(n == 0)
        {
            res.push_back(0);
            return res;
        }
        int halfnum = 1 << (n - 1);
        vector<int> g_c_pre = grayCode(n - 1);
        for(int i = 0; i < halfnum; ++i)
        {
            res.push_back(g_c_pre[i]);
        }
        int num = 1 << n;
        for(int j = halfnum; j < num; ++j)
        {
            res.push_back(g_c_pre[num - j - 1] + halfnum);
        }
        
        return res;
    }
};
