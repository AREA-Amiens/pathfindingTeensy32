#include <Arduino.h>

typedef struct{
  uint8_t x; //position x,y du noeud
  uint8_t y;
  float h; // heuristique
}noeud;

uint8_t table[150][100];

noeud listeRetenue[100]; //liste retenue de noeud
noeud listeAttente[3];
noeud n1;
noeud n2;
noeud n3;


float pente;
uint8_t dir;

uint8_t xcourant;
uint8_t ycourant;

uint8_t xparent;
uint8_t yparent;
