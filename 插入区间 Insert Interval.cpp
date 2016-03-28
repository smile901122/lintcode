/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> res;
        vector<Interval> &a = intervals;
        Interval b = newInterval;
        int i = 0;
        int n = a.size();
        while(i < n && a[i].end < b.start)
        {
            res.push_back(a[i]);
            ++i;
        }
        while(i < n && a[i].start <= b.end)
        {
            b.start = min(a[i].start, b.start);
            b.end = max(a[i].end, b.end);
            ++i;
        }
        res.push_back(b);
        while(i < n)
        {
            res.push_back(a[i]);
            ++i;
        }
        return res;
    }
};
