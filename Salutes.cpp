/*
Since every "left moving" ie "<" soldier will salute 
every "right moving" is ">" soldier which is on the 
LEFT side of the left moving soldier, a simple 
approach is as follows:

1. Keep a variable count. Whenever a ">" soldier is 
    observed, increment count.
2. When a "<" soldier is observed, increment the 
    salutes by count, since this soldier will salute
    all the "count" soldiers he has seen on his left.
3. Iterate the entire string and return the sum 
    of salutes.
*/

long Solution::countSalutes(string A) {
    long count=0,t=0;
    for(int i=0;i<A.length();i++){
        if(A[i]=='>')
            t++;
        else
            count+=t;
    }
    return count;
}
