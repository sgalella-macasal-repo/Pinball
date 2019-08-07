/*
Project: Pinball
Name: restoring_table.h
Authors: mcasal & sgalella
Description: retrieve original status of the table
 */

void restoring_table(int table[50][50], int table_backup[50][50]){
	int i,j;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			table[i][j] = table_backup[i][j]; //changing each modified vañue in the table for its original value
		}
	}
}