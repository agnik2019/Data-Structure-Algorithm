/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

*/

int Solution::pow(int x, int y, int d) {
   
    int res;
    if(y == 0) 
        return 1; 
    else if(y % 2 == 0) {
        res = pow(x, y / 2,d) * pow(x, y / 2,d); 
        return (res%d);
    }
    else
        res =  x * pow(x, y / 2,d) * pow(x, y / 2,d);
        return (res % d);
}
