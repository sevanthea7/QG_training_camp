#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/LinkQueue.h"

// 测试选择功能
int test_option( char s[30], int m ){
	int n, flag;
	do{
		flag = 1;
		n = atoi( s );
		if( n < 1 || n > m ){
        	flag = 0;
        	printf( "\n没有这个功能！请重新选择：" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
} 


// 测试输入数字
int test_number( char s[30] ){
	int n, flag;
	do{
		flag = 1;
		if( strcmp( s, "0" ) == 0 ){
			n = 0;
			break;
		}
		n = atoi( s );
		if( n == 0 ){
        	flag = 0;
        	printf( "\nNot a number! Reenter:" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
}

Status InitLQueue( pQueue *Q ){
	*Q = (pQueue)malloc(sizeof(Queue));						// 为队列的头结点分配内存空间
	pNode p = ( pNode )malloc( sizeof( Node ) );			// 初始化队列的头结点和尾结点
	(*Q) -> front = p;
	(*Q) -> back = p;
	(*Q) -> back -> next = NULL;
	return OK;
}


Status InLQueue( pQueue Q, EType e ){
	pNode p = ( pNode )malloc( sizeof( Node ) );
	p -> data = e;
	p -> next = NULL;
	Q -> back -> next = p;									// 将新节点插入到队列的尾部
	Q -> back = p;
	return OK;
}


Status OutLQueue( pQueue Q, EType *e ){
	if( Q -> front == Q -> back ){
		printf( "队列为空，没有可出队的元素！\n" );
		return ERROR; 
	}
	pNode p = Q -> front -> next;
	*e = p -> data;
	Q -> front -> next = p -> next;
	free( p );
	if( p == Q -> back ){									// 如果出队的是最后一个元素，则更新队尾指针
		Q -> back = Q -> front;
	} 
	return OK;
}


Status GetHeadElement( pQueue Q, EType *e ){
	if( Q -> front == Q -> back ){
		printf( "队列为空，没有可取的元素！\n" );
		return ERROR; 
	}
	pNode p = Q -> front -> next;
	*e = p -> data;
	return OK;
}


Status ClearLQueue( pQueue Q ){
	if( Q -> front == Q -> back ){
		printf( "队列为空，无需清空！\n" );
		return ERROR; 
	}
	pNode p = Q -> front -> next;
	while( p ){												// 释放队列中的所有节点
		Q -> front -> next = p -> next;
		free( p );
		p = Q -> front -> next;
	} 
    Q -> back = Q -> front;									// 更新队尾指针
    return OK;
	return OK;
}


Status DestroyLQueue( pQueue *Q ){
	if( (*Q) -> front != (*Q) -> back ){
		ClearLQueue( *Q );
	}
	free( (*Q) -> front );
	(*Q) -> front = NULL;
	(*Q) -> back = NULL;
	*Q = NULL;
	return OK;
}


Status IsEmpty( pQueue Q ){
	if( Q -> front == Q -> back ){
		return 0; 
	} else{
		return 1;
	}
}


int GetLength( pQueue Q ){
	int len;
	pNode p = Q -> front -> next;
	if( Q -> front != Q -> back ){
		while( p ){
			len ++;
			p = p -> next;
		}
	}
	return len;
}


Status PrintLQueue( pQueue Q ){
	if( Q -> front == Q -> back ){
		printf( "队列为空，没有可打印的元素！\n" );
		return ERROR; 
	}
	pNode p;
	printf( "\n" );
	for( p = Q -> front -> next; p; p = p -> next ){
		printf( " %d ->", p -> data );
	}
	printf( "\n\n" ); 
	return OK;
}

