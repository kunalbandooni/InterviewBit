int Solution::findDiceSum(int d, int m, int x){  
    if(d>x) return 0;
    int mod=1e9+7;
    long long table[2][x+1];
    memset(table,0,sizeof(table));
    for(int j=1;j<=min(m,x);j++)
        table[0][j]++;
    for(int i=1;i<d;i++)
        for(int j=1;j<=x;j++){
            int it = max(0,j-m-1);
            long long val = table[i%2][j-1] + table[(i-1)%2][j-1] - table[(i-1)%2][it];
            table[i%2][j] = (val + mod) % mod;
        }
    return table[(d-1)%2][x];
}
