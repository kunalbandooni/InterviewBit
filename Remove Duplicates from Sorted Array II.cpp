int Solution::removeDuplicates(vector<int> &A) {
    map<int,int> m;
    for(auto i:A)
        m[i]++;

    int c=0, k;

    for(auto i:m){
        if(i.second > 1)
            k=2;
        else
            k=1;
        
        while(k>0){
            A[c] = i.first;
            k--;
            c++;
        }
    }

    return c;
}
