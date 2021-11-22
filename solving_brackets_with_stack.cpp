#include <iostream>
 
using namespace std;

struct Node 
{
    int Value; 
    Node* link;
};

Node* header = NULL;

int main() 
{  
    /*
    { = 123; } = 125; [ = 91; ] = 93; ( = 40; ) = 41;
    */
    char x[11] = "{()[]()}[]";
    char *ptr = x;
    for (int i = 0; i < sizeof(x)-1; i++)
    {
        Node *tempo = header;
        while (tempo != NULL)
        {
            cout << tempo->Value << " ";
            tempo = tempo->link;
        }
        cout << "\n";

        if ( int(*(ptr + i)) == 123 || int(*(ptr + i)) == 91 || int(*(ptr + i)) == 40)
        {
            Node *temp = (Node*)malloc(sizeof(Node));

            if (*(ptr + i) == '(')
                {temp->Value = int(*(ptr + i)) + 1;}
            else
                {temp->Value = int(*(ptr + i)) + 2;}

            if (header == NULL)
            {
                header = temp;
                temp->link = NULL;
            }
            else
            {
                temp->link = header;
                header = temp;
            }
        }
        else
        {
            if (header != NULL && int(*(ptr + i)) == header->Value)
            {   
                Node *temp_1 = header;
                header = header->link;
                free(temp_1);
            }
            else if ((header != NULL && int(*(ptr + i)) != header->Value) || header == NULL)
            {
                cout << "Chain is broken!! Exit.";
                exit(1);
            }
        }
    }

    Node *temp_2 = header;
    
    if (header == NULL || header->link == NULL)
        cout << "Good chain" << endl;
    else
        cout << "Chain is broken" << endl;
    
    return 0;
}