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

int foundAt(Node *head, int data)
{
    int i = 0;
    Node *temp = head;
    if (head->data == data)
    {
        return i;
    }

    while (temp != NULL)
    {

        temp = temp->next;
        i++;
        if (temp->data == data)
        {
            return i;
        }
    }
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << endl;
    cout << foundAt(head, 4);
}