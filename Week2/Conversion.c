#include <stdio.h>
#include <math.h>

int main(void)
{

   /* Declare variables */
   int i, inum, tmp;
   float fnum;
   char binnum[60];

   /* Intialise 4-byte integer */
   inum = 33554431;
   /* Convert to 4-byte float */
   fnum = (float)inum;

   /* Convert to binary number (string)*/
   i = 0;
   tmp = inum;
   while (tmp > 0)
   {
      sprintf(&binnum[i], "%1d", tmp % 2);
      tmp = tmp / 2;
      i++;
   }

   /* Terminate the string */
   binnum[i] = '\0';

   /* Complete the expression */
   int numdigits_inum = ceil(log2((double)inum));
   int numdigits_fnum = ceil(log2((double)fnum));

   /* Results */
   printf("inum(binary) = %s\n", binnum);
   printf("The number of binary digits represented by int = %d\n", numdigits_inum);
   printf("Number of digits represented by float = %d\n", numdigits_fnum);

   return 0;
}
