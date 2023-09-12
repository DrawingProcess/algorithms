#include <iostream>
#include <string>
#include <vector>

bool parenthesis(std::string& str)
{
    std::vector<char> paren;
    for (int idx = 0; idx < str.size(); idx++)
    {
        if (str[idx] == '(')
        {
            paren.push_back(str[idx]);
        }
        else if (str[idx] == ')')
        {
            if (!paren.size())
            {
                return false;
            }
            paren.pop_back();
        }
    }
    if (paren.size())
    {
        return false;
    }
    return true;
}

int main()
{
    int num;
    std::cin >> num;

    std::string str;
    for (int i = 0; i < num; i++)
    {
        std::cin >> str;
        bool correct = parenthesis(str);
        if (correct)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}