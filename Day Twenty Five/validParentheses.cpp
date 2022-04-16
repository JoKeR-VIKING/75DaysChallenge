class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        
        for (int i=0;i<s.length();i++)
        {
            if (s[i] == '(')
            {
                stk.push('(');
            }
            else if (s[i] == '[')
            {
                stk.push('[');
            }
            else if (s[i] == '{')
            {
                stk.push('{');
            }
            else if (s[i] == ')')
            {
                if (stk.empty())
                    return false;
                
                if (stk.top() == '(')
                    stk.pop();
                
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (stk.empty())
                    return false;
                
                if (stk.top() == '[')
                    stk.pop();
                
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (stk.empty())
                    return false;
                
                if (stk.top() == '{')
                    stk.pop();
                
                else
                    return false;
            }
        }
        
        if (stk.empty())
            return true;
        
        return false;
    }
};
