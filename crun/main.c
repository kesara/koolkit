/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) Kesara Nanayakkara Rathnayake 2007 <kesara@bcs.org>
 * 
 * main.c is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * main.c is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with main.c.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define MIN	3	/* Minimum number of command line arguments. */

int main(int argc, char** argv) {

	register int nTimes;
	register int time;
	register char* program;

	if (argc > MIN) {
		nTimes = atoi(argv[1]);
		time = atoi(argv[2]);
		program = argv[3];

		int i;
		for (i = 0; i < MIN; i++)
			++argv;

		for(i = 0; i < nTimes; i++) {
			int cid = fork();

			if (cid == 0)
				execvp(program, argv);

			if (i+1 != nTimes && time > 0)
				sleep(time);
		}
	}
	else {
		printf("usage: crun <No of Times> <Time Interval> <Program Namge> [Program Parameters]\n");
		return (-1);
	}
	return (0);
}
