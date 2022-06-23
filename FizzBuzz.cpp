vector<string> Solution::fizzBuzz(int A) {
    vector<string> v;
    for(int i=1; i<=A; i++){
        string str="";
        if(i%3 == 0)
            str = "Fizz";
        if(i%5 == 0)
            str += "Buzz";
        if(str == "")
            str = to_string(i);
        v.push_back(str);
    }
    return v;
}
