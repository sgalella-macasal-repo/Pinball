/*
Project: Pinball
Name: main.c
Authors: macasal & sgalella
Description: main of the program
*/

#ifndef PINBALL_H
#define PINBALL_H

void amount_lines(int table[50][50], int s[10]);
void backing_up(int table[50][50], int table_backup[50][50]);
void ball_fall(int table[50][50], int position, char direction, int action);
void longest_line(int s[10]);
int menu();
void restoring_table(int table[50][50], int table_backup[50][50]);
void restoring_table(int table[50][50], int table_backup[50][50]);
void simulation1(int table[50][50], int action);
void simulation10(int table[50][50], int shots_position[10], char shots_direction[10], int action);
void statistics(int table [50][50], int s[10]);
void visualization(int table[50][50], int action, int table_backup[50][50]);

#endif