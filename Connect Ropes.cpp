int Solution::solve(vector<int> &A) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Min heap performs push & pop operations in O(logN) time
    for (int i = 0; i < A.size(); i++) 
        minHeap.push(A[i]);
    int ans = 0;
    while (minHeap.size() > 1) {
        int x = minHeap.top(); minHeap.pop();
        int y = minHeap.top(); minHeap.pop();
        ans += x + y;
        minHeap.push(x + y);
    }
    return ans;
}
