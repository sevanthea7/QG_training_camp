#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/stack_calculator.h"


// 进行四则运算
int operate_cal( int left, int right, char opr ){
	switch( opr ){
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			if( right == 0 ){		// 除数为0时，标为错误
				return 999999; 
			}
			return left / right;
		default:
			break;
	}
}


// 计算后缀表达式
Status calculate( Stack S, char pf[512] ){
	char num[6];
	int i = 0;
	EType e;
	while( pf[i] ){
		int j = 0;
		if( is_number( pf[i] ) ){
			while( is_number( pf[i] ) ){			// 循环读入连续数字，保证多位数完整入栈 
				num[j] = pf[i];
				j ++;
				i ++;
			}
			num[j] = '\0';
			PushLStack( S, atoi( num ) );			// 将多位数整数入栈
		} else if( is_operator( pf[i] ) ){
			if( GetLength( S ) < 2 ){				// 操作的数字不足两位，报错 
                printf( "输入的式子不合规范！\n" );
                return ERROR;
            }
			PopLStack( S, &e );
			int right = e;							// 弹出第一个栈顶元素 
			PopLStack( S, &e );
			int left = e;							// 弹出第二个栈顶元素 
			int ans = operate_cal( left, right, pf[i] );	// 先后进行计算 
			if( ans == 999999 ){
				printf( "输入的式子不合规范！\n" );
    			return ERROR;
			}
   			PushLStack( S, ans );					// 计算结果重新压入栈 
		} else if( pf[i] == ' ' ){
			continue;
		} else{
			printf( "输入的式子不合规范！\n" );
			return ERROR;
		}
		i ++;
	}
	if( GetLength( S ) != 1 ){						// 最后剩下的不是一个元素，报错 
        printf( "输入的式子不合规范！\n" );
        return ERROR;
    }
	return OK;
}


// 转换中缀表达式为后缀表达式
Status transform( char f[256], char postf[512] ){
	Stack S;
	EType e;
	int i;
	int j = 0;
	InitLStack( &S );
	for( i = 0; f[i]; i ++ ){
		if( is_number( f[i] ) ){
			postf[j ++] = f[i];
			while (is_number(f[i + 1])) {			// 检查下一个字符是否为数字，循环读入多位数 
		        i++;
		        postf[j++] = f[i];
		    }
    		postf[j++] = ' ';						 // 数字之后添加空格 
		} else if ( f[i] == '(' ){
			PushLStack( S, f[i] );
		} else if ( f[i] == ')' ){
			PopLStack( S, &e );
			while( e != '(' ){						//不断弹出运算符，直到遇到对应的左括号 
                postf[j ++] = e;
                if( EmptyLStack( S ) == 0 ){
                	printf( "输入的式子不合规范！\n" );
    				return ERROR;
				}
                PopLStack( S, &e );
            }	
		} else if( is_operator( f[i] ) ){
			if( f[i+1] == '0' && f[i] == '/' ){		// 0做除数，报错 
               	printf( "输入的式子不合规范！\n" );
    			return ERROR;
            }
			while ( EmptyLStack( S ) ){
				if( priority( f[i] ) <= priority( S -> top -> data ) ){	// 运算符优先级小时弹出 
					PopLStack( S, &e );
	                postf[j ++] = e;
	                postf[j ++] = ' ';
				} else{
					break;
				}
            }
            PushLStack( S, f[i] );
		}else if( f[i] == ' '){
			continue;
		}else {
			printf( "输入的式子不合规范！\n" );
    		return ERROR;
		}
	}
	while( EmptyLStack( S ) && PopLStack( S, &e ) ){					// 剩余内容出栈 
        postf[j ++] = e;
    }
    postf[j] = '\0';
    return OK;
	
}


int is_number( char x ){
	if( x <= '9' && x >= '0' ){
		return 1;
	}
	return 0;
}


int is_operator( char x ){
	if( x == '+' || x == '-' || x == '*' || x == '/' ){
		return 1;
	}
	return 0;
}


int priority( char x ){
	if( x == '+' || x == '-' ){
		return 1;
	}else if( x == '*' || x == '/' ){
		return 2;
	}
	return 0;
}


