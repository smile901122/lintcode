class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        string ans = "";
        int n = s.length();
        if (n == 0)     return ans;
        
        int maxlen = 0;
        
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) {
                ++j;
            }
            --j;
            if (2 * j + 1 > maxlen) {
                maxlen = 2 * j + 1;
                ans = s.substr(i - j, 2 * j + 1);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (i - j >= 0 && i + 1 + j < n && s[i - j] == s[i + 1 + j]) {
                ++j;
            }
            --j;
            if (2 * j + 2 > maxlen) {
                maxlen = 2 * j + 2;
                ans = s.substr(i - j, 2 * j + 2);
            }
        }
        
        return ans;
    }
};
