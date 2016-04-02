class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        char c = k + '0';
        for(int i = 0; i <= n; ++i)
        {
            for(auto s : to_string(i))
            {
                if(c == s)  ++count;
            }
        }
        return count;
    }
};
