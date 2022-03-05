
// Method 1:-

int Solution::solve(int a, int b, int c, int d) {
    if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c)) return 1;
    else return 0;
}

// Method 2:-

int Solution::solve(int A, int B, int C, int D) {
    map<int,int> m;
    m[A]++;
    m[B]++;
    m[C]++;
    m[D]++;
    if(m.size()!=2)
        return 0;
    for(auto i:m)
        if(i.second==2)
            return 1;
    return 0;
}
