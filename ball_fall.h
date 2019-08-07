/*
Project: Pinball
Name: ball_fall.h
Authors: mcasal & sgalella
Description: simulation of the falling ball
 */


void ball_fall(int table[50][50], int position, char direction, int action){
	int counter=2,row=0; //initializing the counter z in 2 to match both types of simulation
	while (row<=49){
		if (table[row][position]!=1){
			table[row][position]= table[row][position] + counter;
		}
		else if (table[row][position]==1){
			if (table[row-1][position-1]==1){
				position++;
				row--;
			 	table[row][position]= table[row][position] + counter;
			 	direction='d';
			}
			else if (table[row-1][position+1]==1){
				position--;
				row--;
				table[row][position]= table[row][position] + counter;
				direction='i';
			}
			else if ((table[row-1][position-1]!=1)&&(table[row-1][position+1]!=1)){
				if (direction=='d'){
					position++;
					row--;
					table[row][position]= table[row][position] + counter;
				}
				else if (direction=='i'){
					position--;
					row--;
					table[row][position]= table[row][position] + counter;
				}
			}
		}
		row++;
		if (action==3){
			counter++; /*if the simulation is 1 ball fall we want the position of the ball in each time step.
                        So, we increment the counter together as time step increases. If it is 10 ball fall
                        we do not need to increase the counter*/
		}
	}
}