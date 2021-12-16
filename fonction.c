#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "fonction.h"
#include "callbacks.h"
#include "interface.h"
#include <string.h>
#include "support.h"
#include <stdio.h>
/////verif/////
int verifier_user (user u2 , char nomf[])
{
int trouve =-1;
FILE *f1=NULL;
user u;
f1=fopen("user.txt","r");
if (f1!=NULL)
{
while (fscanf(f1,"%s %s ",&(u2.username), &(u2.password))!=EOF)
{
if ((strcmp(u2.username,u.username)==0)&&(strcmp(u2.password,u.password)==0))
trouve = 1;
}
fclose(f1);
}

return trouve ;
}
int verifier_admin (user a , char nomf[])
{
int trouve =-1;
FILE *f2=NULL;
char ch1[20];
char ch2[20];
f2=fopen("admin.txt","a+");
if (f2!=NULL)
{
while (fscanf(f2,"%s %s ",ch1, ch2)!=EOF)
{
if ((strcmp(ch1,a.username)==0)&&(strcmp(ch2,a.password)==0))
trouve = 1;
}
fclose(f2);
}

return trouve ;
}
//////////////////

/////debit///
/*
void tester_debit (debit d)
{

}

/////////////

*/

//////ajout//////
void ajouter_user (user u , char nomf[])
{

FILE *f;
f= fopen("user.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s \n" , u.username , u.password);
fclose(f);
}
}
void ajouter_admin (user a , char nomf2[])
{

FILE *f2;
f2= fopen("admin.txt","a+");
if (f2!=NULL)
{
fprintf(f2,"%s %s \n" , a.username , a.password);
fclose(f2);
}
}
//////////

////////supprimer///////
void supprimer (user u , char nomf[])

{

user u2; 

FILE *f,*g;
f=fopen("user.txt","r");
g=fopen("user2.txt","w");

if (f==NULL || g==NULL)
		return;

else
	{
		while(fscanf(f,"%s %s\n", u2.username,u2.password)!=EOF)
			{
		if ( strcmp (u.username, u2.username)!=0 ||  strcmp (u.password, u2.password)!=0 )
			fprintf(g, "%s %s\n", u2.username, u2.password);
			}
	fclose(f);
	fclose(g);
remove("user.txt" );
rename("user2.txt","user.txt");
	}
}
////////////////////

///////modif///////

void modifier_user (user u , char nomf[])
{
user m;
FILE *f, *g;
f=fopen("user.txt","r");
f=fopen("modif.txt","w");
if (f==NULL||g==NULL)
{
return;
}
else 
{
while (fscanf(f,"%s", &(m.username))!=EOF)
{
if (m.username!=u.username)
fprintf(g,"%s %s",m.username,u.password);
else 
fprintf(g,"%s %s",u.username,u.password);
}
fclose(f);
fclose(g);
remove("user.txt");
rename("modif.txt","user.txt");

}
}

void modifier_pw (user u , char nomf[])
{
user m;
FILE *f, *g;
f=fopen("user.txt","r");
f=fopen("modif.txt","w");
if (f==NULL||g==NULL)
{
return;
}
else 
{
while (fscanf(f,"%s %s", &(m.username), &(m.password))!=EOF)
{
if (m.username!=u.username)
fprintf(g,"%s %s",m.username,m.password);
else 
fprintf(g,"%s %s",u.username,u.password);
}
fclose(f);
fclose(g);
remove("user.txt");
rename("modif.txt","user.txt");

}
}

///////////////////

/////// PARTIE TREEVIEW

enum
{
EUSERNAME,
EPASSWORD,
COLUMNS,
};

void afficher_users(GtkTreeView *liste)
{
user u;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter  iter;
GtkListStore  *store;
char username [50];
char password[50];

store=NULL;
FILE *f;

store=gtk_tree_view_get_model(liste);
if(store=NULL)
{
renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("username", renderer , "text", EUSERNAME, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("password", renderer , "text", EPASSWORD, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
 
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("user.txt", "r");
if (f==NULL)
{
return;
}
else 
{
	f = fopen("user.txt","a+");
	while(fscanf(f,"%s %s \n", username, password)!= EOF)
	{
		sprintf(username, "%s", u.username);
		sprintf(password, "%s", u.password);
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store, &iter, EUSERNAME, u.username, EPASSWORD, u.password, -1);
	}
	fclose(f);
	gtk_tree_view_set_model  (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);

}

}







