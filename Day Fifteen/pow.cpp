class Solution {
public:
    double powerFunc(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        
        if (n % 2)
            return x * powerFunc(x, n - 1);
        
        return powerFunc(x * x, n / 2);
    }
    
    double myPow(double x, int n) 
    {
        bool isNegative = false;
        
        if (n < 0)
        {
            n *= -1;
            isNegative = true;
        }
        
        double ans = powerFunc(x, n);
        
        if (isNegative)
            ans = 1 / ans;
        
        return ans;
    }
};
