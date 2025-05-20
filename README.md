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

## Installation

### Cloning with Submodules

This project uses the Unity testing framework as a git submodule.
To clone the repository and initialize all submodules, use:

```bash
git clone --recurse-submodules git@github.com:Dino-Lu/libft-tests.git
```

If you have already cloned the repository, run:

```bash
git submodule update --init --recursive
```

Your project structure should look like this:
```
your-libft-project/
├── libft.h
├── libft.a
├── ft_*.c files
└── libft_tests/  (this test suite)
    ├── unity/    (Unity submodule)
    ├── test_libft.c
    ├── Makefile
    └── ...
```

// ... rest of your README content ... 