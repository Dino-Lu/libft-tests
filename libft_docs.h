#ifndef LIBFT_DOCS_H
# define LIBFT_DOCS_H

# include <stdlib.h>   // for NULL & malloc & size_t
# include <unistd.h>    // file descriptor & write
# include <stdint.h>    // SIZE_MAX

/**
 * @brief Checks if a character is an alphabetic letter (A-Z or a-z).
 *
 * Useful for validating input or parsing text where only letters are allowed.
 *
 * @param c The character to check.
 * @return Non-zero if c is a letter, 0 otherwise.
 *
 * @code
 * if (ft_isalpha('A')) { /* true */ }
 * @endcode
 *
 * @note Implementation Considerations:
 * - Consider using ASCII values for efficiency
 * - Handle both uppercase and lowercase letters
 * - Return type should be int for compatibility with standard library
 * - No need to handle NULL as input is a single character
 */
int ft_isalpha(int c);

/**
 * @brief Checks if a character is a digit (0-9).
 *
 * Useful for parsing numbers or validating numeric input.
 *
 * @param c The character to check.
 * @return Non-zero if c is a digit, 0 otherwise.
 *
 * @code
 * if (ft_isdigit('5')) { /* true */ }
 * @endcode
 *
 * @note Implementation Considerations:
 * - Use ASCII value range 48-57 ('0'-'9')
 * - Consider performance for high-frequency calls
 * - Return type should be int for compatibility
 * - No need to handle NULL as input is a single character
 */
int ft_isdigit(int c);

/**
 * @brief Checks if a character is alphanumeric (A-Z, a-z, 0-9).
 *
 * Useful for validating identifiers or user input.
 *
 * @param c The character to check.
 * @return Non-zero if c is alphanumeric, 0 otherwise.
 *
 * @code
 * if (ft_isalnum('a')) { /* true */ }
 * @endcode
 *
 * @note Implementation Considerations:
 * - Can reuse ft_isalpha and ft_isdigit
 * - Consider performance optimization
 * - Handle both uppercase and lowercase letters
 * - Return type should be int for compatibility
 */
int ft_isalnum(int c);

/**
 * @brief Checks if a character is an ASCII character (0-127).
 *
 * Useful for ensuring compatibility with standard C functions.
 *
 * @param c The character to check.
 * @return Non-zero if c is ASCII, 0 otherwise.
 *
 * @code
 * if (ft_isascii(65)) { /* true */ }
 * @endcode
 *
 * @note Implementation Considerations:
 * - Check if value is between 0 and 127
 * - Handle negative values correctly
 * - Consider performance for high-frequency calls
 * - Return type should be int for compatibility
 */
int ft_isascii(int c);

/**
 * @brief Checks if a character is printable (including space).
 *
 * Useful for filtering or displaying only printable characters.
 *
 * @param c The character to check.
 * @return Non-zero if c is printable, 0 otherwise.
 *
 * @code
 * if (ft_isprint(' ')) { /* true */ }
 * @endcode
 *
 * @note Implementation Considerations:
 * - Check if value is between 32 and 126
 * - Include space character (32)
 * - Handle negative values correctly
 * - Return type should be int for compatibility
 */
int ft_isprint(int c);

/**
 * @brief Calculates the length of a string.
 *
 * Useful for determining the size of a string for memory allocation,
 * string manipulation, or validation.
 *
 * @param s The string whose length is to be calculated.
 * @return The number of characters in the string (excluding the null terminator).
 *
 * @note Passing NULL is undefined behavior.
 *
 * @code
 * size_t len = ft_strlen("Hello");
 * // len == 5
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input (undefined behavior)
 * - Return type should be size_t for large strings
 * - Consider performance for long strings
 * - Don't count the null terminator
 * - Be careful with pointer arithmetic
 */
size_t ft_strlen(const char *s);

/**
 * @brief Converts a string to an integer.
 *
 * Useful for parsing numbers from user input or files.
 *
 * @param str The string to convert.
 * @return The integer value represented by the string.
 *
 * @code
 * int n = ft_atoi("42"); // n == 42
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle whitespace at the beginning
 * - Handle optional sign (+ or -)
 * - Handle overflow cases
 * - Handle invalid input
 * - Handle empty strings
 * - Consider performance for long strings
 * - Handle leading zeros
 */
int ft_atoi(const char *str);

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * Useful for searching or parsing strings.
 *
 * @param s The string to search.
 * @param c The character to find.
 * @return Pointer to the first occurrence or NULL if not found.
 *
 * @code
 * char *p = ft_strchr("Hello", 'e'); // p points to "ello"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle empty strings
 * - Consider the null terminator as part of the search
 * - Return type should be char* for string operations
 * - Be careful with pointer arithmetic
 */
