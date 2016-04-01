class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        if(n < 10 && n > -10)  return n;
        
        int sign = n > 0 ? 1 : -1;
        long long res = 0;  //res应为long long
        n = n * sign; //abs(n)
        while(n > 0)
        {
            res = res * 10 + n % 10;
            n /= 10;
        }
        res *= sign;
        
        if(res > INT_MAX || res < INT_MIN)  return 0;
        return res;
    }
};
