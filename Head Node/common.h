#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define ElemType int

void SWap(ElemType *a, ElemType *b)
{
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;

}
#endif/*_COMMON_H_*/
