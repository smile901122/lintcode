class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<int> v;
        v.push_back(1);
        int count = 1;
        int i, j, k;
        i = j = k = 0;
        while(count < n)
        {
            int m = min(min(v[i] * 2, v[j] * 3), v[k] * 5);
            v.push_back(m);
            while(v[i] * 2 <= m)    ++i;
            while(v[j] * 3 <= m)    ++j;
            while(v[k] * 5 <= m)    ++k;
            ++count;
        }
        return v.back();
    }
};
