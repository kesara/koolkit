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
#include <string.h>

/* Global Veriables */
char *program_name;					/* Program Name */
char *program_version = "0.1.1";	/* Program Version */

/* Prototypes */
void print_usage (void);
void print_help (void);
void print_version (void);

int main(int argc, char** argv)
{
	register int n;					/* number of times to execute */
	register int time;				/* time interval */
	register char* program;			/* command name */
	
	program_name = argv[0];

	if (argc > 3)
	{
		n = atoi(argv[1]);
		time = atoi(argv[2]);
		program = argv[3];

		int i;
		int cid;
		
		for (i = 0; i < 3; i++)
		{
			++argv;
		}

		for (i = 0; i < n; i++)
		{
			cid = fork();

			if (cid == 0)
			{
				execvp (program, argv);
			}

			if (i+1 != n && time > 0)
			{
				sleep (time);
			}
		}
		
		waitpid (cid, NULL, NULL);
	}
	else if (argc == 2)
	{
		char *help = "--help";
		char *version = "--version";
		
		if (strcmp (argv[1], help) == 0)
		{
			print_help ();
			exit (0);
		}
		else if (strcmp (argv[1], version) == 0)
		{
			print_version ();
			exit (0);
		}
		else
		{
			fprintf (stderr, "%s: invalid arguments\n", program_name);
			print_usage ();
			exit (-1);
		}
	}
	else
	{
		fprintf (stderr, "%s: invalid arguments\n", program_name);
		print_usage ();
		exit (-1);
	}
	
	exit (0);
}

/*
 * print_usage - print usage message
 */
void print_usage (void)
{
	
	fprintf (stderr,
			 "usage: %s no_of_times time_interval program \n",
			 program_name);
}

/*
 * print_help - print help on the program
 */
void print_help (void)
{
	print_usage ();
	fprintf (stdout,
			 "Executes an user defined programs multiple times with a user ");
	fprintf (stdout,
			 " defined time interval.\n");
	fprintf (stdout,
			 "  --help\tprint help\n");
	fprintf (stdout,
			 "  --version\tprint version\n");
	fprintf (stdout,
			 "\nReport bugs to http://code.google.com/p/koolkit/issues/list\n");
}

/*
 * print_version - print program version information
 */
void print_version (void)
{
	fprintf (stdout, "%s %s (beta)\n", program_name, program_version);
	fprintf (stdout, "Copyright (C) 2007 Kesara Nanayakkara Rathnayake\n");
	fprintf (stdout, "This is free software. You may redistribute copies of it");
	fprintf (stdout, "the terms of\n");
	fprintf (stdout, "the GNU General Public License ");
	fprintf (stdout, "<http://www.gnu.org/licenses/gpl.html>.\n");
	fprintf (stdout, "There is NO WARRANTY, to the extent permitted by law.\n");
	fprintf (stdout, "\nWritten by Kesara Nanayakkara Rathnayake.\n");
}
