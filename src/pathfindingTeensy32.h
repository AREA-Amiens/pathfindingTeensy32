#include <Arduino.h>

typedef struct{
  uint8_t x; //position x,y du noeud
  uint8_t y;
  float h; // heuristique
}noeud;

void triliste(noeud liste[3]);
void choixdir(uint8_t dir,noeud objectif);

uint8_t table[150][100];

noeud listeRetenue[100]; //liste retenue de noeud
noeud listeAttente[3];
noeud n1;
noeud n2;
noeud n3;
noeud depart;
noeud arrive;
noeud noeudcourant;
noeud noeudparent;

float pente;

uint8_t dir;
uint8_t noeudfaux=0;
uint8_t nbrnoeud=0;

uint8_t xcourant;
uint8_t ycourant;

uint8_t xparent;
uint8_t yparent;
