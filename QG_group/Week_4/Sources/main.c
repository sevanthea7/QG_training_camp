#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/binary_sort_tree.h"
#include "./binary_sort_tree.c"

int main(){
	char s[256]; 
	int i, n, k, len = 1, r; 
	pTSort T = (pTSort)malloc(sizeof(TSort));;
	pTNode tmp = NULL;
	BST_init( T );
	printf( "初始化成功！现在树为空，请先插入元素。\n" ); 
	again:
	while( 1 ){
		printf("********************************\n");
		printf("*       请选择需要的功能       *\n");
		printf("********************************\n");
		printf("*          1.插入元素          *\n");
		printf("*          2.删除元素          *\n");
		printf("*          3.查找元素          *\n");
		printf("*        4.先序遍历-递归       *\n");
		printf("*       5.先序遍历-非递归      *\n");
		printf("*        6.中序遍历-递归       *\n");
		printf("*       7.中序遍历-非递归      *\n");
		printf("*        8.后序遍历-递归       *\n");
		printf("*       9.后序遍历-递非归      *\n");
		printf("*          10.层序遍历         *\n");
		printf("********************************\n");
		printf("请输入需要的功能( 输入x退出程序 )：");
		scanf( "%s", s );
		if( strcmp( s, "x"  ) == 0 ){
			break;
		} 
		k = test_option( s, 10 ); 
		switch( k ){
			case 1:
				while( 1 ){
					printf( "请输入第%d个整型元素( 输入x停止输入 )：", len );
					scanf( "%s", s );
					if( strcmp( s, "x" ) == 0 ){
						break;
					}
					n = test_number( s );
					if( BST_insert( T, n ) ){
						printf( "插入成功！\n" );
					}
					len ++;
				}
				break;
			case 2:
				if( T -> root == NULL ){
					printf( "树为空，无可删除的元素！\n" );
					goto again;
				}
				printf( "请输入要删除的元素：" );
				scanf( "%s", s );
				n = test_number( s );
				T -> root = BST_delete( T -> root, n );
				break;
			case 3:
				if( T -> root == NULL ){
					printf( "树为空，无可查找的元素！\n" );
					goto again;
				}
				printf( "请输入要查找的元素：" );
				scanf( "%s", s );
				n = test_number( s );
				r = BST_search( T, n );
				if( r ){
					printf( "\n查找成功！该元素存在于树中。\n\n" );
				} else{
					printf( "\n没有找到该元素。\n\n" );
				}
				break;
			case 4:
				if( T -> root == NULL ){
					printf( "树为空，无可排序的元素！\n" );
					goto again;
				}
				BST_preorderI( T -> root ); 
				printf( "\n遍历完成！\n\n" );
				break;
			case 5:
				if( T -> root == NULL ){
					printf( "树为空，无可排序的元素！\n" );
					goto again;
				}
				BST_preorderR( T );
				printf( "\n遍历完成！\n\n" );
				break;
			case 6:
				if( T -> root == NULL ){
					printf( "树为空，无可排序的元素！\n" );
					goto again;
				}
				BST_inorderI( T -> root );
				printf( "\n遍历完成！\n\n" );
				break;
			case 7:
				if( T -> root == NULL ){
					printf( "树为空，无可排序的元素！\n" );
					goto again;
				}
				BST_inorderR( T );
				printf( "\n遍历完成！\n\n" );
				break;
			case 8:
				if( T -> root == NULL ){
					printf( "树为空，无可排序的元素！\n" );
					goto again;
				}
				BST_postorderI( T -> root );
				printf( "\n遍历完成！\n\n" );
				break;
			case 9:
				if( T -> root == NULL ){
					printf( "树为空，无可排序的元素！\n" );
					goto again;
				}
				BST_postorderR( T );
				printf( "\n遍历完成！\n\n" );
				break;
			case 10:
				if( T -> root == NULL ){
					printf( "树为空，无可排序的元素！\n" );
					goto again;
				}
				BST_levelOrder( T );
				printf( "\n遍历完成！\n\n" );
				break;
		}
		printf( "\n\n" );
	}
}
