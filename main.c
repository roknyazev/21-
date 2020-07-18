#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

void checkret(int c1, int c2)
{
	if (c1 != c2)
		printf("\033[0;31m[KO!]\033[0m\n\n");
	if (c1 == c2)
		printf("\033[0;32m[OK!]\033[0m\n\n");
}

int main()
{
	int c1;
	int c2;
	void *null = NULL;

	printf("---------------------------------\n");
	printf("--->FT_PRINTF CHECKLIST TESTS<---\n");
	printf("---------------------------------\n");

	c1 = ft_printf("Test output\n");
	c2 = printf("Test output\n");
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("---Only one arg---\n");
	c1 = ft_printf("%d", 15);
	printf("\n");
	c2 = printf("%d", 15);
	printf("\n");
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("---Multiple args with string between---\n");
	c1 = ft_printf("char:%c string:%s pointer:%p decimal:%d integer:%i unsigned:%u hex:%x HEX: %X percent:%%\n", \
	'*', "Hi!", &c1, -15, -15, 10, 576, 576);
	c2 = printf("char:%c string:%s pointer:%p decimal:%d integer:%i unsigned:%u hex:%x HEX: %X percent:%%\n", \
	'*', "Hi!", &c1, -15, -15, 10, 576, 576);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("---Null and special cases---\n");
	c1 = ft_printf("empty_string:%s null_string:%s null_pointer:%p min_int:%d max_int:%d\n", "", 0, null, \
	INT_MIN, INT_MAX);
	c2 = printf("empty_string:%s null_string:%s null_pointer:%p min_int:%d max_int:%d\n", "", 0, null, \
	INT_MIN, INT_MAX);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("----------------------------------\n");
	printf("----->Simple flag management<-----\n");
	printf("----------------------------------\n");

	char *str = "TEST";
	int num = -245;

	printf("---Minimum field width---\n");
	c1 = ft_printf("smaller:%2s equal:%4s bigger:%6s\n", str, str, str);
	c2 = printf("smaller:%2s equal:%4s bigger:%6s\n", str, str, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("smaller:%-2s equal:%-4s bigger:%-6s with '-'\n", str, str, str);
	c2 = printf("smaller:%-2s equal:%-4s bigger:%-6s with '-'\n", str, str, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("smaller:%02s equal:%04s bigger:%06s with '0'\n", str, str, str);
	c2 = printf("smaller:%02s equal:%04s bigger:%06s with '0'\n", str, str, str);
	printf("\033[0;35mUNDEFINED BEHAVIOR EXPECTED!\033[0m\n");
	printf("Returned %d %d\t", c1, c2);
	printf("\n\n\t");

	printf("-Additional valid case with '0'-\n");
	c1 = ft_printf("smaller:%02d equal:%04d bigger:%06d with '0' and %%d\n", num, num, num);
	c2 = printf("smaller:%02d equal:%04d bigger:%06d with '0' and %%d\n", num, num, num);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("---Minimum field width with precision---\n");
	c1 = ft_printf("smaller:%2.2s equal:%4.2s bigger:%6.2s with '.2'\n", str, str, str);
	c2 = printf("smaller:%2.2s equal:%4.2s bigger:%6.2s with '.2'\n", str, str, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("smaller:%-2.4s equal:%-4.4s bigger:%-6.4s with '.4'\n", str, str, str);
	c2 = printf("smaller:%-2.4s equal:%-4.4s bigger:%-6.4s with '.4'\n", str, str, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("smaller:%02.6s equal:%04.6s bigger:%06.6s with '.6'\n", str, str, str);
	c2 = printf("smaller:%02.6s equal:%04.6s bigger:%06.6s with '.6'\n", str, str, str);
	printf("\033[0;35mUNDEFINED BEHAVIOR EXPECTED!\033[0m\n");
	printf("Returned %d %d\t", c1, c2);
	printf("\n\n");

	printf("----------------------------------\n");
	printf("---->Advanced flag management<----\n");
	printf("----------------------------------\n");

	printf("---Minimum field width with '*'---\n");
	c1 = ft_printf("pos:%*s null:%*s neg:%*s|\n", 8, str, 0, str, -8, str);
	c2 = printf("pos:%*s null:%*s neg:%*s|\n", 8, str, 0, str, -8, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("---Precision with '*'---\n");
	c1 = ft_printf("pos:%.*s null:%.*s neg:%.*s\n", 8, str, 0, str, -8, str);
	c2 = printf("pos:%.*s null:%.*s neg:%.*s\n", 8, str, 0, str, -8, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("---Both with '*'---\n");
	c1 = ft_printf("+/+:%*.*s -/-:%*.*s -/+:%*.*s +/-:%*.*s\n", 6, 8, str, -6, -8, str, -6, 8, str,  6, -8, str);
	c2 = printf("+/+:%*.*s -/-:%*.*s -/+:%*.*s +/-:%*.*s\n", 6, 8, str, -6, -8, str, -6, 8, str,  6, -8, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("0/+:%*.*s| 0/-:%*.*s| -/0:%*.*s| +/0:%*.*s|\n", 0, 8, str, 0, -8, str, -6, 0, str,  6, 0, str);
	c2 = printf("0/+:%*.*s| 0/-:%*.*s| -/0:%*.*s| +/0:%*.*s|\n", 0, 8, str, 0, -8, str, -6, 0, str,  6, 0, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("+/+:%-*.*s -/-:%-*.*s -/+:%-*.*s +/-:%-*.*s with '-'\n", 6, 8, str, -6, -8, str, -6, 8, str,  6, -8, str);
	c2 = printf("+/+:%-*.*s -/-:%-*.*s -/+:%-*.*s +/-:%-*.*s with '-'\n", 6, 8, str, -6, -8, str, -6, 8, str,  6, -8, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	printf("-----------------------------------\n");
	printf("------------>GET CRAZY<------------\n");
	printf("-----------------------------------\n");

	c1 = ft_printf("%d\n", UINT_MAX);
	c2 = printf("%d\n", UINT_MAX);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("%30u\n", UINT_MAX);
	c2 = printf("%30u\n", UINT_MAX);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("%x %X %x %X %x %X %x %X\n", 0, -500, 500, 176549, 1, 13, 24, 15);
	c2 = printf("%x %X %x %X %x %X %x %X\n", 0, -500, 500, 176549, 1, 13, 24, 15);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("%x %X\n", UINT_MAX, UINT_MAX + 1);
	c2 = printf("%x %X\n", UINT_MAX, UINT_MAX + 1);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("%p %p %p %p %p %p %p\n", str, &str, &num, null, &null, "42", (void *)'!');
	c2 = printf("%p %p %p %p %p %p %p\n", str, &str, &num, null, &null, "42", (void *)'!');
	printf("\033[0;35mUNDEFINED BEHAVIOR EXPECTED!\033[0m\n");
	printf("Returned %d %d\t", c1, c2);
	printf("\n\n");

	c1 = ft_printf("%%%%%d%%%05%%s%%\n", 346, "HI!");
	c2 = printf("%%%%%d%%%05%%s%%\n", 346, "HI!");
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("testtest%testtest\n");
	c2 = printf("testtest%testtest\n");
	printf("\033[0;35mUNDEFINED BEHAVIOR EXPECTED!\033[0m\n");
	printf("Returned %d %d\t", c1, c2);
	printf("\n\n");

	c1 = ft_printf("%15p %*.7d MIXED %*.*s TEST! %%%05%%% I %10.7u H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", \
	 &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
	c2 = printf("%15p %*.7d MIXED %*.*s TEST! %%%05%%% I %10.7u H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", \
	 &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("%20d|%.5d|%15X|%10.7d|%-7.3d|%-7.5X|%7.0d|%14u|%.10u|%12.5u|%-12.6X|%-7.3u|%10.7u|%5.5i|%1.1X|%-8X|%.8i|%0i|%010i|%15.7i|%012x|%012.3x|%15x|%x|%.2x\n", 156, -4516, \
	 0, 0, 654, 2, 1, -9, -4, 65, 1554665, 546887, 14566, -5, 14, -15, 13, 14000, 99999999, 145, 1000, 500, 1477777, 155644, 0);
	c2 = printf("%20d|%.5d|%15X|%10.7d|%-7.3d|%-7.5X|%7.0d|%14u|%.10u|%12.5u|%-12.6X|%-7.3u|%10.7u|%5.5i|%1.1X|%-8X|%.8i|%0i|%010i|%15.7i|%012x|%012.3x|%15x|%x|%.2x\n", 156, -4516, \
	 0, 0, 654, 2, 1, -9, -4, 65, 1554665, 546887, 14566, -5, 14, -15, 13, 14000, 99999999, 145, 1000, 500, 1477777, 155644, 0);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("%4.3s %-8.2s %3.8s %1.1s %4.4s %4.2s %-6.15s\n", str, str, str, str, str, str, str);
	c2 = printf("%4.3s %-8.2s %3.8s %1.1s %4.4s %4.2s %-6.15s\n", str, str, str, str, str, str, str);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("%20d %14u %4.3s %.10u %12.5u %-12.6X %1.1s %010i %15.7i %-6.15s %x %.2x\n", \
	 -4516, 65441, str, 546887, 14566, -5, str, 14, -15, str, 13, 0);
	c2 = printf("%20d %14u %4.3s %.10u %12.5u %-12.6X %1.1s %010i %15.7i %-6.15s %x %.2x\n", \
	 -4516, 65441, str, 546887, 14566, -5, str, 14, -15, str, 13, 0);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("|%7.0d|%7.0d|%7.0X|%7.0X|%7.0u|%7.0u|\n", 0, 9, 0, 9, 0, 9, 0, 9);
	c2 = printf("|%7.0d|%7.0d|%7.0X|%7.0X|%7.0u|%7.0u|\n", 0, 9, 0, 9, 0, 9, 0, 9);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);

	c1 = ft_printf("|%-7.5X|%-7.5d|%-7.5i|%-7.5u|\n", 5, 5, 5 ,5);
	c2 = printf("|%-7.5X|%-7.5d|%-7.5i|%-7.5u|\n", 5, 5, 5 ,5);
	printf("Returned %d %d\t", c1, c2);
	checkret(c1, c2);
}