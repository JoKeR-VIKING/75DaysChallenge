class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> addedNumber(digits.size() + 1);
        int carry = 1, index = digits.size();
        
        for (int i=digits.size() - 1;i>=0;i--)
        {
            if (digits[i] + carry > 9)
            {
                addedNumber[index] = (digits[i] + carry) % 10; 
                carry = (digits[i] + carry) / 10;
            }
            else
            {
                addedNumber[index] = digits[i] + carry; 
                carry = 0;
            }
            
            index--;
        }
        
        if (carry > 0)
        {
            addedNumber[0] = carry;
            return addedNumber;
        }
        
        reverse(addedNumber.begin(), addedNumber.end());
        addedNumber.pop_back();
        reverse(addedNumber.begin(), addedNumber.end());
        
        return addedNumber;
    }
};
