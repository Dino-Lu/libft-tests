#include "../Libft/libft.h"
#include "unity/unity.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

// Unity requires these even if empty
void setUp(void) {}
void tearDown(void) {}

// Helper function to check for memory leaks
void check_memory_leaks(void) {
    printf("Starting memory leak check...\n");
    #ifdef __APPLE__
        printf("Running leaks command...\n");
        // Wait a moment to ensure all memory is freed
        usleep(100000);  // 100ms delay
        int result = system("leaks test_libft_bonus > /dev/null");
        if (result != 0) {
            printf("Memory leaks detected!\n");
        } else {
            printf("No memory leaks detected.\n");
        }
    #elif defined(__linux__)
        printf("Running valgrind...\n");
        int result = system("valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./test_libft_bonus > /dev/null");
        if (result != 0) {
            printf("Valgrind command failed with status %d\n", result);
            return;
        }
        
        FILE *fp = fopen("valgrind-out.txt", "r");
        if (!fp) {
            printf("Failed to open valgrind output file\n");
            return;
        }
        
        char line[256];
        int leaks_found = 0;
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "definitely lost:") || 
                strstr(line, "indirectly lost:") || 
                strstr(line, "possibly lost:")) {
                if (strstr(line, "0 bytes")) continue;
                leaks_found = 1;
                printf("Memory Leak Detected: %s", line);
            }
        }
        fclose(fp);
        
        if (!leaks_found) {
            printf("No memory leaks detected.\n");
        }
        
        if (unlink("valgrind-out.txt") != 0) {
            printf("Warning: Failed to remove valgrind output file\n");
        }
    #endif
    printf("Memory leak check completed.\n");
}

// Helper function to measure execution time
double measure_time(void (*test_func)(void)) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    test_func();
    gettimeofday(&end, NULL);
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

// Helper function to create a temporary file
int create_temp_file(const char *content) {
    int fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd != -1) {
        write(fd, content, strlen(content));
        close(fd);
    }
    return fd;
}

// Helper function for detailed error reporting
void report_error(const char *test_name, const char *expected, const char *actual) {
    printf("\nTest Failed: %s\n", test_name);
    printf("Expected: %s\n", expected);
    printf("Actual: %s\n", actual);
}

// Character functions tests
void test_isalpha(void) {
    TEST_ASSERT_EQUAL(1, ft_isalpha('a'));
    TEST_ASSERT_EQUAL(1, ft_isalpha('Z'));
    TEST_ASSERT_EQUAL(0, ft_isalpha('1'));
    TEST_ASSERT_EQUAL(0, ft_isalpha('@'));
    TEST_ASSERT_EQUAL(0, ft_isalpha('\0'));
    TEST_ASSERT_EQUAL(0, ft_isalpha(-1));
    TEST_ASSERT_EQUAL(0, ft_isalpha(128));
}

void test_isdigit(void) {
    TEST_ASSERT_EQUAL(1, ft_isdigit('0'));
    TEST_ASSERT_EQUAL(1, ft_isdigit('9'));
    TEST_ASSERT_EQUAL(0, ft_isdigit('a'));
    TEST_ASSERT_EQUAL(0, ft_isdigit('@'));
    TEST_ASSERT_EQUAL(0, ft_isdigit('\0'));
    TEST_ASSERT_EQUAL(0, ft_isdigit(-1));
    TEST_ASSERT_EQUAL(0, ft_isdigit(128));
}

void test_isalnum(void) {
    TEST_ASSERT_EQUAL(1, ft_isalnum('a'));
    TEST_ASSERT_EQUAL(1, ft_isalnum('Z'));
    TEST_ASSERT_EQUAL(1, ft_isalnum('0'));
    TEST_ASSERT_EQUAL(0, ft_isalnum('@'));
    TEST_ASSERT_EQUAL(0, ft_isalnum('\0'));
    TEST_ASSERT_EQUAL(0, ft_isalnum(-1));
    TEST_ASSERT_EQUAL(0, ft_isalnum(128));
}

void test_isascii(void) {
    TEST_ASSERT_EQUAL(1, ft_isascii(0));
    TEST_ASSERT_EQUAL(1, ft_isascii(127));
    TEST_ASSERT_EQUAL(0, ft_isascii(128));
    TEST_ASSERT_EQUAL(0, ft_isascii(-1));
}

