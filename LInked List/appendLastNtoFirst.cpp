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
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void append(Node *head, int le, int n)
{
    Node *temp = head;

    int pos = le - n;
    for (int i = 1; i <= pos; i++)
    {
        temp = temp->next;
    }
    Node *a = temp->next;
    temp->next = NULL;
    Node *stemp = a;
    while (stemp != NULL)
    {
        stemp = stemp->next;
    }
    stemp->next = head;
    head = a;
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << endl;
    int len = length(head);
    // cout << length(head);
    append(head, len, 3);
    print(head);
}