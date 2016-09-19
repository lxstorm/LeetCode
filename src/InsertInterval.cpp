/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), comp);
        if(intervals.size() == 0)
            return result;
        result.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();++i){
            if(intervals[i].start > result.back().end)
                result.push_back(intervals[i]);
            else
                result.back().end = max(result.back().end, intervals[i].end);
        }
        return result;

    }
private:
    static bool comp(Interval a, Interval b){
        return a.start < b.start;
    }
};
/* another solution
class Solution{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        vector<Interval> result;
        vector<Interval>::iterator it = intervals.begin();
        for(;it != intervals.end();++it){
            if((*it).end < newInterval.start)
                result.push_back(*it);
            else if((*it).start > newInterval.end)
                break;
            else{
                newInterval.start = min(newInterval.start, (*it).start);
                newInterval.end = max(newInterval.end, (*it).end);
            }
        }
        result.push_back(newInterval);
        for(;it != intervals.end();++it)
            result.push_back(*it);

        return result;
    }
};

// another solution search the right most start that less than newInterval.start
    and the left most end that greater than newInterval.end, the intervals that
    between them is covered by the newInterval.So we only need to check two intervals
    and merge them with newInterval.
*/
