#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "texture_packs/texturesMobile.dat"
#include <unistd.h>
#include "source/rooms.dat"

int minDamage = 1;
int maxDamage = 3;

int inventorySlot = 1;
int inventory[] = {2};
int inventoryIndex = (0);
void showInventory() {
  inventoryIndex = (0);
  while (inventoryIndex < 19) {
    printf("\n");
    if (inventory[inventoryIndex] == 0) {
      //0 code
    }
    if (inventory[inventoryIndex] == 1) {
      printf("Gp");
    }
    if (inventory[inventoryIndex] == 2) {
      printf("Charm of Sight");
    }

    inventoryIndex = (inventoryIndex + 1);
  }
  sleep(2);
  return;
}

int rand_num = 0;
void generate_random(int l, int r, int count) {
   int i;
   for (i = 0; i < count; i++) {
      rand_num = (rand() % (r - l + 1)) + l;
      
   }
}
//26 pc
//3 watch

int mapSize = 20;

float map[150][300] = {};

float mapPlan[15][15] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


int mapUnitMax = 15;
int countX = (0);
int countY = (0);
int playerX = (110);
int playerY = (55);
int index2 = 0;
int mapUnitX = 3;
int mapUnitY = 3;

int level = 0;

void genMap() {
  int mapPlanIndex = 0;
  usleep(100);
  int randMapDir = 0;
  int mapGenPos[] = {0,0};

  while (mapGenPos[1] < 15) {
    mapGenPos[0] = 0;
    while (mapGenPos[0] < 15) {
      generate_random(1,23,1);
      if (rand_num == 0) {
        generate_random(1,23,1);
      }
      if (rand_num == 3) {
        generate_random(0,level,1);
        if (rand_num == 0) {
          generate_random(1,23,1);
        }
        else{
          rand_num = 3;
        }
      }
      if (rand_num == 4) {
        generate_random(0,level,1);
        if (rand_num == 0) {
          generate_random(1,23,1);
        }
        else{
          rand_num = 4;
        }
      }
      if (rand_num == 10) {
        generate_random(0,level,1);
        if (rand_num == 0) {
          generate_random(1,23,1);
        }
        else{
          rand_num = 10;
        }
      }

      if (rand_num == 12) {
        generate_random(1,23,1);
        if (rand_num == 12) {
          mapPlan[mapGenPos[0] - 1][mapGenPos[1] - 1] = 12.25;
          mapPlan[mapGenPos[0] - 1][mapGenPos[1]] = 12.5;
          mapPlan[mapGenPos[0]][mapGenPos[1] - 1] = 12.75;
        }
      }

      if (rand_num == 15) {
        rand_num = 1;
      }
      if (rand_num == 16) {
        rand_num = 1;
      }
      if (rand_num == 17) {
        rand_num = 1;
      }
      
      mapPlan[mapGenPos[0]][mapGenPos[1]] = rand_num;
      mapGenPos[0] = mapGenPos[0] + 1;
    }
    mapGenPos[1] = mapGenPos[1] + 1;
  } 
  mapPlan[0][0] = 0;
  mapPlan[1][0] = 0;
  mapPlan[2][0] = 0;
  mapPlan[3][0] = 0;
  mapPlan[4][0] = 0;
  mapPlan[5][0] = 0;
  mapPlan[6][0] = 0;
  mapPlan[7][0] = 0;
  mapPlan[8][0] = 0;
  mapPlan[9][0] = 0;
  mapPlan[10][0] = 0;
  mapPlan[11][0] = 0;
  mapPlan[12][0] = 0;
  mapPlan[13][0] = 0;
  mapPlan[14][0] = 0;
  mapPlan[0][14] = 0;
  mapPlan[1][14] = 0;
  mapPlan[2][14] = 0;
  mapPlan[3][14] = 0;
  mapPlan[4][14] = 0;
  mapPlan[5][14] = 0;
  mapPlan[6][14] = 0;
  mapPlan[7][14] = 0;
  mapPlan[8][14] = 0;
  mapPlan[9][14] = 0;
  mapPlan[10][14] = 0;
  mapPlan[11][14] = 0;
  mapPlan[12][14] = 0;
  mapPlan[13][14] = 0;
  mapPlan[14][14] = 0;
  mapPlan[0][1] = 0;
  mapPlan[0][2] = 0;
  mapPlan[0][3] = 0;
  mapPlan[0][4] = 0;
  mapPlan[0][5] = 0;
  mapPlan[0][6] = 0;
  mapPlan[0][7] = 0;
  mapPlan[0][8] = 0;
  mapPlan[0][9] = 0;
  mapPlan[0][10] = 0;
  mapPlan[0][11] = 0;
  mapPlan[0][12] = 0;
  mapPlan[0][13] = 0;
  mapPlan[0][14] = 0;
  mapPlan[0][0] = 0;
  mapPlan[14][1] = 0;
  mapPlan[14][2] = 0;
  mapPlan[14][3] = 0;
  mapPlan[14][4] = 0;
  mapPlan[14][5] = 0;
  mapPlan[14][6] = 0;
  mapPlan[14][7] = 0;
  mapPlan[14][8] = 0;
  mapPlan[14][9] = 0;
  mapPlan[14][10] = 0;
  mapPlan[14][11] = 0;
  mapPlan[14][12] = 0;
  mapPlan[14][13] = 0;
  mapPlan[14][14] = 0;
  mapPlan[14][0] = 0;
  mapPlan[5][5] = 1;
  generate_random(2,12,1);
  int tempRandY = rand_num;
  generate_random(2,12,1);
  mapPlan[tempRandY][rand_num] = -1;
  mapPlan[tempRandY][rand_num - 1] = 15;
  mapPlan[tempRandY][rand_num + 1] = 16;
  mapPlan[tempRandY - 1][rand_num + 1] = 12;
  mapPlan[tempRandY - 1][rand_num - 1] = 12.75;
  mapPlan[tempRandY - 2][rand_num - 1] = 12.25;
  mapPlan[tempRandY - 2][rand_num + 1] = 12.5;
  mapPlan[tempRandY - 1][rand_num] = -2;
  mapPlan[tempRandY - 2][rand_num] = -3;
  return;
}

