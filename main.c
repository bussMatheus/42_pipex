#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	if (argc < 5)
		error_exit(NULL, "Invalid arguments!");
	pipex(argc, argv, env);
	printf("Ran");
	return (0);
}