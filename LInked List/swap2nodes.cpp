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

node *skipMdeleteN(node *head, int M, int N)
{

    if (M == 0)
        return NULL; // edge case  not a base case

    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *temp = head;
    int count1 = 0;
    int count2 = 0;
    while (temp->next != NULL && count1 < M - 1) // travel M nodes
    {
        count1++;
        temp = temp->next;
    }
    node *t1 = temp;
    // t1=temp;
    temp = temp->next;
    if (temp == NULL)
        return head;

    while (temp->next != NULL && count2 < N - 1)
    {
        count2++;
        temp = temp->next;
    }

    node *t2;
    t2 = temp->next;

    node *m = skipMdeleteN(t2, M, N);
    t1->next = m;
    return head;
}

node *swap_nodes(node *head, int i, int j)
{
    // write your code here
    node *p = head, *q = head;

    for (int index = 0; index < i; index++)
    {
        p = p->next;
    }
    for (int index = 0; index < j; index++)
    {
        q = q->next;
    }

    int x = p->data;
    p->data = q->data;
    q->data = x;

    return head;
}
int main()
{
    node *head = takeInputLL();
    print(head);
    cout << endl;
    int i, j;
    cin >> i >> j;
    node *fH = swap_nodes(head, i, j);
    print(fH);
}