// 判断是否为空栈
Status EmptyLStack( Stack S ){
	if( S == NULL ){
		printf( "栈已销毁，请重新初始化栈！\n" ); 
		return WRONG;
	}
	if( S -> top == NULL ){
		return 0;
	}
	return 1; 
} 


// 测试选择功能
int test_option( char s[30], int m ){
	int n, flag;
	do{
		flag = 1;
		n = atoi( s );
		if( n < 1 || n > m ){
        	flag = 0;
        	printf( "\n没有这个功能！请重新选择：" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
} 


// 测试输入数字
int test_number( char s[30] ){
	int n, flag;
	do{
		flag = 1;
		if( strcmp( s, "0" ) == 0 ){
			n = 0;
			break;
		}
		n = atoi( s );
		if( n == 0 ){
        	flag = 0;
        	printf( "\nNot a number! Reenter:" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
}

// 初始化栈 
Status InitLStack( Stack *S ){
	*S = ( Stack )malloc( sizeof( Stackptr ) );
	if( *S != NULL ){
		(*S) -> top = NULL;
		(*S) -> cnt = 0;
		return OK;
	}
	return ERROR;
}


// 元素入栈 
Status PushLStack( Stack S, EType e ){
	if( S == NULL ){
		printf( "栈已销毁，请重新初始化栈！\n" ); 
		return WRONG;
	}
	LinkStack p = ( LinkStack )malloc( sizeof( Node ) );// 创建新节点
	if( p == NULL ){
		return ERROR;
	}
	p -> data = e;										// 将要入栈的元素赋值给新节点的数据域
	p -> next = S -> top;								// 将新节点插入到栈顶	
	S -> top = p;										// 更新栈顶指针
	S -> cnt ++;										// 栈中元素数量加一
	return OK;
}

// 元素出栈 
Status PopLStack( Stack S, EType *e ){
	if( S == NULL ){
		printf( "栈已销毁，请重新初始化栈！\n" ); 
		return WRONG;
	}
	LinkStack tmp = S -> top;							// 暂存栈顶指针
	*e = tmp -> data;									// 将栈顶元素赋值给传入的参数
	S -> top = tmp -> next;								// 栈顶指针指向下一个元素
	free( tmp );										// 释放栈顶元素所占内存
	S -> cnt --;										// 栈元素数量减一
	return OK;
}

// 取栈顶元素 
Status GetTopElement( Stack S, EType *e ){
	if( S == NULL ){
		printf( "栈已销毁，请重新初始化栈！\n" ); 
		return WRONG;
	}
	if( S -> top == NULL ){
        return ERROR;
    }
    *e = S -> top -> data;								// 将栈顶元素赋值给传入的参数
    return OK;
} 


// 获得栈的长度
int GetLength( Stack S ){
	return  S -> cnt;
} 


// 清空栈
Status ClearStack( Stack S ){
	if( S == NULL ){
		printf( "栈已销毁，请重新初始化栈！\n" ); 
		return WRONG;
	}
	LinkStack p = S -> top;
	while( p ){
		LinkStack tmp = p;
		p = p -> next;
		free( tmp );									// 释放每个栈元素所占内存
	}
	S -> top = NULL;									// 将栈顶指针置空
	S -> cnt = 0;										// 将栈中元素数量置为0
	return OK;
} 


// 销毁栈
Status DestroyStack( Stack *S ){
	if( *S == NULL ){
		printf( "栈不存在，请重新初始化栈！\n" ); 
		return WRONG;
	}
	ClearStack( *S );									// 清空栈
	free( *S );											// 释放栈所占内存
	*S = NULL;											// 将栈指针置空
	return OK;
}

// 打印栈 
Status PrintStack( Stack S ){
	if( S == NULL ){
		printf( "栈已销毁，请重新初始化栈！\n" ); 
		return WRONG;
	}
	LinkStack p = S -> top;
	printf("\n");
	while( p ){
		printf( "|____%d____|\n", p -> data );
		p = p -> next;
	}
	printf("\n");
	return OK;
}

