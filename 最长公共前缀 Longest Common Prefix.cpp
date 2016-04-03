class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.empty()) return "";
        string longestLCP = strs[0];
        for(int i = 1; i < strs.size(); ++i)
        {
            string str = strs[i];
            string result = longestLCP;
            longestLCP = "";
            int j = 0;
            while(j < str.size() && j < result.size() && result[j] == str[j])
            {
                longestLCP += result[j];
                ++j;
            }
        }
        return longestLCP;
    }
};