void generateMap() {
  countX = 0;
  countY = 0;
  mapUnitX = 0;
  mapUnitY = 0;
  while (mapUnitY < mapUnitMax) {
    mapUnitX = 0;
    while (mapUnitX < mapUnitMax) {
      countY = 0;
      
      generate_random(1,4,1);
      while (countY < 10) {
        countX = 0;
        while (countX < 20) {
          if (mapPlan[mapUnitY][mapUnitX] == 1) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room1[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 2) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room2[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 0) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room0[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 3) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room3[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 4) {
            if (rand_num == 1) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room4a[countY][countX];
            }
            if (rand_num == 2) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room4b[countY][countX];
            }
            if (rand_num == 3) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room4c[countY][countX];
            }
            if (rand_num == 4) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room4d[countY][countX];
            }
          }
          if (mapPlan[mapUnitY][mapUnitX] == 5) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room5[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 6) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room6[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 7) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room7[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 8) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room8[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 9) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room9[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 10) {
            if (rand_num == 1) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room10a[countY][countX];
            }
            if (rand_num == 2) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room10b[countY][countX];
            }
            if (rand_num == 3) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room10c[countY][countX];
            }
            if (rand_num == 4) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room10d[countY][countX];
            }
          }
          if (mapPlan[mapUnitY][mapUnitX] == 11) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room11[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 12) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room12c[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 12.25) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room12a[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 12.5) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room12b[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 12.75) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room12d[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 13) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room13[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 14) {
            if(rand_num == 1) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room14a[countY][countX];
            }
            if(rand_num == 2) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room14b[countY][countX];
            }
            if(rand_num == 3) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room14c[countY][countX];
            }
            if(rand_num == 4) {
              map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room14d[countY][countX];
            }
          }
          if (mapPlan[mapUnitY][mapUnitX] == 15) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room15[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 16) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room16[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 17) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room17[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 18) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room18[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 19) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room19[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 20) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room20[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 21) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room21[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == -1) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = roomExit[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == -2) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room12f[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == -3) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room12e[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 22) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room22[countY][countX];
          }
          if (mapPlan[mapUnitY][mapUnitX] == 23) {
            map[countY + (mapUnitY * 10)][countX + (mapUnitX  * 20)] = room23[countY][countX];
          }
          countX = countX + 1;
        }
        countY = countY + 1;
      }

      mapUnitX = mapUnitX + 1;
    }
    mapUnitY = mapUnitY + 1;
  }
  return;
}
char startK;

int distance(float x1,float y1,float x2,float y2) {
  int Xdist = abs(x1 - x2);
  int Ydist = abs(y1 - y2);
  int dist = abs((Ydist / 2) + (Xdist / 2));
  return dist;
}

#include "source/rat.dat"

void type_text(char *s, float ms_delay)
{
   float usecs = ms_delay * 1000; /* 1000 microseconds per ms */

   for (; *s; s++) {
      putchar(*s);
      fflush(stdout); /* alternatively, do once: setbuf(stdout, NULL); */
      usleep(usecs);
   }
}

float Health = 40.00;
int barCount = 0;

void displayPlayerStats() {
  printf("|");
  while (barCount < (Health / 2)) {
    printf("#");
    barCount = barCount + 1;
  }
  barCount = 0;
  while (barCount < (20 - (Health / 2))) {
    printf(" ");
    barCount = barCount + 1;
  }
  printf("|");
}

void playerUpdate() {
  map[playerY][playerX] = (0);
}
int tempRand = 0;

