#include <bits/stdc++.h>
using namespace std;

void print(list<int> &list1)
{
    list<int>::iterator it;
    for (it = list1.begin(); it != list1.end(); it++)
    {
        cout << *it << " ";
    }
}
int main()
{
    list<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(5);
    list1.push_back(6);
    print(list1);
}