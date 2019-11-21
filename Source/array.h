
typedef struct{
	int size;
	int head,tail; //tail存放，head删除 
	int length;
	TYPEC array[0];
}oriArray;
typedef oriArray Queue;
typedef oriArray Stack;

#define oriArray_location(index,num,length) \
					(((index)+(length)+(num))%(length))

static inline oriArray * oriArray_init(int len)
{
    if(!len)    return NULL;
	oriArray *p = (oriArray *)calloc(1,sizeof(oriArray)+sizeof(TYPEC)*len);
	if(p != NULL)
		p->length = len;
	return p;
}
static inline int oriArray_sizeok(oriArray *array)
{
    if(!array)   return 1;
    int num = (array->tail + array->length - array->head)%(array->length);
    if(!num && array->size == array->length)    return 0;
    return num != array->size;
}
static inline int oriArray_size(oriArray *array)
{
    if(oriArray_sizeok(array))   return -1;
    return array->size;
}
/*	head turn to low address,tail turn to high address.			*/
/*	so when we add data to head, the head index will decrease.	*/
static inline int oriArray_add_head(oriArray *array, TYPEC data)
{
	if(oriArray_sizeok(array) || array->size==array->length)	
		return 1;
	
    array->head = oriArray_location(array->head,-1,array->length);//因为head辅助tail，因此head先移动在填数据，不会影响大小计算 
	array->array[array->head] = data;
	array->size++;
	return 0;
}

/*	remove function receive TYPEC variable or TYPEC pointer which have alloc memory	*/
/*	when function receive a TYPEC pointer which is uninitialized ,					*/
/*	function may have segment fault.												*/
static inline int oriArray_remove_head(oriArray *array, TYPEC *data)
{
	if(oriArray_sizeok(array) || array->size==0)	
		return 1;
		
	if(data)
		*data = array->array[array->head];
	array->array[array->head]=0;	//因为head先移动再填充，所以删除时先删除再移动 
	array->size--;
	array->head = oriArray_location(array->head,1,array->length);
	return 0;
}

static inline int oriArray_add_tail(oriArray *array, TYPEC data)
{
	if(oriArray_sizeok(array) || array->size==array->length)	
		return 1;
	
    array->array[array->tail] = data;	
	array->tail = oriArray_location(array->tail,1,array->length);
	array->size++;
	return 0;
}

static inline int oriArray_remove_tail(oriArray *array, TYPEC *data)
{
	if(oriArray_sizeok(array) || array->size==0)	
		return 1;	
		
	array->tail = oriArray_location(array->tail,-1,array->length);
	if(data)   *data = array->array[array->tail];
	array->array[array->tail]=0;
	array->size--;
		
	return 0;
}

static inline void oriArray_prt(oriArray *array,char flag)
{
	printf("Array List:[");
	for(int i=0;i<array->size;i++){
		if(!flag)
			printf("%d\t",array->array[oriArray_location(array->head,i,array->length)]);
		else if(flag ==1)
			printf("%x\t",array->array[oriArray_location(array->head,i,array->length)]);
		else if (flag ==2)
			printf("%s\t",array->array[oriArray_location(array->head,i,array->length)]);
		else
			printf("%c\t",array->array[oriArray_location(array->head,i,array->length)]);
	}
	printf("]\n");
}

/* Queue API */
static inline Queue * queue_init(int len)
{
	return oriArray_init(len);
}
static inline void queue_add(Queue *queue,TYPEC data)
{
	int rc;
	rc = oriArray_add_tail(queue,data);
	if(rc)
		printf("Add fail,maybe array is full or struct was modified incorrectly\n");
}
static inline void queue_remove(Queue *queue, TYPEC *data)
{
	int rc;
	rc = oriArray_remove_head(queue,data);
	if(rc)
		printf("Remove fail,maybe array is empty or struct was modified incorrectly\n");
}
static inline int queue_size(Queue *queue)
{
    return oriArray_size(queue);
}
static inline TYPEC queue_next(Queue *queue)
{
	return queue->array[queue->head];
}
static inline void queue_prt(Queue *queue)
{
	return oriArray_prt(queue,0);
}
static inline void queue_prt_hex(Queue *queue)
{
	return oriArray_prt(queue,1);
}
static inline void queue_prt_str(Queue *queue)
{
	return oriArray_prt(queue,2);
}
static inline void queue_prt_char(Queue *queue)
{
	return oriArray_prt(queue,3);
}

/* Stack API */
static inline Stack * stack_init(int len)
{
	return oriArray_init(len);
}
static inline void stack_add(Stack *stack,TYPEC data)
{
	int rc;
	rc = oriArray_add_tail(stack,data);
	if(rc)
		printf("Add fail,maybe array is full or struct was modified incorrectly\n");
}
static inline void stack_remove(Stack *stack, TYPEC *data)
{
	int rc;
	rc = oriArray_remove_tail(stack,data);
	if(rc)
		printf("Remove fail,maybe array is empty or struct was modified incorrectly\n");
}
static inline int stack_size(Stack *stack)
{
    return oriArray_size(stack);
}
static inline TYPEC stack_next(Stack *stack)
{
	return stack->array[oriArray_location(stack->tail,-1,stack->length)];
}
static inline void stack_prt(Stack *stack)
{
	return oriArray_prt(stack,0);
}
static inline void stack_prt_hex(Stack *stack)
{
	return oriArray_prt(stack,1);
}
static inline void stack_prt_str(Stack *stack)
{
	return oriArray_prt(stack,2);
}
static inline void stack_prt_char(Stack *stack)
{
	return oriArray_prt(stack,3);
}
