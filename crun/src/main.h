/*
 * main.h
 * Main header file
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Global Veriables */
char *program_name;                 // Program Name
char *program_version = "0.1.3";    // Program Version

/* Prototypes */
void print_usage(void);
void print_help(void);
void print_version(void);

