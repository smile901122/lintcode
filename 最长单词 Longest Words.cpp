class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        if(dictionary.empty())  return res;
        int max = 0;
        for(auto i : dictionary)
        {
            if(i.size() == max)  res.push_back(i);
            else if(i.size() > max)
            {
                if(res.size())  res.clear();
                max = i.size();
                res.push_back(i);
            }
        }
        return res;
    }
};