char *ft_strchr(const char *s, int c);

/**
 * @brief Finds the last occurrence of a character in a string.
 *
 * Useful for searching or parsing strings from the end.
 *
 * @param s The string to search.
 * @param c The character to find.
 * @return Pointer to the last occurrence or NULL if not found.
 *
 * @code
 * char *p = ft_strrchr("Hello", 'l'); // p points to "lo"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle empty strings
 * - Consider the null terminator as part of the search
 * - Return type should be char* for string operations
 * - Be careful with pointer arithmetic
 * - Consider performance for long strings
 */
char *ft_strrchr(const char *s, int c);

/**
 * @brief Compares two strings up to n characters.
 *
 * Useful for sorting or checking string equality with a limit.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Maximum number of characters to compare.
 * @return 0 if equal, <0 if s1 < s2, >0 if s1 > s2.
 *
 * @code
 * int cmp = ft_strncmp("abc", "abd", 2); // cmp == 0
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle n = 0 case
 * - Handle strings shorter than n
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Handle unsigned char comparison
 */
int ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Sets a block of memory to a specific value.
 *
 * Useful for initializing arrays or buffers.
 *
 * @param b Pointer to the memory area.
 * @param c Value to set (converted to unsigned char).
 * @param len Number of bytes to set.
 * @return Pointer to the memory area b.
 *
 * @code
 * char buf[10];
 * ft_memset(buf, 0, 10); // All bytes set to 0
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle len = 0 case
 * - Consider performance for large blocks
 * - Be careful with pointer arithmetic
 * - Handle alignment issues
 * - Consider using word-sized operations for speed
 */
void *ft_memset(void *b, int c, size_t len);

/**
 * @brief Sets a block of memory to zero.
 *
 * Useful for clearing buffers or structures.
 *
 * @param s Pointer to the memory area.
 * @param n Number of bytes to set to zero.
 *
 * @code
 * char buf[10];
 * ft_bzero(buf, 10); // All bytes set to 0
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle n = 0 case
 * - Consider performance for large blocks
 * - Be careful with pointer arithmetic
 * - Handle alignment issues
 * - Consider using word-sized operations for speed
 */
void ft_bzero(void *s, size_t n);

/**
 * @brief Copies memory from source to destination.
 *
 * Useful for duplicating data or moving blocks of memory.
 *
 * @param dst Destination buffer.
 * @param src Source buffer.
 * @param n Number of bytes to copy.
 * @return Pointer to dst.
 *
 * @note Undefined behavior if src or dst is NULL and n > 0.
 *
 * @code
 * char src[] = "abc";
 * char dst[4];
 * ft_memcpy(dst, src, 4); // Copies "abc\0"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle n = 0 case
 * - Consider performance for large blocks
 * - Be careful with pointer arithmetic
 * - Handle alignment issues
 * - Consider using word-sized operations for speed
 * - Handle overlapping memory regions (use memmove instead)
 */
void *ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Moves memory from source to destination, safe for overlapping regions.
 *
 * Useful for shifting data within the same buffer.
 *
 * @param dst Destination buffer.
 * @param src Source buffer.
 * @param len Number of bytes to move.
 * @return Pointer to dst.
 *
 * @code
 * char buf[] = "abcdef";
 * ft_memmove(buf + 2, buf, 4); // buf == "ababcd"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle len = 0 case
 * - Consider performance for large blocks
 * - Be careful with pointer arithmetic
 * - Handle alignment issues
 * - Consider using word-sized operations for speed
 * - Handle overlapping memory regions correctly
 * - Consider direction of copy for overlapping regions
 */
