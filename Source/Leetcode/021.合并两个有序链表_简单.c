#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*		一级指针解法		*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head=NULL,*tail;
    if(!l1 && !l2)  return NULL;
    while(l1&&l2){
        int flag=0;
        if(l1->val>l2->val) flag =1;
        if(head==NULL){
            head = flag?l2:l1;
            tail = head;
        }	else{
            tail->next = flag?l2:l1;  
            tail = tail->next;
        }
        
        if(flag)    l2 = l2->next;
        else    l1=l1->next;
    }
    if(l1)  
        if(head==NULL)  head = l1;
        else    tail->next = l1;
    else
        if(head == NULL) head=l2;
        else    tail->next = l2;
    return head;
}

/*		二级指针		*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(!l1&&!l2) return NULL;
    struct ListNode *head = NULL, **tail = &head;
    
    while(l1&&l2){
        int flag=0;
        if(l2->val<l1->val) flag=1;
        *tail = flag?l2:l1;
        tail = &(*tail)->next;
        if(flag)    l2=l2->next;
        else    l1=l1->next;
    }
    
    if(l1)  *tail = l1;
    else    *tail = l2;
    return head;
}
