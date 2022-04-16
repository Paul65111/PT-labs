#include <stdlib.h>
#include <stdio.h>
void sort(float arrval[],float arrweigth[],int length){
	int ok,aux1,aux2,i;
	do{
		ok=0;
		for(i=0;i<length;i++){
			if(arrval[i]/arrweigth[i]<arrval[i+1]/arrweigth[i+1]){
			aux1=arrval[i];
			arrval[i]=arrval[i+1];
			arrval[i+1]=aux1;
			aux2=arrweigth[i];
			arrweigth[i]=arrweigth[i+1];
			arrweigth[i+1]=aux2;
			ok=1;
			}
		}
	
	}while(ok!=0);
	
	
}

int main(){
	float arrval[10]={100,1800,60};
	float arrweigth[10]={20,60,10};
	int n=3,capacity=50,sum=0,i=0;
	sort(arrval,arrweigth,n);
	while(capacity>=arrweigth[i]){
		sum=sum+arrval[i];
		capacity=capacity-arrweigth[i];
		i++;	
	}
	if(capacity!=0){
		sum=sum+((capacity/arrweigth[i])*arrval[i]);
	}
	
	printf("sum=%d\n",sum);
	
	return 0;
	
}
