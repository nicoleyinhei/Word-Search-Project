/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : CHAN Yin Hei Nicole
 * Student ID    : 1155115755
 * Class/Section : B
 * Date          : 30 Oct 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Macros */
#define MAX_GRID 10
#define MAX_WORDLIST 8
#define MAX_WORD 11
#define MAX_FILENAME 260

/* NO global variables are allowed */

/* Read the letter grid from console into the 2D array parameter letterGird
   Return the size of the letter grid */
int readLetterGridFromConsole(char letterGrid[MAX_GRID][MAX_GRID]) {
    int row, col;
    int gridSize;

    printf("Enter the size of the letter grid:\n");
    scanf("%d", &gridSize);
    printf("Enter the letter grid:\n");

    for(row = 0; row < gridSize; row++) {
        for(col = 0; col < gridSize; col++) {
            /* In scanf(), use " %c" instead of "%c" to read the first non-whitespace character,
               so that the newline character at the end of the previous line can be ignored */
            scanf(" %c", &letterGrid[row][col]);
        }
    }

    return gridSize;
}


/* Read the word list from console into the 2D array parameter wordList
   Return the number of words */
int readWordListFromConsole(char wordList[MAX_WORDLIST][MAX_WORD]) {
    int i;
    int listSize;

    printf("Enter the size of the word list:\n");
    scanf("%d", &listSize);
    printf("Enter the word list:\n");
    
    for(i = 0; i < listSize; i++) {
        /* no & before wordList[i] since wordList[i] already represents the memory address */
        scanf("%s", wordList[i]);
    }

    return listSize;
}


/* Read the letter grid from file into the 2D array parameter letterGird
   Return
        the size of the letter grid if successful
        -1 if there is any file reading error */
int readLetterGridFromFile(char letterGrid[MAX_GRID][MAX_GRID]) {
        int row, col;
        char filename[MAX_FILENAME];
        char temp[MAX_GRID];
        char arr[MAX_GRID*MAX_GRID];
        int gridSize;
        int i;

		FILE *fptr;
		
        printf("Enter filename of the letter grid:\n");
        scanf("%s",filename);

        fptr = fopen(filename,"r");
        
        fscanf(fptr,"%d",&gridSize);
        
        if(fptr==NULL) {
        	gridSize = -1;
        	printf("Error in reading the letter grid file. Program terminates.");
			exit(1);
		}
		
		while(!feof(fptr)) {
			fscanf(fptr,"%s\n",temp);
			strcat(arr,temp);
		}
		
		//printf("%s\n",arr);
		
		for(row=0;row<gridSize;row++){
			for(col=0;col<gridSize;col++){
				letterGrid[row][col] = arr[i];
				i++;
			}
		}
		
		fclose(fptr);

        return gridSize;
/* TODO: Complete the function, you can refer to readLetterGridFromConsole() for reference */

}


/* Read the word list from file into the 2D array parameter wordList
   Return
         the number of words if successful
         -1 if there is any file reading error */
int readWordListFromFile(char wordList[MAX_WORDLIST][MAX_WORD]) {
	int i,a=0;
	char filename[MAX_FILENAME];
	char temp[MAX_WORD];
	char arr[MAX_WORDLIST*MAX_WORD];
    int listSize;
    FILE *fptr;

    printf("Enter filename of the word list:\n");
    scanf("%s",filename);
    
    fptr = fopen(filename,"r");
    
    fscanf(fptr,"%d",&listSize);
        
    //printf("%d\n",listSize);
	    
    if(fptr==NULL) {
    	listSize = -1;
        printf("Error in reading the word list file. Program terminates.");
		exit(1);
	}
    
    while(!feof(fptr)) {
    	fscanf(fptr,"%s\n",temp);
    	strcat(arr,temp);
	}
	
	printf("%s\n",arr);
	/**
	while(arr[i]!='\n') {
		wordList[a][i] = arr[i];
		i++;
	}
	**/
	//printf("%s",wordList[a]);
	
	fclose(fptr);

    return listSize;

/* TODO: Complete the function, you can refer to readWordListFromConsole() for reference */
}


/* Display the letter grid, assume gridSize <= 10 */
void printLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize) {
    int row, col;

    /* For debugging */
    if(gridSize < 2 || gridSize > MAX_GRID) {
        printf("DEBUG: gridSize is %d but not between 2 and %d\n", gridSize, MAX_GRID);
        printf("Program terminates.\n");
        exit(1);
    }

    printf("### %d x %d Letter Grid ###\n", gridSize, gridSize);
	printf("  + 0 1 2 3 4\n");
	printf("+ + + + + + +\n");
	for(row=0;row<gridSize;row++){
		printf("%d + ",row);
		for(col=0;col<gridSize;col++){
			printf("%c ",letterGrid[row][col]);
		}
		printf("\n");
	}
/* TODO: Print the letter grid */
}


