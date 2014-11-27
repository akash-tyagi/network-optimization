/*
 * Source_header.h
 * Keeps the important libraries, Print functions, Constants
 *  Created on: 23-Nov-2014
 *      Author: akash
 */

#ifndef SOURCE_HEADER_H_
#define SOURCE_HEADER_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
/*included to remove the warning coming from using memset*/
#include <string.h>
/*included to measure the time taken by the functions*/
#include<time.h>

/*pretty handy when comes to debugging*/
#define PRINT_VALUES(x,y) printf("%d %d\n",x,y);
#define PRINT_VALUE(x) printf("%d\n",x);
#define PRINT_TEXT_VALUE(x,y) printf("%s:%d\n",x,y);
#define MIN(x,y) (((x)< (y))?(x):(y))
#define PRINT_TEXT(x) (printf("%s\n",x));

/*Java style constants*/
#define TRUE 1
#define FALSE 0

#endif /* SOURCE_HEADER_H_ */
