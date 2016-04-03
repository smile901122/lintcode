class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        
        //method 1
        auto &a = colors;
        int n = a.size();
        vector<int> color(k, 0);
        
        for (int i = 0; i < n; ++i) {
            ++color[a[i] - 1];
        }
        int index = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < color[i]; ++j) {
                a[index++] = i + 1;
            }
        }
        
        /*
        //method2
        int index = 0;
        for(int ii = 1; ii <= k; ++ii)
        {
            sortOneColor(colors, index, ii);
        }
    }
    
private:
    void sortOneColor(vector<int> &colors, int &index, int k)
    {
        int &i = index;
        int j = colors.size() - 1;
        while(i <= j)
        {
            while(i <= j && colors[i] == k) ++i;
            while(i <= j && colors[j] != k) --j;
            if(i < j)
            {
                swap(colors[i], colors[j]);
                ++i;
                --j;
            }
        }
        index = ++j;
        */
    }
};
