#include <stdio.h>
#include <math.h>

int main()
{
    double b, h,d, a, result = 0;
    printf("Enter interval limits:");
    scanf_s("%lf %lf", &a, &b);
    printf("Enter step:");
    scanf_s("%lf", &h);
    do 
    {
        if (a < 0.6)
            result = exp(a - sin(a));
        else   if (a >= 0.7)
            result = atan(pow(a, 7));
        else
            result = tan(fabs(log(a)));
       printf("%g: \t %lf\n", a, result);
       a += h;
    } while (roundf(a*1000)/1000 <= roundf(b*1000)/1000);
    

    printf("Enter interval limits:");
    scanf_s("%lf %lf", &a, &b);
    printf("Enter step:");
    scanf_s("%lf", &h);
    printf("Enter precision:");
    scanf_s("%lf", &d);
    int precis=0, j=0;//ітератор кількості близьких значень результату поспіль
    double temp_d = d, temp_res;
    while (temp_d < 1)
    {
        temp_d *= 10;
        ++precis;
    }

    for (; round(a*1000)/1000 <= round(b * 1000) / 1000; a += h)
    {
        result = 0, temp_res = 1;
        for (double k = 1;j<5; ++k)
        {
            if (fabs(result - temp_res) < d / 100)
                ++j;
            else 
                j = 0;

            temp_res = result;
            result += pow(-1, k) * a * sin(2 * k + 1) / (k * (k + 1));
        }
        j = 0;
        printf("%+.3lf: \t %+.*lf\n", a, precis, result);
    }
    
    return 0;
}

