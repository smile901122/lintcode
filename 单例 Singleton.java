class Solution {
    /**
     * @return: The same instance of this class every time
     */
    /*
    private static Solution solution = null;
    public static Solution getInstance() {
        // write your code here
        if(solution == null)
            solution = new Solution();
        return solution;
    }
    */
    private Solution(){}
    private static Solution solution = new Solution ();
    public static Solution getInstance() {
        return solution;
    }
};
