/* File-name wildcard pattern matching for GNU.
   Copyright (C) 1985-2022 Free Software Foundation, Inc.

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

#ifndef	_GLOB_H_
#define	_GLOB_H_

#include "stdc.h"
#include <glob.h>

extern int extglob_pattern_p (const char *);

extern char *glob_error_return;
extern int noglob_dot_filenames;
extern int glob_ignore_case;
extern int glob_always_skip_dot_and_dotdot;

#endif /* _GLOB_H_ */
