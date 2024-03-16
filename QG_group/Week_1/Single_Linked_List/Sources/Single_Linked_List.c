#include <stdio.h>
#include <stdlib.h>
#include "../Headers/S_LinkedList.h"


int main(){
	LinkedList L;
	InitList( &L );
	CreateList( &L );
	PrintList( &L );
	PrintMenu();
	int n;
	scanf( "%d", &n );
	EType e;
	Node *q, *mid;
	do{
		switch( n ){
			case 1:
				q = ( LinkedList )malloc( sizeof( Node ) );
				printf( "please enter the data of the new node: " );
				scanf( "%d", &( q -> data ) );
				printf( "please enter the data of node before the position you want to insert the new node: " );
				scanf( "%d", &e );
				Node* p = SearchListNode( &L, e );
				InsertList( &L, p, q );
				PrintList( &L );
				break;
			case 2:
				printf( "please enter the data of the node you want to search: " );
				scanf( "%d", &e );
				SearchList( &L, e );
				break;
			case 3:
				printf( "please enter the data of the node you want to delete: " );
				scanf( "%d", &e );
				DeleteList( &L, e );
				PrintList( &L );
				break;
			case 4:
				DestroyList( &L );
				printf( "\nsuccess.\n\n" );
				break;
			case 5:
				PrintList( &L );
				break; 
			case 6:
				ExchangeOddEven( &L );
				PrintList( &L ); 
				break;
			case 7:
				mid = FindMid( &L );
				printf( "\nthe data of the middle node is %d\n", mid -> data );
				printf( "*If the list's length is even, then the result will be the previous one of the center.\n\n");
				break;
			case 8:
				IsLoop( &L );
				break; 
			case 9:
				ReverseList( &L );
				PrintList( &L ); 
				break;
			case 10:
				L = ReverseList_Recursive( &L );
				PrintList2( &L ); 
				break;
			case 0:
				return 0;
		}
		PrintMenu();
		scanf( "%d", &n );
	} while(1);
} 

// 功能菜单 
void PrintMenu() {
    printf("******************************\n");
    printf("*          1.insert          *\n");
    printf("*          2.search          *\n");
    printf("*          3.delete          *\n");
    printf("*          4.destroy         *\n");
    printf("*          5.print           *\n");
    printf("*     6.exchange odd&even    *\n");
    printf("*     7.find middle node     *\n");
    printf("*      8.is loop or not      *\n");
    printf("*       9.reverse list       *\n");
    printf("*  10.reverse list recursive *\n");
    printf("******************************\n");
    printf("Enter 0 to exit.\n");
    printf("Enter the number of the function you want: ");
}

// 初始化单链表 
Status InitList( LinkedList *head ){
	*head = ( LinkedList )malloc( sizeof( Node ) );		// 生成头节点，为其分配内存 
	( *head ) -> next = NULL; 
	return OK;
}

// 创建列表结点
Status CreateList( LinkedList *L ){
	*L = ( LinkedList )malloc( sizeof( Node ) );	// 为头结点分配内存 
	LinkedList p, q;
	p = *L;											// p指向头结点
	p -> next = NULL;
	int i = 1;
	while(1){
		q = ( Node* )malloc( sizeof( Node ));		// 为新节点分配内存空间
		printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%d", &q -> data );
		if( q -> data == -1 ){						// 如果输入 -1，则结束输入并释放新节点的内存空间
			free( q );
			break;
		}
		q -> next = NULL;							// 新节点的下一个结点为空
		p -> next = q;								// 将新节点连接到链表中
		p = p -> next;								// 移动p指针到下一个节点
		i ++;
	}
	p -> next = NULL;								// 将最后一个节点的next指针设为空
	return OK;
} 

// 销毁单链表 
Status DestroyList( LinkedList *L ){
	if( *L == NULL ){
		return ERROR;
	}
	LinkedList p = *L;		// p指针指向头节点
	while( *L ){
		*L = ( *L ) -> next;	// 指向要释放元素的指针L指向要删除的下一个 
		free( p );			// 释放L原来在的位置的内存 
		p = *L;				// 指针p指向第一步找到的下一个要删除的结点 
	}
	return OK; 
} 

// 单链表的元素查找
Status SearchList( LinkedList *L, EType e ){
	LinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			printf( "\nelement found: data=%d\n\n", p -> data );
			return OK;
		}
		p = p -> next;
	}
	printf( "Not found.\n" );
	return ERROR;
} 

