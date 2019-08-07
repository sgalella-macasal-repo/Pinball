/*
Project: Pinball
Name: simulation10.h
Authors: mcasal & sgalella
Description: simulate the falling of 10 different balls
 */

void simulation10 (int table[50][50], int shots_position[10], char shots_direction[10], int action){
	int i,position;
	char direction;
	/* we will add 2 units instead of 1 each time a ball goes through a given position. Doing this we can avoid conflicts with 1s
    obstacles when printing. We will consider this change and divide each position by 2 when printing*/
	for (i=0;i<10;i++){
		position = shots_position[i];
		direction = shots_direction[i];
		ball_fall(table,position,direction,action); //call the function simulating the physiscs for ball falling
	}
}