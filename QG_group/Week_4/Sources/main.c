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
	printf( "��ʼ���ɹ���������Ϊ�գ����Ȳ���Ԫ�ء�\n" ); 
	again:
	while( 1 ){
		printf("********************************\n");
		printf("*       ��ѡ����Ҫ�Ĺ���       *\n");
		printf("********************************\n");
		printf("*          1.����Ԫ��          *\n");
		printf("*          2.ɾ��Ԫ��          *\n");
		printf("*          3.����Ԫ��          *\n");
		printf("*        4.�������-�ݹ�       *\n");
		printf("*       5.�������-�ǵݹ�      *\n");
		printf("*        6.�������-�ݹ�       *\n");
		printf("*       7.�������-�ǵݹ�      *\n");
		printf("*        8.�������-�ݹ�       *\n");
		printf("*       9.�������-�ݷǹ�      *\n");
		printf("*          10.�������         *\n");
		printf("********************************\n");
		printf("��������Ҫ�Ĺ���( ����x�˳����� )��");
		scanf( "%s", s );
		if( strcmp( s, "x"  ) == 0 ){
			break;
		} 
		k = test_option( s, 10 ); 
		switch( k ){
			case 1:
				while( 1 ){
					printf( "�������%d������Ԫ��( ����xֹͣ���� )��", len );
					scanf( "%s", s );
					if( strcmp( s, "x" ) == 0 ){
						break;
					}
					n = test_number( s );
					if( BST_insert( T, n ) ){
						printf( "����ɹ���\n" );
					}
					len ++;
				}
				break;
			case 2:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿�ɾ����Ԫ�أ�\n" );
					goto again;
				}
				printf( "������Ҫɾ����Ԫ�أ�" );
				scanf( "%s", s );
				n = test_number( s );
				T -> root = BST_delete( T -> root, n );
				break;
			case 3:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿ɲ��ҵ�Ԫ�أ�\n" );
					goto again;
				}
				printf( "������Ҫ���ҵ�Ԫ�أ�" );
				scanf( "%s", s );
				n = test_number( s );
				r = BST_search( T, n );
				if( r ){
					printf( "\n���ҳɹ�����Ԫ�ش��������С�\n\n" );
				} else{
					printf( "\nû���ҵ���Ԫ�ء�\n\n" );
				}
				break;
			case 4:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿������Ԫ�أ�\n" );
					goto again;
				}
				BST_preorderI( T -> root ); 
				printf( "\n������ɣ�\n\n" );
				break;
			case 5:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿������Ԫ�أ�\n" );
					goto again;
				}
				BST_preorderR( T );
				printf( "\n������ɣ�\n\n" );
				break;
			case 6:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿������Ԫ�أ�\n" );
					goto again;
				}
				BST_inorderI( T -> root );
				printf( "\n������ɣ�\n\n" );
				break;
			case 7:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿������Ԫ�أ�\n" );
					goto again;
				}
				BST_inorderR( T );
				printf( "\n������ɣ�\n\n" );
				break;
			case 8:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿������Ԫ�أ�\n" );
					goto again;
				}
				BST_postorderI( T -> root );
				printf( "\n������ɣ�\n\n" );
				break;
			case 9:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿������Ԫ�أ�\n" );
					goto again;
				}
				BST_postorderR( T );
				printf( "\n������ɣ�\n\n" );
				break;
			case 10:
				if( T -> root == NULL ){
					printf( "��Ϊ�գ��޿������Ԫ�أ�\n" );
					goto again;
				}
				BST_levelOrder( T );
				printf( "\n������ɣ�\n\n" );
				break;
		}
		printf( "\n\n" );
	}
}
