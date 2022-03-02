string Solution::solve(int A) {
    if(A>=1 and A<=12){
        if(A>2 and A<6)
            return "Spring";
        if(A>5 and A<9)
            return "Summer";
        if(A>8 and A<12)
            return "Autumn";
        else
            return "Winter";
    }
    return "Invalid";
}
