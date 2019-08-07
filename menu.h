/*
Project: Pinball
Name: menu.h
Authors: mcasal & sgalella
Description: interactive menu for the pinball
 */

int menu(){
	int action;
	printf("What would you like to do?\n	1. Visualizing game table\n	2. Visualize game table statistics\n	3. Simulate 1 ball fall\n	4. Simulate 10 ball fall\n	5. Exit\n");
	scanf("%d", &action);
	return action;
}