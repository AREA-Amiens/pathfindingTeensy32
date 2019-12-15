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
  depart.cout=0;
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

}
