bool check(vector<string> v, int x, int y){
    // back column check
    for(int i=0;i<=x;i++)
        if(v[i][y] == 'Q')
            return false;
    
    // upper back diagonal
    int r = x, c = y;
    while(r>=0 and c>=0){
        if(v[r--][c--] == 'Q')
            return false;
    }
    
    // lower back diagonal
    r = x, c = y;
    while(r>=0 and c<v.size()){
        if(v[r--][c++] == 'Q')
            return false;
    }
    
    return true;
}

void solve(vector<vector<string>> &s, vector<string> &v, int row, int n){
    if(row >= n){
        s.push_back(v);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(check(v, row, i)){
            v[row][i] = 'Q';
            solve(s, v, row+1, n);
        }
        v[row][i] = '.';
    }
    return;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> s;
    vector<string> v(A);
    string g = "";
    
    for(int i=0;i<A;i++)
        g = g + ".";
    
    for(int i=0;i<A;i++)
        v[i] = g;
    
    solve(s, v, 0, A);
    return s;
}
