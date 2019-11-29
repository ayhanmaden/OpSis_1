#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int i; 
   FILE *out = fopen("database", "a");  
   if (out==NULL) {
       FILE *fptr = fopen("database", "w"); //dosya olusturmak
   }
   for (i=1; i<atoi(argv[0]); i++)   
   { 
       if(atoi(argv[i])>0){        
	   fprintf(out,"%d\n",atoi(argv[i])); // dosya yazdiriyor
       }
   }
   printf("Girilen sayilar eklendi.");
   fclose(out);  
   return 0;
}
