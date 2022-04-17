/*
Python Apporach:-

class Solution:
    def solve(self, A):
        return ' '.join((A.split()[::-1]))
        
# obsservations... Know a second language :)

*/


string Solution::solve(string A) {
    A = " " + A + " ";
    vector<string> arr;
    for(int i=0;i<A.size();i++){
        if(A[i] != ' ')
            continue;
        while(i < A.size() and A[i+1] == ' ')
            i++;
        for(int j=i+1;j<A.size();j++){
            if(A[j] == ' '){
                arr.push_back(A.substr(i+1, j-i-1));
                j = i;
                break;
            }
        }
    }
    reverse(arr.begin(), arr.end());
    string ans = "";
    for(auto &x: arr){
        ans += x;
        ans += ' ';
    }
    ans.pop_back();
    return ans;
}
