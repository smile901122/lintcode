class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if(n < 0)   return 1.0 / myPow(x, -n);  //考虑 n < 0
        if(n == 0)  return 1;  // n == 0的情况
        double res = myPow(x, n / 2);
        res *= res;
        if(n % 2 == 0)  return res;  
        else return res * x;  // n 为 奇数
    }
};
