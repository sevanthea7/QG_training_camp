#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���巵��״̬ 
#define OK 1
#define ERROR 0
typedef int Status;

// ����Ԫ������
typedef int EType;

// ��������ṹ 
typedef struct _node {
	EType data;
	struct _node *next;
} Node, *LinkedList;

void PrintMenu();										// ���ܲ˵� 
Status InitList( LinkedList *head );					// ��ʼ�������� 
Status CreateList( LinkedList *L );						// �����б���
Status DestroyList( LinkedList *L );					// ���ٵ����� 
Status SearchList( LinkedList *L, EType e );			// �������Ԫ�ز���
Node* SearchListNode( LinkedList *L, EType e );			// �������Ԫ�ؽ�����
Status InsertList( LinkedList *L, Node *p, Node *q );	// �������Ԫ�ز���
Status PrintList( LinkedList *L );						// ������Ԫ�ش�ӡ
Status PrintList2( LinkedList *L );						// ��ӡ�ݹ���ת��ĵ����� 
Status DeleteList( LinkedList *L, EType e );			// ������Ԫ��ɾ�� 
Status ExchangeOddEven( LinkedList *L );				// ��������żλ����
Node* FindMid( LinkedList *L );							// �ҵ������е� 
Status IsLoop( LinkedList *L );							// �ж������Ƿ�ɻ� 
Status ReverseList( LinkedList *L );					// ��ת������
Node* ReverseList_Recursive( LinkedList *head );		// �ݹ���ת������ 
int test_number( char s[30] );							// ������������ 
int test_number_list( char s[30], int i );				// ������������ 

// ��������ṹ 
typedef struct _Dnode {
	EType data;
	struct _Dnode *prev, *next;
} DNode, *DLinkedList;

void PrintMenuD();											// ���ܲ˵� 
Status InitDList( DLinkedList *head );						// ˫�����ʼ��
Status DestroyDList( DLinkedList *L );						// ˫���������
void PrintDList( DLinkedList *L );							// �����ӡ˫����
void PrintDList_reverse( DLinkedList *L );					// �����ӡ˫����
Status CreateList_Head( DLinkedList * L);					// ͷ�巨���� 
Status CreateList_Tail( DLinkedList *L );					// β�巨���� 
Status DeleteDList( DLinkedList *L, EType e );				// ɾ���ڵ�
Status SearchDList( DLinkedList *L, EType e );				// Ԫ�ز���
DNode* SearchDListNode( DLinkedList *L, EType e );			// Ԫ�ؽ����� 
Status InsertDList( DLinkedList *L, DNode *p, DNode *q );	// Ԫ�صĲ���
int test_numberD( char s[30] );

#endif
