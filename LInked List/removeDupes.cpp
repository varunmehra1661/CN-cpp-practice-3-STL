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
Node *remDupes(Node *head)
{
    // write your code here
    Node *t2 = head->next, *t1 = head;
    while (t2)
    {
        if (t2->data == t1->data)
        {
            t1->next = t2->next;
            Node *t = t2;
            t2 = t2->next;
            delete t;
        }
        else
        {
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << endl;
    Node *nh = remDupes(head);
    print(nh);
}