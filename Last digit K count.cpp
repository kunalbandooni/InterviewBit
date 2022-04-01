// TC: O(1)
int get(int x, int C){
    int ans = x / 10;
    ans += (x % 10 >= C);
    return ans;
}
int Solution::solve(int A, int B, int C) {
    return get(B, C) - get(A - 1, C);
}

// TC: O(n)
/*int Solution::solve(int A, int B, int C) {
    int start = (A/10 + 1) * 10 + 1;
    int end = (B/10) * 10;

    int ans = 0;
    if(start < end){
        // cout << start << " " << end << endl;
        ans += (end-start+1)/10;
        for(int i=A;i<start;i++) if(i%10==C) ans++;
        for(int i=end+1;i<=B;i++) if(i%10==C) ans++;
    } else {
        for(int i=A;i<=B;i++) if(i%10==C) ans++;
    }
    return ans;
}*/
