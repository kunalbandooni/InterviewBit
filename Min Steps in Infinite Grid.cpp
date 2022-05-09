int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int steps =0;
    int xdis =0;
    int ydis =0;

    for(int i=1; i<B.size(); i++){
        xdis = abs(A[i]-A[i-1]);
        ydis = abs(B[i]-B[i-1]);
        
        steps += min(xdis,ydis);
        steps += abs(xdis-ydis);
    }
    return steps;
}
