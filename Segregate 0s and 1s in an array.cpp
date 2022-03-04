vector<int> Solution::solve(vector<int> &arr) {
    int count = 0;
    int n=arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count++;
    }
 
    // Loop fills the arr with 0 until count
    for (int i = 0; i < count; i++)
        arr[i] = 0;
 
    // Loop fills remaining arr space with 1
    for (int i = count; i < n; i++)
        arr[i] = 1;
    return arr;
}
