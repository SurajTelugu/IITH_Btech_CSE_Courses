# Reader-writer-problem
It contains codes for famous problem like reader-writer and fair reader-writer using semaphores. 

Input should be given using file "inp-params.txt" consisting of the following parameters:

1. nw, The number of writer threads.
2. nr, The number of reader threads.
3. kw, The number of times each writer thread tries to enter the critical section.
4. kr, the number of times each reader thread tries to enter the critical section.
5. mucs, average of exponentially distributed time for which each process remain in critical section.
6. murem, average of exponentially distributed time for which each process remain in remainder section.

