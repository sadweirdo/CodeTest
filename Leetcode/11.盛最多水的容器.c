#include"../macro.h"
int maxArea(int* height, int heightSize){
	IN int *n = height;
	OUT int volume;
	REFOUT int tail=heightSize-1,head=0;
	int tmp;
	
	while(head<tail){
		tmp=min(n[head],n[tail]);
		volume = max(volume,tmp*(tail-head));
		if(n[head]>n[tail])
			tail--;
		else 
			head++;
	}
	
	return volume;
}