void *ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Copies a string with size limitation.
 *
 * Useful for safe string copying to avoid buffer overflows.
 *
 * @param dst Destination buffer.
 * @param src Source string.
 * @param dstsize Size of the destination buffer.
 * @return Total length of the string it tried to create (length of src).
 *
 * @code
 * char buf[5];
 * size_t n = ft_strlcpy(buf, "Hello", 5); // buf == "Hell", n == 5
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle dstsize = 0 case
 * - Always null-terminate the destination
 * - Return the length of src
 * - Don't write beyond dstsize - 1
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 */
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Concatenates strings with size limitation.
 *
 * Useful for safe string concatenation to avoid buffer overflows.
 *
 * @param dst Destination buffer (must be null-terminated).
 * @param src Source string.
 * @param dstsize Total size of the destination buffer.
 * @return Total length of the string it tried to create (initial length of dst + length of src).
 *
 * @code
 * char buf[10] = "Hi";
 * size_t n = ft_strlcat(buf, " there", 10); // buf == "Hi there", n == 8
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle dstsize = 0 case
 * - Always null-terminate the destination
 * - Return the length of src + initial length of dst
 * - Don't write beyond dstsize - 1
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Handle case where dst is not null-terminated
 */
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Locates a substring in a string, up to a maximum length.
 *
 * Useful for searching for substrings in a buffer.
 *
 * @param haystack The string to search in.
 * @param needle The substring to find.
 * @param len Maximum number of characters to search.
 * @return Pointer to the first occurrence or NULL if not found.
 *
 * @code
 * char *p = ft_strnstr("Hello world", "world", 11); // p points to "world"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle empty needle string
 * - Handle len = 0 case
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Handle case where needle is longer than haystack
 * - Consider using efficient string matching algorithms
 */
char *ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Searches for a byte in a block of memory.
 *
 * Useful for binary data processing.
 *
 * @param s Memory area to search.
 * @param c Byte to find.
 * @param n Number of bytes to search.
 * @return Pointer to the first occurrence or NULL if not found.
 *
 * @code
 * char buf[] = {1, 2, 3, 4};
 * void *p = ft_memchr(buf, 3, 4); // p points to buf[2]
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle n = 0 case
 * - Consider performance for large blocks
 * - Be careful with pointer arithmetic
 * - Handle alignment issues
 * - Consider using word-sized operations for speed
 * - Handle unsigned char comparison
 */
void *ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares two blocks of memory.
 *
 * Useful for checking equality of binary data.
 *
 * @param s1 First memory area.
 * @param s2 Second memory area.
 * @param n Number of bytes to compare.
 * @return 0 if equal, <0 if s1 < s2, >0 if s1 > s2.
 *
 * @code
 * int cmp = ft_memcmp("abc", "abd", 2); // cmp == 0
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle n = 0 case
 * - Consider performance for large blocks
 * - Be careful with pointer arithmetic
 * - Handle alignment issues
 * - Consider using word-sized operations for speed
 * - Handle unsigned char comparison
 */
int ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocates memory for an array and initializes it to zero.
 *
 * Useful for creating arrays or buffers with all elements set to zero.
 *
 * @param count Number of elements.
 * @param size Size of each element.
 * @return Pointer to the allocated memory, or NULL on failure.
 *
 * @code
 * int *arr = (int *)ft_calloc(10, sizeof(int));
 * // arr[0..9] == 0
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle count = 0 or size = 0
 * - Handle overflow in count * size
 * - Initialize all bytes to zero
 * - Return NULL on failure
 * - Consider alignment requirements
 * - Handle large allocations
 * - Check for memory leaks in error cases
 */
void *ft_calloc(size_t count, size_t size);

/**
 * @brief Duplicates a string by allocating new memory.
 *
 * Useful for making a copy of a string that can be modified or freed independently.
 *
 * @param s1 The string to duplicate.
 * @return Pointer to the new string, or NULL on failure.
 *
 * @code
 * char *copy = ft_strdup("Hello");
 * // copy == "Hello"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Allocate enough memory for string + null terminator
 * - Return NULL on failure
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Check for memory leaks in error cases
 * - Handle empty strings
 */
char *ft_strdup(const char *s1);

/**
 * @brief Extracts a substring from a string.
 *
 * Useful for parsing or manipulating parts of a string.
 *
 * @param s The source string.
 * @param start Starting index.
 * @param len Maximum length of the substring.
 * @return Pointer to the new substring, or NULL on failure.
 *
 * @code
 * char *sub = ft_substr("Hello", 1, 3); // sub == "ell"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle start beyond string length
 * - Handle len beyond string length
 * - Allocate only necessary memory
 * - Return NULL on failure
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Check for memory leaks in error cases
 * - Handle empty strings
 */
char *ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Joins two strings into a new string.
 *
 * Useful for concatenating strings with dynamic memory allocation.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @return Pointer to the new string, or NULL on failure.
 *
 * @code
 * char *joined = ft_strjoin("Hello", " world"); // joined == "Hello world"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Allocate enough memory for both strings + null terminator
 * - Return NULL on failure
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Check for memory leaks in error cases
 * - Handle empty strings
 * - Handle string overflow
 */
