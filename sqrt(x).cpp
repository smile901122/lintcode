class Solution {
public:
    int mySqrt(int x) {
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
    }
};
