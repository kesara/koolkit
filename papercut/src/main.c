/*
 * main.c
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

#define GT(A, B)	((A) > (B) ? 1 : 0)  

/* Variables */
short	u_choice;		// User's choice
short	m_choice;		// Machine's choice
struct	stats current_stat;	// Session stats
short	random_choice;
short	randomizer;
pthread_t select_thread;	

/* Prototypes */
void	play			(void);
int	valid			(int);
void	match			(void);
int	get_result		(void);
void	print_wepon		(char*, int);
void*	random_engine		(void*);

/*
 * main: Main method
 */
int
main (int argc, char **argv)
{
	/* Create and start random_engine Thread */
	random_choice = 0;
	randomizer = 1;

	pthread_create(&select_thread, NULL, random_engine, NULL);

	/* Set current session stats to zero */
	current_stat.w = 0;
	current_stat.l = 0;
	current_stat.d = 0;

	int i, limit;
	
	/* Identify arguments */
	limit = process_args (argc, argv);
	
	/* Play */
	for (i = 0; i < limit; i++)
	{
		play();
	}

	/* Stop random_engine Thread */
	randomizer = 0;
	pthread_join (select_thread, NULL);

	/* Display stats and update stats file */
	process_stats (current_stat);

	exit (EXIT_SUCCESS);
}

/*
 * play: Gets the user choice.
 */
void
play (void)
{
	printf ("Your weapon? (R)ock (P)aper (S)cissors : ");
	while (!valid (getchar ()));

	match ();
}

/*
 * valid: Validate user input.
 * Return 0, if valid input; 1 otherwise.
 */
int
valid (int value)
{
	if (value == 'r' || value == 'R')
	{
		u_choice = 0;
		return 1;
	}
	else if (value == 'p' || value == 'P')
	{
		u_choice = 1;
		return 1;
	}
	else if (value == 's' || value == 'S')
	{
		u_choice = 3;
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * match: Perform the game.
 */
void
match (void)
{
	/* Stop the random_engine thread */
	randomizer = 0;
	pthread_join (select_thread, NULL);
	
	/* Get the machine choice */
	m_choice = random_choice;

	if (m_choice == 2)
	{
		m_choice = 3;
	}

	/* Start the random_engine thread */
	randomizer = 1;
	pthread_create(&select_thread, NULL, random_engine, NULL);

	/* Print wepons */
	print_wepon ("You", u_choice);
	print_wepon ("Machine", m_choice);

	/* Print result */
	switch (get_result ())
	{
		case 0:
			printf("Youe lose. :-(\n\n");
			current_stat.l++;
			break;
		case 1:
			printf("You win. :-)\n\n");
			current_stat.w++;
			break;
		case 2:
			printf("It's a draw.\n\n");
			current_stat.d++;
			break;
	}
}

/*
 * get_result: Identify the game result and print.
 * Returns,
 *	0 - draw
 * 	1 - win
 * 	2 - lose
 */
int
get_result (void)
{
	if (u_choice == m_choice)
	{
		printf("Both are equaly tough.\n");
		return 2;
	}
	else if (u_choice +  m_choice == 1)
	{
		printf("Paper covers rock; paper wins.\n");
		if (GT(u_choice, m_choice))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (u_choice +  m_choice == 4)
	{
		printf("Scissors cut paper; scissors wins.\n");
		if (GT(u_choice, m_choice))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else	/* u_choice +  m_choice == 3 */
	{
		printf ("Rock smashes scissors; rock wins.\n");
		if (GT (u_choice, m_choice))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

/*
 * print_wepon: Print username and the wepon.
 */
void
print_wepon (char *uid, int wepon)
{
	if (wepon == 0)
	{
		printf ("%s rock, ", uid);
	}
	else if (wepon == 1)
	{
		printf ("%s paper, ", uid);
	}
	else
	{
		printf("%s scissors, ", uid);
	}
}

/*
 * random_engine: Get a random number between 0 and 2.
 */
void*
random_engine (void *arg)
{
	while (randomizer)		// Do while randomizer is not -1.
	{
		random_choice++;

		if (random_choice > 2)
		{
			random_choice = 0;
		}
	}

	pthread_exit (0);
}
