/*
Project: Pinball
Name: backing_up.h
Authors: mcasal & sgalella
Description: backup array of table
 */

void backing_up(int table[50][50],int table_backup[50][50]){
	int f,c; //going through the matrix to copy it into a new variable tu use as a back up
	for (f=0;f<50;f++){
		for (c=0;c<50;c++){
			table_backup [f][c] = table[f][c];
		}
	}
}