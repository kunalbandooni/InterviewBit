int Solution::solve(vector<int> &A, int B, int C) {
    if (B == 0 || A.size() == 0)    return 0;

    // case 1
    string str = to_string(C);
    int n = str.length();
    if (n < B)  return 0;

    // case 2
    else if (n > B)
    {
        if (A[0] == 0){
            int ans = (A.size() - 1) * pow(A.size(), B - 1);
            if (B == 1)
                ans = ans + 1;
            return ans;
        }
        else
            return pow(A.size(), B);
   }

   // case 3
    else
    {
        int num = str[0] - '0';
        int count = 0, ans = 0;

        if (B == 1)
        {
            for (int i = 0; i < A.size(); i++)
                if (A[i] < num)
                    count++;
            return count;
        }
        count = 0;
        bool flag = false;
        for (int i = 0; i < A.size(); i++){
            if (A[i] > 0 && A[i] < num)
                count++;
            if (A[i] == num)
                flag = true;
        }

        ans += count * pow(A.size(), B - 1);
        if (!flag)
            return ans;

        n--;
        int pos = 1;

        while (n--){
            
            count = 0;
            bool flag = false;
            
            for (int i = 0; i < A.size(); i++){
                if (A[i] < str[pos] - '0')
                count++;
                if (A[i] == str[pos] - '0')
                flag = true;
            }
            ans += count * pow(A.size(), n);
            if (!flag)
                return ans;
            pos++;
        }
        return ans;
    }
}