char *ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trims characters from the beginning and end of a string.
 *
 * Useful for removing unwanted characters (like whitespace) from input.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return Pointer to the trimmed string, or NULL on failure.
 *
 * @code
 * char *trimmed = ft_strtrim("  Hello  ", " "); // trimmed == "Hello"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle empty strings
 * - Handle empty set
 * - Allocate only necessary memory
 * - Return NULL on failure
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Check for memory leaks in error cases
 * - Handle strings with only trim characters
 */
char *ft_strtrim(char const *s1, char const *set);

/**
 * @brief Splits a string into an array of strings using a delimiter.
 *
 * Useful for parsing CSV, command-line arguments, or any delimited data.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return Array of strings, terminated by NULL. NULL on failure.
 *
 * @code
 * char **words = ft_split("a,b,c", ',');
 * // words[0] == "a", words[1] == "b", words[2] == "c", words[3] == NULL
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle empty strings
 * - Handle strings with no delimiters
 * - Handle consecutive delimiters
 * - Handle delimiter at start/end
 * - Allocate memory for array and each string
 * - Return NULL on failure
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Check for memory leaks in error cases
 * - Handle string overflow
 * - Free all allocated memory on failure
 */
char **ft_split(char const *s, char c);

/**
 * @brief Converts an integer to a string.
 *
 * Useful for displaying numbers or writing them to files.
 *
 * @param n The integer to convert.
 * @return Pointer to the new string, or NULL on failure.
 *
 * @code
 * char *s = ft_itoa(42); // s == "42"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle negative numbers
 * - Handle zero
 * - Handle INT_MIN
 * - Allocate enough memory for the string
 * - Return NULL on failure
 * - Consider performance
 * - Be careful with pointer arithmetic
 * - Check for memory leaks in error cases
 * - Handle string overflow
 */
char *ft_itoa(int n);

/**
 * @brief Applies a function to each character of a string, creating a new string.
 *
 * Useful for mapping or transforming strings.
 *
 * @param s The source string.
 * @param f The function to apply (takes index and character).
 * @return Pointer to the new string, or NULL on failure.
 *
 * @code
 * char to_upper(unsigned int i, char c) { (void)i; return ft_toupper(c); }
 * char *upper = ft_strmapi("abc", to_upper); // upper == "ABC"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle empty strings
 * - Allocate enough memory for the string
 * - Return NULL on failure
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Check for memory leaks in error cases
 * - Handle function pointer NULL
 */
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies a function to each character of a string in place.
 *
 * Useful for modifying strings directly.
 *
 * @param s The string to modify.
 * @param f The function to apply (takes index and pointer to character).
 *
 * @code
 * void to_upper(unsigned int i, char *c) { (void)i; *c = ft_toupper(*c); }
 * char str[] = "abc";
 * ft_striteri(str, to_upper); // str == "ABC"
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL inputs
 * - Handle empty strings
 * - Consider performance for long strings
 * - Be careful with pointer arithmetic
 * - Handle function pointer NULL
 * - Handle string overflow
 */
void ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Writes a character to a file descriptor.
 *
 * Useful for outputting characters to files or standard output.
 *
 * @param c The character to write.
 * @param fd The file descriptor.
 *
 * @code
 * ft_putchar_fd('A', 1); // Writes 'A' to stdout
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle invalid file descriptor
 * - Handle write errors
 * - Consider performance for multiple writes
 * - Handle system call errors
 * - Handle character encoding
 */
void ft_putchar_fd(char c, int fd);

/**
 * @brief Writes a string to a file descriptor.
 *
 * Useful for outputting strings to files or standard output.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 *
 * @code
 * ft_putstr_fd("Hello", 1); // Writes "Hello" to stdout
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle invalid file descriptor
 * - Handle write errors
 * - Consider performance for long strings
 * - Handle system call errors
 * - Handle string encoding
 */
void ft_putstr_fd(char *s, int fd);

/**
 * @brief Writes a string followed by a newline to a file descriptor.
 *
 * Useful for outputting lines to files or standard output.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 *
 * @code
 * ft_putendl_fd("Hello", 1); // Writes "Hello\n" to stdout
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle NULL input
 * - Handle invalid file descriptor
 * - Handle write errors
 * - Consider performance for long strings
 * - Handle system call errors
 * - Handle string encoding
 * - Handle newline encoding
 */
void ft_putendl_fd(char *s, int fd);

/**
 * @brief Writes an integer as a string to a file descriptor.
 *
 * Useful for outputting numbers to files or standard output.
 *
 * @param n The integer to write.
 * @param fd The file descriptor.
 *
 * @code
 * ft_putnbr_fd(42, 1); // Writes "42" to stdout
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle negative numbers
 * - Handle INT_MIN
 * - Handle invalid file descriptor
 * - Handle write errors
 * - Consider performance
 * - Handle system call errors
 * - Handle number encoding
 */
