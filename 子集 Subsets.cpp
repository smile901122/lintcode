class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	vector<vector<int> > result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        
        vector<int> list;
        dfs(nums, 0, list, result);

        return result;
    }

private:
    void dfs(vector<int>& nums, int pos, vector<int> &list, vector<vector<int> > &ret) 
    {
        ret.push_back(list);

        for (int i = pos; i < nums.size(); ++i) 
        {
            list.push_back(nums[i]);
            dfs(nums, i + 1, list, ret);
            list.pop_back();
        }
    }
};
