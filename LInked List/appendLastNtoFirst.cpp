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

Node *append_LinkedList(Node *head, int n)
{
    // write your code here
    Node *p = head;
    Node *q = head;
    for (int i = 1; i < length(head) - n; i++)
    {
        p = p->next;
    }
    for (int i = 1; i < length(head); i++)
    {
        q = q->next;
    }
    q->next = head; // circular LL
    head = p->next;
    p->next = NULL; // breaking that circular LL

    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << endl;
    int len = length(head);
    // cout << length(head);
    Node *nh = append_LinkedList(head, 3);
    print(nh);
}