/*
Project: Pinball
Name: amount_lines.h
Authors: mikirubio & sgalella
Description: count lines
 */

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