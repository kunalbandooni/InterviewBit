/*
I had to read it a few times to understand it.

A is an array that contains available seats in
that row. The ticket price is the number of 
empty seats in a row.

So looking at the examples:-

A = [2, 3] B = 3
There are 2 row with tickets available. The 
first row has 2 tickets and the second row has
3 tickets. To maximize profit, you want to
sell the $3 ticket first. 

That leaves 2 tickets available in both rows, 
according to condition in the question.

Since we need to sell 3 tickets. We’d sell 
the $3 and $2 ticket from the second row and
the $2 ticket from row one.

This leaves A[1,1].


A = [1, 4] B = 2
In this case, we take 2 from the second row.
The $4 and $3 ticket.
This will leave A[1,2]
*/

int Solution::solve(vector<int> &A, int B) {    
    // TC:- O(n)    SC:- O(n)
    // Use max-heap, and calculate easily
    priority_queue<int> q;
    for(int i=0;i<A.size();i++)
        q.push(A[i]);
    int c=0;
    while(B--){
        int x=q.top();
        c+=x;
        q.pop();
        q.push(--x);
    }
    return c;
  
    // TC:- O(nlogn)    SC:- O(1)
    // Sort and find lower_bound and work using iterator
    /*
    sort(A.begin(), A.end());
    auto it = A.end();
    int res = 0;
    for (int i = 0; i < B; ++i) {
        if (it == A.end())
            it = lower_bound(A.begin(), A.end(), A.back());
        auto& val = *it;
        res += val;
        --val;
        ++it;
    }
    return res;
    */
}
