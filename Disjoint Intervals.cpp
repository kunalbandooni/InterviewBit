bool compare( vector<int> &a , vector<int> &b){
    return a[1] < b[1];
}
int Solution::solve(vector<vector<int> > &mat) {
    sort(mat.begin() , mat.end() , compare);
    
    int n=mat.size();
    vector<int> temp=mat[0];
    
    int count=1;
    for(int i=1;i<n;i++)
        if( mat[i][0] > temp[1]){
            count++;
            temp=mat[i];
        }

    return count;
}
