class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n == 0)  return 1 % b;
        if(n == 1)  return a % b;
        long long res = fastPower(a, b, n >> 1) % b;
        if (n & 1)
            return res  * res % b * a % b;
        else 
            return res * res % b;
    }
};
