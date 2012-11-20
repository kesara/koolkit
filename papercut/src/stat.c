/*
 * stat.c
 * Copyright (C) 2007-2012 Kesara Nanayakkara Rathnayake <kesara@kesara.lk>
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
void            process_stats       (struct stats);
void            print_overall_stats (void);
void            print_stat          (struct stats, char*);
char*           get_statfile_path   (void);
struct stats    get_stat            (char*);
int             stat_file_exists    (char*);
struct stats    update_stat         (struct stats, struct stats);
void            update_statfile     (struct stats, char*);
FILE*           file_open           (char*, char*);
void            file_close          (FILE*);

/*
 * process_stats: Process user stats.
 */
void process_stats (struct stats current_stat)
{
    /* Print current session's stats */
    print_stat (current_stat, "This Session:\t");

    /* Determine statfile path */
    char *path;
    path = get_statfile_path ();

    /* Get old stats */
    struct stats old_stat;
    old_stat = get_stat (path);

    /* Update overall stats */
    struct stats overall_stat;
    overall_stat = update_stat (old_stat, current_stat);

    /* Print updated overall stats */
    print_stat (overall_stat, "Overall:\t");

    /* Update statfile */
    update_statfile (overall_stat, path);
}

/*
 * print_overall_stats: Prints overall stats.
 */
void print_overall_stats (void)
{
    /* Determine statfile path */
    char *path;
    path = get_statfile_path ();

    /* Get overall stats */
    struct stats overall_stats;
    overall_stats = get_stat (path);
    
    /* Print overall stats */
    print_stat (overall_stats, "Overall:\t");
}

/*
 * print_stat: Prints given stats and description.
 */
void print_stat (struct stats t_stat, char *str)
{
    printf ("%sWins: %d, Losses: %d, Draws: %d\n",
            str, t_stat.w, t_stat.l, t_stat.d);
}

/*
 * get_statfile_path: Determine statfile path.
 */
char* get_statfile_path (void)
{
    char *home_dir;

    /* Read environment variable HOME */
    if ((home_dir = getenv ("HOME")) != NULL)
    {
        strcat (home_dir, "/");

        /* Create path */
        char *path;
        path = strcat (home_dir, STATFILE);
        return path;
    }
    else
    {
        print_error ("Can not determind HOME directory.");
        exit (EXIT_FAILURE);
    }
}

/*
 * get_stat: Get stats from statfile and return.
 */
struct stats get_stat (char *path)
{
    struct stats temp;
    
    if (!stat_file_exists (path))         // statfile exists.
    {
        FILE *fd;
        fd = file_open (path, "rb");

        if (fread (&temp, sizeof (struct stats), 1, fd) < 1)
        {
            print_error ("File read error.\n");
            exit (EXIT_FAILURE);
        }

        file_close (fd);
    }
    else                    // statfile doesn't exists.
    {
        temp.w = 0;
        temp.l = 0;
        temp.d = 0;
    }

    return temp;
}

/*
 * stat_file_exists: Indetifies whether statfile exists or not.
 * Returns,
 *      0 if statfile exists.
 *     -1 if stat_file_exists and create a statfile too.
 */
int stat_file_exists (char *path)
{
    FILE *fd;
        
    if ((fd = fopen (path, "r")) == NULL)
    {
        /* Create new statfile */
        struct stats temp;

        temp.w = 0;
        temp.l = 0;
        temp.d = 0;

        update_statfile (temp, path);
        
        return -1;
    }

    file_close (fd);

    return 0;
}

/*
 * update_stat: Calculate the summation of current and old stats.
 * returns summation of stats.
 */
struct stats update_stat (struct stats x, struct stats y)
{
    struct stats temp;
    
    temp.w = x.w + y.w;
    temp.l = x.l + y.l;
    temp.d = x.d + y.d;

    return temp;
}

/*
 * update_statfile: Update statfile with new stats.
 */
void update_statfile (struct stats s, char *path)
{
    FILE *fd;
    fd = file_open (path, "wb");

    if (fwrite (&s, sizeof (struct stats), 1, fd) < 1)
    {
        print_error ("File write error.");
        exit (EXIT_FAILURE);
    }

    fflush (fd);
    file_close (fd);
}

/*
 * file_open: Open statfile with given mode.
 * Returns valid file descriptor.
 */
FILE* file_open (char *path, char *mode)
{
    FILE *fd;
        
    if ((fd = fopen (path, mode)) == NULL)
    {
        print_error ("Can not open stat file.");
        exit (EXIT_FAILURE);
    }
    return fd;
}

/*
 * file_close: Close a open file.
 */
void file_close (FILE *fd)
{
    if (fclose (fd) == EOF)
    {
        print_error ("Can not close stat file.");
        exit (EXIT_FAILURE);
    }
}
