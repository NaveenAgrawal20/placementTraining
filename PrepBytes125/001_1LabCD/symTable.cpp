#include <iostream>
#include <cstring>
using namespace std;

struct SymbTab
{
    char label[10], symbol[10];
    int addr;
    SymbTab *next;
};
SymbTab *first = NULL, *last = NULL;

void Display()
{
    int i;
    SymbTab *p;
    p = first;
    printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");
    while (p)
    {
        printf("\t%s\t\t%s\t\t%d\n", p->label, p->symbol, p->addr);
        p = p->next;
    }
}

bool Search(char *l, int &k)
{
    SymbTab *p = first;
    while (p)
    {
        if (strcmp(p->label, l) == 0)
            return true;
        p = p->next;
        k++;
    }
    return false;
}
void Insert()
{
    cout<<"---------INSERT--------\n";
    int n, pos = 0;
    char l[10];
    cout << "Enter label ";
    cin >> l;
    n = Search(l, pos);
    if (n)
    {
        cout << "Duplicate entry not allowed\n";
        return;
    }
    else
    {
        SymbTab *newnode = new SymbTab();
        strcpy(newnode->label, l);
        cout << "Enter symbol and address\n";
        cin >> newnode->symbol;
        cin >> newnode->addr;

        newnode->next = NULL;
        if (first == NULL)
        {
            first = last = newnode;
        }
        else
        {
            SymbTab *p = first;
            while (p->next != NULL)
                p = p->next;
            p->next = newnode;
            last = newnode;
        }
    }
    cout << "Inserted\n";
    Display();
}

void Delete()
{
    cout<<"---------DELETE-------\n";
    int n,pos = 0;
    char l[10];
    if (first == NULL)
    {
        cout << "EMPTY\n";
        return;
    }
    cout << "Enter label ";
    cin >> l;
    n = Search(l,pos);
    SymbTab *p = first;
    if (n)
    {
        if (strcmp(first->label, l) == 0)
        {
            first = first->next;
        }
        else if (strcmp(last->label, l) == 0)
        {
            SymbTab *q = p;
            while (q->next != last)
            {
                q = q->next;
            }
            q->next = NULL;
        }
        else
        {
            while (strcmp(p->next->label, l) != 0)
            {
                p = p->next;
            }
            p->next = p->next->next;
        }
        cout << "Label Deleted\n";
    }
    else
    {
        cout << "NOT FOUND\n";
    }
    Display();
}

void Modify()
{
    cout<<"---------MODIFY--------\n";
    char nl[10], l[10];
    int choice, newAddr, s, pos = 0;
    printf("Enter the old label : ");
    scanf("%s", l);
    s = Search(l, pos);
    if (!s)
    {
        cout << "LABEL NOT FOUND\n";
        return;
    }

    SymbTab *p = first;
    printf("\n\tWhat do you want to modify?\n");
    printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
    printf("\tEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        cout << "Enter new Label\n";
        cin >> nl;
        for (int i = 1; i <= pos; i++)
        {
            p = p->next;
        }
        strcpy(p->label, nl);
        break;
    case 2:
        cout << "Enter new address\n";
        cin >> newAddr;
        for (int i = 1; i <= pos; i++)
        {
            p = p->next;
        }
        p->addr = newAddr;
        break;
    case 3:
        cout << "Enter new Label\n";
        cin >> nl;
        cout << "Enter new address\n";
        cin >> newAddr;
        for (int i = 1; i <= pos; i++)
        {
            p = p->next;
        }
        strcpy(p->label, nl);
        p->addr = newAddr;
        break;
    }
    Display();
}

int main()
{
    Insert();
    Insert();
    Insert();
    Delete();
    Insert();
    Modify();
    Delete();
    Modify();
    Delete();
    Modify();
    Delete();
}
/*
PLUS + 100
MINUS - 200
MULT * 300
PLUS
DIV / 500

*/