#include "minunit.h"
#include "../src/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#include "tests_ft_printf_c_and_%.c"
#include "tests_ft_printf_s.c"

MU_TEST(test_ft_printf_print_one_pointer)
{
	// ARRANGE
	char	*ptr = (void *)0x1234abcd; // Example pointer to test
	char	expected_output[100];
	int	expected_return_value;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Create the expected output using snprintf
	expected_return_value = snprintf(expected_output, sizeof(expected_output), "%p", ptr);

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%p", ptr);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_p_flag_null_pointer)
{
	// ARRANGE
	void	*ptr = NULL;
	char	expected_output[] = "(nil)";
	int	expected_return_value = 5;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%p", ptr);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

/*
MU_TEST(test_ft_printf_print_percent_sign)
{
	// ARRANGE
	//char	c = '%';
	char	expected_output[] = "%";
	int	expected_return_value = 1;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%%");

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_one_int)
{
	// ARRANGE
	int	num = 0;
	char	expected_output[] = "0";
	int	expected_return_value = 1;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%d", num);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_one_positive_int_and_one_normal)
{
	// ARRANGE
	int	num1 = 42;
	int	num2 = -42;
	char	expected_output[] = "42-42";
	int	expected_return_value = 5;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%d%d", num1, num2);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_int_max)
{
	// ARRANGE
	int	num = INT_MAX;
	char	expected_output[] = "2147483647";
	int	expected_return_value = 10;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%d", num);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_int_min)
{
	// ARRANGE
	int	num = INT_MIN;
	char	expected_output[] = "-2147483648";
	int	expected_return_value = 11;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%d", num);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_int_max_plus_one)
{
	// ARRANGE
	int	num = INT_MAX;
	char	expected_output[] = "-2147483648";
	int	expected_return_value = 11;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%d", num + 1);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_int_min_minus_one)
{
	// ARRANGE
	int	num = INT_MIN;
	char	expected_output[] = "2147483647";
	int	expected_return_value = 10;  // Expected number of characters printed
	char	buffer[100];
	int	temp_fd;
	int	saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%d", num - 1);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_two_unsigned_int_int_max_and_int_min)
{
	// ARRANGE
	unsigned int	num1 = INT_MIN;
	unsigned int	num2 = INT_MAX;
	char		expected_output[] = "21474836482147483647";
	int		expected_return_value = 20;  // Expected number of characters printed
	char		buffer[100];
	int		temp_fd;
	int		saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%u%u", num1, num2);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_one_number_x_specifier)
{
	// ARRANGE
	unsigned int	num = 42;
	char		expected_output[] = "2a";
	int		expected_return_value = 2;  // Expected number of characters printed
	char		buffer[100];
	int		temp_fd;
	int		saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%x", num);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_one_number_X_specifier)
{
	// ARRANGE
	unsigned int	num = 42;
	char		expected_output[] = "2A";
	int		expected_return_value = 2;  // Expected number of characters printed
	char		buffer[100];
	int		temp_fd;
	int		saved_stdout;

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%X", num);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}

MU_TEST(test_ft_printf_print_mix)
{
	// ARRANGE
	char		c = 'a';
	char		*str = "caio";
	char		*ptr = (void *)0x1234abcd; // Example pointer to test
	int		num1 = 42;
	int		num2 = -42;
	unsigned int	num3 = 4200;
	unsigned int	num4 = 42;
	char		expected_output[200];
	int		expected_return_value;  // Expected number of characters printed
	char		buffer[200];
	int		temp_fd;
	int		saved_stdout;

	// Create the expected output using snprintf
	expected_return_value = snprintf(expected_output, sizeof(expected_output), "%c%s%p%%%d%d%u%x%X", c, str, ptr, num1, num2, num3, num4, num4);

	// Save the current stdout file descriptor
	saved_stdout = dup(STDOUT_FILENO);

	// Create a temporary file and get its file descriptor
	temp_fd = open("/tmp/test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (temp_fd == -1) {
		mu_fail("Failed to open temporary file");
	}

	// Redirect stdout to the temporary file
	if (dup2(temp_fd, STDOUT_FILENO) == -1) {
		mu_fail("Failed to redirect stdout");
	}

	// ACT
	int	actual_return_value = ft_printf("%c%s%p%%%d%d%u%x%X", c, str, ptr, num1, num2, num3, num4, num4);

	// Reset stdout to its original value
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
	close(saved_stdout);
	close(temp_fd);

	// Read the content of the temporary file
	FILE	*temp_file = fopen("/tmp/test_output.txt", "r");
	if (!temp_file) {
		mu_fail("Failed to open temporary file for reading");
	}
	size_t	bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_file);
	buffer[bytes_read] = '\0';  // Null-terminate the string read
	fclose(temp_file);

	// ASSERT
	mu_assert_string_eq(expected_output, buffer);  // Check printed output
	mu_assert_int_eq(expected_return_value, actual_return_value);  // Check return value

	// Clean up the temporary file
	remove("/tmp/test_output.txt");
}
*/

MU_TEST_SUITE(ft_printf_test_suite)
{
	MU_RUN_TEST(test_ft_printf_print_one_pointer);
	MU_RUN_TEST(test_ft_printf_p_flag_null_pointer);
/*
	MU_RUN_TEST(test_ft_printf_print_one_int);
	MU_RUN_TEST(test_ft_printf_print_one_positive_int_and_one_normal);
	MU_RUN_TEST(test_ft_printf_print_int_max);
	MU_RUN_TEST(test_ft_printf_print_int_min);
	MU_RUN_TEST(test_ft_printf_print_int_max_plus_one);
	MU_RUN_TEST(test_ft_printf_print_int_min_minus_one);
	MU_RUN_TEST(test_ft_printf_print_int_min_minus_one);
	MU_RUN_TEST(test_ft_printf_print_two_unsigned_int_int_max_and_int_min);
	MU_RUN_TEST(test_ft_printf_print_one_number_x_specifier);
	MU_RUN_TEST(test_ft_printf_print_one_number_X_specifier);
	MU_RUN_TEST(test_ft_printf_print_mix);
*/
}

int	main(void)
{
	MU_RUN_SUITE(ft_printf_test_suite);
	MU_RUN_SUITE(ft_printf_c_and_percent_sign_test_suite);
	MU_RUN_SUITE(ft_printf_s_test_suite);

	MU_REPORT();
	return MU_EXIT_CODE;
}
