# Building Unit Tests for libft

This guide explains how to create and run unit tests for the libft library using the Unity testing framework.

## Table of Contents
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Writing Tests](#writing-tests)
- [Test Categories](#test-categories)
- [Best Practices](#best-practices)
- [Debugging](#debugging)
- [Common Issues](#common-issues)
- [Resources](#resources)

## Prerequisites

- GCC compiler (version 4.2.1 or higher)
- Make (version 3.81 or higher)
- Unity testing framework (included in this project)
- Basic understanding of C programming
- Familiarity with libft functions

## Project Structure

```
libft_tests/
├── unity/           # Unity testing framework
├── test_libft.c     # Main test file
├── Makefile         # Build configuration
├── libft_docs.h     # Function documentation
├── testing_guide.md # This guide
└── docs/           # Additional documentation
```

## Getting Started

1. **Setup Your Environment**
```bash
# Clone the test suite
git clone https://github.com/Dino-Lu/libft-tests.git libft_tests

# Navigate to the test directory
cd libft_tests

# Build the test suite
make
```

2. **Basic Test Structure**
```c
#include "unity.h"
#include "../Libft/libft.h"

void setUp(void) {
    // Setup code (runs before each test)
}

void tearDown(void) {
    // Cleanup code (runs after each test)
}

void test_function_name(void) {
    // Test implementation
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_name);
    return UNITY_END();
}
```

## Writing Tests

### 1. Test Function Structure
```c
void test_function_name_scenario(void) {
    // Arrange: Set up test data
    char *input = "test";
    
    // Act: Call the function being tested
    char *result = ft_strdup(input);
    
    // Assert: Verify the results
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(input, result);
    
    // Cleanup: Free allocated memory
    free(result);
}
```

### 2. Available Assertions
```c
// Basic assertions
TEST_ASSERT_EQUAL(expected, actual);
TEST_ASSERT_EQUAL_STRING(expected, actual);
TEST_ASSERT_NULL(pointer);
TEST_ASSERT_NOT_NULL(pointer);
TEST_ASSERT_TRUE(condition);
TEST_ASSERT_FALSE(condition);

// Memory assertions
TEST_ASSERT_EQUAL_MEMORY(expected, actual, length);
TEST_ASSERT_EQUAL_MEMORY_ARRAY(expected, actual, element_size, length);

// String assertions
TEST_ASSERT_EQUAL_STRING_LEN(expected, actual, length);
TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, length);

// Custom messages
TEST_ASSERT_EQUAL_MESSAGE(expected, actual, "Custom error message");
```

## Test Categories

### 1. Character Functions
```c
void test_isalpha(void) {
    TEST_ASSERT_TRUE(ft_isalpha('A'));
    TEST_ASSERT_TRUE(ft_isalpha('z'));
    TEST_ASSERT_FALSE(ft_isalpha('1'));
    TEST_ASSERT_FALSE(ft_isalpha('@'));
}
```

### 2. String Functions
```c
void test_strlen(void) {
    TEST_ASSERT_EQUAL(5, ft_strlen("Hello"));
    TEST_ASSERT_EQUAL(0, ft_strlen(""));
    TEST_ASSERT_EQUAL(1, ft_strlen("A"));
}
```

### 3. Memory Functions
```c
void test_memset(void) {
    char buffer[10];
    ft_memset(buffer, 'A', 5);
    
    for (int i = 0; i < 5; i++)
        TEST_ASSERT_EQUAL('A', buffer[i]);
    TEST_ASSERT_EQUAL('\0', buffer[5]);
}
```

### 4. List Functions (Bonus)
```c
void test_lstnew(void) {
    char *content = "test";
    t_list *node = ft_lstnew(content);
    
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL_PTR(content, node->content);
    TEST_ASSERT_NULL(node->next);
    
    free(node);
}
```

## Best Practices

### 1. Test Organization
- Group related tests together
- Use descriptive test names
- Follow the pattern: `test_function_name_scenario`
- Include edge cases and error conditions

### 2. Memory Management
- Always free allocated memory
- Use `setUp` and `tearDown` for common operations
- Check for memory leaks using `valgrind`
- Handle allocation failures

### 3. Edge Cases
- NULL pointers
- Empty strings
- Boundary values
- Invalid inputs
- Memory limits

### 4. Performance Considerations
- Keep tests focused and fast
- Avoid unnecessary setup/teardown
- Use appropriate assertions
- Consider test execution time

## Debugging

### 1. Using Print Statements
```c
void test_function(void) {
    printf("Debug: Input: %s\n", input);
    printf("Debug: Result: %s\n", result);
}
```

### 2. Using Unity's Debug Features
```c
// Enable verbose output
#define UNITY_INCLUDE_DOUBLE
#define UNITY_DOUBLE_PRECISION 1e-12

// Use custom messages
TEST_ASSERT_EQUAL_MESSAGE(expected, actual, "Detailed error message");
```

### 3. Using Valgrind
```bash
valgrind --leak-check=full ./test_libft
```

## Common Issues

### 1. Segmentation Faults
- Check NULL pointer dereferences
- Verify memory allocation
- Ensure proper string termination
- Check array bounds

### 2. Memory Leaks
- Use `valgrind` to detect leaks
- Free all allocated memory
- Check cleanup in error cases
- Verify list operations

### 3. Test Failures
- Compare expected vs actual values
- Check edge cases
- Review function documentation
- Verify test assumptions

## Resources

- [Unity Documentation](https://github.com/ThrowTheSwitch/Unity)
- [libft Documentation](docs/html/index.html)
- [C Unit Testing Best Practices](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md)
- [Valgrind Documentation](https://valgrind.org/docs/manual/manual.html)