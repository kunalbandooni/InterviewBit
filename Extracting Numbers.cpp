long findSum(string str){
    string temp = "";
    long sum = 0;   // holds sum

    for (char ch : str) {
        // if current character is a digit
        if (isdigit(ch))
            temp += ch; 
        // if current character is an alphabet
        else {
            // increment sum by number found earlier
            // (if any)
            sum += atoi(temp.c_str());
            // reset temporary string to empty
            temp = "";
        }
    }
    // atoi(temp.c_str()) takes care of trailing
    // numbers
    return sum + atoi(temp.c_str());
}
long Solution::solve(string A) {
    return findSum(A);
}
