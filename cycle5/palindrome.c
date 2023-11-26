#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node* prev;
    struct node* next;
};

struct node* insert(char s, struct node* head)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = s;
    temp->next = NULL;

    if(head->next == NULL)
    {
        temp->prev = head;
        head->next = temp;
    }
    else
    {
        struct node* ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
    return head;
}

int isPalindrome(struct node* head)
{
    struct node* ptr1 = head->next; //beginning side
    struct node* ptr2 = head->next; //last node

    while(ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }

    while(ptr1 != ptr2 && ptr2->next != ptr1) //loop terminates when both nodes point to same location in case of odd length or when last node reaches before first node in case of even length
    {
        if(ptr1->data != ptr2->data)
        {
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->prev;
    }
    return 1;
}

void main()
{
    char str[25];
    struct node* head;
    head=malloc(sizeof(struct node));
    head->prev=NULL;
    head->next=NULL;

    printf("Enter the string : ");
    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++)
    {
        head = insert(str[i], head);
    }

    if(isPalindrome(head))
    {
        printf("%s is Palindrome\n", str);
    }
    else
    {
        printf("%s is NOT a palindrome\n", str);
    }
}
