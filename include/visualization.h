/*
Project: Pinball
Name: visualization.h
Authors: macasal & sgalella
Description: visualize the table as a pinball
 */


#include "restoring_table.h"

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