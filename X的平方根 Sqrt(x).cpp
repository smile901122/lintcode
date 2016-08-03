class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        //method 1
        int l = 0;
        int r = x;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(x / mid > mid)   l = mid + 1;
            else if(x / mid == mid) return mid;
            else    r = mid - 1;
        }
        return r;
        //method 2
        /*
        if(x < 2)   return x;
        int begin = 1;
        int end = x / 2;
        int lastMid;
        int middle;
        while(begin <= end)
        {
            middle = begin + (end - begin) / 2;
            if(x / middle == middle)//用middle*middle会溢出
            {
                return middle;
            }
            else if(x / middle > middle)
            {
                begin = middle + 1;
                lastMid = middle;
            }
            else
            {
                end = middle - 1;
            }
        }
        return lastMid;
        */
    }
};
