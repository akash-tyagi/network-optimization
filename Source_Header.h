/*
 * Source_header.h
 *
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

#define PRINT_VALUES(x,y) printf("%d %d \n",x,y);
#define PRINT_VALUE(x) printf("%d ",x);
#define PRINT_TEXT_VALUE(x,y) printf("%s:%d ",x,y);
#define MIN(x,y) (((x)< (y))?(x):(y))
#define PRINT_TEXT(x) (printf("%s\n",x));
#endif /* SOURCE_HEADER_H_ */