/* Display the word list stored in wordList of size listSize with the matching status for each word */
void printWordList(char wordList[MAX_WORDLIST][MAX_WORD], int listSize, int matchingStatus[MAX_WORDLIST]) {
    int i;

    /* For debugging */
    if(listSize < 1 || listSize > MAX_WORDLIST) {
        printf("DEBUG: listSize is %d but not between 1 and %d\n", listSize, MAX_WORDLIST);
        printf("Program terminates.\n");
        exit(1);
    }

    printf("### Word List of Size %d ###\n", listSize);

	for(i=0;i<listSize;i++) {
		if (matchingStatus[i]==0) {
			printf("[ ]");
		} else {
			printf("[X]");
		}
		
		printf("%s\n",wordList[i]);
	}
	
	
/* TODO: Print the word list with matching status */


}


/* Check whether the input word is in the word list and whether it is matched before
   Return
        the index of the input word in the word list (i.e., a value between 0 and listSize - 1) if the input word is in the word list and has not been matched before
        listSize if the input word is in the word list but has been matched already
        -1 if the input word is not in the word list */
int checkWordList(char wordList[MAX_WORDLIST][MAX_WORD], int listSize, int matchingStatus[MAX_WORDLIST], char inputWord[MAX_WORD]) {
	int i;
	int status = -1;
	
	for(i=0;i<listSize;i++) {
		if(strcmp(inputWord,wordList[i])==0) {
			if(matchingStatus[i]==0) {
				status = 0;
			} else if(matchingStatus[i]==1) {
				status = 1;
			}
		} 
	}

/* TODO: Complete the function */

	return status;
}


/* Check whether the input word is in the letter grid in the specified row, column, and direction
   Return
        1 if the input word is in the letter grid in the specified row, column, and direction
        0 if the input word cannot be found in the letter grid in the specified row, column, and direction
        -1 if the search of the input word exceeds the boundary of the letter grid
   This function should not print anything, except debugging messages (if any) */
int checkLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize, char inputWord[MAX_WORD], int matchRow, int matchCol, int matchDirection) {
	int i;
	int status;
	int word[MAX_WORD];
	

/* TODO: Complete the function */

	return status;
}


/* Display the secret table */
void printSecretTable(char letterGrid[MAX_GRID][MAX_GRID],char wordList[MAX_WORDLIST][MAX_WORD],int gridSize, int listSize) {
	char word[MAX_WORD];
	char check_ch;
	int status = 0;
	int row,col,dir;
	int i=0;
	int j=0;
	int a=0;
	int counter=0;
	int len;
	char ch;
	char ch1;
	
	printf("### Secret Table ###\n");
	
	strcpy(word,wordList[a]);
	len = strlen(word);
	
	//printf("%d %c %c\n",len,word[a],word[a+1]);
	/**
	for(i=0;i<gridSize;i++){
		for(j=0;j<gridSize;j++){
		while(a<len-1){	
			if(ch[0] == letterGrid[i][j]){
					if(word[a+1] == letterGrid[i-1][j-1]) {
						dir += 7;
						status += 1;
						row += i;
						col += j;
					} else if(word[a+1] == letterGrid[i-1][j]) {
						dir += 8;
						status += 1;
						row += i;
						col += j;
					} else if (word[a+1] == letterGrid[i-1][j+1]) {
						dir += 9;
						status += 1;
						row += i;
						col += j;
					} else if (word[a+1] == letterGrid[i][j-1]) {
						dir += 4;
						status += 1;
						row += i;
						col += j;
					} else if (word[a+1] == letterGrid[i][j+1]) {
						dir += 6;
						status += 1;
						row += i;
						col += j;
					} else if (word[a+1] == letterGrid[i+1][j-1]) {
						dir += 1;
						status += 1;
						row += i;
						col += j;
					} else if (word[a+1] == letterGrid[i+1][j]) {
						dir += 2;
						status += 1;
						row += i;
						col += j;
					} else if (word[a+1] == letterGrid[i+1][j+1]) {
						dir += 3;
						status += 1;
						row += i;
						col += j;
					}
		
				
		}
			a++;
		}
	
	
	}
	//a++;
}
	dir = dir%9;
	row = row%len;
	col = col%len;
	**/
	
		for(i=0;i<gridSize;i++){
			for(j=0;j<gridSize;j++){
				while(a<len) {
				if(word[a] == letterGrid[i-a][j+a]){
						status++;
						printf("ch = %c a = %d row = %d col = %d status = %d\n",word[a],a,i,j,status);
						
				}
				a++;
			}
			}
			
		}
	
	
	
		row = i-1;
		col = j-len;
		dir = status;
	
	
	printf("%d\n",status);
	
	
	
	
	//if (status == len){
	//	printf("%s: R%d C%d D%d %d\n",word,row,col,dir,status);
	//}
	
	
/* TODO: Complete the function */
}



