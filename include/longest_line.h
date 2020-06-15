/*
Project: Pinball
Name: longes_line.h
Authors: macasal & sgalella
Description: compute longest line
 */

void longest_line(int s[10]){
	int i=0;
	for(i=4;i<8;i++){
		if(s[i]>=s[9]){
			s[9] = s[i];
		}
	}
}