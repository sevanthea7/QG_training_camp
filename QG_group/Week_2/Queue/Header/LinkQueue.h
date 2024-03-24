#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ¶¨Òå·µ»Ø×´Ì¬ 
#define OK 1
#define ERROR 0
typedef int Status;

typedef int EType;

typedef struct _node{
	int data;
	struct _node *next;
}Node, *pNode;


typedef struct LinkQueue{
	pNode front;
	pNode back;
}Queue, *pQueue;


Status InitLQueue( pQueue *Q );
Status ClearLQueue( pQueue Q );
Status DestoryLQueue( pQueue *Q );
Status IsEmptyLQueue( pQueue Q );
Status InLQueue( pQueue Q, EType e );
Status OutLQueue( pQueue Q, EType *e );
Status GetHeadElement( pQueue Q, EType *e );
int GetLength( pQueue Q );
Status PrintLQueue( pQueue Q );
int test_option( char s[30], int m );
int test_number( char s[30] );



#endif 
