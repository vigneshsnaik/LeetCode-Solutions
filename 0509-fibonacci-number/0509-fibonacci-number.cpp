// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n<3)
            return 1;
        return fib(n-1)+fib(n-2);
    }
};