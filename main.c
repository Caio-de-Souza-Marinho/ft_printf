/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:11:51 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/24 21:28:26 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define TEST(args...) \
{ \
	int orig_len, ft_len; \
	printf("\nTest: \""); \
	printf(args); \
	printf("\"\n"); \
	printf("Format: \"%s\"\n", #args); \
	printf("Original: |"); \
	orig_len = printf(args); \
	printf("| (length: %d)\n", orig_len); \
	printf("ft_printf: |"); \
	ft_len = ft_printf(args); \
	printf("| (length: %d)\n", ft_len); \
	if (orig_len == ft_len) \
		printf("Length check: \033[0;32mOK\033[0m\n"); \
	else \
		printf("Length check: \033[0;31mFAIL\033[0m (expected: %d, got: %d)\n", orig_len, ft_len); \
	printf("-----------------------\n"); \
	fflush(stdout); \
}

int main(void)
{
	/* ========== MANDATORY TESTS (ALL CONVERSIONS) ========== */
	printf("\n==== MANDATORY: BASIC CONVERSIONS ====\n");

	// %c
	TEST("%%c: |%c|", 'A');
	TEST("%%5c: |%5c|", 'B');
	TEST("%%-5c: |%-5c|", 'C');
	TEST("%%05c: |%05c|", 'D');  // 0-pad char (non-standard but test behavior)

	// %s
	TEST("%%s: |%s|", "hello");
	TEST("%%10s: |%10s|", "hello");
	TEST("%%-10s: |%-10s|", "hello");
	TEST("%%.3s: |%.3s|", "hello");
	TEST("%%10.3s: |%10.3s|", "hello");
	TEST("%%-10.3s: |%-10.3s|", "hello");
	TEST("%%s (NULL): |%s|", NULL);

	// %p
	void *ptr = &main;
	TEST("%%p: |%p|", ptr);
	TEST("%%20p: |%20p|", ptr);
	TEST("%%-20p: |%-20p|", ptr);
	TEST("%%0p: |%0p|", ptr);  // 0-pad pointer (non-standard but test behavior)

	// %d
	TEST("%%d: |%d|", 42);
	TEST("%%10d: |%10d|", 42);
	TEST("%%-10d: |%-10d|", 42);
	TEST("%%010d: |%010d|", 42);
	TEST("%%.5d: |%.5d|", 42);
	TEST("%%10.5d: |%10.5d|", 42);
	TEST("%%-10.5d: |%-10.5d|", 42);
	TEST("%%0-10.5d: |%0-10.5d|", 42);  // Conflicting flags test
	TEST("%%d (neg): |%d|", -42);

	// %i (same as %d)
	TEST("%%i: |%i|", 42);
	TEST("%%+i: |%+i|", 42);  // Bonus flag but test anyway

	// %u
	TEST("%%u: |%u|", 42);
	TEST("%%10u: |%10u|", 42);
	TEST("%%-10u: |%-10u|", 42);
	TEST("%%010u: |%010u|", 42);

	// %x
	TEST("%%x: |%x|", 255);
	TEST("%%10x: |%10x|", 255);
	TEST("%%-10x: |%-10x|", 255);
	TEST("%%010x: |%010x|", 255);

	// %X
	TEST("%%X: |%X|", 255);
	TEST("%%10X: |%10X|", 255);
	TEST("%%-10X: |%-10X|", 255);
	TEST("%%010X: |%010X|", 255);

	// %%
	TEST("%%%%: |%%|");
	TEST("%%10%%: |%10%|");
	TEST("%%-10%%: |%-10%|");
	TEST("%%0-10%%: |%0-10%|");  // Conflicting flags test

	/* ========== BONUS TESTS (FLAG COMBINATIONS) ========== */
	printf("\n==== BONUS: FLAG COMBINATIONS ====\n");

	// # Flag Combinations
	TEST("%%#x: |%#x|", 255);
	TEST("%%#X: |%#X|", 255);
	TEST("%%#10x: |%#10x|", 255);
	TEST("%%#-10x: |%#-10x|", 255);
	TEST("%%#010x: |%#010x|", 255);
	TEST("%%#0-10x: |%#0-10x|", 255);  // Conflicting flags

	// + Flag Combinations
	TEST("%%+d: |%+d|", 42);
	TEST("%%+d: |%+d|", -42);
	TEST("%%+10d: |%+10d|", 42);
	TEST("%%+-10d: |%+-10d|", 42);
	TEST("%%+010d: |%+010d|", 42);
	TEST("%%+-010d: |%+-010d|", 42);  // Conflicting flags

	// Space Flag Combinations
	TEST("%% d: |% d|", 42);
	TEST("%% d: |% d|", -42);
	TEST("%% 10d: |% 10d|", 42);
	TEST("%% -10d: |% -10d|", 42);
	TEST("%% 010d: |% 010d|", 42);
	TEST("%% -010d: |% -010d|", 42);  // Conflicting flags

	// Combined + and Space (should prioritize +)
	TEST("%%+ d: |%+ d|", 42);  // Invalid combination test
	TEST("%% +d: |% +d|", 42);  // Invalid combination test

	// Combination with All Flags
	TEST("%%#+-0 20x: |%#+-0 20x|", 255);  // Extreme combination test
	TEST("%%#+ -0 20d: |%#+ -0 20d|", 42);  // Invalid combination test

	// Edge Cases
	TEST("%%#x: |%#x|", 0);      // Zero value with #
	TEST("%%#.0x: |%#.0x|", 0);  // Zero precision with #
	TEST("%%+0d: |%+0d|", 0);    // Zero value with + and 0
	TEST("%% 0d: |% 0d|", 0);    // Zero value with space and 0

	// Additional edge cases and test scenarios for ft_printf

	/* ========== EDGE CASES FOR INTEGERS ========== */
	printf("\n==== EDGE CASES FOR INTEGERS ====\n");

	// INT_MIN, INT_MAX, UINT_MAX
	TEST("%%d (INT_MIN): |%d|", INT_MIN);
	TEST("%%d (INT_MAX): |%d|", INT_MAX);
	TEST("%%u (UINT_MAX): |%u|", UINT_MAX);
	TEST("%%x (UINT_MAX): |%x|", UINT_MAX);
	TEST("%%X (UINT_MAX): |%X|", UINT_MAX);

	// Long integers with different formats
	TEST("%%10d (INT_MIN): |%10d|", INT_MIN);
	TEST("%%-10d (INT_MIN): |%-10d|", INT_MIN);
	TEST("%%010d (INT_MIN): |%010d|", INT_MIN);
	TEST("%%.10d (INT_MIN): |%.10d|", INT_MIN);

	// Zero value with different formats
	TEST("%%d (0): |%d|", 0);
	TEST("%%+d (0): |%+d|", 0);
	TEST("%% d (0): |% d|", 0);
	TEST("%%#x (0): |%#x|", 0);
	TEST("%%#X (0): |%#X|", 0);
	TEST("%%.0d (0): |%.0d|", 0);
	TEST("%%+.0d (0): |%+.0d|", 0);
	TEST("%% .0d (0): |% .0d|", 0);
	TEST("%%#.0x (0): |%#.0x|", 0);

	/* ========== POINTER EDGE CASES ========== */
	printf("\n==== POINTER EDGE CASES ====\n");

	// NULL pointer with various formats
	TEST("%%p (NULL): |%p|", NULL);
	TEST("%%20p (NULL): |%20p|", NULL);
	TEST("%%-20p (NULL): |%-20p|", NULL);

	// Printing addresses of different variables
	static int static_var = 42;
	int local_var = 42;
	TEST("%%p (stack var): |%p|", &local_var);
	TEST("%%p (static var): |%p|", &static_var);
	TEST("%%p (function): |%p|", &main);

	/* ========== STRING EDGE CASES ========== */
	printf("\n==== STRING EDGE CASES ====\n");

	// Empty string
	TEST("%%s (empty): |%s|", "");
	TEST("%%10s (empty): |%10s|", "");
	TEST("%%-10s (empty): |%-10s|", "");
	TEST("%%.5s (empty): |%.5s|", "");

	// String with special characters
	TEST("%%s (special): |%s|", "Hello\nWorld\tTab\\Backslash");
	TEST("%%.10s (special): |%.10s|", "Hello\nWorld\tTab\\Backslash");

	// Very long string
	char long_str[1000];
	memset(long_str, 'A', 999);
	long_str[999] = '\0';
	TEST("%%s (long): |%.10s...|", long_str);
	TEST("%%.100s (long): |%.100s...|", long_str);

	/* ========== PRECISION EDGE CASES ========== */
	printf("\n==== PRECISION EDGE CASES ====\n");

	// Zero precision with different values
	TEST("%%.0d (42): |%.0d|", 42);
	TEST("%%.0d (0): |%.0d|", 0);
	TEST("%%.0s (hello): |%.0s|", "hello");
	TEST("%%.0x (255): |%.0x|", 255);
	TEST("%%.0x (0): |%.0x|", 0);

	// Large precision values
	TEST("%%.50d (42): |%.50d|", 42);
	TEST("%%.50x (42): |%.50x|", 42);
	TEST("%%50.50d (42): |%50.50d|", 42);

	/* ========== COMPLEX FORMAT STRINGS ========== */
	printf("\n==== COMPLEX FORMAT STRINGS ====\n");

	// Multiple conversions in a single format string
	TEST("Multiple: |%d|%s|%c|%x|", 42, "hello", 'A', 255);
	TEST("Mixed flags: |%+d|%#x|%-10s|%05d|", 42, 255, "hello", 42);

	// Format strings with escaped '%' characters
	TEST("Escaped %%: |%%|%%%%%%|%%d|", 42);
	TEST("Mixed escapes: |%%%d|%%%s|", 42, "hello");

	/* ========== FLAG COMBINATIONS ========== */
	printf("\n==== COMPREHENSIVE FLAG COMBINATIONS ====\n");

	// More thorough testing of space vs plus
	TEST("%%+10d vs %% 10d: |%+10d|% 10d|", 42, 42);
	TEST("%%+010d vs %% 010d: |%+010d|% 010d|", 42, 42);
	TEST("%%+-10d vs %% -10d: |%+-10d|% -10d|", 42, 42);

	// All possible combinations of flags for different specifiers
	TEST("%%#+0 d: |%#+0 d|", 42);  // Combining all flags
	TEST("%%#+-0 x: |%#+-0 x|", 255);  // Combining all flags for hex
	TEST("%%+ 0d: |%+ 0d|", 42);  // Space and plus (plus wins)

	// Complex width and precision combinations
	TEST("%%15.10d: |%15.10d|", 42);
	TEST("%%15.10d: |%15.10d|", -42);
	TEST("%%#15.10x: |%#15.10x|", 255);
	TEST("%%0#15.10x: |%0#15.10x|", 255);
	TEST("%%-#15.10x: |%-#15.10x|", 255);

	// Tests with asterisk width and precision
	TEST("%%*d: |%*d|", 10, 42);
	TEST("%%*.*d: |%*.*d|", 10, 5, 42);
	TEST("%%*.*s: |%*.*s|", 10, 3, "hello");

	// Additional edge cases for negative values
	TEST("%%+d negative: |%+d|", -42);
	TEST("%% d negative: |% d|", -42);
	TEST("%%+10.5d negative: |%+10.5d|", -42);
	TEST("%% 10.5d negative: |% 10.5d|", -42);

	/* ========== ADDITIONAL REAL-WORLD USAGE ========== */
	printf("\n==== REAL-WORLD USAGE SCENARIOS ====\n");

	// Decimal formatting (currency-like)
	TEST("Price: $%%d.%%02d | $%d.%02d", 5, 99);
	TEST("Negative price: $%%d.%%02d | $%d.%02d", -10, 50);

	// Table-like alignment
	TEST("| %%10s | %%10s |: | %10s | %10s |", "Name", "Value");
	TEST("| %%10s | %%10d |: | %10s | %10d |", "Total", 42);
	TEST("| %%10s | %%#10x |: | %10s | %#10x |", "Hex", 255);

	// Debug output format
	TEST("[DEBUG] Value=%%d, Ptr=%%p: [DEBUG] Value=%d, Ptr=%p", 42, &main);
	TEST("[ERROR] Code=%%#x: [ERROR] Code=%#x", 255);

	return 0;
}
