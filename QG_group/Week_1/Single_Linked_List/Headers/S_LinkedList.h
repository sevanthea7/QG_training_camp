#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

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

#endif
