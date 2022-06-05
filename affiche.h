// affiche.h
#ifndef AFFICHE_H
#define AFFICHE_H
#define TAILLE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLES 4; 
#define NB_ROTATIONS 4; 
#define NB_PIECE 7; 
void affiche_plat(int plateau_j[TAILLE][TAILLE]);
int get_orientation(int tabPiece[7][4][4][4], int forme );
void Placer_Piece_Utilisateur(int plateau_j[10][10],int tabPiece[7][4][4][4]);  

int verif(int tabPiece[7][4][4][4], int piece, int orientation);
int MaxLigne(int plateau_j[10][10], int colonne, int larg, int piece [4][4]);
int PasDePlace(int plateau_j[TAILLE][TAILLE],int tabPiece[7][4][4][4],int piece, int orientation, int colonne);
int detecter(int plateau_j[TAILLE][TAILLE]);

void disparaitre(int plateau_j[TAILLE][TAILLE],int ligne);

int score(int plateau_j[TAILLE][TAILLE]);

int repeter_tab(int plateau_j[TAILLE][TAILLE],int tabPiece[7][4][4][4], time_t start);


#endif //AFFICHE_H
