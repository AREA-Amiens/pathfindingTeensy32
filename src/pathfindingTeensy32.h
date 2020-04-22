#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  int x; //position x,y du noeud
  int y;
  float h; // heuristique
}noeud;

int table[778][520];

noeud listeRetenue[500]; //liste retenue de noeud
noeud listeAttente[3];
noeud n1;
noeud n2;
noeud n3;

noeud noeudcourant;
noeud posrobot;
noeud objectif;
noeud noeudparent;

float pente;
float b;
int dir;
int noeudfaux=0;
int nbrnoeud;

int xcourant;
int ycourant;

float t1;
float ttot;
float pente1;
float pente2;
float pente3;

void triliste(noeud liste[3]);
void choixdir(int dir,noeud objectif,noeud depart);
void algoPAstar(int table1[778][520],noeud objectif,noeud depart);
void initTable();
void affichetab();
void posEnemi(int posx,int posy);
void cheminRobot(/*noeud liste[150]*/);
