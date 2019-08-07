/*
Project: Pinball
Name: simulation1.h
Authors: mcasal & sgalella
Description: simulate the falling of a single ball
 */

void simulation1(int table[50][50], int action){
	int position,b=0,z=2,s; //n and b are the matrix rows and columns, z is a counter and s is a variable containing the direction
	char direction;
	do{ //insert a valid initial position for 1 ball fall
		printf("Please, give a number from 1 to 50 to choose the column through which the game will leave the ball. If you do not introduce a valid number, we will ask you for another one\n");
		scanf("%d", &position);

		position--;
	} while (position<0||position>49);
	do{ //give a valid initial direction for the ball
		printf("Introduce the direction (choose the number of the option):\n	1.Left\n	2.Right\n ");
		scanf("%d",&s);
		switch(s){
			case 1:
				direction = 'i'; //i stands for "izquierda", which means "left" in spanish
				break;
			case 2:
				direction = 'd'; //d stands for "derecha", which means "right" in spanish
				break;
			default: //if the given number is not valid, another one will be asked
				direction = 'r';
				break;
			}
	}while (direction!='i'&&direction!='d');
	/*we initialize the counter z in two to avoid placing 1s (that would correspond to
    obstacles) and avoid conflicts when printing. When printing, this would be considered*/
	ball_fall(table,position,direction,action); //call the function simulating the physiscs for ball falling
}