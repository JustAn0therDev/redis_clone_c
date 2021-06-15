#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "black_marlin.hpp"

/* TODO: next up,
 * port the main program to C++. Initially, it will stay the same as a REPL
 * but will become an HTTP Server as soon as I figure out how to write it the thing using Boost.
 */
int main() {
	char* command;
	char* key;

	Pair* pairs = malloc(sizeof(Pair) * MAXPAIRS);

	for (int i = 0; i < MAXPAIRS; i++) {
		(pairs + i)->key = NULL;
		(pairs + i)->value = NULL;
	}

	while (1) {
		key = malloc(sizeof(char) * MAXKEYSIZE);
		command = malloc(sizeof(char) * MAXCOMMANDSIZE);

		printf("Insert a command: ");
		scanf("%s", command);

		if (strcmp(command, "GET") == 0) {
			printf("Insert a key: ");
			scanf("%s", key);
			GetValue(&pairs, &key);
		}
		else if (strcmp(command, "SET") == 0) {
			char* value = malloc(sizeof(char) * MAXVALUESIZE);

			printf("Insert a key: ");
			scanf("%s", key);

			printf("Insert a value: ");
			scanf("%s", value);

			SetValue(&pairs, &key, &value);
			free(value);
		}
		else if (strcmp(command, "DELETE") == 0) {
			printf("Insert a key: ");
			scanf("%s", key);
			DeleteValue(&pairs, &key);
		}
		else if (strcmp(command, "GETALL") == 0) {
			GetAll(&pairs);
		}
		else if (strcmp(command, "COUNT") == 0) {
			Count(&pairs);
		}
		else if (strcmp(command, "EXISTS") == 0) {
			printf("Insert a key: ");
			scanf("%s", key);
			Exists(&pairs, &key);
		}
		else if (strcmp(command, "FLUSH") == 0) {
			Flush(&pairs);
		}
		else if (strcmp(command, "STRLEN") == 0) {
			printf("Insert a key: ");
			scanf("%s", key);
			Strlen(&pairs, &key);
		}
		else if (strcmp(command, "QUIT") == 0) {
			break;
		}
		else {
			printf("Unknown command.\n");
		}

		free(command);
		free(key);
	}

	free(command);
	free(key);

	for (int i = 0; i < MAXPAIRS; i++) {
		free((pairs + i)->key);
		free((pairs + i)->value);
	}

	free(pairs);

	return EXIT_SUCCESS;
}
