class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        string res = "";
        int maxlen = 0;
        int n = s.size();
        int start = 0;
        
        for(int i = 0; i < n;){
            int l = i;
            int r = i;
            //将连续相同的字符看做一个整体，当做一个字符对待
            while(r < n - 1 && s[r] == s[r + 1]){
                ++r;
            }
            //跳过连续重复的字符，不需要再判断
            i = r + 1;
            //左右递增判断是否是回文
            while(l > 0 && r < n - 1 && s[l - 1] == s[r + 1]){
                ++r;
                --l;
            }
            int len = r - l + 1;    //回文长度
            if(len > maxlen){
                start = l;  //保存当前最长回文字符串的起始位置
                maxlen = len;   //保存当前最长回文字符串的长度
            }
        }
        res = s.substr(start, maxlen);
        return res;
    }
};
