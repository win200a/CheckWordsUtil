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
void checkwords3(void);
void checkwords4(void);
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
		checkwords3();
	}
	else if (choice == 'd')
	{
		checkwords4();
	}
	else if (choice == 'e')
	{
		seewords();
	}
	getch();
	puts("bye bye");
	getch();
	return 0;
}
char menu(void)
{
	puts("Version 2.1");
	puts("Author:Frank_feng");
	puts("****************************************************************************");
	puts("a.英文对中文从头听写     b.英文对中文跳转听写");
	puts("c.中文对英文从头听写     d.中文对英文跳转听写");
	puts("e.单词查看               f.退出");
	puts("****************************************************************************");
	char input;
	fflush(stdin);
	while (scanf("%c", &input) != 1 || (input<'a' || input>'f'))
	{
		fflush(stdin);
		puts("Input a letter and the letter must be a,b,c,d,e or f.");
	}
	return input;
}
void checkwords1(void)
{
	system("cls");
	FILE*fp;
	char readwords[101];
	char inputwords[101];
	int count = 1;
	int printfcount = 1;
	int retrycount = 0;
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
				retrycount++;
				if (retrycount == 3)
				{
					retrycount = 0;
					fputs(readwords, stdout);
				}
				goto retry;
			}
		}
		count++;
	}
}
void checkwords2(void)
{
	system("cls");
	FILE*fp;
	char readwords[101];
	char inputwords[20];
	int count = 1;
	int printfcount = 1;
	int retrycount = 0;
	fp = fopen("words.txt", "r");
	int turn;
	scanf("%d", &turn);
	system("cls");
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
				retrycount++;
				if (retrycount == 3)
				{
					fputs(readwords, stdout);
					retrycount = 0;
				}
				goto retry;
			}
		}
		count++;
	}
	fclose(fp);

}
void checkwords3(void)
{
	system("cls");
	FILE*fp;
	char readwords[101];
	char inputwords[101];
	char firstwords[101];
	int count = 1;
	int printfcount = 1;
	int retrycount = 0;
	fp = fopen("words.txt", "r");
	while (fgets(readwords, 100, fp) != NULL)
	{
		if (count % 2 != 0)
		{
			strcpy(firstwords,readwords);
		}
		else if (count % 2 == 0)
		{
			printf("%d%c", printfcount, '.');
			fputs(readwords, stdout);
			printfcount++;
		retry:
			fflush(stdin);
			fgets(inputwords, 100, stdin);
			if (strcmp(inputwords, firstwords) == 0)
			{
				puts("correct");
				puts("");
			}
			else
			{
				puts("wrong");
				retrycount++;
				if (retrycount == 3)
				{
					retrycount = 0;
					fputs(firstwords, stdout);
				}
				goto retry;
			}
		}
		count++;
	}
}
void checkwords4(void)
{
	system("cls");
	FILE*fp;
	char readwords[101];
	char inputwords[101];
	char firstwords[101];
	int count = 1;
	int printfcount = 1;
	int retrycount = 0;
	fp = fopen("words.txt", "r");
	int turn;
	scanf("%d", &turn);
	system("cls");
	printfcount = turn;
	for (int i = 0; i < (turn * 2 - 2); i++)
	{
		fgets(readwords, 100, fp);
	}
	while (fgets(readwords, 100, fp) != NULL)
	{
		if (count % 2 != 0)
		{
			strcpy(firstwords, readwords);
		}
		else if (count % 2 == 0)
		{
			printf("%d%c", printfcount, '.');
			fputs(readwords, stdout);
			printfcount++;
		retry:
			fflush(stdin);
			fgets(inputwords, 100, stdin);
			if (strcmp(inputwords, firstwords) == 0)
			{
				puts("correct");
				puts("");
			}
			else
			{
				puts("wrong");
				retrycount++;
				if (retrycount == 3)
				{
					fputs(firstwords, stdout);
					retrycount = 0;
				}
				goto retry;
			}
		}
		count++;
	}
	fclose(fp);

}
void seewords(void)
{
	system("cls");
	FILE*fp;
	fp = fopen("words.txt", "r");
	char readwords[101];
	int count = 1;
	int empty;
	while (fgets(readwords, 100, fp) != NULL)
	{
		if (count % 2 != 0)
		{
			*(strchr(readwords, '\n')) = '\0';
			fputs(readwords, stdout);
			//分隔符数量
			if (strlen(readwords) <= 15)
			{
				empty = (15 - strlen(readwords));
			}
			else
			{
				empty = 15;
			}
			for (int i = 0; i < empty; i++)
			{
				fputs(" ", stdout);
			}
		}
		else if (count % 2 == 0)
		{
			fputs(readwords, stdout);
		}
		count++;
	}
}