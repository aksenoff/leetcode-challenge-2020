bool check(string s,int& stack, int& stars)
{
    char c;
    while (s != "")
    {
        c = s.back();
        s.pop_back();
        switch (c)
        {
        case '(':
            if (stack == 0)
            {
                if (stars == 0)
                    return false;
                else stars--;
            }
            else stack--;
            break;
        case ')': stack++; break;
        case '*': stars++; break;
        }
    }
    return true;
}

class Solution {
public:
    bool checkValidString(string s) {
        int stack = 0;
        int stars = 0;
        char c;
        string s_copy = s;
        if (!check(s, stack, stars)) return false;
        if (stack == 0) return true;
        stack = stars = 0;
        reverse(s.begin(), s.end());
        replace(s.begin(), s.end(), '(', 'x');
        replace(s.begin(), s.end(), ')', '(');
        replace(s.begin(), s.end(), 'x', ')');
        if (!check(s, stack, stars)) return false;
        if (stack == 0 || stack <= stars) return true;
        else return false;
    }
};