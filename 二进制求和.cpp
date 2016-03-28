class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        int a_n = a.size();
        int b_n = b.size();
        
        string res = "";
        int c = 0;
        int i = a_n - 1;
        int j = b_n - 1;
        
        for(; i >= 0 && j >= 0; --i, --j)
        {
            int sum = (a[i]- '0' + b[j] - '0') + c;
            c = sum / 2;
            sum %= 2;
            res += sum + '0';
        }
        
        if(i >= 0)
        {
            for(; i >= 0; --i)
            {
                int sum = (a[i] - '0' + c);
                c = sum / 2;
                sum %= 2;
                res += sum + '0';
            }
        }
        else if(j >= 0)
        {
            for(; j >= 0; --j)
            {
                int sum = (b[j] - '0' + c);
                c = sum / 2;
                sum %= 2;
                res += sum + '0';
            }
        }
        if(c == 1)  res += c + '0'; //最后一个进位
        
        reverse(res.begin(), res.end());    //反转
        return res;
    }
};