// 单链表的元素结点查找 
Node* SearchListNode( LinkedList *L, EType e ){
	LinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			return p;
		}
	}
	printf( "Not found.\n" );
	return NULL;
}

// 单链表的元素插入
Status InsertList( LinkedList *L, Node *p, Node *q ){
	if( *L == NULL || q == NULL || p == NULL ){	// 检查链表是否为空、指针是否为空 
		return ERROR;
	}
	LinkedList m = *L; 		// m指向头结点 
	while( m != NULL ){
		if( m == p ){		// 找到要插入位置 
			q -> next = m -> next;	// 将q的next指针指向p的下一个结点
			m -> next = q;	// 将p的next指针指向q
			return OK;
		}
		m = m -> next;		// m指向下一个节点 
	}
	return ERROR;
}


// 单链表元素打印
Status PrintList( LinkedList *L ){
	LinkedList prt;
	if ( *L == NULL ) { 		// 检查链表是否为空
        return ERROR;
    }
    printf( "\n\n" );
	for( prt = ( *L ) -> next; prt; prt = prt -> next ){
		printf( "%d -> ", prt -> data );		// 遍历打印链表内容 
	}
	printf( "\n\n\n" );
	return OK;
} 

Status PrintList2( LinkedList *L ){
	LinkedList prt;
	if ( *L == NULL ) { 		// 检查链表是否为空
        return ERROR;
    }
    printf( "\n\n" );
	for( prt = *L ; prt -> next; prt = prt -> next ){
		printf( "%d -> ", prt -> data );		// 遍历打印链表内容 
	}
	printf( "\n\n\n" );
	return OK;
} 

// 单链表元素删除 
Status DeleteList( LinkedList *L, EType e ){
	LinkedList p, q;
	p = *L;								// p指向头结点
	q = ( *L ) -> next;					// q指向第一个节点
	if( !p ){
		return ERROR;
	}
	while( q ){
		if( q -> data == e ){
			p -> next = q -> next;		// 将p的next指针指向q的下一个节点
			free( q );					// 释放q所指向节点的内存
			return OK;
		}
		p = q;							// 移动p和q指针到各自的下一个节点
		q = q -> next;
	}
	return ERROR;						// 没找到要删除的 
}


// 单链表奇偶位调换
Status ExchangeOddEven( LinkedList *L ){
	if( *L == NULL ){
		return ERROR;
	}
	LinkedList p = ( *L ) -> next;
	while( p && p -> next ){
		EType tmp = p -> data;				// 交换相邻节点数据
		p -> data = p -> next -> data;
		p -> next -> data = tmp;
		p = p -> next -> next;				// p指针移到下一个奇数位
	}
	return OK;
} 

// 找中间位置
Node* FindMid( LinkedList *L ){
	if( *L == NULL || ( *L ) -> next == NULL ){
		return *L;
	}
	LinkedList slow, fast;
	slow = *L;
	fast = *L;
	while( fast && fast -> next ){
		slow = slow -> next;
		fast = fast -> next -> next;
	} 
	return slow;
}

// 判断是否成环 
Status IsLoop( LinkedList *L ){
	if( *L == NULL || ( *L ) -> next == NULL ){
		return ERROR;
	}
	LinkedList slow, fast;
	slow = *L;
	fast = ( *L ) -> next;
	while( fast && fast -> next ){	
		if( fast == slow ){	
			printf( "\nIS LOOP.\n\n" );
			break;
		}
		slow = slow -> next;
		fast = fast -> next -> next; 
	}
	printf( "\nNOT LOOP.\n\n");
	return OK;
}

// 逆转单链表
Status ReverseList( LinkedList *L ){
	if( *L == NULL ){
		return ERROR; 
	} 
	LinkedList head, p, q;
	head = *L;
	p = head -> next;
	head -> next = NULL; 
	while( p ){
		q = p -> next;
		p -> next = head -> next;
		head -> next = p;
		p = q;
	}
	return OK; 
} 


// 递归逆转单链表
Node* ReverseList_Recursive( LinkedList *head ){
	if( *head == NULL || ( *head ) -> next == NULL ){
		return *head;							 		// 递的终止条件，链表为空或只有一个元素时返回 
	}
	Node* reverse_head = ReverseList_Recursive( &( ( *head ) -> next ) );
	( *head ) -> next -> next = *head;						// 头指针的下一个元素的next指针指回头指针，实现两个元素之间的顺序交换 
	( *head ) -> next = NULL;								// 头指针的next置空，作为新的链表尾
	return reverse_head; 
} 
