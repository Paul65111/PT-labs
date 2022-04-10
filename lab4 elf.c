#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct aux{
  uint8_t el_mag0;
  uint8_t el_mag1;
  uint8_t el_mag2;
  uint8_t el_mag3;
  uint8_t el_class;
  uint8_t el_data;
  uint8_t el_version;
  uint8_t el_osabi;
}ELF;

int main(int argc,char **argv){
  FILE *f;
  ELF elf;
  f=fopen("tf","rb");
  if(f==NULL){
    printf("Error open\n");
    exit(1);
  }
  fread(&elf,1,sizeof(ELF),f);
  printf("b0=%d ,b1=%d ,b2=%d ,b3=%d\n",elf.el_mag0,elf.el_mag1,elf.el_mag2,elf.el_mag3);
  if((elf.el_mag0==0x7F)&&(elf.el_mag1=='L')&&(elf.el_mag2=='F')){
	printf("Valid ELF file\n");
  }else{
  	printf("Not valid Elf file\n");
  }
  if(elf.el_class==1){
  	printf("This is a 32 bit ELF file\n");
  }else if(elf.el_class==2){
  	printf("This is a 64 bit ELF file \n");
  }
  if(elf.el_data==1){
  	printf("Little EDIAN\n");
  }else if(elf.el_data==2){
  	printf("Big EDIAN \n");
  }
  if(elf.el_version==1){
  	printf("Original current verion of Elf file \n");
  }else {
  	printf("Not original and current version of ELF file \n");
  }
  switch(elf.el_osabi)
        {
            case 0:
                printf("System V\n");
                break;
            case 1:
                printf("HP-UX\n");
                break;
            case 2:
                printf("NetBSD\n");
                break;
            case 3:
                printf("Linux\n");
                break;
            case 4:
                printf("GNU Hurd \n");
                break;
            case 6:
                printf("Solaris \n");
                break;
            case 7:
                printf("AIX\n");
                break;
            case 8:
                printf("IRIX\n");
                break;
            case 9:
                printf("FreeBSD\n");
                break;
            case 'A':
                printf("Tru64");
                break;
            case 'B':
                printf("Novell Modesto \n");
                break;
            case 'C':
                printf("OpenBSD\n");
                break;
            case 'D':
                printf("OpenVMS\n");
                break;
            case 'E':
                printf("NonStop Kernel\n");
                break;
            case 'F':
                printf("Aros\n");
                break;
            case 10:
                printf("Fenix OS\n");
                break;
            case 11:
                printf("Cloud ABI\n");
                break;
            case 12:
                printf("Stratus Technologies OpenVOS\n");
                break;
        }
  
  
  fclose(f);
  
}
