//
//  main.c
//  230504 algorithm closet
//
//  Created by 한설 on 2023/05/04.
//

#include "Closet.h"

static void checktime(void(*func)(void));          //시간 체크

int main(int argc, const char * argv[]) {
    checktime(TC1_TwoPoint);
    checktime(TC2_TenPoint);
    checktime(TC3_OddPoint);
    checktime(TC4_Hunnitpoint);
    return 0;
}

void checktime(void(*func)(void))
{
    clock_t start, finish;
    double duration;
    start = clock();
    (*func)();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\n================%lf초입니다.================\n", duration);
}
