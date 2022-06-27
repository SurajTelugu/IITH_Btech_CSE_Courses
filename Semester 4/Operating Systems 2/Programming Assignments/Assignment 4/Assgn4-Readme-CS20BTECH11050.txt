Instructions:

Input in file named "inp-params.txt" should be in the following format:

 1) Number of Threads (n)
 2) Number of times each thread enters the critical section
 3) Lamda 1 which is used as average of an exponential distribution to get critical section time
 4) Lamda 2 which is used as average of an exponential distribution to get reminder section time
 5) Example:
    100 100 5 20

For Linux Operating Systems:

 1) Go to the folder containing the code file and run the following commands in Linux terminal
      command1: $g++ SrcAssgn4-tas-CS20BTECH11050.cpp -lpthread
      command2:$./a.out

      command1: $g++ SrcAssgn4-cas-CS20BTECH11050.cpp -lpthread
      command2:$./a.out

      command1: $g++ SrcAssgn4-cas-bounded-CS20BTECH11050.cpp -lpthread
      command2:$./a.out
    
    To name the output file run the following commands
      command1: $g++ -o <name of output> SrcAssgn4-tas-CS20BTECH11050.cpp -lpthread
      command2:$./<name of output> 

      command1: $g++ -o <name of output> SrcAssgn4-cas-CS20BTECH11050.cpp -lpthread
      command2:$./<name of output> 

      command1: $g++ -o <name of output> SrcAssgn4-cas-bounded-CS20BTECH11050.cpp -lpthread
      command2:$./<name of output> 

    Note:"$" in commands above is just for linux terminal reference
         Do not use spaces or any symbols (except underscore(_)) in <name of output>

  2) Output Format:
     1) TAS_output.txt file is obtained after compiling SrcAssgn4-tas-CS20BTECH11050.cpp
     2) CAS_output.txt file is obtained after compiling SrcAssgn4-cas-CS20BTECH11050.cpp
     3) CAS_Bounded_output.txt file is obtained after compiling SrcAssgn4-cas-bounded-CS20BTECH11050.cpp

 
For Other Operating Systems:

 1) Use any IDE which has inbuilt linux libraries and use same commands as above

 2) You can also use the following online IDEs which uses Ubuntu(Linux)
      https://www.onlinegdb.com/online_c_compiler
      https://replit.com/~
    You can upload the source code in any of the above online IDEs 
    and run directly or you can also use the above commands to run your file 