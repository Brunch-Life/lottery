
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int check(int red[6], int blue, int red_ans[6], int blue_ans,int* doflag);
int cmpfunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int looptime,doflag=0;
    printf("How many times do you want to loop?\n");
    scanf("%d", &looptime);
    freopen("out.txt", "w", stdout);
    srand((int)time(0));
    int red[6], blue;
    int red_ans[6] , blue_ans;
    int time=0,money=0;
    for (time;time < looptime;time++)
    {
        for (int i = 0; i < 6; i++)
        {
            red[i] = rand() % 33 + 1;
            red_ans[i] = rand() % 33 + 1;
        }
        for (int i = 0; i < 5; i++)
        {
            qsort(red, 6, sizeof(int), cmpfunc);
            if (red[i] == red[i + 1])
            {
                red[i + 1] = rand() % 33 + 1;
                i=-1;
            }
        }
        for (int i = 0; i < 5; i++)
                {
                    qsort(red_ans, 6, sizeof(int), cmpfunc);
                    if (red_ans[i] == red_ans[i + 1])
                    {
                        red_ans[i + 1] = rand() % 33 + 1;
                        i = -1;
                    }
                }


        for (int i = 0; i < 6; i++)
        {
            printf("%d %d %d\n", i + 1, red[i], red_ans[i]);
        }
        blue = rand() % 16 + 1;
        blue_ans = rand() % 16 + 1;
        printf("7 %d %d\n", blue, blue_ans);
        int get = check(red, blue, red_ans, blue_ans,&doflag);
        money+=(get-2);
        printf("%d %d\n",get, money);
        if (doflag == 1)
        {
            break;
        }

    }
    cout << "money "<<money<<" time "<<time;
    fclose(stdout);
    return 0;
}

int check(int red[6], int blue, int red_ans[6], int blue_ans,int* doflag)
{
    int redget=0;
    int blueget=0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0;j < 6; j++)
        {
            if (red[i] == red_ans[j])
            {
                redget++;
            }
        }
    }
    if (blue == blue_ans)
    {
        blueget = 1;
    }
    if (redget == 6 && blueget == 1)
    {
        printf("HAHA");
        *doflag = 1;
        return 5000000;
    }
    else if (redget == 6 && blueget == 0)
    {
        printf("haha");
        *doflag = 1;
        return 50000;
    }
    else if (redget == 5 && blueget == 1)
    {
        return 3000;
    }
    else if ((redget == 5 && blueget == 0) || (redget == 4 && blueget == 1))
    {
        return 200;
    }
    else if ((redget == 4 && blueget == 0) || (redget == 3 && blueget == 1))
    {
        return 10;
    }
    else if ((redget == 2 && blueget == 1) || (redget == 1 && blueget == 1) || (redget == 0 && blueget == 1))
    {
        return 5;
    }
    else {
        return 0;
    }

}

