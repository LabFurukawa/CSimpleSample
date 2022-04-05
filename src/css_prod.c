#include <css_prod.h>


#include <stdint.h>
#include <stddef.h>
#include <css_error.h>


CSS_ERROR CSS_prod(int32_t* ans, int32_t lhs, int32_t rhs)
{
	if (ans == NULL) return CSS_ERROR_NULLPTR;

	if ((lhs > 0) && (rhs > 0))
	{
		if (INT32_MAX / lhs < rhs) return CSS_ERROR_TOO_BIG;
	}

	if ((lhs > 0) && (rhs <= 0))
	{
		if (INT32_MIN / lhs > rhs) return CSS_ERROR_TOO_SMALL;
	}

	if ((lhs <= 0) && (rhs > 0))
	{
		if (INT32_MIN / lhs > rhs) return CSS_ERROR_TOO_SMALL;
	}

	if ((lhs <= 0) && (rhs <= 0))
	{
		if (lhs != 0)
		{
			if (INT32_MAX / lhs < rhs) return CSS_ERROR_TOO_BIG;
		}
	}

	int32_t ret = lhs * rhs;
	*ans = ret;

	return CSS_ERROR_SUCCESS;
}
