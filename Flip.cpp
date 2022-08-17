vector<int> Solution::flip(string A) {
    int n = A.length();
    int res = 0;
    int l, r;
    for(int i=0;i<n;i++){
        int j = i;
        int count = 0;
        while(i<n){
            if(A[i] == '1')
                count--;
            else
                count++;
            if(res < count){
                res = count;
                l = j;
                r = i;
            }
            if(count < 0)
                break;
            i++;
        }
    }
    if(res == 0)    
        return {};
    return {l+1, r+1};
}
