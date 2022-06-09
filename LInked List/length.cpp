#include <bits/stdc++.h>
using namespace std;
int len(list<int> &l1)
{
    list<int>::iterator it;
    int i = 0;
    for (it = l1.begin(); it != l1.end(); it++)
    {
        i++;
    }
    return i;
}

int main()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    cout << len(l1);
}