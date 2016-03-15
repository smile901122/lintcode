/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        //不知道为什么在lintcode上提交不通过，在leetcode上反倒AC
        int l = 1;
        int r = n;
        if (VersionControl::isBadVersion(l)) 
            return l;
        int mid;
        while (l + 1 < r) 
        {
            mid = l + (r - l) / 2;
            if (VersionControl::isBadVersion(mid)) 
                r = mid;
            else 
                l = mid;
        }
        return r;
    }
};
