vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> ans = {-1, -1};
    int n = A.size();
    int i = 0, j = n-1, k = -1;
    while(i<=j){
        int mid = (i+j)/2;
        if(A[mid] == B){
            k= mid;
            break;
        }
        else if(A[mid] > B)
            j = mid-1;
        else
            i = mid+1;
    }
    if(k==-1)
        return ans;

    i=k;
    j=k;
    while(i>=0 and A[i]== B)
        i--;
    while(j<n and A[j]==B)
        j++;

    ans[0] = i+1;
    ans[1] = j-1;
    return ans;
}
