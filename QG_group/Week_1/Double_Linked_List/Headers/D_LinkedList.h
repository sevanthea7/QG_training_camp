#ifndef D_LINKEDLIST
#define D_LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

// 定义返回状态 
#define OK 1
#define ERROR 0
typedef int Status;

// 定义元素类型
typedef int EType;

// 定义链表结构 
typedef struct _node {
	EType data;
	struct _node *prev, *next;
} DNode, *DLinkedList;

void PrintMenu();											// 功能菜单 
Status InitDList( DLinkedList *head );						// 双链表初始化
Status DestroyDList( DLinkedList *L );						// 双链表的销毁
void PrintDList( DLinkedList *L );							// 正序打印双链表
void PrintDList_reverse( DLinkedList *L );					// 逆序打印双链表
Status CreateList_Head( DLinkedList * L);					// 头插法创建 
Status CreateList_Tail( DLinkedList *L );					// 尾插法创建 
Status DeleteDList( DLinkedList *L, EType e );				// 删除节点
Status SearchDList( DLinkedList *L, EType e );				// 元素查找
DNode* SearchDListNode( DLinkedList *L, EType e );			// 元素结点查找 
Status InsertDList( DLinkedList *L, DNode *p, DNode *q );	// 元素的插入

#endif
