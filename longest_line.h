/*
Project: Pinball
Name: longes_line.h
Authors: mikirubio & sgalella
Description: compute longest line
 */

void longest_line(int s[10]){
	int i,longitud=0;
	for(i=4;i<8;i++){
		if(s[i]>=s[9]){
			s[9] = s[i];
		}
	}
}