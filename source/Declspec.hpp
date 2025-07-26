/**
 * @file Declspec.hpp
 * @brief Sets attributes to declarations (works with Clang, GCC, and MSVC).
 * @author Mario Rosell
 * @since 0.0.1
 */

#pragma once

#if (defined(__GNUC__)) || (defined(__clang__))
#define DECLSPEC(...) __attribute__ ((__VA_ARGS__))
#define DS_UNUSED unused
#define DS_NORETURN noreturn
#define DS_PACKED packed
#define DS_CONST const
#define DS_COLD cold
#define DS_HOT hot
#define DS_FRC_INLINE always_inline
#define DS_NEVER_INLINE noinline
#define DS_NEVER_NLPTR returns_nonnull
#define DS_WARN_UUSED_RES warn_unused_return
#elif (defined(_MSC_VER))
#define DECLSPEC(...) __declspec(__VA_ARGS__)
#define DS_UNUSED __pragma (warning (supress))
#define DS_NORETURN noreturn
#define DS_PACKED #pragma pack
#define DS_CONST /* no equivalent on msvc */
#define DS_COLD  /* no equivalent on msvc */
#define DS_HOT   /* no equivalent on msvc */
#define DS_FRC_INLINE forceinline
#define DS_NEVER_INLINE noinline
#define DS_NEVER_NLPTR    /* again, no equivalent on msvc */
#define DS_WARN_UUSED_RES /* same thing */
#endif

/* vim: set ts=2 sw=2 sts=2 noet tw=80: */
