void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> z;
    int i=0,j=0;

    while(i<A.size() and j<B.size()){
        if(A[i] <= B[j])
            z.push_back(A[i++]);
        else
            z.push_back(B[j++]);
    }

    while(i<A.size())
        z.push_back(A[i++]);
    while(j<B.size())
        z.push_back(B[j++]);

    A=z;
}
