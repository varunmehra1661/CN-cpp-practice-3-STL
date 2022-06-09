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

Node *deleteAt(Node *head, int n)
{
    Node *temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    Node *a = temp->next;
    temp->next = temp->next->next;
    delete a;
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << endl;
    Node *nhead = deleteAt(head, 2);
    print(nhead);
}