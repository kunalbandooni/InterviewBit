const long long MOD = 1000000007;
int Solution::nchoc(int A, vector<int> &B) {
    long long maxChoco = 0;
    priority_queue<int> pq (B.begin(), B.end());   
    for (auto i = 0; i < A; ++i) {
        if (!pq.empty()) {
            long long top = pq.top();
            maxChoco += top;
            maxChoco %= MOD;
            pq.pop();
            pq.emplace(floor(top/2));
        }
    }
    return maxChoco;
}
