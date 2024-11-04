#include <stdio.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>
int d[11];
double random_p() {
    int rand_int = rand() % 11; // 0부터 10 사이의 정수 생성
    return rand_int / 10.0;     // 10으로 나누어 0.0부터 1.0 사이의 값 생성
}
int main()
{
  srand(time(NULL));
  int t = 10000;
  while (t--)
  {
    double p = random_p();
    if(p==0)
    {
      d[0]++;
    }
    else if(p==0.1)
    {
      d[1]++;
    }
    else if(p==0.2)
    {
      d[2]++;
    }
    else if(p==0.3)
    {
      d[3]++;
    }
    else if(p==0.4)
    {
      d[4]++;
    }
    else if(p==0.5)
    {
      d[5]++;
    }
    else if(p==0.6)
    {
      d[6]++;
    }
    else if(p==0.7)
    {
      d[7]++;
    }
    else if(p==0.8)
    {
      d[8]++;
    }
    else if(p==0.9)
    {
      d[9]++;
    }
    else if(p==1.0)
    {
      d[10]++;
    }
  //printf("%.2f ",p);
  }
  printf("\n\n");
  for(int i=0;i<11;i++)
  {
    printf("%d ",d[i]);
  }
}