void loadMap(float loadSpeed){
  countY = playerY - (mapSize / 2.2);
  system("clear");
  while (countY < (mapSize + (playerY - (mapSize / 2.2)))) {
    countX = playerX - (mapSize * 1.4);

    while (countX < ((mapSize * 2.8) + (playerX  - (mapSize * 1.4)))) {
      if (loadSpeed != 0) {
        usleep(loadSpeed);
      }
      if (map[countY][countX] == 1) {
        printf( & player[0] );
      }
      else if (map[countY][countX] == 2) {
        printf( & wall[0] );
      }
      else if (map[countY][countX] == 3) {
        printf( & enemy[0] );
      }
      else if (map[countY][countX] == 4) {
        printf( & door[0] );
      }
      else if (map[countY][countX] == 5) {
        printf("❔ ");
      }
      else if (map[countY][countX] == 6) {
        printf( & chainFence[0] );
      }
      else if (map[countY][countX] == 7) {
        printf( & wallGrid[0] );
      }
      else if (map[countY][countX] == 8) {
        printf( & wall[0] );
      }
      else if (map[countY][countX] == 9) {
        printf( & chest[0] );
      }
      else if (map[countY][countX] == 10) {
        printf( & gp[0] );
      }
      else if (map[countY][countX] == 11) {
        printf( & ironBaracade[0] );
      }
      else if (map[countY][countX] == 12) {
        printf( & arcaneWall[0] );
      }
      else if (map[countY][countX] == 13) {
        printf( & arcaneScroll[0] );
      }
      else if (map[countY][countX] == 14) {
        printf( & clearScroll[0] );
      }
      else {
        printf( & floor[0] );
      }
      countX = countX + 1;
      
    }  
  countY = countY + 1;
  printf("\n");
  }
}

void nextFloor() {
  createRats();
  level = level + 1;
  system("clear");
  char levelChar = char(level);
  type_text("Decending to next floor ",  50);
  genMap();
  generateMap();
  playerX = (110);
  playerY = (55);
  loadMap(500);
}

//main loop

int loop(void) {
  index2 = 0;
  map[playerY][playerX] = (1);

  renderRats();

  loadMap(0);

  char z[1] = {'z'};
  char e[1] = {'e'};
  char w[1] = {'w'};
  char a[1] = {'a'};
  char s[1] = {'s'};
  char d[1] = {'d'};
  char stringKey[] = "";
  char key;
		printf("\n");
    displayPlayerStats();
		scanf("%c", &key);
		printf("\n");

    stringKey[0] = key;
    if (stringKey[0] == w[0]) {
      playerUpdate();
      if ((map[playerY - 1][playerX]) == (0)) {
        playerY = playerY - 1;   
      }
      if ((map[playerY - 1][playerX]) == (4)) {
        playerY = playerY - 1;
        nextFloor();
      }
      if ((map[playerY - 1][playerX]) == (8)) {
        playerY = playerY - 1;
      }
      if ((map[playerY - 1][playerX]) == (10)) {
        map[playerY - 1][playerX] = (0);
        
      }
      if ((map[playerY - 1][playerX]) == (9)) {
        map[playerY - 1][playerX] = (10);
      }
    }

    if (stringKey[0] == e[0]) {
      showInventory();
    }

    if (stringKey[0] == z[0]) {
      generate_random(minDamage,maxDamage,1);
      damageCloseRat(rand_num);
    }
    
    if (stringKey[0] == s[0]) {
      playerUpdate();
      if ((map[playerY + 1][playerX]) == (0)) {
        playerY = playerY + 1;   
      }
      if ((map[playerY + 1][playerX]) == (4)) {
        playerY = playerY + 1;
      }
      if ((map[playerY + 1][playerX]) == (8)) {
        playerY = playerY + 1;
      }
    }

    if (stringKey[0] == a[0]) {
      playerUpdate();
      if ((map[playerY][playerX - 1]) == (0)) {
        playerX = playerX - 1;
      }
      if ((map[playerY][playerX - 1]) == (4)) {
        playerX = playerX - 1;
      }
      if ((map[playerY][playerX - 1]) == (8)) {
        playerX = playerX - 1;
      }
    }

    if (stringKey[0] == d[0]) {
      playerUpdate();
      if ((map[playerY][playerX + 1]) == (0)) {
        playerX = playerX + 1;   
      }
      if ((map[playerY][playerX + 1]) == (4)) {
        playerX = playerX + 1;
      }
      if ((map[playerY][playerX + 1]) == (8)) {
        playerX = playerX + 1;
      }
    }
  
  loop();
  return 0;
  
}

int main(void){
  srand ( time(NULL) );
  system("clear");
  sleep(1);
  type_text("The ", 150);
  printf("\n   ");
  type_text("D U N G E O N", 50);
  printf("\n                ");
  type_text("of A S C I I\n\n", 50);
  usleep(500);
  printf("\nPress enter to start\n");
  scanf("%c", &startK);
  genMap();
  generateMap();
  createRats();
  int mainCount = 0;
  system("clear"); 
  loop();
}
