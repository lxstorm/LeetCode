/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// my AC solution by using compare
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size() == 0)
            return result;
        result.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();++i){
            Interval cur_interval = intervals[i];
            vector<Interval>::iterator iter = result.begin();
            while(iter != result.end()){
                if(cur_interval.end <= iter->end){
                    if(cur_interval.end < iter->start){
                        result.insert(iter, cur_interval);
                        break;
                    }
                    else if(cur_interval.start <= iter->start){
                        iter->start = cur_interval.start;
                        break;
                    }
                    else{
                        break;
                    }
                }
                else if(cur_interval.start <= iter->start){
                    iter = result.erase(iter);
                }
                else if(cur_interval.start <= iter->end){
                    cur_interval.start = iter->start;
                    iter = result.erase(iter);
                }
                else{
                    ++iter;
                }

                if(iter == result.end()){
                    result.push_back(cur_interval);
                    break;
                }
            }
        }
        return result;
    }
};
// another solution use sort
class Solution{
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size() == 0)
            return result;
        sort(intervals.begin(), intervals.end(), comp);
        result.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();++i){
            if(intervals[i].start > result.back().end)
                result.push_back(intervals[i]);
    // we can alse use result.back().end = max(result.back().end, intervals[i].end);
            else if(intervals[i].end > result.back().end)
                result.back().end = intervals[i].end;
        }
        return result;
    }
private:
    static bool comp(Interval &a, Interval &b){
        return a.start < b.start;
    }
};