void ft_putnbr_fd(int n, int fd);

/**
 * @brief Converts a character to uppercase.
 *
 * Useful for case-insensitive comparisons or formatting.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent if c is lowercase, otherwise c.
 *
 * @code
 * char up = ft_toupper('a'); // up == 'A'
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle non-alphabetic characters
 * - Consider performance for high-frequency calls
 * - Handle character encoding
 * - Return type should be int for compatibility
 */
int ft_toupper(int c);

/**
 * @brief Converts a character to lowercase.
 *
 * Useful for case-insensitive comparisons or formatting.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent if c is uppercase, otherwise c.
 *
 * @code
 * char low = ft_tolower('A'); // low == 'a'
 * @endcode
 *
 * @note Implementation Considerations:
 * - Handle non-alphabetic characters
 * - Consider performance for high-frequency calls
 * - Handle character encoding
 * - Return type should be int for compatibility
 */
int ft_tolower(int c);

/**
 * @brief Creates a new list element.
 *
 * @param content The content to be stored in the new element.
 * @return t_list* A pointer to the new element, or NULL if allocation fails.
 *
 * @code
 * t_list *new_node = ft_lstnew("Hello");
 * if (new_node) {
 *     // Use new_node
 *     free(new_node->content);
 *     free(new_node);
 * }
 * @endcode
 *
 * @note Memory for both the element and its content is allocated.
 */
t_list *ft_lstnew(void *content);

/**
 * @brief Adds a new element at the beginning of the list.
 *
 * @param lst A pointer to the first element of the list.
 * @param new The new element to add.
 *
 * @code
 * t_list *list = NULL;
 * t_list *new_node = ft_lstnew("Hello");
 * ft_lstadd_front(&list, new_node);
 * @endcode
 *
 * @note The new element becomes the first element of the list.
 */
void ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 *
 * @param lst The beginning of the list.
 * @return int The number of elements in the list.
 *
 * @code
 * t_list *list = NULL;
 * // Add elements to list
 * int size = ft_lstsize(list);
 * @endcode
 *
 * @note Returns 0 if the list is empty.
 */
int ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The beginning of the list.
 * @return t_list* A pointer to the last element, or NULL if the list is empty.
 *
 * @code
 * t_list *list = NULL;
 * // Add elements to list
 * t_list *last = ft_lstlast(list);
 * @endcode
 *
 * @note Returns NULL if the list is empty.
 */
t_list *ft_lstlast(t_list *lst);

/**
 * @brief Adds a new element at the end of the list.
 *
 * @param lst A pointer to the first element of the list.
 * @param new The new element to add.
 *
 * @code
 * t_list *list = NULL;
 * t_list *new_node = ft_lstnew("Hello");
 * ft_lstadd_back(&list, new_node);
 * @endcode
 *
 * @note The new element becomes the last element of the list.
 */
void ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes a single element from the list.
 *
 * @param lst The element to delete.
 * @param del A function to free the content of the element.
 *
 * @code
 * t_list *list = NULL;
 * // Add elements to list
 * ft_lstdelone(list, free);
 * @endcode
 *
 * @note The content of the element is freed using the del function.
 */
void ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the entire list.
 *
 * @param lst A pointer to the first element of the list.
 * @param del A function to free the content of each element.
 *
 * @code
 * t_list *list = NULL;
 * // Add elements to list
 * ft_lstclear(&list, free);
 * @endcode
 *
 * @note The content of each element is freed using the del function.
 */
void ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates through the list and applies a function to each element.
 *
 * @param lst The beginning of the list.
 * @param f A function to apply to each element.
 *
 * @code
 * t_list *list = NULL;
 * // Add elements to list
 * ft_lstiter(list, print_content);
 * @endcode
 *
 * @note The function f is applied to the content of each element.
 */
void ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Creates a new list resulting from applying a function to each element.
 *
 * @param lst The beginning of the list.
 * @param f A function to apply to each element.
 * @param del A function to free the content of an element if allocation fails.
 * @return t_list* A pointer to the new list, or NULL if allocation fails.
 *
 * @code
 * t_list *list = NULL;
 * // Add elements to list
 * t_list *new_list = ft_lstmap(list, duplicate_content, free);
 * @endcode
 *
 * @note The content of each element is duplicated using the function f.
 */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif 