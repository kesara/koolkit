/*
 * args.c
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

#include "papercut.h"

#define	HELP	"--help"
#define VERSION	"--version"
#define STAT	"--stat"

/* Prototypes */
int	process_args	(int, char**);

/*
 * process_args: Determind user arguments and call appropiate function.
 * Returns number of rounds of gameplay.
 */
int
process_args (int argc, char **argv)
{
	program_name = argv[0];			// Set program name
	program_version = "0.1.0 (beta)";	// Set program version

	if (argc == 1)		// If no parameters standard number of rounds.
	{
		return STDROUNDS;				
	}
	else if (argc == 2)
	{
		/* --help */
		if (strcmp (argv[1], HELP) == 0)
		{
			print_help ();
			exit (EXIT_SUCCESS);
		}
		/* --version */
		else if (strcmp (argv[1], VERSION) == 0)
		{
			print_version ();
			exit (EXIT_SUCCESS);
		}
		/*  --stat */
		else if (strcmp (argv[1], STAT) == 0)
		{
			print_overall_stats ();
			exit (EXIT_SUCCESS);
		}
		/* user has entered number of rounds. */
		else
		{
			int i;
			i = atoi (argv[1]);
			
			/* if number of rounds is not valid. */
			if (i < 1)
			{
				print_arg_error ();
				exit (EXIT_FAILURE);
			}
			/* if valid number of rounds */
			else
			{
				return i;
			}
		}
	}
	/* Incorrect number of parameters */
	else
	{
		print_arg_error ();
		exit (EXIT_FAILURE);
	}
}
