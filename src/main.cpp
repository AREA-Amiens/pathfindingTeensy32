#include <pathfindingTeensy32.h>
noeud depart;
noeud arrive;
noeud noeudcourant;
noeud noeudparent;
void setup() {
  int xpos;//position courante du robot
  int ypos;
  depart.x=xpos;
  depart.y=ypos;
  depart.h=0;
}

void loop() {
  // put your main code here, to run repeatedly:
}

int compareNoeud(noeud n1,noeud n2){
  if (n1.h<n2.h) return 1;
  else if(n1.h==n2.h) return 0;
  else return -1;
}
void algoAstar(uint8_t table[150][100], noeud objectif, noeud depart){
pente = (objectif.y-depart.y)/(objectif.x-depart.x);
if(pente>100&&objectif.y<depart.y)dir=0; //cas ou l'objectif est au dessus du robot dans l'axe des y (pente infini)
if(pente>100&&objectif.y>depart.y)dir=1; //cas ou l'objectif est au dessous du robot dans l'axe des y (pente infini)
if(pente>0&&objectif.x>depart.x)dir=2; //cas ou l'objectif est en haut à droite du robot
if(pente>0&&objectif.x<depart.x)dir=3; //cas ou l'objectif est en bas à gauche du robot
if(pente<0&&objectif.x>depart.x)dir=4; //cas ou l'objectif est bas à droite du robot
if(pente<0&&objectif.x<depart.x)dir=5; //cas ou l'objectif est en haut à gauche du robot
switch (dir) {
  case 0:
  xcourant= depart.x;
  ycourant= depart.y;
  n1.x=xcourant-1;
  n1.y=ycourant-1;
  n1.h=(objectif.x-n1.x)*(objectif.x-n1.x)+(objectif.y-n1.y)*(objectif.y-n1.y);
  n2.x=xcourant;
  n2.y=ycourant-1;
  n2.h=(objectif.x-n2.x)*(objectif.x-n2.x)+(objectif.y-n2.y)*(objectif.y-n2.y);
  n3.x=xcourant+1;
  n3.y=ycourant-1;
  n3.h=(objectif.x-n3.x)*(objectif.x-n3.x)+(objectif.y-n3.y)*(objectif.y-n3.y);
  listeAttente[0]=n1;
  listeAttente[1]=n2;
  listeAttente[2]=n3;
  case 1:
  xcourant= depart.x;
  ycourant= depart.y;
  n1.x=xcourant-1;
  n1.y=ycourant+1;
  n1.h=(objectif.x-n1.x)*(objectif.x-n1.x)+(objectif.y-n1.y)*(objectif.y-n1.y);
  n2.x=xcourant;
  n2.y=ycourant+1;
  n2.h=(objectif.x-n2.x)*(objectif.x-n2.x)+(objectif.y-n2.y)*(objectif.y-n2.y);
  n3.x=xcourant+1;
  n3.y=ycourant+1;
  n3.h=(objectif.x-n3.x)*(objectif.x-n3.x)+(objectif.y-n3.y)*(objectif.y-n3.y);
  listeAttente[0]=n1;
  listeAttente[1]=n2;
  listeAttente[2]=n3;
  case 2:
  xcourant= depart.x;
  ycourant= depart.y;
  n1.x=xcourant;
  n1.y=ycourant-1;
  n1.h=(objectif.x-n1.x)*(objectif.x-n1.x)+(objectif.y-n1.y)*(objectif.y-n1.y);
  n2.x=xcourant+1;
  n2.y=ycourant-1;
  n2.h=(objectif.x-n2.x)*(objectif.x-n2.x)+(objectif.y-n2.y)*(objectif.y-n2.y);
  n3.x=xcourant+1;
  n3.y=ycourant;
  n3.h=(objectif.x-n3.x)*(objectif.x-n3.x)+(objectif.y-n3.y)*(objectif.y-n3.y);
  listeAttente[0]=n1;
  listeAttente[1]=n2;
  listeAttente[2]=n3;
  case 3:
  xcourant= depart.x;
  ycourant= depart.y;
  n1.x=xcourant-1;
  n1.y=ycourant;
  n1.h=(objectif.x-n1.x)*(objectif.x-n1.x)+(objectif.y-n1.y)*(objectif.y-n1.y);
  n2.x=xcourant-1;
  n2.y=ycourant+1;
  n2.h=(objectif.x-n2.x)*(objectif.x-n2.x)+(objectif.y-n2.y)*(objectif.y-n2.y);
  n3.x=xcourant;
  n3.y=ycourant+1;
  n3.h=(objectif.x-n3.x)*(objectif.x-n3.x)+(objectif.y-n3.y)*(objectif.y-n3.y);
  listeAttente[0]=n1;
  listeAttente[1]=n2;
  listeAttente[2]=n3;
  case 4:
  xcourant= depart.x;
  ycourant= depart.y;
  n1.x=xcourant;
  n1.y=ycourant+1;
  n1.h=(objectif.x-n1.x)*(objectif.x-n1.x)+(objectif.y-n1.y)*(objectif.y-n1.y);
  n2.x=xcourant+1;
  n2.y=ycourant+1;
  n2.h=(objectif.x-n2.x)*(objectif.x-n2.x)+(objectif.y-n2.y)*(objectif.y-n2.y);
  n3.x=xcourant+1;
  n3.y=ycourant;
  n3.h=(objectif.x-n3.x)*(objectif.x-n3.x)+(objectif.y-n3.y)*(objectif.y-n3.y);
  listeAttente[0]=n1;
  listeAttente[1]=n2;
  listeAttente[2]=n3;
  case 5:
  xcourant= depart.x;
  ycourant= depart.y;
  n1.x=xcourant-1;
  n1.y=ycourant;
  n1.h=(objectif.x-n1.x)*(objectif.x-n1.x)+(objectif.y-n1.y)*(objectif.y-n1.y);
  n2.x=xcourant-1;
  n2.y=ycourant-1;
  n2.h=(objectif.x-n2.x)*(objectif.x-n2.x)+(objectif.y-n2.y)*(objectif.y-n2.y);
  n3.x=xcourant;
  n3.y=ycourant-1;
  n3.h=(objectif.x-n3.x)*(objectif.x-n3.x)+(objectif.y-n3.y)*(objectif.y-n3.y);
  listeAttente[0]=n1;
  listeAttente[1]=n2;
  listeAttente[2]=n3;
}
if(table[n1.x][n1.y]=!1){}
}
