class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        DFS(1, 0, n, k);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> v;
    
    void DFS(int idx, int cc, int n, int k) 
    {
        if (cc == k) 
        {
            res.push_back(v);
            return;
        }
        
        for (int i = idx; i <= cc + n - k + 1; ++i) 
        {
            v.push_back(i);
            DFS(i + 1, cc + 1, n, k);
            v.pop_back();
        }
    }
};
