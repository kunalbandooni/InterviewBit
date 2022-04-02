/*

We can use bitwise  operations to find 
  if the status of the given positions.
Then swap the positions again using
  bitwise operations.

*/
int Solution::solve(int A, int B, int C) {
    B--;
    C--;
    int x = (A >> B) & 1;
    int y = (A >> C) & 1;
    A = A + (x << C) + (y << B);
    A = A - (x << B) - (y << C);
    return A;
}
