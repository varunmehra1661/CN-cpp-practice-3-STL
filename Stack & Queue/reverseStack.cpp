#include <bits/stdc++.h>
using namespace std;
void revStack(stack<int> &st1, stack<int> &st2)
{
    int x;
    while (!st1.empty())
    {
        x = st1.top();
        st2.push(x);
        st1.pop();
    }
    st1 = st2;
}

int main()
{
    stack<int> st1;
    stack<int> st2;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    revStack(st1, st2);
    while (!st1.empty())
    {
        cout << ' ' << st1.top();
        st1.pop();
    }
}