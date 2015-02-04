/*
 *	欧几里得算法 计算最大公因数
 *	思想:辗转相除，两个数相除取模，知道模等于0，否则模作为被除数，上次的被除数作为除数
 *	一直这样辗转下去.
 */

#include <stdio.h>
unsigned int Gcd(unsigned int M,unsigned int N)
{
	unsigned int rem;
	while(N > 0)
	{
		rem = M % N;
		M = N;
		N = rem;
	}
	return M;
}

int main()
{
	printf("%d\n",Gcd(50,15));
}
