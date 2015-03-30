#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct person {
    int data;
    struct person *next;
}node;

/*
*function : create a single Linked list
*input : int number, -1 means end of input
*return : the head pointer of linked list
*/
node *create(){
    node *head, *p, *s;
    int i, cycle;
    head = (node*)malloc(sizeof(node));
    p = head;
    while(cycle) {
        printf("please input a number\n");
        scanf("%d", &i);
        if (-1 != i) {
            s = (node*)malloc(sizeof(node));
            s->data = i;
            printf("new node's data is %d\n", s->data);
            p->next = s;
            p = s;
        }
        else {
            cycle = 0;
        }
    }
    head = head->next;
    p->next = NULL;
    printf("\n yyy %d \n", p->data);
    return(head);
}
/*
*function : calculate the length of linked list 's length
*input : head pointer of list
*return : int number of length
*/
int listLength(node *head) {
    int n = 0;
    node *p;
    p = head;
    while(p != NULL) {
        p = p->next;
        n++;
    }
    return (n);
}

void printList(node *head) {
    node *p;
    int n;
    p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/*
*function : delete the first key in the list
*input : head pointer of list, int number of key
*return : list pointer after delete the key
*/
node *deleteKey(node *head, int key) {
    node *p1, *p2;
    p1 = head;
    while (p1 != NULL && key != p1->data) {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1 != NULL) {
        if (p1 == head) {
            head = head->next;
            free(p1);
        } else {
            p2->next = p1->next;
            free(p1);
        }
    }
    else {
        printf("Could not find the key %d  in this linked list\n", &key);
    }
    return head;
}
/*
*function : delete all number given as key in the list
*input : head pointer of list, int number of key
*return : list pointer after delete the key
*/
node *deleteAllKey(node *head, int key) {
    node *p1, *p2;
    p1 = head;
    while (p1 != NULL) {
        if (key == p1->data) {
            if (p1 == head) {
                p1 = head->next;
                node *tmp = head;
                head = head->next;
                free(tmp);
            }
            else{
                p2->next = p1->next;
                p1 = p1->next;
            }
        }
        else {
            p2 = p1;
            p1 = p1->next;
        }
    }
    return head;
}
/*
*function : sort the list
*input : head pointer of list
*return : list pointer after sort
*/
node *sort(node *head) {
    node *p, *p2, *p3;
    int n; int temp;
    n = listLength(head);
    if (head == NULL || head->next == NULL)
        return head;
    p = head;
    for (int j = 1; j < n; ++j) {
        p = head;
        for (int i = 0; i < n - j; ++i) {
            if (p-> data > p->next->data) {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
    return head;
}
/*
*function : reverse the list
*input : head pointer of list
*return : list pointer after sort
*/
node *reverseList(node *head) {
    node *p1, *p2, *p3;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    p1 = head;
    p2 = p1->next;
    while (p2) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head->next = NULL;
    head = p1;
    return head;
}
int main() {
    node *newl;
    newl = create();
    int len = listLength(newl);
    printList(newl);
    newl = deleteAllKey(newl,3);
    printList(newl);
    newl = reverseList(newl);
    printList(newl);
    return 0;
}
