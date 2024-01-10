#include "shell.h"

/**
 * the_full_path - the full path of a command line.
 * @command: Name of the command.
 *
 * Return: If successfull, returns the full path of the command.
 * if unsuccessfull or the command is not found, return NULL.
 */
char *the_full_path(const char *command)
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
		perror("Allocation of Memory failed");
		return (NULL);
	}
	folder = strtok(clone_path, ":");

	while (folder != NULL)
	{
		char full_path[1022];

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
