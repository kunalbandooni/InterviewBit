#include<bits/stdc++.h>
typedef double C;
typedef complex<C> P;
#define X real()
#define Y imag()
P a[205];
int n, x, y, k;
bool check(int r){
    int c=0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            P g = a[j] - a[i];
            double d = abs(g);
            if(d > 2*r) continue;
            P mid = (a[i] + a[j]) * (1.0/2);
            double h = sqrt(r*1.0*r - d*d/4);
            P per = P(-g.Y,g.X) * (h/d);
            int c1 = 2, c2 = 2;
            for(int l = 0; l < n; l++){
                if(l == i or l == j) continue;
                if(abs(a[l] - (mid-per)) <= r)
                    c1++;
                if(abs(a[l] - (mid+per)) <= r)
                    c2++;
            }
            c=max({c,c1,c2});
        }
    }
    return c>=k;
}
int Solution::solve(vector<vector<int> > &A, int B) {
    n = A.size();
    for(int i = 0; i < n;i++)
        a[i] = {1.0*A[i][0], 1.0*A[i][1]};
    k = B;
    int l = 1, h = 2000000000, ans;
    while(h >= l){
        int m = (l+h)/2;
        if(check(m)) {
            ans = m;
            h = m-1;
        }
        else l = m+1;
    }
    return ans;
}
