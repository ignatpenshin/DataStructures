#include <stdlib.h>
#include <stdio.h>
 
using namespace std;

struct Node 
{
    int Value; 
    Node* link;
};

Node* Insert(Node*, int);
void Print(Node*);
Node* Reverse(Node*);
Node* recursReverse(Node*);


int main()
{
    Node* head;
    head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Your number:\n");
        scanf("%d", &x);
        head = Insert(head, x);
        Print(head);
    }

    head = recursReverse(head);
    Print(head);
    
    return 0;
}

Node* Reverse(Node* head)
{
    Node *past, *mid, *next;
    past = NULL;
    mid = head;
    next = head->link;
    while(true)
    {
        if (past == NULL)
        {
            past = mid;
            past->link = NULL;
        }
        else {past = mid;}
        mid = next;
        next = next->link;
        if (next == NULL)
        {
            mid->link = past;
            head = mid;
            break;
        }
        mid->link = past;
    }
    return head;
}

Node* Insert(Node *head, int x)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->Value = x;
    temp->link = NULL;
    if (head != NULL)
    {
        temp->link = head;
    }
    head = temp;

    return head;    
}

void Print(Node *head)
{
    Node* temp = head;  
    printf("list is: ");
    while (temp != NULL)
    {
        printf("%d", temp->Value);
        temp = temp->link;
    }
    printf("\n");
}