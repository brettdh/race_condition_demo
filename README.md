# Race conditions

The included program spawns a number of threads (2 by default; set via command line),
each of which attempts to increment a shared tally 20 times.  There is no 
synchronization, so if the increment is not atomic, strange things may result.

To run, type:

    $ make
    $ ./tally <number of threads>
    
Quit with Ctrl-C.  You will get a failure rate for the number of iterations run.
