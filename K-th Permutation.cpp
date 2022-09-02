vector<int> Solution::findPerm(int A, long B) {
    vector<long>fact(21);
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = i * fact[i - 1];
    }
    vector<int> ans(A);
    int curr = 0;
    for (int i = 0; i < A - 20; i++) {
        ans[i] = i + 1;
        curr = i;
    }
    vector<int> l1;
    for (int i = max(A - 20, 1); i <= A; i++) {
        l1.push_back(i);
    }
    B--;
    for (int i = min(20, A - 1); i >= 0; i--) {
        int idx = (int)(B / fact[i]);
        B -= idx * fact[i];
        ans[curr++] = l1[idx];
        l1.erase(l1.begin() + idx);
    }
    return ans;  
}
