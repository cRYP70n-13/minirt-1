#include "errors.h"

/**
 * @brief -> here where I should manage all the errors
 * @param -> the error number
 * @return -> VOID (NONE)
*/
void    error_handler(int error_number)
{
	if (error_number == -1)
		write(2, "Error!!: Memory not being allocated", 35);
	// And all the other errors should be handled here
}