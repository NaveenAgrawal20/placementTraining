#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data, expX, expY;
    struct Node *next;
} Node;

Node *getNode(int data, int expoX, int expoY)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->expX = expoX;
    newnode->expY = expoY;
    newnode->next = NULL;
    return newnode;
}
void insert(Node **p, int coeff, int expoX, int expoY)
{
    Node *newnode = getNode(coeff, expoX, expoY);
    if (*p == NULL)
    {
        *p = newnode;
    }
    else
    {
        Node *crawler = *p;
        while (crawler->next)
        {
            crawler = crawler->next;
        }
        crawler->next = newnode;
    }
}

void readPolynomial(Node **p)
{
    int n, i, coeff, expoX, expoY;
    printf("Enter num of terms ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter Coeff X ");
        scanf("%d", &coeff);
        printf("Enter exponent for X ");
        scanf("%d", &expoX);
        printf("Enter exponent for Y ");
        scanf("%d", &expoY);
        // inserting in newnode;
        insert(p, coeff, expoX, expoY);
    }
}
void display(Node *p)
{
    if (p == NULL)
    {
        printf("Empty List");
        return;
    }
    Node *crawler = p;
    while (crawler)
    {
        if (crawler->data > 0)
            printf("+%dx^%dy^%d ", crawler->data, crawler->expX, crawler->expY);
        else
            printf("%dx^%dy^%d ", crawler->data, crawler->expX, crawler->expY);
        crawler = crawler->next;
    }
}
void addition(Node *root1, Node *root2, Node **root3)
{
    Node *p1 = root1;
    Node *p2 = root2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expX == p2->expX && p1->expY == p2->expY)
        {
            insert(root3, p1->data + p2->data, p1->expX, p2->expY);
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            if (p1->expX + p1->expY > p2->expX + p2->expY){
                insert(root3, p1->data, p1->expX, p1->expY);
                p1 = p1->next;
            }
            else
            {
                insert(root3, p2->data, p2->expX, p2->expY);
                p2 = p2->next;
            }
        }
        
        
    }
    while(p1)
    {
        insert(root3, p1->data, p1->expX, p1->expY);
        p1 = p1->next;
    }
    while(p2)
    {
        insert(root3, p2->data, p2->expX, p2->expY);
        p2 = p2->next;
    }        
}

int main()
{
    Node *p1 = NULL, *p2 = NULL, *p3 = NULL;
    printf("Enter 1st Polynomial ");
    readPolynomial(&p1);
    display(p1);
    printf("\nEnter 2nd Polynomial ");
    readPolynomial(&p2);
    display(p2);
    // addition
    addition(p1,p2,&p3);
    printf("\nThe addition  = ");
    display(p3);
    return 0;
}
/*
4
8
5
6
-12
3
4
11
3
3
20
-1
3
5
7
5
6
10
4
4
-5
3
4
-6
3
3
10
0
1
// The addition  = +15x^5y^6 +10x^4y^4 -17x^3y^4 +5x^3y^3 +20x^-1y^3 +10x^0y^1
*/