/* The main() function */
int main()
{
    int gridSize = 5;
    char letterGrid[MAX_GRID][MAX_GRID];
	/** = 
	{	[0][0]='T', [0][1]='T', [0][2]='O', [0][3]='E', [0][4]='K',
		[1][0]='Y', [1][1]='A', [1][2]='Z', [1][3]='C', [1][4]='M',
		[2][0]='A', [2][1]='E', [2][2]='I', [2][3]='X', [2][4]='N',
		[3][0]='I', [3][1]='R', [3][2]='Q', [3][3]='R', [3][4]='O',
		[4][0]='T', [4][1]='T', [4][2]='U', [4][3]='V', [4][4]='J'	
	};
	**/
    int listSize = 3;
    char wordList[MAX_WORDLIST][MAX_WORD];
	/** = 
	{
		[0] = "TRICK",
		[1] = "OR",
		[2] = "TREAT"
	};
	**/
    int matchingStatus[MAX_WORDLIST];			/* Each element should be either 0 (not matched) or 1 (matched) */
    char readData;
    char word[MAX_WORD];
    int i;  
	int fin = 0; 
	int checkWord;
	int checkLetter;
	int row_num,col_num,dir;
	char sectbl[6] = "SECTBL";
	
	
/* TODO: Complete the main() function by invoking the functions declared above */


    printf("Read data from file [Y/N]?");     /* Ask the user whether to read the data from file */
    scanf("%c",&readData);                           /* Read the letter grid and the word list from file or console */

    
	if(readData=='N') {
            gridSize = readLetterGridFromConsole(letterGrid);
            listSize = readWordListFromConsole(wordList);
    } else if(readData =='Y') {
            gridSize = readLetterGridFromFile(letterGrid);
            listSize = readWordListFromFile(wordList);
    } else {
    	printf("Wrong input. Please try again.");
	}
	

	
    for (i=0;i<listSize;i++){               /* Initialize all elements in the matchingStatus array to 0 */
            matchingStatus[i] = 0;
    }


    /* FOR TESTING: Uncomment the following two statements to print the letter grid and the word list
       You can move them elsewhere after testing
       Please make sure the five arguments are initialized properly */
    printLetterGrid(letterGrid, gridSize);
    printWordList(wordList, listSize, matchingStatus);

	/* Read the user input repeatedly until the puzzle finishes */
	
    while(fin!=listSize) {						
		printf("Enter the word:\n");
		scanf("%s",word);
		
		if (strcmp(word,sectbl)==0) {
			printSecretTable(letterGrid,wordList,gridSize,listSize);
		} else if (strcmp(word,sectbl)!=0) {
			checkWord = checkWordList(wordList,listSize,matchingStatus,word);
		
			if(checkWord == 0) {
				printf("Enter the row number, the column number, and the direction (1-4 or 6-9):\n");
				scanf("%d %d %d",&row_num,&col_num,&dir);
				
				checkLetter = checkLetterGrid(letterGrid,gridSize,word,row_num,col_num,dir);
				
				if(checkLetter == 1) {
					printf("The word is found!\n");
				} else if(checkLetter == 0) {
					printf("The input word cannot be found in the given location.\n");
				} else if (checkLetter == -1) {
					printf("The search exceeds the boundary of the letter grid.\n");
				}
				
				printLetterGrid(letterGrid, gridSize);
    			printWordList(wordList, listSize, matchingStatus);
    			
			} else if(checkWord == -1) {
				printf("The input word is not in the word list.\n");
			} else if (checkWord == 1) {
				printf("The input word has already been matched before.\n");
			}
		}
		
		for(i=0;i<listSize;i++) {
			fin = fin + matchingStatus[i];
		}
	}
	
	printWordList(wordList, listSize, matchingStatus);
	printf("\nYou have finished the puzzle.\nCongratulations!\n");
	
    return 0;
}
