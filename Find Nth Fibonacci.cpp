int mod = 1e9+7;
void multiply(vector<pair<long,long>> &m1, vector<pair<long,long>> &m2) {
    long a = ((m1[0].first*m2[0].first)%mod + (m1[0].second*m2[1].first)%mod)%mod;
    long b = ((m1[0].first*m2[0].second)%mod + (m1[0].second*m2[1].second)%mod)%mod;
    long c = ((m1[1].first*m2[0].first)%mod + (m1[1].second*m2[1].first)%mod)%mod;
    long d = ((m1[1].first*m2[0].second)%mod + (m1[1].second*m2[1].second)%mod)%mod;
    m1[0].first = a;
    m1[0].second = b;
    m1[1].first = c;
    m1[1].second = d;
}
void power(vector<pair<long,long>> &ans, int n) {
    if(n==0||n==1) return;
    power(ans,n/2);
    multiply(ans,ans);
    if(n%2==1) {
        vector<pair<long,long>> m = {{1,1},{1,0}};
        multiply(ans,m);
    }
}
int Solution::solve(int A) {
    if(A<3) return 1;
    vector<pair<long,long>> ans{{1,1},{1,0}};
    power(ans,A-1);
    return ans[0].first;
}
