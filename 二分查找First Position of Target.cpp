class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.size() == 0)   return -1;
        int start = 0;
        int end = array.size();
        int middle;
        while(start <= end)
        {
            middle = start + (end - start) / 2;
            if(array[middle] == target && middle >= 0)
            {
                --middle;
                while(array[middle] == target) --middle;
                return ++middle;
            }
            else if(array[middle] > target) end = middle - 1;
            else    start = middle + 1;
        }
        return -1;
    }
};
