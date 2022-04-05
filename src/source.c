#include <stdio.h>

#include <css.h>


int main()
{

	int a = 4;
	int b = 33;

	int ans_sum = 0;
	CSS_ERROR err_sum = CSS_sum(&ans_sum, a, b);
	if(err_sum != CSS_ERROR_SUCCESS)
	{
		printf("FAILED TO SUM\r\n");
		return -1;
	}

	int ans_prod = 0;
	CSS_ERROR err_prod = CSS_prod(&ans_prod, a, b);
	if(err_prod != CSS_ERROR_SUCCESS)
	{
		printf("FAILED TO PROD\r\n");
		return -2;
	}

	printf("%d + %d = %d\r\n", a, b, ans_sum);
	printf("%d x %d = %d\r\n", a, b, ans_prod);

	return 0;
}