void test_isprint(void) {
    TEST_ASSERT_EQUAL(1, ft_isprint(' '));
    TEST_ASSERT_EQUAL(1, ft_isprint('~'));
    TEST_ASSERT_EQUAL(0, ft_isprint('\t'));
    TEST_ASSERT_EQUAL(0, ft_isprint('\0'));
    TEST_ASSERT_EQUAL(0, ft_isprint(128));
}

// String functions tests
void test_strlen(void) {
    TEST_ASSERT_EQUAL(0, ft_strlen(""));
    TEST_ASSERT_EQUAL(5, ft_strlen("Hello"));
    TEST_ASSERT_EQUAL(1, ft_strlen("A"));
    TEST_ASSERT_EQUAL(100, ft_strlen("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
    TEST_ASSERT_EQUAL(5, ft_strlen("Hello"));
}

void test_memset(void) {
    char str[10] = "Hello";
    void *result = ft_memset(str, 'A', 5);
    TEST_ASSERT_EQUAL_STRING("AAAAA", str);
    TEST_ASSERT_EQUAL_PTR(str, result);
    
    // Test with zero length
    char str2[10] = "Hello";
    result = ft_memset(str2, 'A', 0);
    TEST_ASSERT_EQUAL_STRING("Hello", str2);
}

void test_bzero(void) {
    char str[10] = "Hello";
    ft_bzero(str, 5);
    TEST_ASSERT_EQUAL(0, str[0]);
    TEST_ASSERT_EQUAL(0, str[4]);
    
    // Test with zero length
    char str2[10] = "Hello";
    ft_bzero(str2, 0);
    TEST_ASSERT_EQUAL_STRING("Hello", str2);
}

void test_memcpy(void) {
    char src[] = "Hello";
    char dest[10];
    void *result = ft_memcpy(dest, src, 6);
    TEST_ASSERT_EQUAL_STRING("Hello", dest);
    TEST_ASSERT_EQUAL_PTR(dest, result);
    
    // Test with zero length
    char dest2[10] = "World";
    result = ft_memcpy(dest2, src, 0);
    TEST_ASSERT_EQUAL_STRING("World", dest2);
}

void test_memmove(void) {
    char str[] = "Hello";
    void *result = ft_memmove(str + 1, str, 4);
    TEST_ASSERT_EQUAL_STRING("HHell", str);
    TEST_ASSERT_EQUAL_PTR(str + 1, result);
    
    // Test with zero length
    char str2[] = "Hello";
    result = ft_memmove(str2 + 1, str2, 0);
    TEST_ASSERT_EQUAL_STRING("Hello", str2);
}

void test_strlcpy(void) {
    char dest[10];
    const char *src = "Hello";
    size_t result = ft_strlcpy(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("Hello", dest);
    TEST_ASSERT_EQUAL(5, result);
    
    // Test with zero size
    TEST_ASSERT_EQUAL(5, ft_strlcpy(dest, src, 0));
}

void test_strlcat(void) {
    char dest[20] = "Hello";
    const char *src = "World";
    size_t result = ft_strlcat(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("HelloWorld", dest);
    TEST_ASSERT_EQUAL(10, result);
    
    // Test with zero size
    TEST_ASSERT_EQUAL(5, ft_strlcat(dest, src, 0));
}

void test_toupper(void) {
    TEST_ASSERT_EQUAL('A', ft_toupper('a'));
    TEST_ASSERT_EQUAL('Z', ft_toupper('z'));
    TEST_ASSERT_EQUAL('A', ft_toupper('A'));
    TEST_ASSERT_EQUAL('1', ft_toupper('1'));
    TEST_ASSERT_EQUAL('@', ft_toupper('@'));
}

void test_tolower(void) {
    TEST_ASSERT_EQUAL('a', ft_tolower('A'));
    TEST_ASSERT_EQUAL('z', ft_tolower('Z'));
    TEST_ASSERT_EQUAL('a', ft_tolower('a'));
    TEST_ASSERT_EQUAL('1', ft_tolower('1'));
    TEST_ASSERT_EQUAL('@', ft_tolower('@'));
}

void test_strchr(void) {
    const char *str = "Hello";
    TEST_ASSERT_EQUAL_STRING("ello", ft_strchr(str, 'e'));
    TEST_ASSERT_EQUAL_STRING("o", ft_strchr(str, 'o'));
    TEST_ASSERT_NULL(ft_strchr(str, 'x'));
    TEST_ASSERT_EQUAL_STRING("", ft_strchr(str, '\0'));
}

void test_strrchr(void) {
    const char *str = "Hello";
    TEST_ASSERT_EQUAL_STRING("ello", ft_strrchr(str, 'e'));
    TEST_ASSERT_EQUAL_STRING("o", ft_strrchr(str, 'o'));
    TEST_ASSERT_NULL(ft_strrchr(str, 'x'));
    TEST_ASSERT_EQUAL_STRING("", ft_strrchr(str, '\0'));
}

void test_strncmp(void) {
    TEST_ASSERT_EQUAL(0, ft_strncmp("Hello", "Hello", 5));
    TEST_ASSERT_EQUAL(0, ft_strncmp("Hello", "Hello", 3));
    TEST_ASSERT(ft_strncmp("Hello", "World", 5) < 0);
    TEST_ASSERT(ft_strncmp("World", "Hello", 5) > 0);
    TEST_ASSERT_EQUAL(0, ft_strncmp("Hello", "World", 0));
}

void test_memchr(void) {
    const char *str = "Hello";
    TEST_ASSERT_EQUAL_STRING("ello", ft_memchr(str, 'e', 5));
    TEST_ASSERT_EQUAL_STRING("o", ft_memchr(str, 'o', 5));
    TEST_ASSERT_NULL(ft_memchr(str, 'x', 5));
    TEST_ASSERT_NULL(ft_memchr(str, 'e', 0));
}

void test_memcmp(void) {
    TEST_ASSERT_EQUAL(0, ft_memcmp("Hello", "Hello", 5));
    TEST_ASSERT_EQUAL(0, ft_memcmp("Hello", "Hello", 3));
    TEST_ASSERT(ft_memcmp("Hello", "World", 5) < 0);
    TEST_ASSERT(ft_memcmp("World", "Hello", 5) > 0);
    TEST_ASSERT_EQUAL(0, ft_memcmp("Hello", "World", 0));
}

void test_strnstr(void) {
    const char *big = "Hello World";
    TEST_ASSERT_EQUAL_STRING("World", ft_strnstr(big, "World", 11));
    TEST_ASSERT_EQUAL_STRING("World", ft_strnstr(big, "World", 20));
    TEST_ASSERT_NULL(ft_strnstr(big, "World", 5));
    TEST_ASSERT_EQUAL_STRING("Hello World", ft_strnstr(big, "", 11));
}

void test_atoi(void) {
    TEST_ASSERT_EQUAL(0, ft_atoi("0"));
    TEST_ASSERT_EQUAL(42, ft_atoi("42"));
    TEST_ASSERT_EQUAL(-42, ft_atoi("-42"));
    TEST_ASSERT_EQUAL(42, ft_atoi("+42"));
    TEST_ASSERT_EQUAL(0, ft_atoi(""));
    TEST_ASSERT_EQUAL(0, ft_atoi("abc"));
    TEST_ASSERT_EQUAL(2147483647, ft_atoi("2147483647"));
    TEST_ASSERT_EQUAL(-2147483648, ft_atoi("-2147483648"));
}

void test_calloc(void) {
    int *arr = ft_calloc(5, sizeof(int));
    TEST_ASSERT_NOT_NULL(arr);
    for (int i = 0; i < 5; i++) {
        TEST_ASSERT_EQUAL(0, arr[i]);
    }
    free(arr);
    
    // Test with zero
    void *ptr = ft_calloc(0, 5);
    if (ptr) {
        free(ptr);
    }
    ptr = ft_calloc(5, 0);
    if (ptr) {
        free(ptr);
    }
    
    // Test with overflow
    TEST_ASSERT_NULL(ft_calloc(SIZE_MAX, SIZE_MAX));
}

void test_strdup(void) {
    char *str1 = ft_strdup("Hello");
    TEST_ASSERT_NOT_NULL(str1);
    TEST_ASSERT_EQUAL_STRING("Hello", str1);
    free(str1);

    char *str2 = ft_strdup("");
    TEST_ASSERT_NOT_NULL(str2);
    TEST_ASSERT_EQUAL_STRING("", str2);
    free(str2);

    char *str3 = ft_strdup("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    TEST_ASSERT_NOT_NULL(str3);
    TEST_ASSERT_EQUAL_STRING("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", str3);
    free(str3);
}

void test_substr(void) {
    const char *str = "Hello World";
    char *sub = ft_substr(str, 6, 5);
    TEST_ASSERT_EQUAL_STRING("World", sub);
    free(sub);
    
    // Test with NULL
    TEST_ASSERT_NULL(ft_substr(NULL, 0, 5));
    
    // Test with invalid start
    sub = ft_substr(str, 20, 5);
    TEST_ASSERT_EQUAL_STRING("", sub);
    free(sub);
    
    // Test with zero length
    sub = ft_substr(str, 0, 0);
    TEST_ASSERT_EQUAL_STRING("", sub);
    free(sub);
}

void test_strjoin(void) {
    const char *s1 = "Hello";
    const char *s2 = "World";
    char *joined = ft_strjoin(s1, s2);
    TEST_ASSERT_EQUAL_STRING("HelloWorld", joined);
    free(joined);
    
    // Test with NULL
    TEST_ASSERT_NULL(ft_strjoin(NULL, s2));
    TEST_ASSERT_NULL(ft_strjoin(s1, NULL));
    
    // Test with empty strings
    joined = ft_strjoin("", "");
    TEST_ASSERT_EQUAL_STRING("", joined);
    free(joined);
}

void test_strtrim(void) {
    const char *str = "  Hello World  ";
    const char *set = " ";
    char *trimmed = ft_strtrim(str, set);
    TEST_ASSERT_EQUAL_STRING("Hello World", trimmed);
    free(trimmed);
    
    // Test with NULL
    TEST_ASSERT_NULL(ft_strtrim(NULL, set));
    TEST_ASSERT_NULL(ft_strtrim(str, NULL));
    
    // Test with empty string
    trimmed = ft_strtrim("", set);
    TEST_ASSERT_EQUAL_STRING("", trimmed);
    free(trimmed);
}

void test_split(void) {
    char **result;
    
    // Test with normal string
    result = ft_split("Hello World", ' ');
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("Hello", result[0]);
    TEST_ASSERT_EQUAL_STRING("World", result[1]);
    TEST_ASSERT_NULL(result[2]);
    free(result[0]);
    free(result[1]);
    free(result);

    // Test with empty string
    result = ft_split("", ' ');
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_NULL(result[0]);
    free(result);

    // Test with multiple delimiters
    result = ft_split("Hello   World", ' ');
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("Hello", result[0]);
    TEST_ASSERT_EQUAL_STRING("World", result[1]);
    TEST_ASSERT_NULL(result[2]);
    free(result[0]);
    free(result[1]);
    free(result);

    // Test with no delimiters
    result = ft_split("HelloWorld", ' ');
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("HelloWorld", result[0]);
    TEST_ASSERT_NULL(result[1]);
    free(result[0]);
    free(result);

    // Test with NULL string
    result = ft_split(NULL, ' ');
    TEST_ASSERT_NULL(result);
}

void test_itoa(void) {
    char *str = ft_itoa(42);
    TEST_ASSERT_EQUAL_STRING("42", str);
    free(str);
    
    str = ft_itoa(-42);
    TEST_ASSERT_EQUAL_STRING("-42", str);
    free(str);
    
    str = ft_itoa(0);
    TEST_ASSERT_EQUAL_STRING("0", str);
    free(str);
    
    str = ft_itoa(2147483647);
    TEST_ASSERT_EQUAL_STRING("2147483647", str);
    free(str);
    
    str = ft_itoa(-2147483648);
    TEST_ASSERT_EQUAL_STRING("-2147483648", str);
    free(str);
}

char test_map(unsigned int i, char c) {
    (void)i;
    return c + 1;
}

void test_strmapi(void) {
    const char *str = "Hello";
    char *mapped = ft_strmapi(str, test_map);
    TEST_ASSERT_EQUAL_STRING("Ifmmp", mapped);
    free(mapped);
    
    // Test with empty string
    mapped = ft_strmapi("", test_map);
    TEST_ASSERT_EQUAL_STRING("", mapped);
    free(mapped);
}

// Helper for test_striteri
static void test_func(unsigned int i, char *c) {
    *c = *c + i;
}

void test_striteri(void) {
    char str[] = "Hello";
    ft_striteri(str, test_func);
    TEST_ASSERT_EQUAL_STRING("Hfnos", str);
}

void test_putchar_fd(void) {
    int fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    
    ft_putchar_fd('A', fd);
    close(fd);
    
    fd = open("temp.txt", O_RDONLY);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    char c;
    ssize_t bytes_read = read(fd, &c, 1);
    TEST_ASSERT_EQUAL(1, bytes_read);
    TEST_ASSERT_EQUAL('A', c);
    close(fd);
    unlink("temp.txt");
}

void test_putstr_fd(void) {
    int fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    
    ft_putstr_fd("Hello", fd);
    close(fd);
    
    fd = open("temp.txt", O_RDONLY);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    char str[10] = {0};
    ssize_t bytes_read = read(fd, str, 5);
    TEST_ASSERT_EQUAL(5, bytes_read);
    TEST_ASSERT_EQUAL_STRING("Hello", str);
    close(fd);
    unlink("temp.txt");
}

void test_putendl_fd(void) {
    int fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    
    ft_putendl_fd("Hello", fd);
    close(fd);
    
    fd = open("temp.txt", O_RDONLY);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    char str[10] = {0};
    ssize_t bytes_read = read(fd, str, 6);
    TEST_ASSERT_EQUAL(6, bytes_read);
    TEST_ASSERT_EQUAL_STRING("Hello\n", str);
    close(fd);
    unlink("temp.txt");
}

void test_putnbr_fd(void) {
    int fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    
    ft_putnbr_fd(42, fd);
    close(fd);
    
    fd = open("temp.txt", O_RDONLY);
    TEST_ASSERT_NOT_EQUAL(-1, fd);
    char str[10] = {0};
    ssize_t bytes_read = read(fd, str, 2);
    TEST_ASSERT_EQUAL(2, bytes_read);
    TEST_ASSERT_EQUAL_STRING("42", str);
    close(fd);
    unlink("temp.txt");
}

// Helper function to print section header
void print_section_header(const char *title) {
    printf("\n\033[1;35m=== %s ===\033[0m\n", title);
}

// Helper function to print test stage
void print_test_stage(const char *stage) {
    printf("\n\033[1;34m%s\033[0m\n", stage);
}

// Helper function to print test result
void print_test_result(const char *test_name, int passed) {
    if (passed) {
        printf("  \033[1;32m✓ %s\033[0m\n", test_name);
    } else {
        printf("  \033[1;31m✗ %s\033[0m\n", test_name);
    }
}

// Helper function to print performance result
void print_performance_result(const char *test_name, double time_taken) {
    printf("  \033[1;36m%s: %.6f seconds\033[0m\n", test_name, time_taken);
}

// Add performance test wrapper with error checking
void run_performance_test(const char *test_name, void (*test_func)(void)) {
    double time_taken = measure_time(test_func);
    print_performance_result(test_name, time_taken);
}

// Helper functions for list tests
static void modify_content(void *content) {
    char *str = (char *)content;
    str[0] = 'X';
}

static void *map_content(void *content) {
    char *str = (char *)content;
    char *new_str = strdup(str);
    new_str[0] = 'X';
    return new_str;
}

// Dummy free function for integer content
static void dummy_free(void *ptr) { (void)ptr; }

// Bonus list functions tests
void test_lstnew(void) {
    t_list *node;
    
    // Test with normal content
    int content = 42;
    node = ft_lstnew(&content);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL_PTR(&content, node->content);
    TEST_ASSERT_NULL(node->next);
    free(node);
    
    // Test with NULL content
    node = ft_lstnew(NULL);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_NULL(node->content);
    TEST_ASSERT_NULL(node->next);
    free(node);
    
    // Test with string content
    char *str = strdup("test");
    node = ft_lstnew(str);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL_STRING("test", (char *)node->content);
    TEST_ASSERT_NULL(node->next);
    free(node->content);
    free(node);
}

void test_lstadd_front(void) {
    t_list *list = NULL;
    int content1 = 1;
    int content2 = 2;
    int content3 = 3;
    
    // Test adding to empty list
    t_list *node1 = ft_lstnew(&content1);
    ft_lstadd_front(&list, node1);
    TEST_ASSERT_EQUAL_PTR(node1, list);
    TEST_ASSERT_NULL(node1->next);
    
    // Test adding to non-empty list
    t_list *node2 = ft_lstnew(&content2);
    ft_lstadd_front(&list, node2);
    TEST_ASSERT_EQUAL_PTR(node2, list);
    TEST_ASSERT_EQUAL_PTR(node1, node2->next);
    TEST_ASSERT_NULL(node1->next);
    
    // Test adding multiple nodes
    t_list *node3 = ft_lstnew(&content3);
    ft_lstadd_front(&list, node3);
    TEST_ASSERT_EQUAL_PTR(node3, list);
    TEST_ASSERT_EQUAL_PTR(node2, node3->next);
    TEST_ASSERT_EQUAL_PTR(node1, node2->next);
    TEST_ASSERT_NULL(node1->next);
    
    // Clean up
    ft_lstclear(&list, dummy_free);
    
    // Test with NULL list pointer
    list = NULL;
    t_list *node4 = ft_lstnew(&content1);
    ft_lstadd_front(NULL, node4);
    free(node4);
    
    // Test with NULL new node
    list = NULL;
    ft_lstadd_front(&list, NULL);
    TEST_ASSERT_NULL(list);
}

void test_lstsize(void) {
    t_list *list = NULL;
    int content1 = 1;
    int content2 = 2;
    int content3 = 3;
    
    // Test empty list
    TEST_ASSERT_EQUAL(0, ft_lstsize(list));
    
    // Test single node
    t_list *node1 = ft_lstnew(&content1);
    list = node1;
    TEST_ASSERT_EQUAL(1, ft_lstsize(list));
    
    // Test multiple nodes
    t_list *node2 = ft_lstnew(&content2);
    t_list *node3 = ft_lstnew(&content3);
    node1->next = node2;
    node2->next = node3;
    TEST_ASSERT_EQUAL(3, ft_lstsize(list));
    
    // Clean up
    ft_lstclear(&list, dummy_free);
    
    // Test NULL list
    TEST_ASSERT_EQUAL(0, ft_lstsize(NULL));
}

void test_lstlast(void) {
    t_list *list = NULL;
    int content1 = 1;
    int content2 = 2;
    int content3 = 3;
    
    // Test empty list
    TEST_ASSERT_NULL(ft_lstlast(list));
    
    // Test single node
    t_list *node1 = ft_lstnew(&content1);
    list = node1;
    TEST_ASSERT_EQUAL_PTR(node1, ft_lstlast(list));
    
    // Test multiple nodes
    t_list *node2 = ft_lstnew(&content2);
    t_list *node3 = ft_lstnew(&content3);
    node1->next = node2;
    node2->next = node3;
    TEST_ASSERT_EQUAL_PTR(node3, ft_lstlast(list));
    
    // Clean up
    ft_lstclear(&list, dummy_free);
    
    // Test NULL list
    TEST_ASSERT_NULL(ft_lstlast(NULL));
}

void test_lstadd_back(void) {
    t_list *list = NULL;
    int content1 = 1;
    int content2 = 2;
    int content3 = 3;
    
    // Test adding to empty list
    t_list *node1 = ft_lstnew(&content1);
    ft_lstadd_back(&list, node1);
    TEST_ASSERT_EQUAL_PTR(node1, list);
    TEST_ASSERT_NULL(node1->next);
    
    // Test adding to non-empty list
    t_list *node2 = ft_lstnew(&content2);
    ft_lstadd_back(&list, node2);
    TEST_ASSERT_EQUAL_PTR(node1, list);
    TEST_ASSERT_EQUAL_PTR(node2, node1->next);
    TEST_ASSERT_NULL(node2->next);
    
    // Test adding multiple nodes
    t_list *node3 = ft_lstnew(&content3);
    ft_lstadd_back(&list, node3);
    TEST_ASSERT_EQUAL_PTR(node1, list);
    TEST_ASSERT_EQUAL_PTR(node2, node1->next);
    TEST_ASSERT_EQUAL_PTR(node3, node2->next);
    TEST_ASSERT_NULL(node3->next);
    
    // Clean up
    ft_lstclear(&list, dummy_free);
    
    // Test with NULL list pointer
    list = NULL;
    t_list *node4 = ft_lstnew(&content1);
    ft_lstadd_back(NULL, node4);
    free(node4);
    
    // Test with NULL new node
    list = NULL;
    ft_lstadd_back(&list, NULL);
    TEST_ASSERT_NULL(list);
}

void test_lstdelone(void) {
    // Test with normal node
    char *str1 = strdup("test1");
    t_list *node1 = ft_lstnew(str1);
    ft_lstdelone(node1, free);  // This frees both content and node
    
    // Test with NULL node
    ft_lstdelone(NULL, free);
    
    // Test with NULL del function
    char *str2 = strdup("test2");
    t_list *node2 = ft_lstnew(str2);
    ft_lstdelone(node2, NULL);  // This doesn't free anything
    free(str2);  // Free the content manually
    free(node2);  // Free the node manually
    
    // Test with integer content
    int content = 42;
    t_list *node3 = ft_lstnew(&content);
    ft_lstdelone(node3, dummy_free);  // This frees both content and node
}

void test_lstclear(void) {
    t_list *list = NULL;
    
    // Test with empty list
    ft_lstclear(&list, free);
    TEST_ASSERT_NULL(list);
    
    // Test with single node
    char *str1 = strdup("test1");
    t_list *node1 = ft_lstnew(str1);
    list = node1;
    ft_lstclear(&list, free);
    TEST_ASSERT_NULL(list);
    
    // Test with multiple nodes
    char *str2 = strdup("test2");
    char *str3 = strdup("test3");
    t_list *node2 = ft_lstnew(str2);
    t_list *node3 = ft_lstnew(str3);
    node2->next = node3;
    list = node2;
    ft_lstclear(&list, free);
    TEST_ASSERT_NULL(list);
    
    // Test with NULL list pointer
    ft_lstclear(NULL, free);
    
    // Test with NULL del function
    char *str4 = strdup("test4");
    node1 = ft_lstnew(str4);
    list = node1;
    ft_lstclear(&list, NULL);
    free(str4);
    free(node1);
}

void test_lstiter(void) {
    t_list *list = NULL;
    
    // Test with empty list
    ft_lstiter(list, NULL);
    
    // Test with single node
    char *str1 = strdup("test1");
    t_list *node1 = ft_lstnew(str1);
    list = node1;
    ft_lstiter(list, NULL);
    
    // Test with multiple nodes
    char *str2 = strdup("test2");
    char *str3 = strdup("test3");
    t_list *node2 = ft_lstnew(str2);
    t_list *node3 = ft_lstnew(str3);
    node1->next = node2;
    node2->next = node3;
    
    // Test with NULL function
    ft_lstiter(list, NULL);
    
    // Test with function
    ft_lstiter(list, modify_content);
    TEST_ASSERT_EQUAL_STRING("Xest1", (char *)node1->content);
    TEST_ASSERT_EQUAL_STRING("Xest2", (char *)node2->content);
    TEST_ASSERT_EQUAL_STRING("Xest3", (char *)node3->content);
    
    // Clean up
    ft_lstclear(&list, free);
}

void test_lstmap(void) {
    t_list *list = NULL;
    t_list *new_list = NULL;
    
    // Test with empty list
    TEST_ASSERT_NULL(ft_lstmap(NULL, NULL, NULL));
    
    // Test with single node
    char *str1 = strdup("test1");
    t_list *node1 = ft_lstnew(str1);
    list = node1;
    
    // Test with NULL functions
    TEST_ASSERT_NULL(ft_lstmap(list, NULL, NULL));
    
    // Test with function
    new_list = ft_lstmap(list, map_content, free);
    TEST_ASSERT_NOT_NULL(new_list);
    TEST_ASSERT_EQUAL_STRING("Xest1", (char *)new_list->content);
    TEST_ASSERT_NULL(new_list->next);
    
    ft_lstclear(&new_list, free);
    
    // Test with multiple nodes
    char *str2 = strdup("test2");
    char *str3 = strdup("test3");
    t_list *node2 = ft_lstnew(str2);
    t_list *node3 = ft_lstnew(str3);
    node1->next = node2;
    node2->next = node3;
    
    new_list = ft_lstmap(list, map_content, free);
    TEST_ASSERT_NOT_NULL(new_list);
    TEST_ASSERT_EQUAL_STRING("Xest1", (char *)new_list->content);
    TEST_ASSERT_NOT_NULL(new_list->next);
    TEST_ASSERT_EQUAL_STRING("Xest2", (char *)new_list->next->content);
    TEST_ASSERT_NOT_NULL(new_list->next->next);
    TEST_ASSERT_EQUAL_STRING("Xest3", (char *)new_list->next->next->content);
    TEST_ASSERT_NULL(new_list->next->next->next);
    
    // Clean up
    ft_lstclear(&new_list, free);
    ft_lstclear(&list, free);
}

void test_lstdelone_direct(void) {
    printf("\n=== Testing ft_lstdelone directly ===\n");
    
    // Test 1: Normal case with free
    printf("\nTest 1: Normal case with free\n");
    char *str1 = strdup("test1");
    t_list *node1 = ft_lstnew(str1);
    printf("Before: node1=%p, content=%s\n", (void*)node1, (char*)node1->content);
    ft_lstdelone(node1, free);
    printf("After: node1=%p\n", (void*)node1);
    
    // Test 2: NULL node
    printf("\nTest 2: NULL node\n");
    ft_lstdelone(NULL, free);
    printf("No crash with NULL node\n");
    
    // Test 3: NULL del function
    printf("\nTest 3: NULL del function\n");
    char *str2 = strdup("test2");
    t_list *node2 = ft_lstnew(str2);
    printf("Before: node2=%p, content=%s\n", (void*)node2, (char*)node2->content);
    ft_lstdelone(node2, NULL);
    printf("After: node2=%p, content=%s\n", (void*)node2, (char*)node2->content);
    free(str2);
    free(node2);
    
    // Test 4: Integer content with dummy_free
    printf("\nTest 4: Integer content with dummy_free\n");
    int content = 42;
    t_list *node3 = ft_lstnew(&content);
    printf("Before: node3=%p, content=%d\n", (void*)node3, *(int*)node3->content);
    ft_lstdelone(node3, dummy_free);
    printf("After: node3=%p\n", (void*)node3);
    
    printf("\n=== Direct test complete ===\n");
}

// Modify main to run tests in stages
int main(void) {
    UNITY_BEGIN();
    
    print_section_header("Running Standard Tests");
    
    // Stage 1: Basic character and string functions
    print_test_stage("Stage 1: Basic character and string functions");
    RUN_TEST(test_isalpha);
    RUN_TEST(test_isdigit);
    RUN_TEST(test_isalnum);
    RUN_TEST(test_isascii);
    RUN_TEST(test_isprint);
    RUN_TEST(test_strlen);
    RUN_TEST(test_memset);
    RUN_TEST(test_bzero);
    RUN_TEST(test_memcpy);
    RUN_TEST(test_memmove);
    RUN_TEST(test_strlcpy);
    RUN_TEST(test_strlcat);
    RUN_TEST(test_toupper);
    RUN_TEST(test_tolower);
    
    // Stage 2: String search and comparison functions
    print_test_stage("Stage 2: String search and comparison functions");
    RUN_TEST(test_strchr);
    RUN_TEST(test_strrchr);
    RUN_TEST(test_strncmp);
    RUN_TEST(test_memchr);
    RUN_TEST(test_memcmp);
    RUN_TEST(test_strnstr);
    RUN_TEST(test_atoi);
    
    // Stage 3: Memory allocation functions
    print_test_stage("Stage 3: Memory allocation functions");
    RUN_TEST(test_calloc);
    RUN_TEST(test_strdup);
    
    // Stage 4: String manipulation functions
    print_test_stage("Stage 4: String manipulation functions");
    RUN_TEST(test_substr);
    RUN_TEST(test_strjoin);
    RUN_TEST(test_strtrim);
    RUN_TEST(test_split);
    RUN_TEST(test_itoa);
    RUN_TEST(test_strmapi);
    RUN_TEST(test_striteri);
    
    // Stage 5: File descriptor functions
    print_test_stage("Stage 5: File descriptor functions");
    RUN_TEST(test_putchar_fd);
    RUN_TEST(test_putstr_fd);
    RUN_TEST(test_putendl_fd);
    RUN_TEST(test_putnbr_fd);
    
#ifdef BONUS
    // Stage 6: Bonus list functions
    print_test_stage("Stage 6: Bonus list functions");
    RUN_TEST(test_lstnew);
    RUN_TEST(test_lstadd_front);
    RUN_TEST(test_lstsize);
    RUN_TEST(test_lstlast);
    RUN_TEST(test_lstadd_back);
    RUN_TEST(test_lstdelone);
    RUN_TEST(test_lstclear);
    RUN_TEST(test_lstiter);
    RUN_TEST(test_lstmap);
#endif
    
    print_section_header("Running Performance Tests");
    
    // Performance tests for memory-intensive functions
    print_test_stage("Testing memory-intensive functions");
    run_performance_test("strdup", test_strdup);
    run_performance_test("split", test_split);
    run_performance_test("strjoin", test_strjoin);
    run_performance_test("substr", test_substr);
    run_performance_test("strtrim", test_strtrim);
    
    // Performance tests for string manipulation functions
    print_test_stage("Testing string manipulation functions");
    run_performance_test("strlen", test_strlen);
    run_performance_test("strchr", test_strchr);
    run_performance_test("strrchr", test_strrchr);
    run_performance_test("strncmp", test_strncmp);
    run_performance_test("strnstr", test_strnstr);
    
    print_section_header("Test Summary");
    printf("\033[1;32mAll tests completed successfully!\033[0m\n");
    
    return UNITY_END();
} 