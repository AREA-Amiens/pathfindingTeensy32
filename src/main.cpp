#include <pathfindingTeensy32.h>

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("com ok");
  int xpos=10;//position courante du robot
  int ypos=32;
  depart.x=xpos;
  depart.y=ypos;
  depart.h=0;
  objectif.x=xpos+62;
  objectif.y=ypos+12;
  objectif.h=1000;
  initTable();
  table[depart.x][depart.y]=2;
  table[objectif.x][objectif.y]=3;

  algoAstar(table,objectif,depart);
  delay(1000);

  affichetab();
}

void loop() {

}

void affichetab(){
  //Serial.print("b");
  for(int i=0;i<150;i++){
    for(int j=0;j<100;j++){
      Serial.print(table[i][j]);

    }
    Serial.println();
}
}
void initTable(){
  //definition des tassots sur la table2020 et initialise le tableau

  for (int  i=93;i<100;i++){
    table[45][i]=1;
    table[46][i]=1;
  }

  for (int   i=85;i<100;i++){
    table[75][i]=1;
    table[76][i]=1;
  }

  for (int   i=93;i<100;i++){
    table[105][i]=1;
    table[106][i]=1;
  }
}

void algoAstar(uint8_t table[150][100], noeud objectif, noeud depart){

  pente = ((objectif.y-depart.y)/(objectif.x-depart.x))*10;
  Serial.println(pente);
  if(pente>1000&&objectif.y<depart.y)dir=0; //cas ou l'objectif est au dessus du robot dans l'axe des y (pente infini)
  if(pente>1000&&objectif.y>depart.y)dir=1; //cas ou l'objectif est au dessous du robot dans l'axe des y (pente infini)
  if(pente>=0&&objectif.x>depart.x)dir=2; //cas ou l'objectif est en haut à droite du robot
  if(pente>=0&&objectif.x<depart.x)dir=3; //cas ou l'objectif est en bas à gauche du robot
  if(pente<0&&objectif.x>depart.x)dir=4; //cas ou l'objectif est bas à droite du robot
  if(pente<0&&objectif.x<depart.x)dir=5; //cas ou l'objectif est en haut à gauche du robot
  choixdir(dir,objectif,depart);
  for(int i=0;i<3;i++){
    if((table[listeAttente[i].x][listeAttente[i].y]==1)||(table[listeAttente[i].x][listeAttente[i].y]==6)){
      noeudfaux++;
    }

    if(noeudfaux==3){
      switch(dir){
        case 0:
        dir=2;
        choixdir(dir,objectif,listeRetenue[nbrnoeud-1]);
        case 1:
        dir=3;
        choixdir(dir,objectif,listeRetenue[nbrnoeud-1]);
        case 2:
        dir=4;
        choixdir(dir,objectif,listeRetenue[nbrnoeud-1]);
        case 3:
        dir=5;
        choixdir(dir,objectif,listeRetenue[nbrnoeud-1]);
        case 4:
        dir=0;
        choixdir(dir,objectif,listeRetenue[nbrnoeud-1]);
        case 5:
        dir=2;
        choixdir(dir,objectif,listeRetenue[nbrnoeud-1]);
      }
    }
  }

  listeRetenue[nbrnoeud]=listeAttente[0];
  table[listeRetenue[nbrnoeud].x][listeRetenue[nbrnoeud].y]=4;
  if((listeRetenue[nbrnoeud].x!=objectif.x)&&(listeRetenue[nbrnoeud].y!=objectif.y)){
    algoAstar(table,objectif,listeRetenue[nbrnoeud]);
  }
  nbrnoeud++;

}

void triliste(noeud liste[3]){
  noeud temp;
  for(int i=0;i<3;i++){
      if(liste[i+1].h<liste[i].h){
        temp=liste[i];
        liste[i]=liste[i+1];
        liste[i+1]=temp;
      }
  }
}

void choixdir(uint8_t dir,noeud objectif, noeud depart){
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
    triliste(listeAttente);
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
    triliste(listeAttente);

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
    triliste(listeAttente);

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
    triliste(listeAttente);

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
    triliste(listeAttente);

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
    triliste(listeAttente);

  }
}
