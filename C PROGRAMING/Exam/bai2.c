#include <stdio.h>
#define max 1000

void daotu(char string[])
{
int i = 0, j = 0, length = 0;
while(string[length] != '\0')
{
   length++;
}

   // dao ki tu cua moi tu
   while(j<= length)
   {
      if(string[j]==' '|| string[j]=='\0' || string[j]=='.')
      {
         int x = i, y= j-1;
         while(x<y)
         {
            char temp = string[x];
            string[x]= string[y];
            string[y] = temp;
            x++;
            y--;
         }
         i = j + 1;
      }
      j++;
   }
// dao ki tu cua chuoi
int u =0, t=length-1;
while (u<t)
{
   char temp= string[u];
   string[u]= string[t];
   string[t]= temp;
   u++;
   t--;
}

}
int main()
{
   char string1[max]= "dao ki tu cua doan van.";
   daotu(string1);
   printf("%s", string1);
   return 0;

}