int calcModulus(string b, int a){
    int mod = 0;
    for (int i = 0; i < b.length(); i++)
        mod = (mod * 10 + b[i] - '0') % a;
    return mod;
}

int Solution::solve(string a, string b) {
    int len_a = a.length(), len_b = b.length();
    if (len_a == 1 && len_b == 1 && b[0] == '0' && a[0] == '0')
        return 1;
    if (len_b == 1 && b[0] == '0')
        return 1;
    if (len_a == 1 && a[0] == '0')
        return 0;
    int exponent = (calcModulus(b, 4) == 0) ? 4 : calcModulus(b, 4);
    int base = a[len_a - 1] - '0';
    int result = pow(base, exponent);
    return result % 10;
}
