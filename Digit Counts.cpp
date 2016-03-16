class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
     //与整数有关的题大家可能比较容易想到求模求余等方法
     //但其实很多与整数有关的题使用字符串的解法更为便利
     //将整数 i 分解为字符串，然后遍历之，自增 k 出现的次数即可
     //时间复杂度为 O(n * L), L为字符最大长度，空间复杂度为O(L)
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
