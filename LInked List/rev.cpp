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

Node *reverseLL(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *after;
    while (curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    head = prev;
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    Node *nh = reverseLL(head);
    cout << endl;
    print(nh);
}