#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200000
#define MAX 15000
#define TIMES 100000

#define OK 1
#define ERROR 0
typedef int Status;

int Menu1();
Status InsertSort( int* a, int len );
void generate( int *a, int len );
Status print( int* a, int len );
void MergeSort( int *a, int head, int tail );
void Merge( int *a, int head, int mid, int tail );
void QuickSortRec( int *a, int head, int tail );
void QuickSortNonRec( int *a, int head, int tail );
int SideSort( int *a, int head, int tail );
void swap( int *x, int *y );
Status CountSort( int *a, int len );
int findmax( int *a, int len );
Status RadixCountSort( int *a, int len );
void CountSort2( int *a, int len, int step );
int test_option( char s[30], int m );
int test_number( char s[30] );


#endif 
