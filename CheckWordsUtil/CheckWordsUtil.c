/*
Copyright (C) 2014 Frank_feng, Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
void checkwords1(void);
void checkwords2(void);
void seewords(void);
char menu(void);
int main(void)
{
	char choice=menu();
	if (choice =='a')
	{
		checkwords1();
	}
	else if (choice == 'b')
	{
		checkwords2();
	}
	else if (choice == 'c')
	{
		seewords();
	}
	puts("bye bye");
	getch();
	return 0;
}
char menu(void)
{
	puts("Version 1.0");
	puts("Author:Frank_feng");
	puts("****************************************************************************");
	puts("a.从头听写     b.跳转听写");
	puts("c.单词查看     e.退出");
	puts("****************************************************************************");
	char input;
	fflush(stdin);
	while (scanf("%c", &input) != 1 || ((input<'a' || input>'c') && input != 'e'))
	{
		fflush(stdin);
		puts("Input a letter and the letter must be a,b,c or e.");
	}
	return input;
}
void checkwords1(void)
{
	FILE*fp;
	char readwords[101];
	char inputwords[20];
	int count = 1;
	int printfcount = 1;
	fp = fopen("words.txt", "r");
	while (fgets(readwords, 100, fp) != NULL)
	{
		if (count % 2 != 0)
		{
			printf("%d%c", printfcount, '.');
			fputs(readwords, stdout);
			printfcount++;
		}
		else if (count % 2 == 0)
		{
		retry:
			fflush(stdin);
			fgets(inputwords, 20, stdin);
			if (strcmp(inputwords, readwords) == 0)
			{
				puts("correct");
				puts("");
			}
			else
			{
				puts("wrong");
				goto retry;
			}
		}
		count++;
	}
	getch();
}
void checkwords2(void)
{
	FILE*fp;
	char readwords[101];
	char inputwords[20];
	int count = 1;
	int printfcount = 1;
	fp = fopen("words.txt", "r");
	int turn;
	scanf("%d", &turn);
	printfcount = turn;
	for (int i = 0; i < (turn*2-2); i++)
	{
		fgets(readwords, 100, fp);
	}
	while (fgets(readwords, 100, fp) != NULL)
	{
		if (count % 2 != 0)
		{
			printf("%d%c", printfcount, '.');
			fputs(readwords, stdout);
			printfcount++;
		}
		else if (count % 2 == 0)
		{
		retry:
			fflush(stdin);
			fgets(inputwords, 20, stdin);
			if (strcmp(inputwords, readwords) == 0)
			{
				puts("correct");
				puts("");
			}
			else
			{
				puts("wrong");
				goto retry;
			}
		}
		count++;
	}
	getch();

}
void seewords(void)
{
	FILE*fp;
	fp = fopen("words.txt", "r");
	char readwords[31];
	int count = 1;
	while (fgets(readwords, 100, fp) != NULL)
	{
		if (count % 2 != 0)
		{
			*(strchr(readwords, '\n')) = '\0';
			fputs(readwords, stdout);
			fputs("  ", stdout);
		}
		else if (count % 2 == 0)
		{
			fputs(readwords, stdout);
		}
		count++;
	}
}