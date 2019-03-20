/*
 * text1.c
 *
 *  Created on: 2018年9月28日
 *      Author: Administrator
 */
#define val "12312"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

int add(int, int);
int mul(int, int);

/*int f(int n){
	if(n > 1){
		return n * f(n - 1);
	}else{
		return n;
	}
}*/

/*void a(int i, ...){
	va_list args;
	int m;
	va_start(args, i);
	m = va_arg(args, int);
	printf("%d", m);
	char *s;
	s = va_arg(args, char *);
	//printf("%c", va_arg(args, int));
	printf("%c", *s);
	va_end(args);
}*/

int test(){
	/*int i = 22;
	int *c = &i;
	printf("%d\n", *c);
	int n=123456789;
	char str[20];
	sprintf(str, "%d", n);
	printf("%s\n",str);*/
	/*printf("%s\n", argv[0]);

	time_t t;
	struct tm *tm;
	time(&t);
	tm = localtime(&t);
	printf("%d年%d月%d日%d时%d分%d秒\n",
			tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
			tm->tm_hour, tm->tm_min, tm->tm_sec);*/

	/*char s = 'b';
	exit(1);
	abort();
	a(1,3,&s);*/

	/*int (*p[2])(int, int);
	p[0] = add;
	p[1] = mul;
	printf("%d\n", p[0](2,3));
	printf("%p\n", p[0]);
	printf("%p\n", add);

	auto (*p_)(char *);
	p_ = strlen;
	char c[20] = {0};
	c[0] = 's';
	c[1] = 's';
	printf("%d\n", p_(c));
	printf("%p\n", strlen);*/

	/*char c[20] = {0};
	char * c_ = c;
	while(1)
	{
		*c_ = getchar();
		if('\n' != *c_)
		{
			c_++;
		}else
		{
			break;
		}
	}
	c_ = c;
	int i;
	while(1)
	{
		if('\n' != *c_){
			if(*c_ >= 48 && *c_ <=57)
			{
				i = i * 10 + (*c_ - 48);
			}
			c_++;
		}
		else
		{
			break;
		}
	}
	printf("%d,%d", i, strlen(c));*/


	//int (*p)[5] = (int (*)[5])malloc(25 * sizeof(int));
	int (*p)[5] = (int (*)[5])calloc(25 , sizeof(int));
	int *p_ = (int *)p;
	p[0][0] = 24;
	p[0][1] = 25;
	(*(p + 1))[2] = 26;
	*((p + 1)[2] + 2)= 29;
	(p[0] + 1)[5] = 27;
	p[0][5] = 22;
	*(*p+3) = 5;
	//memset(p, 10, 4);

	p = (int *)p_;
	printf("%p\n", &p[1][1]);
	printf("%p\n", (*(p + 1)) + 1);
	printf("%d\n", *(*(p + 1) + 2));
	printf("%d\n", (*(p + 1))[2]);
	printf("%d,%d,%d,%d,%d\n", p[0][0], p[0][1], p[0][2], p[0][3], p[0][4]);
	printf("%d,%d,%d,%d,%d\n", p[1][0], p[1][1], p[1][2], p[1][3], p[1][4]);
	printf("%d,%d,%d,%d,%d\n", p[2][0], p[2][1], p[2][2], p[2][3], p[2][4]);
	printf("%d,%d,%d,%d,%d\n", p[3][0], p[3][1], p[3][2], p[3][3], p[3][4]);
	printf("%d,%d,%d,%d,%d\n", p[4][0], p[4][1], p[4][2], p[4][3], p[4][4]);
	printf("%p,%p\n", p, p_);
	if(NULL != p_){
		free(p_);
	}
	printf("%d\n", *p_);

	//printf("%d", *((int *)((long int)p + 4)));
	/*int a[2][3] = {10,20,30,40,50,60};
	int (*p)[3] = a;
	printf("%p\n", a);
	printf("%p\n", p);
	//printf("%p\n", ++p);
	printf("%p\n", p[0]);
	printf("%p\n", a[0]);
	printf("%d\n", p[0][0]);
	printf("%p\n", p[1]);
	printf("%p\n", a[1]);

	int *p1[3];
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	p1[0] = a[0];
	p1[1] = &i2;
	p1[2] = &i3;
	printf("%d\n", *((int *)((long int)p1[0] + 8)));*/


	/*int *pj;
	int i[] = {1,2,3,4,5};
	printf("%p\n", i);
	pj = i;
	printf("%d\n", *++pj);
	pj = (int *)((long int)pj + sizeof(int));
	printf("%d\n", *pj);*/

	/*if(isalnum('!')){
		printf("sss");
	}
	char c = 'a';
	if(islower(c)){
		printf("%c", toupper(c));
	}
	char c1 = '\n';
	if(isblank(c1)){
			printf("标准空白字符");
		}
	if(isspace(c1)){
				printf("空白字符");
			}*/

	/*char s1[] = "www.";
	char s2[] = "bing.com";
	strncat(s1, s2, 3);
	printf("%s\n", s1);
	printf("%c\n", s1[8]);
	printf("%d\n", sizeof(s1) / sizeof(s1[0]));

	printf("%s\n", strstr("2131adasda", "ad"));
	printf("%s\n", strchr("2131adasda", 'a'));
	printf("%s\n", strrchr("2131adasda", 'a'));
	printf("%d\n", strspn("2131adasda", "21"));
	printf("%d\n", strcspn("2131adasda", "21"));
	printf("%s\n", strpbrk("2131adasda", "as"));
	printf("%s\n", strtok(s2, "."));
	printf("%s\n", strtok(NULL, "."));*/

	/*int * a;
	int s[2][3][4] = {1,2,3,4,5,6};
	printf("%x\n", s[0][0]);
	printf("%x\n", s[0][1]);
	printf("%d\n", sizeof(int *) * 8);
	printf("%p\n", s);
	printf("%d\n", sizeof(s) / sizeof(s[0][0][0]));

	char ss[5] = "1234";
	ss[3] = '\0';
	printf("%s\n", ss);
	printf("%d\n", sizeof(ss) / sizeof(ss[0]));*/
}

int add(int a, int b){
	return a + b;
}

int mul(int a, int b){
	return a * b;
}
