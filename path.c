#include "shell.h"
#include "stdio.h"

/**
 * finding_full_path - to find full path of a command line.
 * @command: the command name.
 *
 * Return: If successfull, returns the full path of the command.
 * if unsuccessfull or the command is not found, return NULL.
 */
char *finding_full_path(const char *command)
{
	const char *path_env = getenv("PATH");
	char *clone_path;
	char *folder;

	if (path_env == NULL)
	{
		fprintf(stderr, "PATH variable environment is not set\n");
		return (NULL);
	}
	clone_path = strdup(path_env);
	if (clone_path == NULL)
	{
		perror("memory allocation failed");
		return (NULL);
	}
	folder = strtok(clone_path, ":");

	while (folder != NULL)
	{
		char full_path[1024];

		snprintf(full_path, sizeof(full_path), "%s/%s", folder, command);
		if (access(full_path, X_OK) == 0)
		{
			free(clone_path);
			return (strdup(full_path));
		}
		folder = strtok(NULL, ":");
	}
	free(clone_path);
	return (NULL);
}
