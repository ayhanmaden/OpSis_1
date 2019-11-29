#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 100
char *str3[MAX_LIMIT], *pozitif[100], *calc[4];
void inputword(char *input); // get word from user input;;
void mathods(int i);
void main(int argc, char **argv, char **envp)
{
	// accountant , inserter , calculate , readall , clear , exit
	char str[MAX_LIMIT]; // limit input
	while (1)
	{
		printf("\naccountant>>");
		fgets(str, MAX_LIMIT, stdin); // input from user
		inputword(str);				  // full array
		if ((strcmp(str3[0], "inserter")) == 0)
		{
			int k = 1;
			for (int i = 1; i < 100; i++) // negative numbers control
			{
				if (str3[i] != NULL)
				{
					pozitif[k] = str3[i];
					k++;
				}
			}
			for (int d = 0; d < 100; d++)
			{
				str3[d] = NULL;
			}
			char snum[2];
			sprintf(snum, "%d", k);
			pozitif[0] = snum;
			mathods(1);
		}
		else if ((strcmp(str3[0], "calculate")) == 0)
		{
			if ((strcmp(str3[1], "-r") == 0))
			{

				calc[0] = str3[1];
				calc[1] = str3[2];
				calc[2] = str3[3];
			}
			else if ((strcmp(str3[1], "-s") == 0))
			{
				calc[0] = str3[1]; // 	-s
				calc[1] = str3[2]; // ilk sayi
				calc[2] = str3[3]; // ikinci sayi
			}
			else
			{
				printf("error");
			}
			mathods(2);
		}
		else if ((strcmp(str3[0], "readall\n")) == 0)
		{
			static const char filename[] = "database";
			FILE *file = fopen(filename, "r");
			if (file != NULL)
			{
				char line[128];				   /* or other suitable maximum line size */
				while (fgets(line, sizeof line, file) != NULL) /* read a line */
				{
					fputs(line, stdout); /* write the line */
				}
				fclose(file);
			}
			else
			{
				perror(filename); /* why didn't the file open? */
			}
		}
		else if ((strcmp(str3[0], "clear\n")) == 0)
		{
			system("clear");
		}
		else if ((strcmp(str3[0], "exit\n")) == 0)
		{
			exit(0);
		}
		else
		{
			printf("Yanlis bir komut girdiniz..!");
		}
	}
}

void inputword(char *input)
{
	char *str2 = (char *)malloc(sizeof(char) * MAX_LIMIT); // char str2[MAX_LIMIT]
	strcpy(str2, input);								   // string make cp
	char ayrac[] = " ";									   // splite
	char *ptr = strtok(str2, ayrac);					   // string ptr[]=split(" ");
	for (int i = 0; 1; i++)
	{
		if (ptr == NULL)
		{
			break;
		}
		str3[i] = ptr;
		ptr = strtok(NULL, ayrac);
	}
}

void mathods(int flg)
{
	int pid = fork(), id;
	if (pid == 0)
	{
		if (flg == 1)
		{
			id = execv("inserter", pozitif);
		}
		else if (flg == 2)
		{
			id = execv("calculate", calc);
		}
	}
	else
	{
		wait(&id);
	}
}
