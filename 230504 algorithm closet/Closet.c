//
//  Closet.c
//  230504 algorithm closet
//
//  Created by 한설 on 2023/05/05.
//

#include "Closet.h"


Point *closet(Point *a, int l, int r, int n)
{
    static Point res[2];
    Point *leftres = NULL, *rightres = NULL, *centerres = NULL, *center;
    double shortest, tmp = 0.0;
    if (n <= 3)
    {
        shortest = distance(a[r], a[l]);
        res[0] = a[l];
        res[1] = a[r];
        for(int i = 0; i < n; i++)
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
    else {
        int m = (r + l) / 2;
        int cl = 0, cr = 0;
        int count = 0;
        int who;
        
        leftres = closet(a, l, m, m - l + 1);
        rightres = closet(a, m, r, r - l);
        
        if (distance(leftres[0], leftres[1]) < distance(rightres[0], rightres[1])) {
            shortest = distance(leftres[0], leftres[1]);
            who = 0;
        }
        else {
            shortest = distance(rightres[0], rightres[1]);
            who = 1;
        }
        
        center = (Point*)malloc(sizeof(Point) * n);
        tmp = a[m].x - shortest;
        
        for (int i = l; i <= m; i++)
        {
            if (tmp > (double)abs(a[m].x - a[i].x))
            {
                center[count] = a[i];
                if (cl == 0)
                {
                    cl = count;
                }
                count++;
            }
            }
        
        tmp = a[m + 1].x + shortest;
        
        for (int i = m + 1; i < n; i++)
        {
            if (tmp > (double)(a[i].x - a[m + 1].x))
            {
                center[count] = a[i];
                cr = count;
                count++;
            }
        }
        
        centerres = closet(center, cl, cr, cr + 1);
        if (distance(centerres[0], centerres[1]) < shortest)
            return centerres;
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
