# Introduction #
**papercut** is command line based **Rock, Paper, Scissors game** for _Unix based operating systems_ like _GNU/Linux_, _BSD_ etc. User can play the game by entering users choice that is either, Rock (**R** or **r**), Paper (**P** or **p**), Scissors (**S** or **s**). Game play is explained in **How to play section**. papercut also stores user statics. i.e. number of _wins_, _losses_ and _draws_.


**Current Beta Version: papercut-0.1.2 (_beta_) [download (tar.gz)](http://koolkit.googlecode.com/files/papercut-0.1.2.tar.gz)**

# How to Play #
  * Start the game by executing `papercut` or `papercut [number of rounds]` _If number of rounds not specified, game will have a standard of 3 rounds._ (_See **Usage** section_)
  * Make your choice. (_Select your weapon_)
    * For Rock, enter **R** or **r**
    * For Paper, enter **P** or **p**
    * For Scissors, enter **S** or **s**
  * If you can beat machine's weapon, if both weapon are same game is a draw, other wise you will lose. (_Explained in **Game Rules** section_)
  * At the end of game rounds, your **current sessions stats** and **overall stats** will be displayed.

## Usage ##
```
papercut [number of rounds]
```
(_If no number of rounds given, game will have 3 rounds_)

### Other Command Line Parameters ###
  * `--stat`	- print user statistics.
  * `--help`	- print help
  * `--version` - print version

## Game Rules ##
Rules are similar to common **Rock, Paper, Scissors** game.
  * Rock beats Scissors
  * Paper beats Rock
  * Scissors beats Paper

# Change Log #
  * 25 - DEC - 2007 **Version 0.1.0** _(beta)_
    * Initial Version
  * 26 - DEC - 2007 **Version 0.1.1** _(beta)_
    * CUP Usage Issue Fixed _([Issue# 1](http://code.google.com/p/koolkit/issues/detail?id=1))_
  * 20 - NOV - 2012 **Version 0.1.2** (beta)
    * Minor bug fixes. (_Including [Issue# 2](https://code.google.com/p/koolkit/issues/detail?id=2)_)
    * Made program faster.

# Get papercut #
  * Source Code: [papercut-0.1.2.tar.gz](http://koolkit.googlecode.com/files/papercut-0.1.2.tar.gz)
  * Arch Linux: [Available on AUR](https://aur.archlinux.org/packages/papercut/)

# External links #
  * [Developer's Blog](http://kesara.lk/)

Copyright (C) 2007 [Kesara Nanayakkara Rathnayake](http://kesara.lk/)