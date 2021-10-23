// Add support for exporting symbols to be used in DLLs
// This is needed because of how MSVC handles default visibility
// Which is not supported by other compilers, this macro handles the cases

#pragma once

#if defined _WIN32 || defined __CYGWIN__
#define USC_DLL_IMPORT __declspec(dllimport)
#define USC_DLL_EXPORT __declspec(dllexport)
#define USC_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define USC_DLL_IMPORT __attribute__((visibility("default")))
#define USC_DLL_EXPORT __attribute__((visibility("default")))
#define USC_DLL_LOCAL __attribute__((visibility("hidden")))
#else
#define USC_DLL_IMPORT
#define USC_DLL_EXPORT
#define USC_DLL_LOCAL
#endif
#endif

// Source: https://gcc.gnu.org/wiki/Visibility