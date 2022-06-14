#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(node *n1)
{
    node *head = n1;
    node *temp = n1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *takeInputLL()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
class Pair
{
public:
    node *head;
    node *tail;
    Pair()
    {
        head = NULL;
        tail = NULL;
    }
};
Pair reverse(node *head)
{

    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallans = reverse(head->next);
    smallans.tail->next = head;
    smallans.tail = head;
    head->next = NULL;

    return smallans;
}
node *kReverse(node *head, int n)
{
    if (head == NULL)
        return NULL;

    node *h1 = head, *t1 = head;
    int count = 1;

    // counting till n nodes
    while (count < n && t1->next)
    {
        t1 = t1->next;
        count++;
    }
    // break this part from LL
    // and reverse it
    node *h2 = t1->next;
    t1->next = NULL;

    Pair smallans = reverse(h1);
    // we have head and tail of reversed LL in small ans

    h2 = kReverse(h2, n);

    // connecting LL again

    smallans.tail->next = h2;

    return smallans.head;
    // write your code here
}

int main()
{
    node *head = takeInputLL();
    print(head);
    cout << endl;
    node *fH = kReverse(head, 3);
    print(fH);
}