#ifndef __MY_DEFS_H__
#define __MY_DEFS_H__


#define NUM_OF_COLUMNS 		7 	// currently supporting 1-9 (including) columns
#define NUM_OF_ROWS 		7	// top row is used for column info keeping. so always add + 1.	supporting 2 or more (including) rows
#define NUM_OF_PLAYERS 		2 	// currently supporting only 2 players
#define SEQUENCE_FOR_WIN 	4
#define UN_VALID_MOVE 		999
#define WINNER 				0

#define WHITE_CIRCLE	"\U000026AA"
#define YELLOW_CIRCLE	"\U0001F315"
#define RED_CIRCLE		"\U0001F534"
#define WINNER_TROPY	"\U0001F947"

#define KNRM		"\x1B[0m"
#define KBLK 		"\x1B[30m"
#define KRED 		"\x1B[31m"
#define KYEL 		"\x1B[33m"
#define K_BG_BLUE	"\x1B[44m"
#define K_BG_GREY	"\x1B[47m"
#define K_L_GRN		"\x1B[92m"
#define K_L_BLUE	"\x1B[96m"


#endif //__MY_DEFS_H__



