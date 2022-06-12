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
Node *midPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool pallin(Node *head)
{
    Node *mid = midPoint(head);
    Node *fH = head;
    Node *s = mid->next;
    mid->next = NULL;
    Node *sH = reverseLL(s);
    while (fH and sH)
    {
        if (fH->data != sH->data)
        {
            return false;
        }
        fH = fH->next;
        sH = sH->next;
    }
    return true;
}

int main()
{
    Node *head = takeInput();
    print(head);
    // Node *nh = reverseLL(head);
    cout << endl;
    bool pal = pallin(head);
    cout << pal;
}