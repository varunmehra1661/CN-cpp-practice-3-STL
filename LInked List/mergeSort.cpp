#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int length(Node *head)
{

    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
Node *mergeTwoLLs(Node *head1, Node *head2)
{

    Node *p = NULL, *q = NULL;
    if (head1->data < head2->data)
    {
        p = head1;
        q = head1;
        head1 = head1->next;
    }
    else if (head1->data >= head2->data)
    {
        p = head2;
        q = head2;
        head2 = head2->next;
    }
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            q->next = head1;
            q = head1;
            head1 = head1->next;
            q->next = NULL;
        }
        else if (head1->data >= head2->data)
        {
            q->next = head2;
            q = head2;
            head2 = head2->next;
            q->next = NULL;
        }
    }
    if (head1)
        q->next = head1;
    if (head2)
        q->next = head2;

    return p;
}

Node *mergeSort(Node *head)
{
    // write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // breaking Node into two half
    Node *p = head;
    for (int i = 1; i < length(head) / 2; i++)
    {
        p = p->next;
    }
    Node *head1 = p->next;
    p->next = NULL;

    head = mergeSort(head);
    head1 = mergeSort(head1);

    return mergeTwoLLs(head, head1);
}
int main()
{
    Node *head = takeInput();
    Node *fH = mergeSort(head);
    print(fH);
}