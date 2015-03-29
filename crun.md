# Introduction #

**crun** is a light weight, easy to use, simpler cron like tool. It Executes a given program, a specified number of times, after a specified time interval. Currently in beta status.

**Current Beta Version: crun-0.1.3 (_beta_) [download (tar.gz)](http://koolkit.googlecode.com/files/crun-0.1.3.tar.gz)**

## How to Use ##

Usage: **`crun < No of Times > < Time Interval in Seconds > < Program > [Program Parameters]`**

**crun** would come handy when you need execute certain command over and over again with several time interval in between those executions.
For ex. let say you wants to run **`netstat -na`** command **20** times with in time interval of **1 second**. Then you can use crun with following arguments:
```
crun 20 1 netstat -na
```
crun won't return until final process is executed and returned.

## Why crun? Not cron? ##

**cron** is a great tool. Even I'm using it. **crun** is not meant by any means to replace to cron. crun is cron like (_not a daemon like cron_) tool to be use for quick problems/fixes/uses. If u want to run a certain program several times you can use crun. For quick fixes/uses crun is better because,
  * No need of any configurations. (You may be only use it once.)
  * Gives out put to the user terminal/screen. (Where cron is a daemon)
  * No restrictions. (Anybody can run crun, where cron jobs may be restricted.)

# Change Log #
  * 14 - NOV - 2007 **Version 0.1** _(beta)_
    * Initial Version
  * 21 - NOV - 2007 **Version 0.1.1** _(beta)_
    * Minor Bug Fixes
    * Waits for last process to be executed
    * Error output is written to standard error (stderr)
    * Added "--help" and "--version" options
  * 19 - NOV - 2012 **Version 0.1.2** _(beta)_
    * Minor Bug Fixes
    * Performance enhancements.
    * Upgraded program license from GPL v2 to  GPL v3.
  * 23 - NOV - 2012 **Version 0.1.3** _(beta)_
    * Minor Bug Fixes

# Get crun #
  * Source Code: [crun-0.1.3.tar.gz](http://koolkit.googlecode.com/files/crun-0.1.3.tar.gz)
  * Arch Linux: [Available on AUR](https://aur.archlinux.org/packages/crun/)

# External links #
  * [Developer's Blog](http://kesara.lk/)

Copyright (C) 2007-2012 [Kesara Nanayakkara Rathnayake](http://kesara.lk/)