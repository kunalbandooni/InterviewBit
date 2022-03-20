vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> v;
    int i=0,j=0;
    while(i<A.size() and j<B.size()){
        if(A[i] == B[j]){
            v.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i] < B[j])
            i++;
        else
            j++;
    }
    return v;
}
