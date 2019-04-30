/*
 * This header has been extracted from PDPCLIB (Public Domain Project
 * C Library) - See http://pdos.sourceforge.net/ and modified to pickup
 * #defines from GCC, if they are available.
 */

/*********************************************************************/
/*                                                                   */
/*  This Program Written by Paul Edwards.                            */
/*  Released to the Public Domain                                    */
/*                                                                   */
/*********************************************************************/
/*********************************************************************/
/*                                                                   */
/*  limits.h - limits header file.                                   */
/*                                                                   */
/*********************************************************************/

#ifndef __LIMITS_INCLUDED
#define __LIMITS_INCLUDED

/** @defgroup NLIBC_LIMITS nlibc Limits
 * nlibc Limits
 * @ingroup NLIBC
 * @{
 * */

#define CHAR_BIT 8
#define SCHAR_MIN -128
#define SCHAR_MAX 127
#define UCHAR_MAX 255
#if ('\x80' < 0)
#define CHAR_MIN -128
#define CHAR_MAX 127
#else
#define CHAR_MIN 0
#define CHAR_MAX 255
#endif
#define MB_LEN_MAX 1
#define SHRT_MIN (-SHRT_MAX-1)
#define SHRT_MAX 32767
#define USHRT_MAX ((unsigned short)65535U)

#if (defined(__OS2__) || defined(__32BIT__) || defined(__MVS__) \
    || defined(__VSE__) \
    || defined(__CMS__) || defined(__WIN32__) || defined(__gnu_linux__))
#define INT_MIN (-INT_MAX-1)
#define INT_MAX 2147483647
#define UINT_MAX 4294967295U
#endif

#if (defined(__MSDOS__) || defined(__DOS__) || defined(__POWERC))
#define INT_MIN (-INT_MAX-1)
#define INT_MAX 32767
#define UINT_MAX 65535U
#endif

/* Get values from compiler, if available */
#ifdef __INT_MAX__
#undef INT_MAX
#define INT_MAX __INT_MAX__
#undef INT_MIN
#define INT_MIN (-INT_MAX-1)
#undef UINT_MAX
#define UINT_MAX (INT_MAX * 2U + 1U)
#endif

#define LONG_MIN (-LONG_MAX-1)
#define LONG_MAX 2147483647L
#define ULONG_MAX (LONG_MAX * 2UL + 1UL)

/** @} end of group NLIBC_LIMITS */

#endif