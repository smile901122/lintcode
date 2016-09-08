class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        int i = 0;
        return getValue(expression, i);
    }
private:
    int getValue(vector<string> &exp, int &i){
        deque<string> q;
        int n = exp.size();
        while(i < n && exp[i] != ")"){
            if(exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/"){
                    q.push_back(exp[i]);
            }
            else if(exp[i] == "("){
                ++i;
                addNum(q, to_string( getValue(exp, i) ));
            }
            else{
                addNum(q, exp[i]);
            }
            ++i;
        }
        return getNum(q);
    }
    
    void addNum(deque<string> &q, string num){
        if(!q.empty()){
            string pre = q.back();
            if(pre == "+" || pre == "-"){
                q.push_back(num);
            }
            else{
                q.pop_back();
                string cur = q.back();
                q.pop_back();
                if(pre == "*"){
                    q.push_back( to_string( str2int(cur) * str2int(num) ) );
                }
                else{
                    q.push_back( to_string( str2int(cur) / str2int(num) ) );
                }
            }
        }
        else
            q.push_back(num);
    }
    
    int getNum(deque<string> &q){
        int res = 0;
        string cur = "";
        bool add = true;
        while(!q.empty()){
            cur = q.front();
			q.pop_front();
            if(cur == "+")
                add = true;
            else if(cur == "-")
                add = false;
            else{
                int num = str2int(cur);
                res += ( add ? num : (-1 * num) );
            }
        }
        return res;
    }
    
    int str2int(string s){
        stringstream ss;
        ss << s;
        int res;
        ss >> res;
        return res;
    }
};
