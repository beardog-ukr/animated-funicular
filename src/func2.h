#ifndef __func2_c__
#define __func2_c__

#include <stddef.h>

#define GREEN_COLOR_INT 1
#define RED_COLOR_INT   2
#define GREY_COLOR_INT  3

/**  This function makes a string from two integers.
 *  The function creates some kind of message from two integer values.
 * First integer value will be converted to corresponding "color" constant,
 * another will be added as is
 * Example: for 1 and 22 output will be "Color is green, number is 22"
 * Also there is a bug for one of color constants, libfuzzer will 
 * find it easily.
 * \param first is first integer value, related to "color"
 * \param second is second integer value, will be added as is
 * \param buffer is the buffer to store result
 * \param buffer_len is the buffer size
 */
void int_pair_to_str(const int first, const int second, 
                     char* buffer, const size_t buffer_len);

#endif 
