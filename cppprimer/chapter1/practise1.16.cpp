#include<iostream>
int main()
{
	int value;
	int sum=0;
	while(std::cin>>value)
		sum += value;	
	std::cout << sum << std::endl;
}
