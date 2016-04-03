//比较策略
bool comp(const string &s1, const string &s2)
{
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        string res = "";
        int n = num.size();
        
        vector<string> a;
        for (int i = 0; i < n; ++i) 
        {
            a.push_back(to_string(num[i]));
        }
        sort(a.begin(), a.end(), comp);
        
        int i = 0;
        //若数组全为0，则只输出一个0
        while (i < n - 1 && a[i] == "0") 
        {
            ++i;
        }
        
        while (i < n) 
        {
            res += a[i++];
        }
        return res;
    }
};
