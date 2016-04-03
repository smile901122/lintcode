class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        //双指针，动态维护一个区间
        //尾指针不断往后扫，当扫到有一个窗口包含了所有T 的字符后
        //然后再收缩头指针，直到不能再收缩为止
        //最后记录所有可能的情况中窗口最小的
        
        if(source.empty() || target.empty())    return "";
        if(source.size() < target.size())   return "";
        vector<int> s(256, 0);
        vector<int> t(256, 0);
        int start = 0;
        int end;
        
        for(auto i : target)    ++t[i];
        //找到完整包含target的子串的末尾
        int count = 0;
        for(end = 0; end < source.size(); ++end)
        {
            if(t[source[end]] > 0)
            {
                ++s[source[end]];
                if(s[source[end]] <= t[source[end]])  ++count;
            }
            
            if(count == target.size())  break;
        }
        //若到了末尾还没有包含target，则return ""
        if(count != target.size())   return "";
        //收缩头指针      
        while(s[source[start]] > t[source[start]] || t[source[start]] == 0)  
        {
            --s[source[start]];
            ++start;
        }
        
        return source.substr(start, end - start + 1);
    }
};
