#ifndef TOOLS_H
# define TOOLS_H
# include <limits.h>

/*
** LSFR(Linear Feedback Shift Register) pseudo random number generator
*/

unsigned int lfsr113_Bits(void);


/*
** generate random number between -1 and 1
*/
float genrate_random_number();
#endif