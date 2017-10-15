#include "func2.h"

//#include <stdint.h>
//#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void int_to_color(const int v, char* buffer, const size_t buffer_len)
{
    char green_str[] = "green";
    char red_str[] =   "red";    
    //more arrays here ....
    char unrecongized_str[] = "<BadValue>";

    char* str = 0;
    size_t str_len = 0;

    switch (v%10)
    {
        case GREEN_COLOR_INT:
          str = green_str;
          str_len = sizeof(green_str);
          break;

        case RED_COLOR_INT:
          str = red_str;
          str_len = sizeof(green_str);
          break;

        // more cases with colors here ....        

        default:
          str = unrecongized_str;
          str_len = sizeof(unrecongized_str);
    }

    str_len = (buffer_len>=str_len)? str_len : buffer_len;
    memcpy(buffer, str, str_len-1);
    buffer[str_len-1] = '\0';
}

void int_pair_to_str(const int first, const int second, 
	                char* buffer, size_t buffer_len)
{
    const int MAX_STR_LEN = 40;
    char order_buff[MAX_STR_LEN] ;
    int_to_color(first, order_buff, MAX_STR_LEN);
    
    snprintf(buffer, buffer_len, "%s: %d", order_buff, second);
}


