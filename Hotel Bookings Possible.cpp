bool Solution::hotel(vector<int> &A, vector<int> &D, int K) {
    int n= A.size();
    vector< pair<int, int> > t;
    for(int i=0; i<n; i++) 
        t.push_back({A[i], D[i]});

    sort(t.begin(), t.end());  
 
    priority_queue <int, vector<int>, greater<int>> rooms;
    for(int i=0; i<n; i++){
        if(rooms.size() < K)
            rooms.push(t[i].second);  

        else if(t[i].first > rooms.top()){
            rooms.pop();
            rooms.push(t[i].second);
        }

        // if arrival time and departure time is same
        else if(t[i].first ==  t[i].second){
            if(rooms.size()>=K) 
                return false;
            else{
               rooms.pop();
               rooms.push(t[i].second);
            }
        }  
        else
            return false;
    }
    return true;
}
