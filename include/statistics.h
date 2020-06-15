/*
Project: Pinball
Name: statistics.h
Authors: macasal & sgalella
Description: compute statistics
 */

#include "amount_lines.h"
#include "longest_line.h"

void statistics (int table [50][50], int s[10]){
	amount_lines(table,s);
	longest_line(s);
}