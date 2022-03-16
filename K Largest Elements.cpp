// Create maxHeap :) and enjoy
vector<int> Solution::solve(vector<int> &A, int B) {
  priority_queue <int> q;
    vector <int> ans;
    for(int i=0; i<A.size(); i++)
        q.push (A[i]);
    int i=0;
    while (i<B) {
        ans.push_back(q.top());
        q.pop();
        i++;
    }
    return ans;
}
