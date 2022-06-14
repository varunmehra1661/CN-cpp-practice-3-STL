#include <bits/stdc++.h>
using namespace std;
bool checkRedundantBrackets(char *input)
{
    // Write your code here
    stack<char> s;
    int count;
    int i = 0;
    int len = 0;
    while (input[len] != '\0')
    {
        len++;
    }
    while (i < len)
    {
        count = 0;
        while (input[i] != ')' && i < len)
        {
            s.push(input[i]);
            i++;
        }
        i = i - 1;
        while (input[i] != '(')
        {
            s.pop();
            count++;
            i--;
        }
        s.pop();

        if (count == 0)
            return true;

        else
            i = i + count + 2;
    }
    return false;
}

int main()
{
    char ch[] = "((a+b))";
    cout << checkRedundantBrackets(ch);
}