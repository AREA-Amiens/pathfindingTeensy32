#include <Arduino.h>

typedef struct{
  uint8_t x; //position x,y du noeud
  uint8_t y;
  int cout; // cout du noeud
  int h; // heuristique
}noeud;

uint8_t table[150][100];

int compareNoeud(noeud n1, noeud n2);

void algoAstar(uint8_t table[][],uint8_t objectif[][],uint8_t depart[][]);
