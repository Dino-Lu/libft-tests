# Libft Test Suite

A comprehensive test suite for the 42 School's Libft project, built with the Unity testing framework.

[![GitHub Actions](https://img.shields.io/github/actions/workflow/status/Dino-Lu/libft-tests/test.yml?branch=main)](https://github.com/Dino-Lu/libft-tests/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Features

- 🧪 Comprehensive test coverage for all libft functions
- 🔍 Memory leak detection
- ⚡ Performance testing
- 📊 Detailed test reporting
- 🔄 Automated testing with GitHub Actions
- 📚 Complete documentation

## Test Coverage

### Mandatory Part
- All required libft functions
- Edge cases and error handling
- Memory management
- Performance benchmarks

### Bonus Part (Coming Soon)
- List manipulation functions:
- Memory management for linked lists
- Complex list operations
- Edge cases for list manipulation
- Performance testing for list operations

## Installation

Your project structure should look like this:
```
your-libft-project/
├── libft.h
├── libft.a
├── ft_*.c files
└── libft_tests/  (this test suite)
    ├── unity/
    ├── test_libft.c
    ├── Makefile
    └── ...
```

### Step 1: Clone this repository
```bash
# From your libft project directory
git clone https://github.com/Dino-Lu/libft-tests.git libft_tests
```

### Step 2: Update the Makefile (if needed)
- Open `libft_tests/Makefile`
- Make sure `LIBFT_DIR = ..` points to your libft directory
- This should be correct by default if you cloned into the `libft_tests` directory

### Step 3: Run the tests
```bash
cd libft_tests
make
make test
```

## Documentation

- [Full Documentation](docs/html/index.html) - Detailed function documentation and test examples
- [Testing Guide](testing_guide.md) - How to write and run tests
- [GitHub Actions](.github/workflows/test.yml) - Automated testing configuration

## Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest improvements
- Add new test cases
- Improve documentation

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Version History

- v1.0.0 (Current)
  - Initial release
  - Mandatory part test coverage
  - Basic documentation
  - GitHub Actions integration

- v1.1.0 (Planned)
  - Bonus part test coverage
  - Extended test cases
  - Additional documentation

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