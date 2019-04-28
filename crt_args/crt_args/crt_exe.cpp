#include "pch.h"
//#include <iostream>    // test comment out by KH

// crt_exec.c
// Illustrates the different versions of exec, including
//      _execl          _execle          _execlp          _execlpe
//      _execv          _execve          _execvp          _execvpe
//
// Although CRT_EXEC.C can exec any program, you can verify how
// different versions handle arguments and environment by
// compiling and specifying the sample program CRT_ARGS.C. See
// "_spawn, _wspawn Functions" for examples of the similar spawn
// functions.

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>    // for atoi

//char *my_env[] =     // Environment for exec?e
const char *my_env[] =     // Environment for exec?e
{
   "THIS=environment will be",
   "PASSED=to new process by",
   "the EXEC=functions",
   NULL
};

int main(int ac, char* av[])
{
	//char *args[4];
	const char *args[4];    // KH
	//int ch;    // KH unreference local variable
	if (ac != 3) {
		fprintf(stderr, "Usage: %s <program> <number (1-8)>\n", av[0]);
		//return;
		return 1;    // KH
	}

	// Arguments for _execv?
	args[0] = av[1];
	args[1] = "exec??";
	args[2] = "two";
	args[3] = NULL;

	switch (atoi(av[2]))
	{
	case 1:
		_execl(av[1], av[1], "_execl", "two", NULL);
		break;
	case 2:
		_execle(av[1], av[1], "_execle", "two", NULL, my_env);
		break;
	case 3:
		_execlp(av[1], av[1], "_execlp", "two", NULL);
		break;
	case 4:
		_execlpe(av[1], av[1], "_execlpe", "two", NULL, my_env);
		break;
	case 5:
		_execv(av[1], args);
		break;
	case 6:
		_execve(av[1], args, my_env);
		break;
	case 7:
		_execvp(av[1], args);
		break;
	case 8:
		_execvpe(av[1], args, my_env);
		break;
	default:
		break;
	}

	// This point is reached only if exec fails.
	printf("\nProcess was not execed.");
	exit(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
