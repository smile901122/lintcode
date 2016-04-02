class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> result;
        map<string, int> orderStr;
        for(auto s : strs)
        {
            sort(s.begin(),s.end());
            ++orderStr[s];
        }
        for(auto s : strs)
        {
            auto tempStr = s;
            sort(tempStr.begin(),tempStr.end());
            if(orderStr[tempStr] > 1) 
                result.push_back(s);
        }
        return result;
    }
};
