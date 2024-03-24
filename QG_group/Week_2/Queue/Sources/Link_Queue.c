#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/LinkQueue.h"

// ����ѡ����
int test_option( char s[30], int m ){
	int n, flag;
	do{
		flag = 1;
		n = atoi( s );
		if( n < 1 || n > m ){
        	flag = 0;
        	printf( "\nû��������ܣ�������ѡ��" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
} 


// ������������
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
	*Q = (pQueue)malloc(sizeof(Queue));						// Ϊ���е�ͷ�������ڴ�ռ�
	pNode p = ( pNode )malloc( sizeof( Node ) );			// ��ʼ�����е�ͷ����β���
	(*Q) -> front = p;
	(*Q) -> back = p;
	(*Q) -> back -> next = NULL;
	return OK;
}


Status InLQueue( pQueue Q, EType e ){
	pNode p = ( pNode )malloc( sizeof( Node ) );
	p -> data = e;
	p -> next = NULL;
	Q -> back -> next = p;									// ���½ڵ���뵽���е�β��
	Q -> back = p;
	return OK;
}


Status OutLQueue( pQueue Q, EType *e ){
	if( Q -> front == Q -> back ){
		printf( "����Ϊ�գ�û�пɳ��ӵ�Ԫ�أ�\n" );
		return ERROR; 
	}
	pNode p = Q -> front -> next;
	*e = p -> data;
	Q -> front -> next = p -> next;
	free( p );
	if( p == Q -> back ){									// ������ӵ������һ��Ԫ�أ�����¶�βָ��
		Q -> back = Q -> front;
	} 
	return OK;
}


Status GetHeadElement( pQueue Q, EType *e ){
	if( Q -> front == Q -> back ){
		printf( "����Ϊ�գ�û�п�ȡ��Ԫ�أ�\n" );
		return ERROR; 
	}
	pNode p = Q -> front -> next;
	*e = p -> data;
	return OK;
}


Status ClearLQueue( pQueue Q ){
	if( Q -> front == Q -> back ){
		printf( "����Ϊ�գ�������գ�\n" );
		return ERROR; 
	}
	pNode p = Q -> front -> next;
	while( p ){												// �ͷŶ����е����нڵ�
		Q -> front -> next = p -> next;
		free( p );
		p = Q -> front -> next;
	} 
    Q -> back = Q -> front;									// ���¶�βָ��
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
		printf( "����Ϊ�գ�û�пɴ�ӡ��Ԫ�أ�\n" );
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

