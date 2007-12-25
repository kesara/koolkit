/*
 * papercut.h
 * Copyright (C) 2007 Kesara Nanayakkara Rathnayake <kesara@bcs.org>
 *
 * This file is part of papercut.
 * 
 * papercut is free software: you may redistribute it and/or modify
 * it under the terms of the GNU General Public License, as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * papercut is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with papercut. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define	STDROUNDS	3		/* Standard number of rounds */
#define	STATFILE	".papercut"	/* stat file name */

/* Global Veriables */
char *program_name;			/* Program Name */
char *program_version;			/* Program Version */

/* stats data structure */
struct stats {
	int l;		// Number of loses
	int w;		// Number of wins
	int d;		// Number of draws
};
