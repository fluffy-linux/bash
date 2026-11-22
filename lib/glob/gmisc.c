/* gmisc.c -- miscellaneous pattern matching utility functions for Bash.

   Copyright (C) 2010-2022 Free Software Foundation, Inc.

   This file is part of GNU Bash, the Bourne-Again SHell.
   
   Bash is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Bash is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Bash.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <config.h>

#include "bashtypes.h"

#if defined (HAVE_UNISTD_H)
#  include <unistd.h>
#endif

#include "bashansi.h"
#include "shmbutil.h"
#include "chartypes.h"

#include "stdc.h"

#ifndef FNM_CASEFOLD
#  include "strmatch.h"
#endif
#include "glob.h"

/* Make sure these names continue to agree with what's in smatch.c */
extern char *glob_patscan (char *, char *, int, int);

/* Compile `gm_loop.c' for single-byte characters. */
#define CHAR	char
#define INT	int
#define L(CS)	CS
#define EXTGLOB_PATTERN_P extglob_pattern_p
#define MATCH_PATTERN_CHAR match_pattern_char
#define MATCHLEN umatchlen
#define FOLD(c) ((flags & FNM_CASEFOLD) \
	? TOLOWER ((unsigned char)c) \
	: ((unsigned char)c))
#ifndef LPAREN
#define LPAREN '('
#define RPAREN ')'
#endif
#include "gm_loop.c"

/* Compile `gm_loop.c' again for multibyte characters. */
#if HANDLE_MULTIBYTE

#define CHAR	wchar_t
#define INT	wint_t
#define L(CS)	L##CS
#define EXTGLOB_PATTERN_P wextglob_pattern_p
#define MATCH_PATTERN_CHAR match_pattern_wchar
#define MATCHLEN wmatchlen

#define FOLD(c) ((flags & FNM_CASEFOLD) && iswupper (c) ? towlower (c) : (c))
#define LPAREN L'('
#define RPAREN L')'
#include "gm_loop.c"

#endif /* HANDLE_MULTIBYTE */
