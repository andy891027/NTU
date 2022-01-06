#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  /*身分證字號產生邏輯為一英文字（背後有代表數字）＋一位性別碼（1男2女）＋7位數字＋一位驗證碼（英文背後代表數字之十位數*1+個位數*9+性別碼*8+後續數字依序*7 *6...相加再取除10之餘數）*/
int main(void)
{
  /* 設定亂數種子 */
  srand( time(NULL) );
  int a;
  do{
     a = rand();
     a = a%35; 
  }while(a<10);/*隨機製造亂數，因身分證英文所代表的數字介於10~34，非0~34即重跑*/
  char list_county[] ={'A','B','C','D','E','F','G','H','J','K','L','M','N','P','Q','R','S','T','U','V','X','Y','W','Z','I'};
  char alpha = list_county[a-10];

  int a1 = a/10;
  int a2 = a%10;/* a1 a2為字母背後代表數字拆解*/
  int b = 0;
  do{
      b = rand();
      b = b%3;/*因第一碼數字僅有1和2，若為0即重跑*/
  }while(b == 0);
  
  /*製造後續各數*/
  int c = rand();
  c = c%10;
  int d = rand();
  d = d%10;
  int e = rand();
  e = e%10;
  int f = rand();
  f = f%10;
  int g = rand();
  g = g%10;
  int h = rand();
  h = h%10;
  int i = rand();
  i = i%10;

  int j;/*生成驗證碼*/
  j = (a1*1+a2*9+b*8+c*7+d*6+e*5+f*4+g*3+h*2+i)%10;

  printf("%c%d%d%d%d%d%d%d%d%d",alpha,b,c,d,e,f,g,h,i,j);/*印出身分證號*/
    return 0;
}
