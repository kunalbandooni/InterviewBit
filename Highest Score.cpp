int Solution::highestScore(vector<vector<string> > &A) {
    unordered_map<string, pair<int,int>> hash;
    for(int i=0;i<A.size();i++){
        hash[A[i][0]].first+=stoi(A[i][1]);
        hash[A[i][0]].second+=1;
    }
    unordered_map<string, pair<int, int>>:: iterator it;
    int highest=0;
    for(it=hash.begin();it!=hash.end();it++){
        highest=max(highest,(it->second.first)/it->second.second);
    }
    return highest;
}
