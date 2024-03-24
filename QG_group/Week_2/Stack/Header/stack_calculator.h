#ifndef STACK_CALC
#define STACK_CALC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义返回状态 
#define OK 1
#define ERROR 0
#define WRONG -1 
typedef int Status;

// 定义元素类型
typedef int EType;

typedef struct _node{
	EType data;
	struct _node *next;
}Node, *LinkStack;


typedef struct _stack{
	LinkStack top;
	int cnt;
}*Stack, Stackptr;



int test_option( char s[30], int m );
int test_number( char s[30] );
Status InitLStack( Stack *S );
Status EmptyLStack( Stack S );
Status PushLStack( Stack S, EType e );
Status PopLStack( Stack S, EType *e );
Status GetTopElement( Stack S, EType *e );
int GetLength( Stack S );
Status ClearStack( Stack S );
Status DestroyStack( Stack *S );
Status PrintStack( Stack S );


Status transform( char f[256], char postf[512] );
int is_number( char x );
int is_operator( char x );
int priority( char x );
/*
Status InitOStack( OStack *S );
Status PushOStack( OStack S, OType e );
Status EmptyOStack( OStack S );
Status PopOStack( OStack S, OType *e );
Status GetTopElementO( OStack S, OType *e );
*/
Status calculate( Stack T, char pf[512] );
int operate_cal( int left, int right, char opr );

#endif
