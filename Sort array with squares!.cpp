// METHOD - 1
// TC: O(n)

vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans(A.size());

    int left = 0;
    int right = A.size()-1;

    for(int i=A.size()-1;i>=0;--i){
        if(abs(A[left]) > abs(A[right])){
            ans[i] = A[left]*A[left];
            left++;
        }
        else{
            ans[i] = A[right]*A[right];
            right--;
        }
    }
    return ans;
}




// METHOD - 2
// TC: O(nlogn)
vector<int> Solution::solve(vector<int> &A) {
    for(int i=0; i<A.size(); i++)
        A[i] = A[i] * A[i];
    sort(A.begin(),A.end());
    return A;
}
