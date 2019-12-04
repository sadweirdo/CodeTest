#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *slow,*quick;
	/* 不用quick=head->next初始化避免额外检测head值 */
	/* 这形势下初始slow会和quick同值，所以要先quick=quick->next再对slow赋值 */
    for(slow=quick=head;quick;quick = quick->next,slow->next = NULL){	
        if(slow->val != quick->val) {
            slow->next = quick;
            slow = slow->next;
        }
    }
    return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *slow,*quick;
	/*	修改版使用quick->next作为slow的next，因为quick会遍历链表，所以遍历到最后一项时quick->next必然为NULL，以用于切断链表尾部重复数据 */
    for(slow=quick=head ;quick; slow->next = quick = quick->next){	
        if(slow->val != quick->val) {
            slow->next = quick;
            slow = slow->next;
        }
    }
    return head;
}