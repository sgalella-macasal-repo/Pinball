/*
PRACTICA 1

 Miguel Ángel Casal Santiago
 Santiago Galella Toledo
 */

#include <stdio.h>
#include <stdlib.h>


int menu(); //scanning action from the user
void visualization (int table[50][50], int action, int table_backup[50][50]); //visualizing game table
void statistics (int table[50][50], int s[10]); //table statistics are given
void simulation1 (int table[50][50], int action); //simulating 1 ball fall
void simulation10 (int table[50][50], int shots_position[10], char shots_direction[10], int action); //simulating 10 balls fall
void restoring_table (int table[50][50], int table_backup[50][50]); //getting the original table after modifications;
void amount_lines (int table[50][50], int s[10]);//getting the amount of lines (obstacles) and their orientation
void longest_line (int s[10]); //finding the longest obstacle
void backing_up(int table[50][50], int table_backup[50][50]); // creating a table back-up
void ball_fall(int table[50][50], int position, char direction, int action); /*
                                                                            algorithm of the ball fall modifying the table depending on choosing 1 ball or 10 ball fall.
                                                                            If 1 ball fall is chosen it will show the position of the ball at each time step.
                                                                            If 10 ball fall is chosen it will show the ocupation matrix (how many balls have gone through
                                                                            each specific position)
                                                                            */

int main(){
	int table[50][50]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};     

	int table_backup[50][50]; // creating a back up of the original table such that when can restor it after any modification
	backing_up(table,table_backup);
	int shots_position[10] = {1, 5, 14, 22, 37, 48, 43, 40, 28, 19}; //vector of positions of the 10 balls in 10 ball fall
	char shots_direction[10]= {'i','i','d','i','d','d','i','d','d','i'}; //vector of initial direction for the 10 balls in 10 ball fall
	int s[10],action=0; // s=vector of statistics, p=user action
	while (action!=5){ //while the user does not choose to exit, the program ask for an action
		action = menu();
		switch(action){
			case 1: //visualizing the table
				visualization(table,action,table_backup);
				break;
			case 2: //visualizing table statistics
				statistics(table,s);
				printf("The amount of vertical lines is %d \n", s[0]);
				printf("The amount of horizontal lines is %d \n", s[1]);
				printf("The total amount of diagonal lines from top-right to bottom-left is %d \n", s[2]);
				printf("The total amount of diagonal lines from top-left to bottom-right is %d \n", s[3]);
				printf("The longest vertical line dimension is %d \n", s[4]);
				printf("The longest horizontal line dimension is %d \n", s[5]);
				printf("The longest diagonal line from top-right to bottom-left has a dimension of %d \n", s[6]);
				printf("The longest diagonal line from top-left to bottom-right has a dimension of %d \n", s[7]);
				printf("The total amount of lines is %d \n", s[8]);
				printf("The global longest line dimension is %d \n", s[9]);
				break;
			case 3: //simulating 1 ball fall
				simulation1(table,action);
				//printing matrix after 1 ball fall with single ball position in each time step
				visualization(table,action,table_backup);
				break;
			case 4: //simulating 10 ball fall
				simulation10(table,shots_position,shots_direction,action);
				//printing ocupation matrix after 10 ball fall
				visualization(table,action,table_backup);
				break;
			case 5:
				printf("See you!\n");
				exit(-1);
			default: //if any of the previous action is selected it reminds the user what he or she can do
				printf("Please, choose a number from 1 to 5 \n");
				break;
		}
	}
}

void visualization(int table[50][50], int action, int table_backup[50][50]){ /*visualizing the table as a pinball substituting the 0s by spaces and 1s by obstacles (*)
                                                                              also if any simulation was performed, we show the corresponding output
                                                                              */
	int i,j;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			if(table[i][j]==0){ //substituting 0s by spaces
				printf("  ");
			}
			else if (table[i][j]==1){ //substituting 1s by *
				printf(" *");
			}
			if(action==3){ //if 1 ball fall was chosen print the positions
				if (table[i][j]>1){
				printf("%2d", table[i][j]-2); /* we add a difference of two because of inititating the1
                                               1 ball fall simulation in 2 to avoid conflicts with 1s
                                               and obstacles*/
				}
			}
			if(action==4){ //if 10 ball fall was chosen print the occupation matrix
				if (table[i][j]>1){
				printf("%2d", table[i][j]/2); /* dividing between 2 because of adding two units per ball
                                               in 10 ball simulation (to avoid conflicts with 1s)*/
				}
			}
		}
		printf("\n");
	}
	//restoring the table after doing any simulation
	restoring_table(table,table_backup);
}

void statistics (int table [50][50], int s[10]){
	amount_lines(table,s);
	longest_line(s);
}

int menu(){
	int action;
	printf("What would you like to do?\n	1. Visualizing game table\n	2. Visualize game table statistics\n	3. Simulate 1 ball fall\n	4. Simulate 10 ball fall\n	5. Exit\n");
	scanf("%d", &action);
	return action;
}

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

void restoring_table(int table[50][50], int table_backup[50][50]){
	int i,j;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			table[i][j] = table_backup[i][j]; //changing each modified vañue in the table for its original value
		}
	}
}

void amount_lines(int table[50][50], int s[10]){
	int i,j,l=0;
	for (i=0;i<10;i++) //initializing the vector in 0
	s[i]=0;
	for(i=0;i<50;i++){ //we go through the matrix checking if there are vetical, horizontal and diagonal lines
		for(j=0;j<50;j++){	
			if(table[i][j]==1){
				if(table[i][j]==table[i+1][j] && table[i-1][j]==0){ //vertical lines
					s[0]++;
					l=0;
					while(table[i+l][j]!=0){ //calculating dimension of the found line
						l++;
					}
					if(l>s[4]){ //if its dimension is larger than the previous longest line, set this line as the longest
						s[4]=l;
					}
				}
				else if(table[i][j]==table[i][j+1] && table[i][j-1]==0){ //horizontal lines
					s[1]++;
					l=0;
					while(table[i][j+l]!=0){ //calculating dimension of the found line
						l++;
					}
					if(l>s[5]){ //if its dimension is larger than the previous longest line, set this line as the longest
						s[5]=l;
					}
				}	
				else if(table[i][j]==table[i-1][j+1] && table[i+1][j-1]==0){ //diagonal lines (from bottom-left to top-right)
					s[2]++;	
					l=0;
					while(table[i-l][j+l]!=0){ //calculating dimension of the found line
						l++;
					}
					if(l>s[6]){ //if its dimension is larger than the previous longest line, set this line as the longest
						s[6]=l; 
					}
				}
				else if(table[i][j]==table[i+1][j+1] && table[i-1][j-1]==0){ //diagonal lines (from bottom-right to top-left)
					s[3]++;	
					l=0;
					while(table[i+l][j+l]==1){ //calculating dimension of the found line
						l++;
					}
					if(l>s[7]){ //if its dimension is larger than the previous longest line, set this line as the longest
						s[7]=l;
					}
				}
			}
		}
	}
	s[8] = s[0] + s[1] + s[2] + s[3]; //computing the total amount of lines
}

void longest_line(int s[10]){
	int i,longitud=0;
	for(i=4;i<8;i++){
		if(s[i]>=s[9]){
			s[9] = s[i];
		}
	}
}

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

void backing_up(int table[50][50],int table_backup[50][50]){
	int f,c; //going through the matrix to copy it into a new variable tu use as a back up
	for (f=0;f<50;f++){
		for (c=0;c<50;c++){
			table_backup [f][c] = table[f][c];
		}
	}
}
