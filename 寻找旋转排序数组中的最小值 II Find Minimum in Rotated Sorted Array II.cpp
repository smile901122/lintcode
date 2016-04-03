class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        //if(num.size() == 1) return num[0];
        int l = 0;
        int r = num.size() - 1;
        int mid;
        while(l + 1 < r)
        {
            if(num[l] < num[r]) 
                return num[l];
            
            mid = l + (r - l) / 2;
            if(num[l] == num[r])
                ++l;
            else if(num[mid] > num[r])
                l = mid;
            else r = mid;
        }
        if(num[l] < num[r]) return num[l];
        else return num[r];
    }
};
