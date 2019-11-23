/*		需要#include前用#define指定TYPEC类型	*/
typedef struct{
	int size;				//数据数量
	int head,tail; 		//head往低地址增长，tail往高地址增长
	int length;			//总长度
	TYPEC array[0];	//根据初始化的length动态申请，并
}oriArray;
typedef oriArray Queue;
typedef oriArray Stack;

/*		移动标尺，支持正负移动并防止越界	 */
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

/*		确认传入的array结构正确	*/
static inline int oriArray_sizeok(oriArray *array)
{
    if(!array)   return 1;
    int num = (array->tail + array->length - array->head)%(array->length);
    if(!num && array->size == array->length)    return 0;
    return num != array->size;
}

/*	返回array数据数量	*/
static inline int oriArray_size(oriArray *array)
{
    if(oriArray_sizeok(array))   return -1;
    return array->size;
}

/*		往head添加元素，head向低地址增长，且为先移动再添加元素 */
static inline int oriArray_add_head(oriArray *array, TYPEC data)
{
	if(oriArray_sizeok(array) || array->size==array->length)	
		return 1;
	
    array->head = oriArray_location(array->head,-1,array->length);//head先移动在填数据
	array->array[array->head] = data;
	array->size++;
	return 0;
}

/*		删除head元素并将数据传入data参数	*/
static inline int oriArray_remove_head(oriArray *array, TYPEC *data)
{
	if(oriArray_sizeok(array) || array->size==0)	
		return 1;
		
	if(data)
		*data = array->array[array->head];
	array->array[array->head]=0;	//删除时head先删除再移动 
	array->size--;
	array->head = oriArray_location(array->head,1,array->length);
	return 0;
}

/*		向tail添加元素，tail先添加再往高地址移动，因此tail指向的位置总是为空(除非已满)	*/
static inline int oriArray_add_tail(oriArray *array, TYPEC data)
{
	if(oriArray_sizeok(array) || array->size==array->length)	
		return 1;
	
    array->array[array->tail] = data;	
	array->tail = oriArray_location(array->tail,1,array->length);
	array->size++;
	return 0;
}

/*		向tail删除元素，同时将元素传入data	*/
static inline int oriArray_remove_tail(oriArray *array, TYPEC *data)
{
	if(oriArray_sizeok(array) || array->size==0)	
		return 1;	
		
	array->tail = oriArray_location(array->tail,-1,array->length);//先移动再删除
	if(data)   *data = array->array[array->tail];
	array->array[array->tail]=0;
	array->size--;
		
	return 0;
}

/*	打印整个array，0-十进制，1-十六进制，2-字符串打印，3-字符打印	*/
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
/*		队列使用tail指针存放数据，用head指针表示队列头	*/
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
/*		堆栈用tail指针存放数据，用tail-1表示栈顶		*/
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
