class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        /*
        int n = str.size();
        if(n < 2)  return true;
        sort(str.begin(), str.end());
        for(int i = 1; i < n; ++i)
        {
            if(str[i] == str[i - 1])
                return false;
        }
        return true;
        */
        int n = str.size();
        if(n < 2)   return true;
        unordered_map<char, int> map;
        for(auto i : str)
        {
            if(map.count(i) > 0)    return false;
            ++map[i];
        }
        return true;
    }
};
