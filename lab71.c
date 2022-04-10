#include <stdlib.h>
#include <stdio.h>
char *a0_19[20]={"zero","one","two","three","four","five","six","seven"
		   ,"eight","nine","ten","eleven","twelve","thirteen"
		   ,"fourteen","fifteen","sixteen","seventeen","eighteen"
		   ,"nineteen"};
char* a20_90[10]={"twenty","thirty","forty","fifty","sixty","seventy"
		    ,"eighty","ninety"};

void ang0_19(int n){
  if(n>0 && n<=19){
    printf("%s ",a0_19[n]);
  }
}

void ang20_99(int n){
  int fd,sd;
  if(n>=20&& n<=99){
    fd=(n/10);
    sd=n%10;
    printf("%s ",a20_90[fd-2]);
    if(sd!=0){
      ang0_19(sd);
    }
  }
}

void ang100_999(int n){
  int fd,sd,td;
  int second_two=0;
  fd=n/100;
  sd=(n/10)%10;
  td=n%10;
  second_two=10*sd+td;
  ang0_19(fd);
  if(fd!=0) printf("hundred ");
  if(second_two>=20&&second_two<=99)
  	ang20_99(second_two);
  else
  	ang0_19(second_two);
  
}

void ang1000_9999(int n){
  int fd,sd,td,dd;
  int aux=0;
  fd=n/1000;
  ang0_19(fd);
  if(fd!=0)printf("thousand ");
  sd=(n/100)%10;
  td=(n/10)%10;
  dd=n%10;
  aux=(100*sd)+(10*td)+dd;
  ang100_999(aux);
}

void ang10000_99999(int n){
  int td,fod,fid;
  int first_two;
  int aux=0;
  first_two=n/1000;
  ang0_19(first_two);
  ang20_99(first_two);
  printf("thousand ");
  td=(n/100)%10;
  fod=(n/10)%10;
  fid=n%10;
  aux=(100*td)+(10*fod)+fid;
  ang100_999(aux);
}

void ang100000_999999(int n){
  int fd,fod,fid,sd,sdd,tdd;
  int aux=0;
  int sd_td=0;
  fd=n/100000;
  ang0_19(fd);
  printf("hundred ");
  sdd=(n/10000)%10;
  tdd=(n/1000)%10;
  sd_td=(10*sdd)+tdd;
  ang0_19(sd_td);
  ang20_99(sd_td);
  printf("thousand ");
  fod=(n/100)%10;
  fid=(n/10)%10;
  sd=n%10;
  aux=(100*fod)+(10*fid)+sd;
  ang100_999(aux);
}


int main(){
  int n;
  printf("Give a number:\n");
  scanf("%d",&n);
  
  if(n==0){
  	printf("zero\n");
  }else if(n>0&&n<=19){
  	ang0_19(n);
  }else if(n>=20&&n<=99){
  	ang20_99(n);
  }else if(n>=100&&n<=999){
  	ang100_999(n);
  }else if(n>=1000&&n<=9999){
  	ang1000_9999(n);
  }else if(n>=10000&&n<=99999){
  	ang10000_99999(n);
  }else if(n>=100000&&n<999999){
  	ang100000_999999(n);
  }else{
  	printf("invalid value");
  }
   
  return 0;
}
