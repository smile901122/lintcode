class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int n = digits.size();
        if(n == 0)  return digits;
        
        int c = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            int sum;
            if(i == n - 1)  sum = digits[i] + 1;
            else    sum = digits[i] + c;
            digits[i] = sum % 10;
            c = sum / 10;
        }
        if(c)   digits.insert(digits.begin(), c);
        return digits;
    }
};
