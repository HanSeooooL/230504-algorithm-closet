//
//  Closet.c
//  230504 algorithm closet
//
//  Created by 한설 on 2023/05/05.
//

#include "Closet.h"


Point *closet(Point *a, int l, int r, int n)
{
    Point *res = NULL, *leftres = NULL, *rightres = NULL, *centerres = NULL;
    double shortest;
    if (n <= 3)         //점이 3개 이하인 경우
    {
        res = (Point*)malloc(sizeof(Point) * 2);
        shortest = distance(a[r], a[l]);
        res[0] = a[l];
        res[1] = a[r];
        
        for(int i = l; i < r; i++)
        {
            if(shortest > distance(a[i], a[i + 1]))
            {
                shortest = distance(a[i], a[i + 1]);
                res[0] = a[i];
                res[1] = a[i + 1];
            }
        }
        return res;
    }
    else {              //점이 3개 이상인 경우
        int m = (r + l) / 2;
        int who, cl = l, cr = r;
        //왼쪽 오른쪽 분할
        leftres = closet(a, l, m, m - l + 1);   //왼쪽 결과 쌍 도출
        rightres = closet(a, m + 1, r, r - m + 1);      //오른쪽 결과 쌍 도출
        
        if (distance(leftres[0], leftres[1]) < distance(rightres[0], rightres[1])) {        //왼쪽이 더 짧은 경우
            shortest = distance(leftres[0], leftres[1]);        //왼쪽 거리 shortest에 기입
            who = 0;        //who로 어느 값이 기입되었는지 기록
        }
        else {
            shortest = distance(rightres[0], rightres[1]);      //오른쪽 거리 shortest에 기입
            who = 1;        //who로 어느 값이 기입되었는지 기록
        }
        
        while ((a[m].x - shortest) > a[m].x - a[cl].x && cl < m) {  //왼쪽에서부터 중간 범위 내 값 파악
            cl++;
        }
        
        while ((a[m + 1].x + shortest < a[cr].x) && cr > m + 1) {   //오른쪽에서부터 중간 범위 내 값 파악
            cr--;
        }
        
        centerres = closet(a, cl, cr, cr - cl);
        
        if (distance(centerres[0], centerres[1]) <= shortest)
        {
            return centerres;
        }
        else {
            if (who == 0) {
                return leftres;
            }
            else {
                return rightres;
            }
        }
        
        
    }
}

double distance(Point a, Point b)   //거리구하기 함수
{
    double distance = 0;
    double x, y;
    x = (double)b.x - (double)a.x;
    y = (double)b.y - (double)a.y;
    x = fabs(x);
    y = fabs(y);
    distance = sqrt((x * x) + (y * y));
    return distance;
}
