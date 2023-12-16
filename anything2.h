#ifndef TT_H_INCLUDED
#define TT_H_INCLUDED


//Partie Gestion client ;
///*********************************************

///***********************************************
typedef struct {
int num_maison;
char quartier[50];
char ville[50];

}Adress;

typedef struct {
    int CNI;
    char nom[50];
    char prenom[50];
    Adress adress ;
    char numero[20];
    char passwd[20];

} Client;


//**********************************************
typedef struct{
int existingId;
char existingNom[50];
char existingPrenom[50];
int existingPrix;
int existingQuantite;
}NProd;
//*********************************************
// Structure pour stocker les codes promo
typedef struct {
    char code[10];
    double reduction;  // La r�duction en pourcentage (0.1 pour 10%)
} CodePromo;
//**********************************************
typedef struct {
    int id;
    char nom[100];
    char prenom[100];
    int prix;
    int quantite_actuelle;
    int quantite_minimale;
    int quantite_ajouter;
    int topsales;
    char date[20];
} Produit;
//**********************************************

typedef struct {
    char nom[100];
    char prenom[100];
    int prix;
    int quantite;
} Produith;

typedef struct {
    int id_com;
    Client client ;
    int prixtotal ;
    char date_com1[20];
    char date_com2[20];
    char dat_final1[20];
    char dat_final2[20];
    int nmbr_art;
    Produith *produith;
} historique;
///*****************************************************
void entete(){
    int cni;
    char passwd[20];
    char nom[20];
    char prenom[20];
    Client client;
FILE* tmpo=fopen("tmp.txt","rt");
FILE* file_c=fopen("Client.txt","rt");
if(tmpo==NULL || file_c==NULL){
    printf("Error\n");
    exit(1);
}
fscanf(tmpo,"%d%s",&cni,passwd);
while(fscanf(file_c, "%d %s %s %d %s %s %s %s", &client.CNI, client.nom, client.prenom, &client.adress.num_maison,client.adress.quartier, client.adress.ville, client.numero, client.passwd) == 8){
       if(cni==client.CNI){
        strcpy(nom,client.nom);
        strcpy(prenom,client.prenom);
       }
}
fclose(tmpo);
fclose(file_c);
    printf("\n");
    printf(" +-----------------------------------------------------------------------+      \n");
    printf("     \033[1;34mNOZAMA\033[0m                                  \033[1;33m%s %s\033[0m            \n",nom,prenom);
    printf(" +-----------------------------------------------------------------------+      \n");
}
///***********************************************************************
FILE *  file_Historique(){
FILE * file =fopen("historique_comm.dat", "a+b");
if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(0);}
        return file ;
}
//*************************************************************
void affichageChargement() {
    int i;


    for (i = 0; i < 20; i++) {
        printf("\033[1;34m%c\033[0m", '|'); // Barre de chargement
        fflush(stdout);
        usleep(100000*0.5); // Pause de 100 millisecondes

        printf("\b"); // Efface le dernier caract re
        printf("\033[1;34m%c\033[0m", '/');
        fflush(stdout);
        usleep(100000*0.5);

        printf("\b");
        printf("\033[1;34m%c\033[0m", '-');
        fflush(stdout);
        usleep(100000*0.5);

        printf("\b");
        printf("\033[1;34m%c\033[0m", '\\');
        fflush(stdout);
        usleep(100000*0.5);

        printf("\b");
    }


}
//************************************************************
void obtenirDateActuelle(char date[20]) {
    time_t tempsActuel;
    struct tm *infoTemps;
    time(&tempsActuel);
    infoTemps = localtime(&tempsActuel);
    strftime(date, 20, "%Y-%m-%d|%H:%M:%S", infoTemps);
}
void ajouterNminutes(char date[20]) {
    time_t tempsActuel;
    struct tm *infoTemps;

    time(&tempsActuel);
    infoTemps = localtime(&tempsActuel);

    // Ajouter 5 minutes
    infoTemps->tm_min += 5;

    // Mettre � jour le temps
    mktime(infoTemps);

    // Formater la nouvelle date et heure
    strftime(date, 20, "%Y-%m-%d|%H:%M:%S", infoTemps);
}

int obtenirDerniercommande(FILE * obtinentfile) {
    FILE *fichier = obtinentfile   ;

    int dernierIndex = 0;

  char ligne[255];
    while (  fgets(ligne ,255,obtinentfile)!= NULL ) {

        dernierIndex++;
    }


    return dernierIndex;
}
int obtenirDernierHC(FILE * obtinentfile) {
    FILE *fichier = obtinentfile   ;
  char ligne[255];
    int dernierIndex = 0;

    while (  fgets(ligne ,255,obtinentfile)!= NULL ) {
         if(ligne[0]=='+')
        dernierIndex++;
    }


    return dernierIndex;
}

int compterStructuresDansFichier() {
    FILE *fichier =file_Historique() ;
    historique his;
    int nombreDeStructures = 0;



    // V�rifier si le fichier est ouvert avec succ�s
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Valeur d'erreur
    }

    // Lire les structures du fichier jusqu'� la fin du fichier
    while (fread(&his, sizeof( historique), 1, fichier) == 1) {
        nombreDeStructures++;
    }

    // Fermer le fichier


    return nombreDeStructures;
}




