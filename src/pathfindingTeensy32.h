#include <Arduino.h>

typedef struct{
  uint8_t x; //position x,y du noeud
  uint8_t y;
  int cout; // cout du noeud
  int h; // heuristique
}noeud;

uint8_t table[150][100];
