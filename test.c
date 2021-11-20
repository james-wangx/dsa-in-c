/**
 * @file test.c
 * @date 2021-11-20
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 测试代码
 */

#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void)
{
	time_t result = time(NULL);

	printf("The current time is %s(%jd seconds since the Epoch)\n",
	       asctime(gmtime(&result)), (intmax_t)result);

	return 0;
}
