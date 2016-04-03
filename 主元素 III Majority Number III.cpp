class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        //利用map比数组较为方便
        unordered_map<int, int> major;
        for(auto n : nums)
        {
            if(major.size() < k)    ++major[n];
            else if(major.count(n))  ++major[n];
            else
            {
                vector<int> key;
                for(auto it : major)
                {
                    --it.second;
                    if(it.second == 0)  key.push_back(it.first);
                }
                for(auto i : key)
                {
                    major.erase(i);
                }
            }
        }
        
        int res;
        int max = 0;
        for(auto it : major)
        {
            if(it.second > max) 
            {
                res = it.first;
                max = it.second;
            }
        }
        return res;
    }
};
