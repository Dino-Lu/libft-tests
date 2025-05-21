# Libft Test Suite

A comprehensive test suite for the 42 School's Libft project, built with the Unity testing framework.

[![GitHub Actions](https://img.shields.io/github/actions/workflow/status/Dino-Lu/libft-tests/test.yml?branch=main)](https://github.com/Dino-Lu/libft-tests/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Table of Contents
- [Features](#features)
- [Test Coverage](#test-coverage)
- [Installation](#installation)
- [Usage](#usage)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [Version History](#version-history)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Features

### Core Features
- 🧪 Comprehensive test coverage for all libft functions
- 🔍 Memory leak detection with detailed reports
- ⚡ Performance testing and benchmarking
- 📊 Detailed test reporting with color-coded output
- 🔄 Automated testing with GitHub Actions
- 📚 Complete documentation and examples

### Testing Capabilities
- Unit tests for all mandatory and bonus functions
- Edge case testing and error handling
- Memory management verification
- Performance benchmarking
- Memory leak detection
- Automated test execution

## Test Coverage

### Mandatory Part
- Character Functions
  - `ft_isalpha`, `ft_isdigit`, `ft_isalnum`
  - `ft_isascii`, `ft_isprint`
  - `ft_toupper`, `ft_tolower`
- String Functions
  - `ft_strlen`, `ft_strlcpy`, `ft_strlcat`
  - `ft_strchr`, `ft_strrchr`, `ft_strncmp`
  - `ft_strnstr`, `ft_strdup`
- Memory Functions
  - `ft_memset`, `ft_bzero`, `ft_memcpy`
  - `ft_memmove`, `ft_memchr`, `ft_memcmp`
  - `ft_calloc`
- Additional Functions
  - `ft_atoi`
  - `ft_substr`, `ft_strjoin`, `ft_strtrim`
  - `ft_split`, `ft_itoa`
  - `ft_strmapi`, `ft_striteri`
  - File descriptor functions

### Bonus Part
- List Manipulation Functions
  - `ft_lstnew`: Node creation and initialization
  - `ft_lstadd_front`: Adding nodes to list front
  - `ft_lstsize`: List size calculation
  - `ft_lstlast`: Finding last node
  - `ft_lstadd_back`: Adding nodes to list end
  - `ft_lstdelone`: Single node deletion
  - `ft_lstclear`: Complete list clearing
  - `ft_lstiter`: List iteration
  - `ft_lstmap`: List transformation

## Installation

### Prerequisites
- GCC compiler
- Make
- Git

### Project Structure
```
xxxxxxxxx/              # Parent directory
├── Libft/              # Your libft project
│   ├── libft.h
│   ├── libft.a
│   └── ft_*.c files
└── libft_tests/        # This test suite
    ├── unity/          # Unity testing framework
    ├── test_libft.c    # Main test file
    ├── Makefile        # Build configuration
    ├── README.md       # This file
    ├── testing_guide.md # Testing documentation
    └── docs/           # Additional documentation
```

### Installation Steps
1. Clone the repository:
   ```bash
   # From your parent directory
   git clone https://github.com/Dino-Lu/libft-tests.git libft_tests
   ```

2. Verify the Makefile configuration:
   - Open `libft_tests/Makefile`
   - Ensure `LIBFT_DIR = ../Libft` points to your libft directory
   - Default configuration should work if cloned into `libft_tests`

## Usage

### Running Tests
```bash
cd libft_tests

# Build the test suite
make

# Run mandatory tests only
make test

# Run all tests (mandatory + bonus)
make bonus

# Clean build files
make clean

# Clean everything
make fclean

# Rebuild everything
make re
```

### Test Output
- Green ✓ indicates passed tests
- Red ✗ indicates failed tests
- Detailed error messages for failed tests
- Memory leak reports
- Performance metrics

## Documentation

### Available Documentation
- [Full Documentation](docs/html/index.html) - Complete function documentation
- [Testing Guide](testing_guide.md) - How to write and run tests
- [GitHub Actions](.github/workflows/test.yml) - CI/CD configuration

### Documentation Structure
- Function specifications
- Test case examples
- Memory management guidelines
- Performance considerations
- Best practices

## Contributing

### How to Contribute
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Contribution Guidelines
- Follow existing code style
- Add tests for new features
- Update documentation
- Ensure all tests pass
- Check for memory leaks

## Version History

### v1.0.0
- Initial release
- Mandatory part test coverage
- Basic documentation
- GitHub Actions integration

### v1.1.0 (Current)
- Added bonus part test coverage
- Enhanced list function tests
- Improved memory leak detection
- New test targets (test/bonus)
- Comprehensive documentation
- Better test organization

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Unity Testing Framework](https://github.com/ThrowTheSwitch/Unity)
- [42 School](https://github.com/42Berlin)
- All contributors who have helped improve this test suite

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=Dino-Lu/libft-tests&type=Date)](https://star-history.com/#Dino-Lu/libft-tests&Date)

---

If you find this test suite helpful, please consider giving it a ⭐️ on GitHub! 