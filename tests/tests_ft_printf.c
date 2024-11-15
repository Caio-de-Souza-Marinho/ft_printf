#include "minunit.h"
#include "../src/ft_printf.h"


MU_TEST(test_ft_printf_print_char)
{
	// ARRANGE
	char	c = 'a';
	int	expected_result = 1;

	// ACT
	int	actual_result = ft_printf("%c", c);	

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_printf_test_suite)
{
	MU_RUN_TEST(test_ft_printf_print_char);
}

int	main(void)
{
	MU_RUN_SUITE(ft_printf_test_suite);

	MU_REPORT();
	return MU_EXIT_CODE;
}

