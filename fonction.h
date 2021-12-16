#include <gtk/gtk.h>

typedef struct 
{
char username[50];
char password[50];
}user;
/*
typedef struct 
{
int jour [29]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
int heure [24]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
int etage [3]={1,2,3};

}debit;


void tester_debit (debit d);
*/
void ajouter_user ( user u , char nomf[]);
void ajouter_admin ( user a , char nomf[]);
void afficher_users(GtkTreeView *liste);
void supprimer (user u , char nomf[]);

int verifier_username ( user u , char nomf[]);
int verifier_admin ( user a , char nomf[]);
void modifier_user (user u , char nomf[]);
void modifier_pw (user u , char nomf[]);
