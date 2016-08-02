class Finder {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        int res = n - K;
        int start = 0;
        int end = n - 1;
        int index = select(a, start, end);
        while(index != res){
            if(index > res){
                end = index - 1;
                index = select(a, start, end);
            }
            else {
                start = index + 1;
                index = select(a, start, end);
            }
        }
        return a[res];
        
    }
    
    int select(vector<int> &a, int start, int end){
        int l = start + 1;
        int r = end;
        int povit = a[start];
        while(l <= r){
            while(l <= r && a[l] <= povit) ++l;
            while(l <= r && a[r] > povit) --r;
            if(l <= r)	swap(a[l++], a[r--]);
        }
        swap(a[start], a[r]);
        return r;
    }
};
