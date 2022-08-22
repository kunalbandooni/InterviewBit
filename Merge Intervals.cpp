/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Better still, watch the "Take U Forward" solution in you tube... for the same problem
vector<Interval> Solution::insert(vector<Interval> &it, Interval newinter) {
    vector<Interval> ans;
    int x,y,n=it.size();
    
    x=min(newinter.start,newinter.end);
    y=max(newinter.start,newinter.end);

    for(int i=0;i<n;i++){
        if(x>=it[i].start && x<=it[i].end)
            x=it[i].start;
        else if(y>=it[i].start && y<=it[i].end)
            y=it[i].end;
        else if(x<it[i].start && y<it[i].start){
            ans.push_back(Interval(x,y));
            x=it[i].start;
            y=it[i].end;
        }
        else if(x>it[i].end)
            ans.push_back(it[i]);
    }
    ans.push_back(Interval(x,y));
    return ans;
}
