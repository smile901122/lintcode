class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int letters[26] = {};
        for(int i = 0; i < B.size(); ++i)
        {
            ++letters[B[i]-'A'];
        }
        for(int i = 0; i < A.size(); ++i)
        {
            --letters[A[i]-'A'];
        }
        for(int i = 0; i < 26; ++i)
        {
            if(letters[i] > 0)  return false;
        }
        return true;
    }
};
