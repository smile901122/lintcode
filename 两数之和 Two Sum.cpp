class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> index;
        unordered_map<int, int> map;
        int gap;
        for(int i = 0; i < nums.size(); ++i)
        {
            map[nums[i]] = i;
        }
        for(int j = 0; j < nums.size(); ++j)
        {
            gap = target - nums[j];
            if(map.find(gap) != map.end() && map[gap] != j)
            {
                index.push_back(j + 1);
                index.push_back(map[gap] + 1);
                return index;
            }
        }
        return index;
    }
};
