#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/LinkQueue.h"
#include "./Link_Queue.c"

int main(){
	char s[30];
	int k, e, r, n, len;
	int cnt = 1;
	pQueue Q;
	InitLQueue( &Q ); 
	while(1){
			again:
			printf("********************************\n");
			printf("*     	   1.元素入队          *\n");
		    printf("*          2.元素出队          *\n");
		    printf("*       3.判断队是否为空       *\n");
		    printf("*         4.取队首元素         *\n");
		    printf("*          5.清空队            *\n");
		    printf("*          6.销毁队            *\n");
		    printf("*        7.检测队的长度        *\n");
		    printf("*        8.重新初始化队        *\n");
		    printf("*          9.打印队            *\n");
		    printf("*         10.退出程序          *\n");
		    printf("********************************\n");
		    printf("请选择需要的功能：");
		    scanf( "%s", s );
			k = test_option( s, 10 ); 
			switch( k ){
				case 1:
					if( Q == NULL ){
						printf( "\n队列已销毁，请重新初始化队列！\n\n" ); 
						goto again;
					}
					while(1){
						printf( "请输入队列的第%d个元素(Element Type: int)，输入x停止入队：", cnt );
						scanf( "%s", s );
						if( strcmp( s, "x" ) == 0 ){
							break;
						} 
						n = test_number( s );
						InLQueue( Q, n );
						cnt ++;
					}
					break;
				case 2:
					if( Q == NULL ){
						printf( "\n队列已销毁，请重新初始化队列！\n\n" ); 
						goto again;
					}
					OutLQueue( Q, &e );
					cnt --;
					printf( "\n队首元素%d出队成功。\n\n", e );
					break;
				case 3:
					if( Q == NULL ){
						printf( "\n队列已销毁，请重新初始化队列！\n\n" ); 
						goto again;
					}
					r = IsEmpty( Q );
					if( r == 1 ){
						printf( "\n************队不为空************\n\n" );
					} else if( r == 0 ) {
						printf( "\n*************队为空*************\n\n" );
					}
					break;
				case 4:
					if( Q == NULL ){
						printf( "\n队列已销毁，请重新初始化队列！\n\n" ); 
						goto again;
					}
					GetHeadElement( Q, &e );
					printf( "\n队首元素为：%d\n\n", e );
					break;
				case 5:
					if( Q == NULL ){
						printf( "\n队列已销毁，请重新初始化队列！\n\n" ); 
						goto again;
					}
					if( ClearLQueue( Q ) == 1 ){
						printf( "\n清空成功！\n\n" ); 
					}
					break;
				case 6:
					if( Q == NULL ){
						printf( "\n队列已不存在，无需销毁！\n\n" ); 
						goto again;
					}
					if( DestroyLQueue( &Q ) == 1 ){
						printf("\n销毁成功！\n\n" );
					}
					break;
				case 7:
					if( Q == NULL ){
						printf( "\n队列已销毁，请重新初始化队列！\n\n" ); 
						goto again;
					}
					len = GetLength( Q );
					printf( "\n栈的长度为：%d\n\n", len-1 );
					break;
				case 8: 
					if( Q != NULL ){
						printf( "\n队列不需要初始化，请直接操作。\n\n" ); 
						goto again;
					}
					InitLQueue( &Q );
					printf( "\n初始化成功！\n\n" );
					break;
				case 9: 
					if( Q == NULL ){
						printf( "\n队列已销毁，请重新初始化队列！\n\n" ); 
						goto again;
					}
					PrintLQueue( Q );
					break;
				case 10:
					return 0;
			}
		}
}
