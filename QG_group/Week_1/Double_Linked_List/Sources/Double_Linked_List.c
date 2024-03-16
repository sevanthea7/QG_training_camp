#include <stdio.h>
#include <stdlib.h>
#include "../Headers/D_LinkedList.h"


int main(){
	DLinkedList L, head;
	int n;
	InitDList( &L );
	printf("******************************\n");
    printf("*        1.create(head)      *\n");
	printf("*        2.create(tail)      *\n");
	printf("******************************\n");
	printf( "Please choose a way to create the list: ");
	scanf( "%d", &n );
	switch( n ){
		case 1:
			CreateList_Head( &L );
			break;
		case 2:
			CreateList_Tail( &L );
			break;
	}
	PrintMenu();
	scanf( "%d", &n );
	EType e;
	DNode *q;
	do{
		switch( n ){
			case 1:
				q = ( DLinkedList )malloc( sizeof( DNode ) );
				printf( "please enter the data of the new node: " );
				scanf( "%d", &( q -> data ) );
				printf( "please enter the data of node before the position you want to insert the new node: " );
				scanf( "%d", &e );
				DNode* p = SearchDListNode( &L, e );
				if (p != NULL) {
                    InsertDList(&L, p, q);
                    PrintDList(&L);
                } else {
                    printf("Node not found.\n");
                }
				break;
			case 2:
				printf( "please enter the data of the node you want to search: " );
				scanf( "%d", &e );
				SearchDList( &L, e );
				break;
			case 3:
				printf( "please enter the data of the node you want to delete: " );
				scanf( "%d", &e );
				DeleteDList( &L, e );
				PrintDList( &L );
				break;
			case 4:
				DestroyDList( &L );
				printf( "\nsuccess.\n\n" );
				break;
			case 5:
				PrintDList( &L );
				break;
			case 6:
				PrintDList_reverse( &L );
				break; 
			case 0:
				return 0;
		}
		PrintMenu();
		scanf( "%d", &n );
	} while(1);
} 


// 功能菜单 
void PrintMenu(){
    printf("******************************\n");
    printf("*          1.insert          *\n");
    printf("*          2.search          *\n");
    printf("*          3.delete          *\n");
    printf("*          4.destroy         *\n");
    printf("*          5.print           *\n");
    printf("*       6.print(reverse)     *\n");
    printf("******************************\n");
    printf("Enter 0 to exit.\n");
    printf("Enter the number of the function you want: ");
}


// 双链表初始化
Status InitDList( DLinkedList *head ){
    *head = ( DLinkedList )malloc( sizeof( DNode ) );
	( *head ) -> next = NULL;
	( *head ) -> prev = NULL;
	return OK;
}


// 双链表的销毁
Status DestroyDList( DLinkedList *L ){
	if( *L == NULL ){
		return ERROR;
	}
	DLinkedList p = *L;
	while( p ){
		*L = ( *L ) -> next;
		free( p );
		p = *L;
	}
	return OK;
}


// 正序打印双链表
void PrintDList( DLinkedList *L ){
    DLinkedList prt;
    printf("\n\n");
    for( prt = ( *L ) -> next; prt; prt = prt -> next ){
    	printf( "%d <-> ", prt -> data );
	}
    printf("\n\n\n");
}


// 逆序打印双链表
void PrintDList_reverse( DLinkedList *L ){
    DLinkedList tail = *L;
    while( tail -> next != NULL ){
        tail = tail -> next;
    }
    printf("\n\n");
    while( tail != *L ){
        printf( "%d <-> ", tail -> data );
        tail = tail -> prev;
    }
    printf("\n\n\n");
}


// 头插法创建 
Status CreateList_Head( DLinkedList * L){
    DLinkedList p, q;
    *L = ( DLinkedList )malloc( sizeof( DNode ) );
    p = *L;				// 指针p始终指向头结点 
    p -> next = NULL; 
    EType e;
    int i = 1;
    while(1){
        q = ( DLinkedList )malloc( sizeof( DNode ) );
        printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%d", &( q -> data ) );
		if( q -> data == -1 ){
			free( q );			// 释放不需要的节点内存
			break;
		}
        q -> next = p -> next; // 将新节点插到链表头部
        if( p -> next != NULL ){
            p -> next -> prev = q; // 原头节点的下一个节点的前一个节点指向新节点
        }
        q -> prev = p; // 新节点的前一个节点指向头节点
        p -> next = q; // 头节点的下一个节点指向新节点
        i ++;
	}
	return OK;
}


// 尾插法创建 
Status CreateList_Tail( DLinkedList *L ){
	DLinkedList p, q;
	*L = ( DLinkedList )malloc( sizeof( DNode ) );
	p = *L;
	p -> next = NULL;
	p -> prev = NULL;
	int i = 1;
	while(1){
		q = ( DLinkedList )malloc( sizeof( DNode ) );
		printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%d", &( q -> data ) );
		if( q -> data == -1 ){
			free( q );			// 释放不需要的节点内存
			break;
		}
		q -> next = NULL;
		p -> next = q;			// 将新节点连接到链表末尾
		q -> prev = p;			// 更新新节点的前驱指针
		p = p -> next;			// 移动到下一个节点
		i ++; 
	}
	return OK;
} 


// 删除节点
Status DeleteDList( DLinkedList *L, EType e ){
	if( *L == NULL ){
		return ERROR;
	} 
	DLinkedList p, q;
	p = *L;
	q = ( *L ) -> next;
	while( q ){							// 遍历链表查找要删除的节点
		if( q -> data == e ){
			p -> next = q -> next;		// 将要删除的节点从链表中去除 
			if( p -> next != NULL ){
				q -> next -> prev = p;	// 更新下一个节点的前驱指针		
			}
			free( q );					// 释放删除节点的内存
			return OK;
		}
		p = q;
		q = q -> next;
	}
	return ERROR;						// 没找到 
} 


// 元素查找
Status SearchDList( DLinkedList *L, EType e ){
	DLinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			printf( "\nelement found: data=%d\n\n", p -> data );
			return OK;
		}
	}
	printf( "Not found.\n" );
	return ERROR;
} 


// 元素结点查找 
DNode* SearchDListNode( DLinkedList *L, EType e ){
	DLinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			return p;
		}
	}
	printf( "Not found.\n" );
	return NULL;
}

// 元素的插入
Status InsertDList( DLinkedList *L, DNode *p, DNode *q ){
	if( *L == NULL || q == NULL || p == NULL ){	// 检查链表是否为空、指针是否为空 
		return ERROR;
	}
	DLinkedList m = *L; 		// m指向头结点 
	while( m != NULL ){
		if( m == p ){		// 找到要插入位置 
			q -> next = m -> next;	// 将q的next指针指向p的下一个结点
			m -> next = q;	// 将p的next指针指向q
			q -> prev = m;
            if (q -> next != NULL) {
                q -> next -> prev = q;
            }
			return OK;
		}
		m = m -> next;		// m指向下一个节点 
	}
	return ERROR;
}




