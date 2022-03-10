vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int a = A.size() - 1, b = B.size() - 1, carry = 0, sum = 0, last = 0;
    vector<int> ans;
    while(a >= 0 && b >= 0) {
        sum = 0;
        sum += carry + A[a] + B[b];
        if(sum > 9) {
            ans.push_back(sum % 10);
            sum = sum / 10;
            carry = sum;
        }
        else {
            ans.push_back(sum);
            carry = 0;
        }
        a--;
        b--;
    }
    while(a >= 0) {
        sum = 0;
        sum += carry + A[a];
        if(sum > 9) {
            ans.push_back(sum % 10);
            sum = sum / 10;
            carry = sum;
        }
        else {
            ans.push_back(sum);
            carry = 0;
        }
        a--;
    }
    while(b >= 0) {
        sum = 0;
        sum += carry + B[b];
        if(sum > 9) {
            ans.push_back(sum % 10);
            sum = sum / 10;
            carry = sum;
        }
        else {
            ans.push_back(sum);
            carry = 0;
        }
        b--;
    }
    if(carry > 0)
        ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}
