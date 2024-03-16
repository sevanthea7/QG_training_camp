#ifndef LINKEDLIST
#define LINKEDLIST

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

#endif
