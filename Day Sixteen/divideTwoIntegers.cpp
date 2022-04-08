class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        bool isNeg = false;
        long new_dividend = dividend, new_divisor = divisor;
        
        if (dividend < 0)
        {
            new_dividend *= -1;
            isNeg = !isNeg;
        }
        
        if (divisor < 0)
        {
            new_divisor *= -1;
            isNeg = !isNeg;
        }
        
        long result = 0;
        
        while (new_dividend >= new_divisor)
        {
            long temp = new_divisor, times = 1;
            
            while (temp <= new_dividend)
            {
                temp <<= 1;
                times <<= 1;
            }
            
            result += times >> 1;
            new_dividend -= temp >> 1;
        }
        
        if (isNeg)
            result = -result;
        
        if (result < INT_MIN)
            return INT_MIN;
        if (result > INT_MAX)
            return INT_MAX;
        
        return result;
    }
};
