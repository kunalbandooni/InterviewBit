vector < string > ans;
void rec(vector < string > & A, int i, int j, string par) {
    string curr = par;
    if (i == A.size()) {
        ans.push_back(curr);
        return;
    }
    if (j < A[i].length() - 1)
        rec(A, i, j + 1, curr);

    curr += A[i][j];
    rec(A, i + 1, 0, curr);
}

vector < string > Solution::specialStrings(vector < string > & A) {
    ans.clear();
    string curr = "";
    rec(A, 0, 0, curr);
    return ans;
}
