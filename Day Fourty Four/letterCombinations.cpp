class Solution {
public:
    unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                 {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

void help(string digits, vector<string>& vect, string s)
{
    if (digits == "")
    {
        vect.push_back(s);
        return;
    }

    char c = digits[0];

    for (int i=0;i<m[c].length();i++)
    {
        string sub = s + m[c][i];
        help(digits.substr(1), vect, sub);
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits == "")
        return {};
    
    vector<string> vect;
    string s;

    help(digits, vect, s);

    return vect;
}

};
