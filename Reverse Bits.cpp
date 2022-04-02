vector<int> convert_to_binary(unsigned int A){
    vector<int> v(32, 0);
    for(int i=0; i<32; i++){
        v[i] = A % 2;
        A = A / 2;
    }
    return v;
}
unsigned int Solution::reverse(unsigned int A) {
    vector<int> v = convert_to_binary(A);
    long long int a = 0;
    for(int i=0; i<32; i++)
        if(v[i])
            a = a + pow(2, 32 - i - 1);
        // cout<<v[i]<<" ";
    return a;
}