int getIntInput() {
    int value;
    while (1) {
        printf("Entrer votre choix : ");
        if (scanf("%d", &value) == 1) {
            // Input is a valid integer
            break;
        } else {
            // Input is not a valid integer
            printf("Erreur : Veuillez saisir un entier.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
    }
    return value;
}
//**********************************************
void printBorder(int length) {
    for (int i = 0; i < length; ++i) {
        printf("*");
    }
    printf("\n");
}
//*******************************************
void printOption(const char *option) {
    printf("* %-30s *\n", option);
}
//*********************************************
void MENU() {
    int borderLength = 34; // Ajustez la longueur en fonction de la taille du texte le plus long
    entete();
    printBorder(borderLength);
    printf("*           MENU           *\n");
    printBorder(borderLength);
    printOption("1- Faire une commande");
    printOption("2- Etat de ma commande");
    printOption("3- Reclamer un probleme");
    printOption("4- FEEDBACK");
    printOption("5- Deconnection");
    printBorder(borderLength);
}
//**********************************************
void printborder(int length) {
    for (int i = 0; i < length; ++i) {
        printf("_");
    }
    printf("\n");
}
//**********************************************************
void printoption(const char *option,const char *color) {
   printf(" %s%-56s%s \n", color, option, "\x1b[0m");
}
//**********************************************************
void OptionCommande() {
    int borderLength = 40; // Ajustez la longueur en fonction de la taille du texte le plus long
    system("color a");
    printf("  ");
    printborder(borderLength);
    printoption("1- Ajouter un produit                 ","\x1b[32m");
    printoption("2- Modifier la quantite d'un produit  ","\x1b[33m");
    printoption("3- Supprimer un produit               ","\x1b[31m");
    printoption("4- Passer a la caisse                 ","\x1b[36m");
    printoption("5- Quitter                            ","\x1b[0m");
    printborder(borderLength);
}
//**********************************************
void displayCategory(FILE *categoryFile) {
    Produit P;
    printf("\n*************************** CONTENU DE LA CATEGORIE ***************************\n");
    printf("%-4s%-20s%-20s%-8s%-10s\n", "ID", "NOM", "PRENOM", "PRIX", "QUANTITE DISPONIBLE");
    printf("-----------------------------------------------------------------------------\n");

    while (fscanf(categoryFile, "%d%s%s%d%d%d%d\n", &P.id, P.nom, P.prenom, &P.prix, &P.quantite_actuelle, &P.quantite_minimale,&P.topsales) != EOF) {
        printf("%-4d%-20s%-20s%-8d%-10d\n", P.id, P.nom, P.prenom, P.prix, P.quantite_actuelle);
    }

    printf("****************************************************************************\n");
}

//***********************************************************************************************
//***********************************************************************************************
void AjouterProd() {
    Produit P;
    int articleexiste =0;
    NProd A;
    int found = 0;
     FILE *commandeFile ;
    do {
    printf("********************************************\n");
    printf("*              MENU CATEGORIE              *\n");
    printf("********************************************\n");
    printf("* 1- Electronique                          *\n");
    printf("* 2- Meuble                                *\n");
    printf("* 3- Vetement                              *\n");
    printf("* 4- Quitter                               *\n");
    printf("********************************************\n");
        int choix;
        do {
            choix = getIntInput();
        } while (choix < 1 || choix > 4);
        system("cls");
        if (choix >= 1 && choix <= 3) {
            FILE *categorieFile = NULL;

            switch (choix) {
                case 1:
                    categorieFile = fopen("categorie1.txt", "r");
                    break;
                case 2:
                    categorieFile = fopen("categorie2.txt", "r");
                    break;
                case 3:
                    categorieFile = fopen("categorie3.txt", "r");
                    break;
                default:
                    break;
            }

            if (categorieFile != NULL) {
                do {
                    system("cls");
                    rewind(categorieFile);
                    displayCategory(categorieFile);
                    int idToAdd;
                    int quantiteAjoutee;
                    int articleExiste = 0;
                    rewind(categorieFile);
                    printf("Entrez l'ID du produit � ajouter : ");
                    idToAdd = getIntInput();
while (fscanf(categorieFile, "%d %s %s %d %d %d %d\n", &P.id, P.nom, P.prenom, &P.prix, &P.quantite_actuelle, &P.quantite_minimale,&P.topsales) != EOF) {

    if (P.id == idToAdd) {
        articleExiste = 1;

        commandeFile = fopen("commande.txt", "a+");
        // Read the existing content of the command file and update the quantity if the product exists
        while (fscanf(commandeFile, "%d %s %s %d %d", &A.existingId, A.existingNom, A.existingPrenom, &A.existingPrix, &A.existingQuantite) != EOF) {
            if (A.existingId == idToAdd && strcmp(A.existingNom, P.nom) == 0 && strcmp(A.existingPrenom, P.prenom) == 0) {
                    found=1;
                printf("Le produit existe d�j� dans la commande. Voulez-vous modifier la quantit� ? (1 pour Oui, 0 pour Non) : ");
                int choixModifierQuantite;
                scanf("%d",&choixModifierQuantite);

                if (choixModifierQuantite==1) {
                    printf("Entrez la nouvelle quantit� pour l'article avec l'ID %d : ", idToAdd);
                    scanf("%d", &quantiteAjoutee);

                    if (quantiteAjoutee > 0 && quantiteAjoutee <= P.quantite_actuelle) {
                        // Update the quantity
                        fseek(commandeFile,-sizeof(NProd),1);
                        fprintf(commandeFile, "%d %s %s %d %d", &A.existingId, A.existingNom, A.existingPrenom, &A.existingPrix,quantiteAjoutee);
                        printf("\nVotre commande est bien modifier");
                    } else
                        printf("Quantite non valide, Op�ration annul�e.\n");
                    fclose(commandeFile);
                    break;
                    }

                }}
        // Rewrite the entire command file with updated content
                    if(articleExiste==1&& found!=1){
                           printf("Le produit n'existe pas dans la commande. Ajout en cours...\n");
                            printf("Entrez la quantite � ajouter pour l'article avec l'ID %d : ", idToAdd);
                            scanf("%d", &quantiteAjoutee);

                            if (quantiteAjoutee > 0 && quantiteAjoutee <= P.quantite_actuelle) {
                                    fseek(commandeFile,0,SEEK_END);
                                fprintf(commandeFile, "%d %s %s %d %d\n", P.id, P.nom, P.prenom, P.prix, quantiteAjoutee);

                                printf("Le produit a ete ajoute a la commande avec succes.\n");
                                }
                            else
                                printf("la quantite choisi n'est pas valide .");
                    }fclose(commandeFile);
                    break;
                    }
                    }

                    if (!articleExiste) {
                        printf("Le produit n'existe pas dans la categorie.\n");
                    }

                    // Demander � l'utilisateur s'il veut choisir un autre article de la m�me cat�gorie
                    printf("\nVoulez-vous choisir un autre article dans la meme categorie ? (1 pour Oui, 0 pour Non) : ");
                    choix=getIntInput();

                } while (choix != 0);

                fclose(categorieFile);
                rewind(categorieFile);
            }
        } else if (choix == 4) {
            break;
        } else {
            printf("Choix invalide. Veuillez choisir une option valide.\n");
        }

    } while (1);
}
//**********************************************
bool VerifDisponibiliteQuantiteCategorie(const char *categoryFilePath, const char *nom, const char *prenom, int quantite) {
    FILE *categoryFile = fopen(categoryFilePath, "r");

    if (categoryFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier de categorie.\n");
        return false;
    }

    Produit P;

    // Parcourir le fichier de cat�gorie pour trouver le produit
    while (fscanf(categoryFile, "%d %s %s %d %d %d %d", &P.id, P.nom, P.prenom, &P.prix, &P.quantite_actuelle, &P.quantite_minimale,P.topsales) != EOF) {
        if (strcmp(P.nom, nom) == 0 && strcmp(P.prenom, prenom) == 0) {
            // V�rifier si la quantit� demand�e est disponible
            if (quantite <= P.quantite_actuelle) {
                fclose(categoryFile);
                return true;  // La quantit� est disponible
            } else {
                fclose(categoryFile);
                return false;  // La quantit� n'est pas disponible
            }
        }
    }

    fclose(categoryFile);

    // Le produit n'a pas �t� trouv� dans le fichier de cat�gorie
    return false;
}
//***************************************************************************
// Fonction pour d�terminer � quelle cat�gorie appartient un produit
int DetermineCategorie(const char *nom, const char *prenom) {
    if (VerifDisponibiliteQuantiteCategorie("categorie1.txt", nom, prenom, 0)) {
        return 1;
    } else if (VerifDisponibiliteQuantiteCategorie("categorie2.txt", nom, prenom, 0)) {
        return 2;
    } else if (VerifDisponibiliteQuantiteCategorie("categorie3.txt", nom, prenom, 0)) {
        return 3;
    } else {
        return 0;  // Aucune cat�gorie trouv�e
    }
}
//*********************************************************************************
// Fonction pour modifier la quantit� d'un article dans la commande
void ModifierArticle() {
    Produit P;
    int quantiteAjoutee;
    bool articleExiste = false;  // Variable pour suivre si l'article existe

    // Ouvrir le fichier en mode lecture et �criture
    FILE *p = fopen("commande.txt", "r+");
    if (p == NULL) {
        printf("Erreur : votre panier est vide.\n");
        return;
    }

    printf("Voici le contenu de votre panier :\n");
    // Lire et afficher le contenu du fichier
    while (fscanf(p, "%d%s%s%d%d", &P.id, P.nom, P.prenom, &P.prix, &P.quantite_actuelle) != EOF) {
        printf("%s %s\t%d\t%d\n", P.nom, P.prenom, P.prix, P.quantite_actuelle);
    }

    // Demander � l'utilisateur d'entrer le nom et le pr�nom du produit � modifier
    char nomToModify[50];
    char prenomToModify[50];
    printf("\nEntrer le nom du produit que vous voulez modifier : ");
    scanf("%s", nomToModify);
    printf("Entrer le type du produit que vous voulez modifier : ");
    scanf("%s", prenomToModify);

    // Rembobiner le fichier pour le lire depuis le d�but
    rewind(p);

    // Fichier temporaire pour stocker les donn�es modifi�es
    FILE *tempFile = fopen("temp.txt", "w+");
    if (tempFile == NULL) {
        printf("Erreur : Impossible de creer le fichier temporaire.\n");
        fclose(p);
        return;
    }

    // Lire et modifier le contenu
    while (fscanf(p, "%d%s%s%d%d", &P.id, P.nom, P.prenom, &P.prix, &P.quantite_actuelle) != EOF) {
        if (strcmp(P.nom, nomToModify) == 0 && strcmp(P.prenom, prenomToModify) == 0) {
            articleExiste = true;  // Marquer que l'article a �t� trouv�

            // Afficher le contenu du stock de la cat�gorie du produit � modifier
            int categorie = DetermineCategorie(P.nom, P.prenom);
            FILE *categoryFile = fopen(
                (categorie == 1) ? "categorie1.txt" : (categorie == 2) ? "categorie2.txt" : "categorie3.txt", "r");
            if (categoryFile == NULL) {
                printf("Erreur lors de l'ouverture du fichier de categorie.\n");
                fclose(p);
                fclose(tempFile);
                return;
            }

            printf("Stock disponible dans la categorie %d pour le produit %s %s :\n", categorie, P.nom, P.prenom);
            while (fscanf(categoryFile, "%d%s%s%d%d%d%d", &P.id, P.nom, P.prenom, &P.prix, &P.quantite_actuelle, &P.quantite_minimale,&P.topsales) != EOF) {
                printf("%s %s\t%d\n", P.nom, P.prenom, P.quantite_actuelle);
            }

            fclose(categoryFile);

            // Demander � l'utilisateur de saisir la nouvelle quantit�
            do {
                printf("Entrer la nouvelle quantite que vous voulez : ");
                scanf("%d", &quantiteAjoutee);

                // V�rifier si la quantit� est disponible en stock
                if (!VerifDisponibiliteQuantiteCategorie(
                        (categorie == 1) ? "categorie1.txt" : (categorie == 2) ? "categorie2.txt" : "categorie3.txt",
                        nomToModify, prenomToModify, quantiteAjoutee)) {
                    printf("La quantite demandee n'est pas disponible en stock.\nVeuillez entrer une quantite valide.\n");
                }
            } while (!VerifDisponibiliteQuantiteCategorie(
                (categorie == 1) ? "categorie1.txt" : (categorie == 2) ? "categorie2.txt" : "categorie3.txt",
                nomToModify, prenomToModify, quantiteAjoutee));

            // Mettre � jour la quantit� dans le fichier de commande sans changer les autres champs
            fprintf(tempFile, "%d %s %s %d %d\n", P.id, nomToModify, prenomToModify, P.prix, quantiteAjoutee);
        } else {
            // Copier les donn�es inchang�es dans le fichier temporaire pour les articles non modifi�s
            fprintf(tempFile, "%d %s %s %d %d\n", P.id, P.nom, P.prenom, P.prix, P.quantite_actuelle);
        }
    }

    // Fermer les deux fichiers
    fclose(p);
    fclose(tempFile);

    // Supprimer le fichier original
    remove("commande.txt");

    // Renommer le fichier temporaire en fichier original
    rename("temp.txt", "commande.txt");

    // Afficher un message si l'article n'a pas �t� trouv�
    if (!articleExiste) {
        printf("Aucun article avec le nom '%s' et le prenom '%s' n'est disponible.\n", nomToModify, prenomToModify);
    }
}


//************************************************************
void AfficherCommande(FILE *orderFile) {
    Produit P;
    int quantiteAjoutee;
    printf("\n*************************** CONTENU DE LA COMMANDE ***************************\n");
    printf("%-4s%-20s%-20s%-8s%-10s\n", "ID", "NOM", "PRENOM", "PRIX", "QUANTITE AJOUTEE");
    printf("-----------------------------------------------------------------------------\n");

    while (fscanf(orderFile, "%d%s%s%d%d", &P.id, P.nom, P.prenom, &P.prix, &quantiteAjoutee) != EOF) {
        printf("%-4d%-20s%-20s%-8d%-10d\n", P.id, P.nom, P.prenom, P.prix, quantiteAjoutee);
    }

    printf("****************************************************************************\n");
}

//************************************************************
int isFichierCommandeVide(FILE *fichierCommande) {
    // V�rifier si le fichier est vide en essayant de lire un caract�re
    int ch = fgetc(fichierCommande);
    ungetc(ch, fichierCommande);
    // Remettre le caract�re en place

    return ch == EOF;
}
//**********************************************************************
void supprimerProduit() {
    Produit P;
    char nomASupprimer[50];
    char prenomASupprimer[50];
    // Ouvrir le fichier en mode lecture et �criture
    FILE *fichierCommande = fopen("commande.txt", "r+");

    if (fichierCommande == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier de commande.\n");
        return;
    }

    // V�rifier si le fichier de commande est vide
    if (isFichierCommandeVide(fichierCommande)) {
        printf("Votre panier est vide. Aucun article � supprimer.\n");
        fclose(fichierCommande);
        return;
    }

    // Afficher le contenu actuel du fichier de commande
    AfficherCommande(fichierCommande);

    // Demander � l'utilisateur de choisir un produit � supprimer par son nom et pr�nom
    printf("\nEntrez le nom du produit que vous voulez supprimer : ");
    scanf("%s", nomASupprimer);
    printf("\nEntrez le type du produit que vous voulez supprimer : ");
    scanf("%s", prenomASupprimer);

    // Rembobiner le fichier pour lire depuis le d�but
    rewind(fichierCommande);

    // Cr�er un fichier temporaire pour stocker les donn�es modifi�es
    FILE *fichierTemporaire = fopen("temp.txt", "w+");
    if (fichierTemporaire == NULL) {
        printf("Erreur : Impossible de creer le fichier temporaire.\n");
        fclose(fichierCommande);
        return;
    }

    // Lire et supprimer le produit choisi par son nom et pr�nom
    int quantiteAjoutee;
    int produitTrouve = 0;
    while (fscanf(fichierCommande, "%d%s%s%d%d", &P.id, P.nom, P.prenom, &P.prix, &quantiteAjoutee) != EOF) {
        if (strcmp(P.nom, nomASupprimer) == 0 && strcmp(P.prenom, prenomASupprimer) == 0) {
            printf("Le produit %s %s a �t� supprim� de votre panier.\n", nomASupprimer, prenomASupprimer);
            produitTrouve = 1;
        } else {
            // Copier les donn�es inchang�es vers le fichier temporaire sauf s'il s'agit de la ligne � supprimer
            fprintf(fichierTemporaire, "%d %s %s %d %d\n", P.id, P.nom, P.prenom, P.prix, quantiteAjoutee);
        }
    }

    if (!produitTrouve) {
        printf("Aucun produit trouv� avec le nom %s et le pr�nom %s dans votre panier.\n", nomASupprimer, prenomASupprimer);
    }

    // Fermer les deux fichiers
    fclose(fichierCommande);
    fclose(fichierTemporaire);

    // Supprimer le fichier original
    remove("commande.txt");

    // Renommer le fichier temporaire en fichier original
    rename("temp.txt", "commande.txt");

    // Demander � l'utilisateur s'il souhaite supprimer un autre article
    int supprimerAutre;

do {
    printf("\nVoulez-vous supprimer un autre article ? (1 pour Oui, 0 pour Non) : ");

    // Lire l'entr�e de l'utilisateur
    if (scanf("%d", &supprimerAutre) != 1) {
        // Si la saisie n'est pas un entier, vider le tampon d'entr�e
        while (getchar() != '\n');
        printf("Veuillez entrer un entier valide.\n");
        continue; // Revenir au d�but de la boucle pour redemander l'entr�e
    }

    // V�rifier si l'entr�e est valide (0 ou 1)
    if (supprimerAutre != 0 && supprimerAutre != 1) {
        printf("Veuillez entrer 0 pour Non ou 1 pour Oui.\n");
    }
} while (supprimerAutre != 0 && supprimerAutre != 1);
    if (supprimerAutre) {
        supprimerProduit(); // Appeler r�cursivement la fonction pour supprimer un autre produit
    }
}

//************************************************************

void ConfirCommande(historique * his) {
    FILE* file_commande = fopen("commande.txt", "rt");
    FILE* fichierHC =fopen("historique_comm.txt", "a+");

    Produit P;
    int quantiteeAjoutee ;
    //EtatC=Etat commande
    if (file_commande == NULL) {
        printf("Le panier est vide. (Veuillez taper entrer pour revenir au menu.)\n");
        getch();
        printf("\n");
        TraiterChoixUtilisateur();
        fclose(file_commande);
    }


    system("cls");
    // Affichage du contenu du fichier commande
    printf("\n***************************** CONTENU DE LA COMMANDE *****************************\n");
    printf("%-4s%-25s%-10s%-8s\n", "ID", "Nom et type", "Prix", "Quantite");
    printf("-------------------------------------------------------------------------------\n");

    while (fscanf(file_commande, "%d %s %s %d %d", &P.id, P.nom, P.prenom, &P.prix, &quantiteeAjoutee) != EOF) {
    char nomComplet[100]; // Ajustez la taille selon vos besoins
    snprintf(nomComplet, sizeof(nomComplet), "%s %s", P.nom, P.prenom);
    printf("%-4d%-25s%-10d%-8d\n", P.id, nomComplet, P.prix,quantiteeAjoutee);

}
    printf("*********************************************************************************\n");
    // Questionner le client s'il veut confirmer sa commande
    int choix;
    printf("Voulez-vous confirmer votre commande ?\n");
    printf("1 - Oui\n");
    printf("2 - Non\n");
    choix = getIntInput();

    if (choix == 1) {

        rewind(file_commande);
        his->nmbr_art= obtenirDerniercommande( file_commande  );


              his->id_com=obtenirDernierHC( fichierHC )+1;


        rewind(fichierHC);

        rewind(file_commande);


    double total = 0;
    double A;
    int utiliserCodePromo;
    printf("Voulez-vous utiliser un code promo ?\n");
    printf("1 - Oui\n");
    printf("2 - Non\n");
    do{
    utiliserCodePromo = getIntInput();
    }while(utiliserCodePromo< 1 && utiliserCodePromo> 2);
    double reduction = 0.0;  // Variable pour stocker la r�duction appliqu�e

    if (utiliserCodePromo == 1) {
        char codePromoSaisi[20];
        printf("Veuillez saisir votre code promo : ");
        scanf("%s", codePromoSaisi);

        // Ouvrir le fichier contenant les codes promo
        FILE* fichierCodePromo = fopen("codepromo.txt", "r");

        if (fichierCodePromo != NULL) {
            char codePromo[20];

            // Parcourir le fichier pour v�rifier si le code promo est valide
            while (fscanf(fichierCodePromo, "%s", codePromo) != EOF) {
                if (strcmp(codePromoSaisi, codePromo) == 0) {
                    // Le code promo est valide, appliquer la r�duction (par exemple, 10%)
                    reduction = 0.10;  // Modifier selon vos besoins
                    printf("Code promo valide! Vous beneficiez d'une reduction de %.2f%%\n", reduction * 100);
                    break;
                }
            }

            // Fermer le fichier des codes promo
            fclose(fichierCodePromo);
        } else {
            printf("Erreur lors de l'ouverture du fichier des codes promo.\n");
        }
    }
    system("cls");
    time_t t;
    struct tm *info;
    time(&t);
    info = localtime(&t);


    printf("\n\033[1;34m------------------------------- NOZAMA FACTURE --------------------------------\033[0m\n");
    printf("Date : %02d/%02d/%d %02d:%02d:%02d\n", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900,
           info->tm_hour, info->tm_min, info->tm_sec);

    printf("%-30s%-15s%-10s%-10s\n", "DESCRIPTION DE L'ARTICLE" , "PRIX",      "QTE",                    "TOTAL");
    printf("---------------------------------------------------------------------------------------\n");
int i=0;
his->produith = (Produith *)malloc(his->nmbr_art * sizeof(Produith));
while (fscanf(file_commande, "%d %s %s %d %d", &P.id, P.nom, P.prenom, &P.prix, &quantiteeAjoutee) != EOF) {
        strcpy( his->produith[i].nom,P.nom);
        strcpy( his->produith[i].prenom,P.prenom);
        his->produith[i].prix =P.prix;
        his->produith[i].quantite=quantiteeAjoutee;
            // Mettre � jour les quantit�s dans les fichiers de cat�gorie correspondants
        UpdateQuantiCatego("categorie1.txt", P.id, P.nom, quantiteeAjoutee);
        UpdateQuantiCatego("categorie2.txt", P.id, P.nom, quantiteeAjoutee);
        UpdateQuantiCatego("categorie3.txt", P.id, P.nom, quantiteeAjoutee);


    double sousTotal = P.prix * quantiteeAjoutee;
    printf("%-20s\t     %-15d\t%-10d%-10.2f\n", strcat(strcat(P.nom, " "), P.prenom), P.prix,quantiteeAjoutee, sousTotal);

    total += sousTotal;
    total=total-(total*reduction);
    A = total + 10;
    i++;
}

printf("-------------------------------------------------------------------------------------------------------\n");
        double TVA;
        TVA=total*(0.2);
        printf("SOUS-TOTAL             %.2f$\n", total);
        printf("TVA(20%% inclu)        %.2f$\n",TVA);
        printf("Livraison                10$\n");
        printf("MONTANT TOTAL          %.2f$\n",A);
        getch();

        char dateacc1[40];
        char date1[20] ;
            obtenirDateActuelle(dateacc1);
            snprintf(date1, sizeof(date1), "%s", dateacc1);
             char partied1[20], partied2[20];
               sscanf(date1, "%[^|]|%s", partied1, partied2);

            char dateacc2[40];
            char date2[20] ;
            ajouterNminutes(dateacc2);
            snprintf(date2, sizeof(date2), "%s", dateacc2);
            char partief1[20], partief2[20];
            sscanf(date2, "%[^|]|%s", partief1, partief2);



        printf("Confirmation de commande en cours\n");
        affichageChargement();
        printf("\033[1;32m Commande confirmee avec succes !\033[0m\n");
        // Enregistrement de la date de confirmation dans le fichier "EtatCommande"


        // Enregistrement de la date de r�ception dans le fichier "EtatCommande"

FILE * file_c=fopen("tmp.txt","r");
Client client0 ;
fscanf(file_c, "%d %s\n", &client0.CNI,client0.passwd);
fclose(file_c);
his->client.CNI=client0.CNI;
 file_c=fopen("Client.txt","r");
   while(fscanf (file_c,"%d %s %s %d %s %s %s %s\n", &client0.CNI, client0.nom, client0.prenom, &client0.adress.num_maison, client0.adress.quartier, client0.adress.ville, client0.numero,client0.passwd)==8){
    if (his->client.CNI == client0.CNI ){
        strcpy(his->client.nom , client0.nom);
        strcpy(his->client.prenom , client0.prenom);

        break;
    }}


    strcpy(his->date_com1 , partied1);
    strcpy(his->date_com2 , partied2);
    strcpy(his->dat_final1 , partief1);
    strcpy(his->dat_final2 , partief2);
    his->prixtotal=A;
   fprintf(fichierHC,"+ %d %d %d %s %s %s %s %s %s %d\n",his->id_com,his->client.CNI,his->prixtotal,his->client.nom,his->client.prenom,his->date_com1,his->date_com2,his->dat_final1,his->dat_final2,his->nmbr_art);
    for(int i =0 ; i<his->nmbr_art ;i++){
        fprintf(fichierHC,"- %s %s %d %d\n",his->produith[i].nom,his->produith[i].prenom ,his->produith[i].prix , his->produith[i].quantite );
    }
fclose(fichierHC);
fclose(file_commande);
    remove("commande.txt");
    } else if (choix == 2) {
        // Demander si le client veut supprimer sa commande
        int supprimerCommande;
        printf("Voulez-vous supprimer votre commande ?\n");
        printf("1 - Oui\n");
        printf("2 - Non\n");
        supprimerCommande = getIntInput();

        if (supprimerCommande == 1) {
            fclose(file_commande);
            remove("commande.txt");
            printf("Votre commande a ete supprimee.\n");
        }
    }

getch();
system("cls");
TraiterChoixUtilisateur();
}

void UpdateQuantiCatego(const char *categoryFile, int id,char *nom, int quantityToUpdate) {
    FILE *file = fopen(categoryFile, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file != NULL && tempFile != NULL) {
        Produit P;
        rewind(file);
        while (fscanf(file, "%d%s%s%d%d%d%d", &P.id, P.nom, P.prenom, &P.prix, &P.quantite_actuelle, &P.quantite_minimale,&P.topsales) != EOF) {
            if (P.id == id  && strcmp(P.nom,nom)==0) {
                // Mettre � jour la quantit� dans la cat�gorie
                P.topsales+=quantityToUpdate;
                P.quantite_actuelle -= quantityToUpdate;
                 fprintf(tempFile, "%d %s %s %d %d %d %d\n", P.id, P.nom, P.prenom, P.prix, P.quantite_actuelle, P.quantite_minimale,P.topsales);
            }
            else
            {
                fprintf(tempFile, "%d %s %s %d %d %d %d\n", P.id, P.nom, P.prenom, P.prix, P.quantite_actuelle, P.quantite_minimale,P.topsales);
            }
        }

        fclose(file);
        fclose(tempFile);
        remove(categoryFile);
        rename("temp.txt",categoryFile);
        // Renommer le fichier temporaire pour �craser le fichier original

    } else {
        printf("Erreur lors de l'ouverture du fichier de categorie %s ou du fichier temporaire.\n", categoryFile);
    }

}
//************************************************************
void GererCommande() {
    int choix;

    do {
        OptionCommande();  // Afficher les options

        printf("\nVeuillez choisir une option (1-5) :");
        choix=getIntInput();
historique his ;
        switch (choix) {
            case 1:{
                system("cls");
                entete();
               printf("\033[1;34mVous avez choisi l'option Ajouter un Produit :\n\033[0m");
                 AjouterProd();
                break;}
            case 2:{
                system("cls");
                entete();
                printf("\033[1;34mVous avez choisi l'option Modification d'un Produit :\n\033[0m");
                ModifierArticle();
                break;}
            case 3:{
                system("cls");
                entete();
                printf("\033[1;34mVous avez choisi l'option supprimer un Produit :\n\033[0m");
                supprimerProduit();
                break;}
            case 4:{
                system("cls");
                entete();
                printf("\033[1;31mVous avez choisi l'option Confirmation de votre commande :\n\033[0m");
                ConfirCommande(&his);
                break;
                }
            case 5:{
                system("cls");
                entete();
                TraiterChoixUtilisateur();  // Revenir au menu principal
                break;
                }
            default:
                printf("Choix invalide. Veuillez choisir un numero entre 1 et 5.\n");
        }

        // Ajoutez d'autres conditions si n�cessaire pour g�rer les choix suppl�mentaires

    } while (choix != 5);  // Continuez tant que l'utilisateur ne choisit pas l'option de retour au menu principal
}

//**********************************************************************************
//**********************************************************************************
void Tmp(int CNI,const char* Mot_passe){
FILE*tempo=fopen("tmp.txt","w");
if(tempo==NULL){
    printf("ERROR\n");
    exit(1);
}
else{
 fprintf(tempo,"%d %s\n",CNI,Mot_passe);
}
fclose(tempo);
}
//**********************************************************************************
int comparerHeures(const char *heure1, const char *heure2) {
    int heures1, minutes1, secondes1;
    int heures2, minutes2, secondes2;

    // Utiliser sscanf pour extraire les composantes des deux heures
    if (sscanf(heure1, "%d:%d:%d", &heures1, &minutes1, &secondes1) != 3 ||
        sscanf(heure2, "%d:%d:%d", &heures2, &minutes2, &secondes2) != 3) {
        // En cas d'erreur dans le format des heures
        printf("Format d'heure incorrect.\n");
        return 0; // Comparaison impossible
    }

    // Comparaison des heures
    if (heures1 < heures2) {
        return -1; // heure1 est antérieure à heure2
    } else if (heures1 > heures2) {
        return 1;  // heure1 est postérieure à heure2
    }

    // Si les heures sont égales, comparer les minutes
    if (minutes1 < minutes2) {
        return -1; // heure1 est antérieure à heure2
    } else if (minutes1 > minutes2) {
        return 1;  // heure1 est postérieure à heure2
    }

    // Si les minutes sont égales, comparer les secondes
    if (secondes1 < secondes2) {
        return -1; // heure1 est antérieure à heure2
    } else if (secondes1 > secondes2) {
        return 1;  // heure1 est postérieure à heure2
    }

    // Les heures sont égales
    return 0;
}
//**********************************************************************************
void Etatcommande(){
FILE* histo=fopen("historique_comm.txt","r");
FILE* tmpo=fopen("tmp.txt","rt");
historique his;
if(histo==NULL|| tmpo==NULL){
    printf("ERROR\n");
    exit(1);
}
int cni;
char passwd[50];
fscanf(tmpo,"%d %s",&cni,passwd);
char ligne[255];
char c ;
int compteur =0 ;
    while(fscanf(histo,"%c %d %d %d %s %s %s %s %s %s %d\n",&c,&his.id_com,&his.client.CNI,&his.prixtotal,his.client.nom,his.client.prenom,his.date_com1,his.date_com2,his.dat_final1,his.dat_final2,&his.nmbr_art)==11){
   int  i=0;
    if(his.client.CNI==cni){
            compteur++;
         printf("\n----------------------------------------------------------------------------------------------------\n");

        // Print headers and order information
        printf("ID de commande   : %d\n", his.id_com);
        printf("Prix Total       : %d$\n", his.prixtotal);
        printf("Date Confirmation: %s %s\n", his.date_com1, his.date_com2);
        printf("Date Reception   : %s %s\n", his.dat_final1, his.dat_final2);
                char dateacc1[40];
        char date1[20] ;
            obtenirDateActuelle(dateacc1);
            snprintf(date1, sizeof(date1), "%s", dateacc1);
            char partied1[20], partied2[20];
            sscanf(date1, "%[^|]|%s", partied1, partied2);

   int resultat = comparerHeures(his.dat_final2, partied2);

    if (resultat < 0) {
        printf("La commande %d est \033[1;34m livree \033[0m\n",his.id_com);
    } else  {
        printf("LA commande %d est \033[1;34m en cours de livraison \033[0m \n", his.id_com );
    }

        printf("\n\033[1;34m ========================================\033[0m\n");
        printf("\033[1;34m  Liste des produits dans la commande %d :\033[0m\n",his.id_com);
        printf("\033[1;34m  =========================================\033[0m\n");
  while(i<his.nmbr_art){
    fscanf(histo,"%c %s %s %d %d\n",&c,his.produith[i].nom,his.produith[i].prenom ,&his.produith[i].prix , &his.produith[i].quantite );
    printf(" Nom de produit : %-20s %s \t Prix : %-5d$ \t Quantite : %-5d   \n", his.produith[i].nom, his.produith[i].prenom, his.produith[i].prix, his.produith[i].quantite);
    i++ ;

}
        // Get the current date
        time_t t;
        struct tm *now;
        time(&t);
        now = localtime(&t);
/*
        // Check if the date of reception is earlier than the current date
        if (strcmp(his.dat_final1, "yyyy") != 0 && strcmp(his.dat_final2, "mm") != 0 &&
            atoi(his.dat_final1) <= now->tm_year + 1900 && atoi(his.dat_final2) <= now->tm_mon + 1) {
             printf("\033[1;32m");
             printf("Commande livree avec succes!\n");
              printf("\033[0m");
        } else {
            printf("\033[1;32m");
            printf("Livraison en cours. Veuillez patienter.\n");
             printf("\033[0m");
        }
*/
}
    else {
        while(i<his.nmbr_art){
fgets(ligne,255,histo);
    i++;
}
    }
    }
 printf(" \nvous aves effectuer : %d commandes dans votre Historique\n  ",compteur+1);

fclose(histo);
fclose(tmpo);
getchar();
getchar();
system("cls");
TraiterChoixUtilisateur();
}

//*******************************************************************************
void enregistrerFeedback(char *feedback, char *commentaire) {
    FILE *fichierFeedback = fopen("feedback.txt", "a+");
    if (fichierFeedback != NULL) {
        FILE *file_c = fopen("tmp.txt", "r");
        Client client0, client1;
        fscanf(file_c, "%d %s\n", &client1.CNI, client1.passwd);
        fclose(file_c);
        printf("\n%d %s\n",client1.CNI, client1.passwd );

        file_c = fopen("Client.txt", "r");
        while (fscanf(file_c, "%d %s %s %d %s %s %s %s", &client0.CNI, client0.nom, client0.prenom,
                      &client0.adress.num_maison, client0.adress.quartier, client0.adress.ville,
                      client0.numero, client0.passwd) == 8) {
            if (client0.CNI == client1.CNI && strcmp(client0.passwd,client1.passwd)==0) {
                fprintf(fichierFeedback, "%s %s %s %s\n", client0.nom, client0.prenom, feedback, commentaire);
                break;
            }
        }


        fclose(fichierFeedback);
        fclose(file_c);

        printf("Feedback enregistr� avec succ�s\n");
        printf("Merci pour votre Opinion !\n");

        // Lire et afficher les feedbacks apr�s les avoir enregistr�s

    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}


void FEEDBACK() {
    char feedback[10];
    char commentaire[101]="Aucun commentaire";
    int estValide=0;
    // Boucle pour obtenir un feedback valide de l'utilisateur
    do {
        // Obtenir le feedback de l'utilisateur
        do{

        printf("Donnez votre feedback en utilisant des etoiles (entre 1 et 5 �toiles) : ");
        scanf("%s",feedback);
        }while(strlen(feedback)>5);
        //fgets(feedback, sizeof(feedback), stdin);
        getch();

        // Supprimer le caract�re de nouvelle ligne ('\n') du feedback
        size_t len = strlen(feedback);
        if (len > 0 && feedback[len - 1] == '\n') {
            feedback[len - 1] = '\0';
        }

        // V�rifier si le feedback est valide (compos� uniquement d'�toiles et ne d�passe pas 5 �toiles)
        estValide = 1;
        for (int i = 0; i < len && feedback[i] != '\0'; i++) {
            if (feedback[i] != '*' || len > 5) {
                estValide = 0;
                break;
            }
        }

        // Afficher un message d'erreur si le feedback n'est pas valide
        if (!estValide) {
            printf("Feedback invalide. Veuillez entrer entre 1 et 5 etoiles (*).\n");
        }

    } while (!estValide);
    // Poser une question pour ajouter un commentaire
    printf("Voulez-vous ajouter un commentaire ? (1 pour Oui, 0 pour Non) : ");
    int choixCommentaire;
    choixCommentaire=getIntInput();

    // Vider le tampon d'entr�e pour �viter des probl�mes de lecture
    while (getchar() != '\n');

    // Si l'utilisateur veut ajouter un commentaire
    if (choixCommentaire) {
        // Obtenir le commentaire de l'utilisateur
        printf("Entrez votre commentaire (maximum 100 caract�res) : ");
        fgets(commentaire, sizeof(commentaire), stdin);
        // Supprimer le caract�re de nouvelle ligne ('\n') du commentaire
        int len = strlen(commentaire);
        if (len > 0 && commentaire[len - 1] == '\n') {
            commentaire[len - 1] = '\0';
        }
    }

    // Enregistrer le feedback (et le commentaire) dans le fichier
    enregistrerFeedback(feedback, commentaire);
    TraiterChoixUtilisateur();
}
//*************************************************************************************
void enregistrerReclamationAdmin(const char *nomUtilisateur,const char *prenomUtilisateur, const char *objet, const char *reclamation) {
    FILE *boiteReceptionAdmin = fopen("boite_reception_admin.txt", "a");
    if (boiteReceptionAdmin != NULL) {
        fprintf(boiteReceptionAdmin, "%s %s %s %s\n", nomUtilisateur,prenomUtilisateur, objet, reclamation);
        fclose(boiteReceptionAdmin);
        printf("Reclamation enregistrre avec succes dans la boete de reception de l'administrateur.\n");
    } else {
        printf("Erreur lors de l'ouverture du fichier de la boite de reception de l'administrateur.\n");
    }
}
//**************************************************************************************
void ReclamaProb() {
    char nomUtilisateur[51],prenomUtilisateur[30];  // Une chaîne de 50 caractères maximum pour le nom de l'utilisateur
    char objetReclamation[20];  // Une chaîne de 20 caractères maximum pour l'objet de la réclamation
    char reclamation[51];     // Une chaîne de 50 caractères maximum pour la réclamation
    int cni;
    char pass[20];
    Client A;
    FILE* tempo=fopen("tmp.txt","rt");
    FILE* clie=fopen("Client.txt","rt");
    if(tempo==NULL|| clie==NULL){
        printf("Erreur d'identification.\n");
        exit(1);
    }
    else{
        fscanf(tempo,"%d%s",&cni,pass);
        while(fscanf(clie,"%d%s%s%d%s%s%s%s",&A.CNI,A.nom,A.prenom,&A.adress.num_maison,A.adress.quartier,A.adress.ville,A.numero,A.passwd)==8){
            if(cni == A.CNI && strcmp(A.passwd,pass)==0){
                  strcpy(nomUtilisateur, A.nom);
                  strcpy(prenomUtilisateur, A.prenom);
            }
        }

    }
    fclose(tempo);
    fclose(clie);
    printf("Bonjour %s %s, veuillez choisir l'objet de votre reclamation :\n", nomUtilisateur,prenomUtilisateur);
    printf("1. Frais imprevus\n");
    printf("2. Retard de livraison\n");
    printf("3. Mauvais service apres vente\n");
    printf("4. Erreur dans la commande\n");
    printf("5. Autre\n");
    printf("6. Quiter\n");
    printf("Votre choix (1-6):\n");

    int choixObjet;
    do {
        choixObjet=getIntInput();
    } while (choixObjet < 1 || choixObjet > 6);

    switch (choixObjet) {
        case 1:
            strcpy(objetReclamation, "Frais imprevus");
            break;
        case 2:
            strcpy(objetReclamation, "Retard de livraison");
            break;
        case 3:
            strcpy(objetReclamation, "Mauvais service apres vente");
            break;
        case 4:
            strcpy(objetReclamation, "Erreur dans la commande");
            break;
        case 5:
            printf("Partagez-nous le sujet de votre reclamation en quelques mots (max 20 caracteres) : \n");
            scanf("%20s", objetReclamation);
            break;
        case 6:
           TraiterChoixUtilisateur();
            break;
    }

//lire meme les espace lors de l'ecriture d'une reclamation
    printf("Partagez-nous les details de votre reclamation (max 50 caractères) : Dites-nous tout sur votre ressenti, nous sommes la pour vous ecouter !\n");
    scanf(" ");
    scanf("%49[^\n]", reclamation);

    enregistrerReclamationAdmin(nomUtilisateur,prenomUtilisateur, objetReclamation, reclamation);
    TraiterChoixUtilisateur();
}
//*************************************************************************************
//************************************************************
void TraiterChoixUtilisateur() {
     system("cls");
    MENU();
    int choix;
    printf("\nEntrer votre choix (1-5):");
    choix=getIntInput();
    switch (choix) {
        case 1:
            system("cls");
            entete();
            GererCommande();
            break;
        case 2:
            system("cls");
            entete();
            Etatcommande();

            break;
        case 3:
            system("cls");
            entete();
            ReclamaProb();
            break;
        case 4:
            system("cls");
            entete();
            FEEDBACK();
            break;
        case 5:
            system("cls");
            Menu_acces();
            break;
        default:{
            system("cls");
            printf("Choix invalide. Veuillez choisir une option valide.\n");
            TraiterChoixUtilisateur();
            }

    }
}
//*****************************
#endif // TT_H_INCLUDED

