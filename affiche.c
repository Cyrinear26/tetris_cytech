#define TAILLE 10
#include "affiche.h"



//plateau de jeu
void affiche_plat(int plateau_j[TAILLE][TAILLE]){
    int i,j;
    int c;
   
    for(c=1;c<=10;c++){
        printf("  %d ",c);
    }
    printf("\n");
        for(i=0;i<10;i++){
             for(j=0;j<10;j++){
               if (plateau_j[i][j]==0){
                 printf("|   ");
               }
               else{
                 printf("| X ");
                 }}
          printf("|\n");
    }}
void vide_buffer(){
  while(getc(stdin)!='\n'){
     }}






//ou l'utilisateur veut placer la pièce?
void Placer_Piece_Utilisateur(int plateau_j[10][10],int tabPiece[7][4][4][4]){
  int colonne, i, j, ligne, max,orientation,piece,larg, hauteur;
  //choix au hasard des pieces
    srand(time(NULL));
    int forme = rand() %7;
  //quelle orientation?
    orientation = get_orientation(tabPiece, forme);
    printf("\nquelle colonne choisissez-vous?");
    scanf("%d",&colonne);
  //condition pour par ecrire n'importe quoi
  vide_buffer();
    while(colonne>10 || colonne<0){
      printf("\n vous sortez du tableau, recommencez:");
    scanf("%d",&colonne);
    vide_buffer();
    }
  max = verif(tabPiece,forme , orientation);
  if(colonne+max > 11){
      printf("\nvous le pouvez pas mettre cette pièce ici, recommencez:");
    scanf("%d",&colonne);
} 
  colonne--;
//verification pour emboitter les pièces
  hauteur = PasDePlace(plateau_j, tabPiece,forme, orientation,  colonne);
    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
        if(tabPiece[forme][orientation][3-i][j]==1){
          plateau_j[hauteur-i][j+colonne]=tabPiece[forme][orientation][3-i][j];
        }}}
  //detecter si ligne remplie
   detecter(plateau_j);

  }






//afficher les piece dans get orientation
void affiche_piece(int tabPiece[4][4]){
  int i,j;
   for(i=0;i<4;i++){
     printf("\t");
             for(j=0;j<4;j++){
               if (tabPiece[i][j]==0){
                 printf(" ");
               }
               else{
                 printf("X");
               }
            
        }
          printf("\n");
    }}






//choix de l'orientation de la piece par l'utilisateur
int get_orientation(int tabPiece[7][4][4][4], int forme ){
  int piece, orientation, i;
  for(i=0; i<4; i++){
    printf("%d\n",i+1);
    affiche_piece(tabPiece[forme][i]);

  }
  printf("\n quelle orientation choissisez vous? : ");
  scanf("%d", &orientation);
  while(orientation<1 || orientation>4){
    printf("\nrecommencez, quelle orientation choisissez vous? : \n");
    scanf("%d",&orientation);
    vide_buffer();
    }
  return (orientation-1);
}








// verfication de la largeur de la piece
int verif(int tabPiece[7][4][4][4], int piece, int orientation){
  int largeur;
  
  if(piece==1 && (orientation==1|| orientation==3)){
    largeur=1;
  }
  else if(piece==1 && (orientation==0|| orientation==2)){
    largeur=4;
  }
  else if(piece==0 || (piece==2 && (orientation==1 || orientation==3) ) || (piece==3 && (orientation==1 || orientation==3) ) || (piece==4 && (orientation==1 || orientation==3) ) || (piece==5 && (orientation==1 || orientation==3) )|| (piece==6 && (orientation==1 || orientation==3) )){

    largeur =2; 
  }
  else{
    largeur=3;
  } 
  return largeur;
}









//emboitement des pièces : verfication hauteur piece
int MaxLigne(int plateau_j[10][10], int colonne, int larg,int piece[4][4]){
    int i=0, j=0, hauteur=9;
    int hauteur_piece=0;
 
    for(j=colonne; j<colonne+larg; j++){
      hauteur_piece=0;
      i=0;
      while(plateau_j[i][j]!=1 && i<10){
        i++;
      }
      i--;
      if(piece[3][j-colonne]==0){
        hauteur_piece=1;
        if(piece[2][j-colonne]==0){
          hauteur_piece=2;
        }}
      i=i+hauteur_piece;
      
     
      if(i<hauteur){
        hauteur=i;
      }

      if(hauteur>9){
        hauteur=9;
      }}
  return hauteur;
  }







//place deja prise
  int PasDePlace(int plateau_j[TAILLE][TAILLE],int tabPiece[7][4][4][4],int piece, int orientation, int colonne){
    int largeur3, max, i;
    largeur3=verif(tabPiece, piece, orientation);
    max=MaxLigne(plateau_j, colonne, largeur3,tabPiece[piece][orientation]);
    return max;}


  





//detecter si ligne pleine:
int detecter(int plateau_j[TAILLE][TAILLE]){
  int i,j, compt,compt2;
  compt=0;
  compt2=0;
  for(i=9;i>=0;i--){
    for (j=0;j<10;j++){
      if(plateau_j[i][j]==1){
        compt++;
      }}
    if(compt==10){
      compt2++;
      printf("score=%d\n",compt2);
      //pb car score est tjr = 1
      disparaitre(plateau_j,i);
      detecter(plateau_j);
    }
    compt=0;
 }} 






//faire disparaitre une ligne complete
void disparaitre(int plateau_j[TAILLE][TAILLE], int ligne){
  int i, j;
  for(i=ligne; i>0;i--){
    for(j=0;j<10;j++){
      plateau_j[i][j]=plateau_j[i-1][j];
      }}}







//repeter le jeu + temps + jeu perdu
int repeter_tab(int plateau_j[TAILLE][TAILLE], int tabPiece[7][4][4][4],time_t start){
  int i;
  unsigned long score;
  int compt=0; 
    //time_t start = time(NULL);
for (i=0;i<10;i++){
  if(plateau_j[0][i]==1){
    compt++;
    }
  }
  if(compt>=1){
printf("vous avez perdu\n");
    time_t end = time(NULL);
score = difftime(end,start);
printf("temps du jeu : %ld secondes\n",score);
  }
  
  else{
    Placer_Piece_Utilisateur(plateau_j,tabPiece);
affiche_plat(plateau_j);
    repeter_tab(plateau_j,tabPiece,start);
    }
  }
