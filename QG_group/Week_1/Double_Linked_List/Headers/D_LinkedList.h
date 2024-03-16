#ifndef D_LINKEDLIST
#define D_LINKEDLIST

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
	struct _node *prev, *next;
} DNode, *DLinkedList;

void PrintMenu();											// ���ܲ˵� 
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

#endif
