class Solution {
public:
    int mySqrt(int x) {
        //method 1：
       int l = 0;
       int r = x;
       while(l <= r){
           int mid = l + (r - l) / 2;
           if(mid == 0){
               if(x >= 0)    l++;
           }
           else{
               if(x / mid >= mid)   l = mid + 1;
               else r = mid - 1;
           }
       }
       return --l;
       //method 2:
       int l = 0;
        int r = x;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(mid > x / mid)   r = mid -1;
            else l = mid;
        }
        return l;
    }
};
