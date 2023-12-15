#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int height;
    Node *next;
};

Node *head = NULL;   // Biến toàn cục cho đầu danh sách
int size = 0;        // Biến toàn cục cho kích thước danh sách
vector<int> outputs; // Biến toàn cục cho output

void Insert(int newHeight)
{
    Node *newNode = new Node;
    newNode->height = newHeight;
    newNode->next = NULL;
    Node *cur;
    if (head == NULL || head->height >= newHeight)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        cur = head;
        while (cur->next != NULL && cur->next->height < newHeight)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    size++;
}

void Remove()
{
    Node *cur = head;
    Node *pre = NULL;
    int count = 0;
    if (size == 1 && cur != NULL)
    {
        delete head;
        head = NULL;
        size--;
        return;
    }
    int idx = (size % 2 == 0) ? (size / 2) - 1 : size / 2;
    while (cur != NULL && count < idx)
    {
        pre = cur;
        cur = cur->next;
        count++;
    }
    if (cur != NULL)
    {
        pre->next = cur->next;
        delete cur;
        size--;
    }
}

void Print()
{
    Node *cur = head;
    int count = 0;
    int idx = (size % 2 == 0) ? size / 2 : (size / 2) + 1;
    while (cur != NULL)
    {
        if (count == idx - 1)
        {
            outputs.push_back(cur->height);
            break;
        }
        else
        {
            cur = cur->next;
            count++;
        }
    }
}

int main()
{
    int h, type, u, n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        Insert(h);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> u;
            Insert(u);
        }
        else if (type == 2)
        {
            Remove();
        }
        else if (type == 3)
        {
            Print();
        }
    }
    for (int i = 0; i < outputs.size(); i++)
        cout << outputs[i] << endl;
    return 0;
}
