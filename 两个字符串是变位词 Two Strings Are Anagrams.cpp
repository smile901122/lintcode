class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if(s.size() != t.size())    return false;
        int chars1[256] = {0};
        int chars2[256] = {0};
        
        int length = s.size();
        for(int i = 0; i < length; ++i)
        {
            ++chars1[s[i]];
            ++chars2[t[i]];
        }
        for(int i = 0; i < 256; ++i)
        {
            if(chars1[i] != chars2[i])  return false;
        }
        return true;
    }
}; 
