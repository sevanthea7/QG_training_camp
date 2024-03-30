#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/Sort.h"
#include "./Sort.c"

int main(){
	int a[SIZE] = {0};
	char s[256]; 
	int i, n, k, len = 0;
	
	while( 1 ){
		len = 0;
		printf("********************************\n");
		printf("*     ��ѡ����������ķ�ʽ     *\n");
		printf("********************************\n");
		printf("*          1.�ֶ�����          *\n");
		printf("*          2.�������          *\n");
		printf("*          3.�˳�����          *\n");
		printf("********************************\n");
		printf("��ѡ����Ҫ�Ĺ��ܣ�");
		scanf( "%s", s );
		k = test_option( s, 3 );
		switch( k ){
			case 1:
				for( i = 0; ; i ++ ){
					printf( "�������%d����( ����xֹͣ���� )��", i + 1 );
					scanf( "%s", s );
					if( strcmp( s, "x" ) == 0 ){
						break;
					} 
					n = test_number( s );
					a[i] = n;
					len ++;
				}
				printf( "�ɹ���������\n" ); 
				print( a, len );
				break;
			case 2:
				while( 1 ){
					printf( "��������Ҫ���ɵ����ĸ�����");
					scanf( "%s", s );
					len = test_number( s );
					if( len > SIZE ){
						printf( "����̫�࣬���������룡\n" );
						continue;
					}else if( len <= 0 ){
						printf( "��������Ч������\n" );
						continue;
					}
					break;
				}
				generate( a, len );
				printf( "�ɹ��������飺\n" ); 
				print( a, len );
				break;
			case 3:
				return 0; 
		}
		printf( "\n" ); 
		k = Menu1();
		switch( k ){
			case 1:
				if( InsertSort( a, len ) ){
					printf( "�ɹ��������飺\n" ); 
					print( a, len );
				}else{
					printf( "����ʧ�ܣ�\n" );
				}
				break;
			case 2:
				if( len > 0 ){
					MergeSort( a, 0, len-1 );
					printf( "�ɹ��������飺\n" ); 
					print( a, len );
				}else{
					printf( "����ʧ�ܣ�\n" );
				}
				break;
			case 3:
				if( len > 0 ){
					QuickSortRec( a, 0, len-1 );
					printf( "�ɹ��������飺\n" ); 
					print( a, len );
				}else{
					printf( "����ʧ�ܣ�\n" );
				}
				break;
			case 4:
				if( len > 0 ){
					QuickSortNonRec( a, 0, len-1 );
					printf( "�ɹ��������飺\n" ); 
					print( a, len );
				}else{
					printf( "����ʧ�ܣ�\n" );
				}
				break;
			case 5:
				if( CountSort( a, len ) ){
					printf( "�ɹ��������飺\n" ); 
					print( a, len );
				}else{
					printf( "����ʧ�ܣ�\n" );
				}
				break;
			case 6:
				if( RadixCountSort( a, len ) ){
					printf( "�ɹ��������飺\n" ); 
					print( a, len );
				}else{
					printf( "����ʧ�ܣ�\n" );
				}
				break;
			case 7:
				return 0;
		}
		printf( "\n\n" );
	}
}
