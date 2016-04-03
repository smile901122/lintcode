class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        if(letters.empty()) return;
        
        int n = letters.size();
        string &str = letters;
        int i = 0;
        int j = n - 1;
        while(i < j)
        {
            while(i < j && islower(str[i])) ++i;    //islower() #include <cctype>;
            while(i < j && isupper(str[j])) --j;    //isupper()
            swap(str[i], str[j]);
        }
    }
};
