class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        //循环，递归会超时
        if(n < 1)   return -1;
        if(n == 1)  return 0;
        if(n == 2) return 1;
        int fn1 = 0;
        int fn2 = 1;
        int fn;
        for(int i = 3; i <= n; ++i)
        {
            fn = fn1 + fn2;
            fn1 = fn2;
            fn2 = fn;
        }
        return fn;
    }
};
