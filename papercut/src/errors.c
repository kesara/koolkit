/*
 * errors.c
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

/* Prototypes */
void	print_help	(void);
void	print_version	(void);
void	print_arg_error	(void);
void	print_usage	(FILE*);
void	print_error	(char*);

/*
 * print_help: Prints program help.
 */
void
print_help (void)
{
	print_usage (stdout);

	fprintf (stdout, "A command line based Rock, Paper, Scissors game.\n");
	fprintf (stdout, "  --stat\tprint user statictics.\n");
	fprintf (stdout, "  --help\tprint help\n");
	fprintf (stdout, "  --version\tprint version\n");
	fprintf (stdout, "\nReport bugs to ");
	fprintf (stdout, "http://code.google.com/p/koolkit/issues/list\n");
}

/*
 * print_version: Prints program version.
 */
void
print_version (void)
{
	fprintf (stdout, "%s %s \n", program_name, program_version);
	fprintf (stdout, "Copyright (C) 2007 Kesara Nanayakkara Rathnayake\n");
	fprintf (stdout, "This is free software. You may redistribute copies ");
	fprintf (stdout, "of it the terms of\n");
	fprintf (stdout, "the GNU General Public License ");
	fprintf (stdout, "<http://www.gnu.org/licenses/gpl.html>.\n");
	fprintf (stdout, "There is NO WARRANTY, to the extent permitted by ");
	fprintf (stdout, "law.\n");
	fprintf (stdout, "\nWritten by Kesara Nanayakkara Rathnayake. ");
	fprintf (stdout, "<http://kesara.f2g.net/>\n");
}

/*
 * print_arg_error: Prints arguments error message.
 */
void
print_arg_error	(void)
{
	fprintf (stderr, "%s: invalid arguments\n", program_name);
	
	print_usage (stderr);
}


/*
 * print_usage: Prints program usage.
 */
void
print_usage (FILE *iostream)
{
	fprintf (iostream, "usage: %s [number of rounds]\n", program_name);
	fprintf (iostream, " (If no number of rounds given, game will have ");
	fprintf (iostream, "%d rounds.)\n", STDROUNDS);
}

/*
 * print_error: Prints program error messages.
 */
void
print_error (char *error)
{
	fprintf (stderr, "%s: %s\n", program_name, error);
}
