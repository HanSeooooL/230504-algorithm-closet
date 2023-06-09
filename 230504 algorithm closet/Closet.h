//
//  Closet.h
//  230504 algorithm closet
//
//  Created by 한설 on 2023/05/05.
//

#ifndef Closet_h
#define Closet_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct _point {
    int x;
    int y;
}Point;
typedef Point Element;

Point *closet(Point *a, int left, int right, int n);       //점 구하기 함수
double distance(Point a, Point b);          //거리구하기 함수

//TestFunc
void TC1_mycode(void);

#endif /* Closet_h */
