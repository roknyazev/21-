#include <stdio.h>
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, World!%d\n%x %X\n", -1356436, 5555, 6666666);
	printf("Hello, World!%d\n%x %X", -1356436, 5555, 6666666);
    return 0;
}

//int main()
//{
//    format_list *test;
//    test = parse("%%%");
//    while (test)
//    {
//        if (test->plh == NULL)
//            printf("%s\n\n", test->text);
//        else
//        {
//            printf("flag %s\n", test->plh->flag);
//            printf("width %s\n", test->plh->width);
//            printf("precision %s\n", test->plh->precision);
//            printf("size %s\n", test->plh->size);
//            printf("type %c\n", test->plh->type);
//            printf("len %d\n\n", test->plh->len);
//
//        }
//        test = test->next;
//    }
//    return (0);
//}