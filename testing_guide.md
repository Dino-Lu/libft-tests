# Building Unit Tests for libft

This guide explains how to create and run unit tests for the libft library using the Unity testing framework.

## Prerequisites

- GCC compiler
- Make
- Unity testing framework (included in this project)

## Project Structure

```
libft_tests/
├── unity/           # Unity testing framework
├── test_libft.c     # Main test file
├── Makefile         # Build configuration
└── libft_docs.h     # Function documentation
```

## Creating a New Test

1. **Include Required Headers**
```c
#include "unity.h"
#include "../Libft/libft.h"

void setUp(void) {
    // Setup code (runs before each test)
}

void tearDown(void) {
    // Cleanup code (runs after each test)
}
```

2. **Write Test Functions**
```c
void test_function_name(void) {
    // Arrange
    char *input = "test";
    
    // Act
    char *result = ft_strdup(input);
    
    // Assert
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(input, result);
    
    // Cleanup
    free(result);
}
```

3. **Register Tests in Main**
```c
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_name);
    return UNITY_END();
}
```

## Available Assertions

- `TEST_ASSERT_EQUAL(expected, actual)` - Compare integers
- `TEST_ASSERT_EQUAL_STRING(expected, actual)` - Compare strings
- `TEST_ASSERT_NULL(pointer)` - Check if pointer is NULL
- `TEST_ASSERT_NOT_NULL(pointer)` - Check if pointer is not NULL
- `TEST_ASSERT_TRUE(condition)` - Check if condition is true
- `TEST_ASSERT_FALSE(condition)` - Check if condition is false

## Building and Running Tests

1. **Build the Tests**
```bash
make
```

2. **Run the Tests**
```bash
make test
```

## Example Test Cases

### Testing String Functions

```c
void test_strlen(void) {
    TEST_ASSERT_EQUAL(5, ft_strlen("Hello"));
    TEST_ASSERT_EQUAL(0, ft_strlen(""));
}

void test_strdup(void) {
    char *str = "Hello";
    char *dup = ft_strdup(str);
    
    TEST_ASSERT_NOT_NULL(dup);
    TEST_ASSERT_EQUAL_STRING(str, dup);
    
    free(dup);
}
```

### Testing Memory Functions

```c
void test_memset(void) {
    char buffer[10];
    ft_memset(buffer, 'A', 5);
    
    TEST_ASSERT_EQUAL('A', buffer[0]);
    TEST_ASSERT_EQUAL('A', buffer[4]);
    TEST_ASSERT_EQUAL('\0', buffer[5]);
}
```

## Best Practices

1. **Test Naming**
   - Use clear, descriptive names
   - Follow the pattern `test_function_name_scenario`

2. **Test Structure**
   - Arrange: Set up test data
   - Act: Call the function being tested
   - Assert: Verify the results
   - Cleanup: Free allocated memory

3. **Edge Cases**
   - Test NULL inputs
   - Test empty strings
   - Test boundary conditions
   - Test error conditions

4. **Memory Management**
   - Always free allocated memory in tests
   - Use `setUp` and `tearDown` for common cleanup

## Debugging Tests

1. **Using Print Statements**
```c
void test_function(void) {
    printf("Debug: Testing with input: %s\n", input);
    // ... test code ...
}
```

2. **Using Unity's Message**
```c
TEST_ASSERT_EQUAL_MESSAGE(expected, actual, "Custom error message");
```

## Adding to Existing Test Suite

1. Add your test function to `test_libft.c`
2. Register it in the `main` function
3. Rebuild and run the tests

## Common Issues

1. **Segmentation Faults**
   - Check for NULL pointer dereferences
   - Verify memory allocation
   - Ensure proper string termination

2. **Memory Leaks**
   - Use `valgrind` to check for leaks
   - Ensure all allocated memory is freed
   - Check cleanup in error cases

3. **Test Failures**
   - Verify expected vs actual values
   - Check edge cases
   - Review function documentation

## Resources

- [Unity Documentation](https://github.com/ThrowTheSwitch/Unity)
- [libft Documentation](docs/html/index.html)
- [C Unit Testing Best Practices](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md) 