#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义返回状态 
#define OK 1
#define ERROR 0
typedef int Status;

// 定义元素类型
typedef int EType;

// 定义链表结构 
typedef struct _node {
	EType data;
	struct _node *next;
} Node, *LinkedList;

void PrintMenu();										// 功能菜单 
Status InitList( LinkedList *head );					// 初始化单链表 
Status CreateList( LinkedList *L );						// 创建列表结点
Status DestroyList( LinkedList *L );					// 销毁单链表 
Status SearchList( LinkedList *L, EType e );			// 单链表的元素查找
Node* SearchListNode( LinkedList *L, EType e );			// 单链表的元素结点查找
Status InsertList( LinkedList *L, Node *p, Node *q );	// 单链表的元素插入
Status PrintList( LinkedList *L );						// 单链表元素打印
Status PrintList2( LinkedList *L );						// 打印递归逆转后的单链表 
Status DeleteList( LinkedList *L, EType e );			// 单链表元素删除 
Status ExchangeOddEven( LinkedList *L );				// 单链表奇偶位调换
Node* FindMid( LinkedList *L );							// 找单链表中点 
Status IsLoop( LinkedList *L );							// 判断链表是否成环 
Status ReverseList( LinkedList *L );					// 逆转单链表
Node* ReverseList_Recursive( LinkedList *head );		// 递归逆转单链表 
int test_number( char s[30] );							// 检验输入内容 
int test_number_list( char s[30], int i );				// 检验输入内容 

// 定义链表结构 
typedef struct _Dnode {
	EType data;
	struct _Dnode *prev, *next;
} DNode, *DLinkedList;

void PrintMenuD();											// 功能菜单 
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
int test_numberD( char s[30] );

#endif
