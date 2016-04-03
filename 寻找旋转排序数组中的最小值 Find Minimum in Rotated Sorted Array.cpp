class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if(num.empty()) return -1;
        int start = 0;
        int end = num.size() - 1;
        if(num[start] < num[end])   return num[start];
        int middle;
        while(start + 1 < end)
        {
            middle = start + (end - start) / 2;
            if(num[middle] < num[end])  end = middle;
            else start = middle;
        }
        return num[end];
    }
};
