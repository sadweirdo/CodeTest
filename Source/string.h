int strlen(char *string)
{
	int i;
	for(i=0 ;string[i] ;i++);
	return i;
}

int dec_to_str(int x,char **string)
{
	int count= num_decdigits(x);
	
	*string = mlloc(char,count+1);
	if(!*string) return 0;
	
	for(int i=count-1,tmp ;i>=0 ;i--){
		tmp = x%10;
		x /=10;
		(*string)[i] = tmp + '0';
	}
	(*string)[count]='\0';
	return count;
}

int str_to_dec(char *string)
{
		int ret = 0;
		int index = strlen(string);

		for(int i=0 ;i<index ;i++)
			ret = ret*10 + string[i]-'0';
		
		return ret;
}