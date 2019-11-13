#include<stdio.h> 
#include<stdlib.h>

#define printarray(num,size) ({printf("Array[\t");                 	\
			for(int prarrayi=0;prarrayi<size;prarrayi++)			\
				printf("%d\t",(num)[prarrayi]);						\
			printf("]\n");	})	
#ifndef NODEBUG
	#define pr(format, ...) (printf(#format,##__VA_ARGS__))
	#define prt(format, ...) (printf("Function:[%s()]\t\tMessage:["#format"]"	\
							,__FUNCTION__,##__VA_ARGS__))
	#define prpara(format, ...) (printf("FUNCTION:  %s(  "#format"  )\n"	\
							,__FUNCTION__,##__VA_ARGS__))
	#define prfile() (printf("File:[%s]\n",__FILE__))
	#define prarray(num,size) ({pr(Array[\t);                 	\
				for(int prarrayi=0;prarrayi<size;prarrayi++)	\
					pr(%d\t,(num)[prarrayi]);					\
				pr(]\n);})										
#else
	#define pr(format, ...) ({})
	#define prt(format, ...) ({})
	#define prpara(format,...) ({})
	#define prfile() ({})
	#define prarray(num,size) ({})
#endif


#define mloc(ptr,TYPE,num) (ptr = (TYPE *)malloc((num)*sizeof(TYPE)))
#define ml(ptr) mloc(ptr,typeof(*(ptr)),1)
#define mll(ptr,num) mloc(ptr,typeof(*(ptr)),(num))

/************************************************************************************************************************************************/					
/*													List interface																				*/
/*	listptr():			return a pointer which linked the next struct list_head in pos struct. 													*/
/*	list_next():		return a pointer to the next struct member which is same type with pos pointer in linked list.							*/
/*	list_next_head():	return a pointer to the next struct member which is same type with pos pointer of the headnode in linked list.			*/
/*	INIT_LIST_HEAD():	init the headnode in linked list.																						*/
/*																																				*/
/*	listadd():			add the same struct to the next member of pos in linked list.															*/
/*	listadd_head():		add the struct to the next member of headnode in linked list.															*/
/*	listremove():		remove the member, isn't free memory.																					*/
/*	clear_list():		Need to be implemented in the .c file beacause the parameter of MACRO couldn't use in function. 						*/
/*																																				*/
/************************************************************************************************************************************************/

struct list_head 
{
	struct list_head *prev;
	struct list_head *next;
};

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({                      			\
				const typeof( ((type *)0)->member ) *__mptr = (ptr);		\
				(type *)( (char *)__mptr - offsetof(type,member) );})

#define listptr(ptr, member, pos) (ptr->member.pos)

#define list_next(ptr, member) 												\
					(container_of((ptr)->member.next,typeof(*ptr),member))
#define list_next_head(head, ptr, member) 									\
					(container_of((head)->next,typeof(*ptr),member))

/*	headnode needn't to be same type(struct) with pos pointer. 	*/
/*		because 'pos = container_of(...)' and '&pos->member'	*/
/*		don't trigger the segment fault							*/	
#define lentry_head(pos, head, member)										\
	for(pos = list_next_head(head,pos,member); &(pos)->member != (head);	\
	    pos = list_next(pos,member))
    
#define INIT_LIST_HEAD(ptr, member) (LIST_HEAD_INIT(&(ptr)->member))
static inline void LIST_HEAD_INIT(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

#define listadd(new, ptr, member) (__list_add(&(new)->member, &(ptr)->member))
#define listadd_head(new, newmember, head) (__list_add(&(new)->newmember, (head)))
static inline void __list_add(struct list_head *_new,
			      struct list_head *prev)
{
	prev->next->prev = _new;
	_new->next = prev->next;
	_new->prev = prev;
	prev->next = _new;
}

#define listremove(ptr, member) (__list_remove(ptr->member))
static inline void __list_remove(struct list_head *_old)
{
	_old->next->prev = _old->prev;
	_old->prev->next = _old->next;
	_old->next = _old;
	_old->prev = _old;
}

/* clear all data struct in linked list */
static inline void clear_list(struct list_head *head);/*
{
	struct data *pos,*tmp;
	for(pos = list_next_head(head,pos,member); &(pos)->member != (head);){
		tmp = pos;
		pos = list_next(pos,member);
		listremove(tmp,member);
		free(tmp);
	}
	__list_remove(head);
}*/	

/*
struct Data{
	struct list_head l1;
}D;

struct list{
	int val;
	struct list_head list; 
}; 


int main()
{
	INIT_LIST_HEAD(&D,l1);
	struct list *l;
	for(int i=1;i<6;i++){
		ml(l);
		l->val = i;
		listadd_head(l,list,&D.l1);
	}
	
	lentry_head(l,&D.l1,list){
		pr(val:%d,l->val);
	}
}
*/
