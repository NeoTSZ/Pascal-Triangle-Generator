
// Earl James Williams Aliñgasa (NeoTSZ on GitHub)

/*============================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*============================================================*/

#define MAX_LAYER_COUNT 100

/*============================================================*/

int main() {
  double tempArray[MAX_LAYER_COUNT + 1],
  mainArray[MAX_LAYER_COUNT];
  int layerCount,
  cellWidth,
  spaceCount;

  char choice;

  newMenu:

  system("@cls||clear");

  // Getting input
  printf("\n:: PASCAL TRIANGLE GENERATOR ::\n\nEnter the number of layers you would like to generate for the Pascal Triangle. (Up to %d layers)\n\n%c ", MAX_LAYER_COUNT, 175);
  badInput:
  scanf("%d", &layerCount);
  if (layerCount < 1 || layerCount > MAX_LAYER_COUNT) {
    printf("\n:: INVALID INPUT ::\nPlease try again.\n\n%c ", 175);
    goto badInput;
  }

  // Initializing arrays
  for (int i = 0; i < MAX_LAYER_COUNT + 1; i++) {
    tempArray[i] = 0;
    if (i < MAX_LAYER_COUNT)
      mainArray[i] = 0;
  }
  tempArray[1] = 1;
  mainArray[0] = 1;

  // Getting cellWidth
  for (int currentLayer = 1; currentLayer <= layerCount; currentLayer++) {
    // Setting value of cellWidth
    if (currentLayer == layerCount)
      cellWidth = 3 + (int) log10(mainArray[layerCount / 2]);

    // Updating mainArray[]
    for (int i = 0; i < MAX_LAYER_COUNT; i++)
      mainArray[i] = tempArray[i] + tempArray[i + 1];

    // Updating tempArray[]
    for (int i = 0; i < MAX_LAYER_COUNT; i++)
      tempArray[i + 1] = mainArray[i];
  }

  // Making cellWidth odd
  if (cellWidth % 2 == 0)
    cellWidth++;

  // Re-initializing arrays
  for (int i = 0; i < MAX_LAYER_COUNT + 1; i++) {
    tempArray[i] = 0;
    if (i < MAX_LAYER_COUNT)
      mainArray[i] = 0;
  }
  tempArray[1] = 1;
  mainArray[0] = 1;

  for (int currentLayer = 1; currentLayer <= layerCount; currentLayer++) {
    printf("\n");

    // Printing leading spaces
    for (int spaceBlock = layerCount - currentLayer; spaceBlock > 0; spaceBlock--) {
      for (int space = 0; space <= cellWidth / 2; space++)
        printf("%c", 255);
    }

    // Printing top left border
    printf("%c", 218);

    // Printing middle borders
    for (int border = 1; border <= ((currentLayer * 2) - 1); border++) {
      if (border % 2 == 0)
        printf("%c", 194);
      else {
        for (int i = 1; i <= cellWidth; i++) {
          if ((i == (cellWidth + 1) / 2) && currentLayer != 1)
            printf("%c", 193);
          else if (i == (cellWidth + 1) / 2)
            printf("%c", 196);
          else
            printf("%c", 196);
        }
      }
    }

    // Printing top right border
    printf("%c", 191);

    printf("\n");

    // Printing leading spaces
    for (int spaceBlock = layerCount - currentLayer; spaceBlock > 0; spaceBlock--) {
      for (int space = 0; space <= cellWidth / 2; space++)
        printf("%c", 255);
    }

    // Printing digits
    for (int i = 0; i < currentLayer; i++) {
      // Printing left cell border
      printf("%c", 179);

      // Getting space count for cell number centering
      spaceCount = cellWidth - ((int) log10(mainArray[i])) - 1;

      // Printing spaces on left of number
      for (int space = 1; space <= (spaceCount / 2); space++)
        printf("%c", 255);

      // Printing number
      printf("%.0lf", mainArray[i]);

      // Printing spaces on right of number
      for (int space = 1; space <= ((spaceCount + 1) / 2); space++)
        printf("%c", 255);
    }

    // Printing end of line
    printf("%c", 179);

    // Printing bottom border
    if (currentLayer == layerCount) {
      // Printing bottom left border
      printf("\n%c", 192);

      // Printing middle borders
      for (int border = 1; border <= ((currentLayer * 2) - 1); border++) {
        if (border % 2 == 0)
          printf("%c", 193);
        else {
          for (int i = 1; i <= cellWidth; i++)
            printf("%c", 196);
        }
      }

      // Printing bottom right border
      printf("%c", 217);

      break;
    }

    // Updating mainArray[]
    for (int i = 0; i < MAX_LAYER_COUNT; i++)
      mainArray[i] = tempArray[i] + tempArray[i + 1];

    // Updating tempArray[]
    for (int i = 0; i < MAX_LAYER_COUNT; i++)
      tempArray[i + 1] = mainArray[i];
  }

  // Checking for more inputs
  printf("\n\nWould you like to generate another Pascal Triangle? (y/n)\n\n%c ", 175);
  badChoice:
  fflush(stdin);
  scanf("%c", &choice);
  if (choice == 'Y' || choice == 'y')
    goto newMenu;
  else if (choice == 'N' || choice == 'n') {
    printf("\n:: EXITING PROGRAM ::\n\n");
    return 0;
  }
  else {
    printf("\n:: INVALID CHOICE ::\nPlease try again.\n\n%c ", 175);
    goto badChoice;
  }

  return 0;
}