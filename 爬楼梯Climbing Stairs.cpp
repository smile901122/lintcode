class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n <= 1)  return 1;
        int state0 = 1;
        int state1 = 1;

        for (int i = 2; i <= n; ++i) 
        {
            int state = state0 + state1;
            state0 = state1;
            state1 = state;
        }
        return state1;
    }
};
