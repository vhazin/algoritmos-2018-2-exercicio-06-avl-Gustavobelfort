#include <stdio.h>
#include <stdlib.h>

#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

int index = 0;
int checkAVL(int arrayT[], int index, int arraySize);

int main(void) 
{
  int testNumber;

  scanf("%d", &testNumber);
  while(testNumber--)
  {
    int arraySize, counter = 0;
    scanf("%d", &arraySize);
    if(arraySize == 0){
        printf("T\n");
        continue;
    }
    int arrayTree[arraySize];
    while(counter<arraySize)
    {
      scanf("%d", (arrayTree+counter));
      counter++;
    }
    checkAVL(arrayTree, 0, arraySize) == -1 ? printf("F\n") : printf("T\n");
  }

  return 0;
}

int checkAVL(int arrayT[], int index, int arraySize)
{
  if(arrayT[index] == -1 || index >= arraySize){
    return 0;
  }
  
  index = (2*index)+1;
  int leftHeight = checkAVL(arrayT, index, arraySize);
  if(leftHeight == -1)
  {
    return -1;
  }

  index = (2*index)+2;
  int rightHeight = checkAVL(arrayT, index, arraySize);
  if(rightHeight == -1)
  {
    return -1;
  }

  if(abs(leftHeight - rightHeight) > 1)
  {
    return -1;
  }

  return 1+(max(leftHeight, rightHeight));

}
