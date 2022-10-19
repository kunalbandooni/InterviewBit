int Solution::solve(int candies, int c1, int p1, int c2, int p2) {
    double ppc1 = p1/(c1*1.0);// price per candy
    double ppc2 = p2/(c2*1.0);// price per candy
    if(ppc1 < ppc2){
        swap(c1, c2);
        swap(p1, p2);
    }
    // means {p1, c1} is costly store and {p2, c2} is cheap

    int cost = 0;
    do{
        if(candies % c2 == 0){ // check if all can be bought from cheap store
            break;
        }else{
            cost+=p1;   // otherwise take minimum possible only 1 packet from costly store and again check
            candies-=c1;
        }
    }while(candies > 0 && candies % c2 != 0);// till remaining cannot be bought from cheap store
    
    if(candies < 0) return -1;
    
    cost += (candies/c2)*p2;
    return cost;
}
