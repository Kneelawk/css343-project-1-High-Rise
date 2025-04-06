# Valgrind Output

Valgrind is automatically run on this project by GitHub actions.

Here is the output:

## Vailgrind Main

```
==2833== Memcheck, a memory error detector
==2833== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==2833== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==2833== Command: build/css343-project-1-High-Rise
==2833== 
Eaten: Wilder
Eaten: Laing
The winner is Frobisher!
==2833== 
==2833== HEAP SUMMARY:
==2833==     in use at exit: 0 bytes in 0 blocks
==2833==   total heap usage: 5 allocs, 5 frees, 77,968 bytes allocated
==2833== 
==2833== All heap blocks were freed -- no leaks are possible
==2833== 
==2833== For lists of detected and suppressed errors, rerun with: -s
==2833== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Valgrind Tests

```
==2835== Memcheck, a memory error detector
==2835== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==2835== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==2835== Command: build/css343-project-1-High-RiseTest
==2835== 
Running main() from /home/runner/work/css343-project-1-High-Rise/css343-project-1-High-Rise/build/_deps/googletest-src/googletest/src/gtest_main.cc
[==========] Running 6 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 6 tests from circular_linked_list
[ RUN      ] circular_linked_list.creation
[       OK ] circular_linked_list.creation (13 ms)
[ RUN      ] circular_linked_list.comparison
[       OK ] circular_linked_list.comparison (2 ms)
[ RUN      ] circular_linked_list.comparison2
[       OK ] circular_linked_list.comparison2 (3 ms)
[ RUN      ] circular_linked_list.remove_next
[       OK ] circular_linked_list.remove_next (4 ms)
[ RUN      ] circular_linked_list.get_current
[       OK ] circular_linked_list.get_current (3 ms)
[ RUN      ] circular_linked_list.winner
[       OK ] circular_linked_list.winner (5 ms)
[----------] 6 tests from circular_linked_list (41 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test suite ran. (77 ms total)
[  PASSED  ] 6 tests.
==2835== 
==2835== HEAP SUMMARY:
==2835==     in use at exit: 0 bytes in 0 blocks
==2835==   total heap usage: 313 allocs, 313 frees, 126,787 bytes allocated
==2835== 
==2835== All heap blocks were freed -- no leaks are possible
==2835== 
==2835== For lists of detected and suppressed errors, rerun with: -s
==2835== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
