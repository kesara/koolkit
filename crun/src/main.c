/*
 * main.c
 * crun main program
 *
 * Copyright (C) 2007-2012  Kesara Nanayakkara Rathnayake <kesara@kesara.lk>
 * 
 * This file is part of crun.
 * 
 * crun is is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * crun is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with crun. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "main.h"

int main(int argc, char** argv)
{
    register int n;                 // number of times to execute
    register int time;              // time interval
    register char* program;         // command name
    
    program_name = argv[0];

    if (argc > 3)
    {
        n = atoi(argv[1]);
        time = atoi(argv[2]);
        program = argv[3];

        int i;
        int cid;
        
        argv +=3;                   // To get external command arguments

        for (i = 0; i < n; i++)
        {
            cid = fork();

            if (cid == 0)
            {
                execvp(program, argv);
            }

            if (i+1 != n && time > 0)
            {
                sleep(time);
            }
        }
        
        waitpid(cid, NULL, NULL);
    }
    else if (argc == 2)
    {
        char *help = "--help";
        char *version = "--version";
        
        if (strcmp(argv[1], help) == 0)
        {
            print_help();
            exit(0);
        }
        else if (strcmp(argv[1], version) == 0)
        {
            print_version();
            exit(0);
        }
        else
        {
            fprintf(stderr, "%s: invalid arguments\n", program_name);
            print_usage();
            exit(-1);
        }
    }
    else
    {
        fprintf(stderr, "%s: invalid arguments\n", program_name);
        print_usage();
        exit(-1);
    }
    
    exit(0);
}

/*
 * print_usage - print usage message
 */
void print_usage(void)
{
    
    fprintf(stderr,
             "usage: %s <no of times> <time interval in second> <program>\n",
             program_name);
}

/*
 * print_help - print help on the program
 */
void print_help(void)
{
    print_usage();
    fprintf(stdout,
             "Executes an user defined programs multiple times with a user ");
    fprintf(stdout,
             " defined time interval.\n");
    fprintf(stdout,
             "  --help\tprint help\n");
    fprintf(stdout,
             "  --version\tprint version\n");
    fprintf(stdout,
             "\nReport bugs to http://code.google.com/p/koolkit/issues/list\n");
}

/*
 * print_version - print program version information
 */
void print_version(void)
{
    fprintf(stdout, "%s %s (beta)\n", program_name, program_version);
    fprintf(stdout, "Copyright (C) 2007-2012 Kesara Nanayakkara Rathnayake\n");
    fprintf(stdout, "This program is free software: you can redistribute it and/or modify");
    fprintf(stdout, "it under the terms of the GNU General Public License as published by");
    fprintf(stdout, "the Free Software Foundation, either version 3 of the License, or");
    fprintf(stdout, "(at your option) any later version.\n");
    fprintf(stdout, "This program is distributed in the hope that it will be useful,");
    fprintf(stdout, "but WITHOUT ANY WARRANTY; without even the implied warranty of");
    fprintf(stdout, "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the");
    fprintf(stdout, "GNU General Public License for more details.\n");
    fprintf(stdout, "You should have received a copy of the GNU General Public License");
    fprintf(stdout, "along with this program.  If not, see <http://www.gnu.org/licenses/>.");
}
