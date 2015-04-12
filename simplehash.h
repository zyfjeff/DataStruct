/*
 =====================================================================================
        Filename:  simplehash.cpp
     	Description:  简单的散列函数
        Version:  1.0
        Created:  27/02/15 01:54:19
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#ifndef _SIMPLE_HASH_H_
#define _SIMPLE_HASH_H_

typedef unsigned int Index;

//hash算法
Index Hash1(const char  *key,int TableSize)
{
	unsigned int HashVal = 0;
	while(*key != '\0')
		HashVal += *key++;
	return HashVal % TableSize;
}

Index Hash2(const char *key,int TableSize)
{
	return (key[0]+27*key[1]+729*key[2]) % TableSize;
}

Index Hash3(const char *key,int TableSize)
{
	unsigned int HashVal = 0;
	while(*key != '\0')
		HashVal = (HashVal << 5) + *key++;
	return HashVal % TableSize;
}
#endif // _SIMPLE_HASH_H_
