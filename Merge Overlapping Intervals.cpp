/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool mycomp(Interval a, Interval b){ 
    return a.start < b.start; 
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), mycomp);
    
    int k = 0;
    // TC: O(n)         SC: O(k)
    for(int i = 1;i<A.size();i++){
        if(A[k].end >= A[i].start)
            A[k].end = max(A[i].end, A[k].end);
        else{
            k++;
            A[k] = A[i];
        }
    }
    
    vector<Interval> z;
    for(int i=0;i<=k;i++) 
        z.push_back(A[i]);
    return z;
}
