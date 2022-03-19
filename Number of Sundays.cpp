int Solution::solve(string A, int B) {
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday",  "Friday", "Saturday", "Sunday"};
    for(int i=0;i<7;i++)
        if(days[i] == A)
            B = B + i;
    return B/7;
}
