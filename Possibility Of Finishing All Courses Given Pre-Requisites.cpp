bool dfs(int book, vector<int> &taken, vector<int> &vis, vector<vector<int>> &preq){
    vis[book] = 1;
    for(auto i: preq[book]){
        // if course is repeating again in path i.e. vis[i] = 1 means cycle is present
        if(vis[i])
            return false;
        if(!taken[i])
            if(!dfs(i, taken, vis, preq)) return false;
    }
    vis[book] = 0; // remove current course from path after traversing all paths which included this course
    taken[book] = 1; // if prerequisites are taken we can now take this course
    return true;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int n = B.size();
    vector<int> taken(A+1); // To check if course is already taken
    vector<int> vis(A+1); //  To maintain path and check for cycle, i.e if course is repeating in path means cycle is present
    // so finishing courses not possible i.e. course is prereq of itself
    vector<vector<int>> preq(A+1); // To store prerequisite of courses
    for(int i=0; i<n;i++){
        preq[B[i]].push_back(C[i]);
    }
    for(int i=1; i<A+1;i++){
        if(!taken[i]){
            if(!dfs(i, taken, vis, preq)) return false;
        }
    }
    return true;
}
