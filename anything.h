#ifndef ANYTHING_H_INCLUDED
#define ANYTHING_H_INCLUDED
#include "anything2.h"


// structs
typedef struct {
    char pseudo[50];
    char password[50];
} Admin;

typedef struct {
    char pseudo[50];
    char password[50];
} Fournisseur;



typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int quantite_stock_fournisseur;
} Fournisseurfs;

typedef struct {
char nom[20];
char prenom[20];
int  quantite_ajouter;
char date[50];
char four_asso[20];
char categorie_asso[20];

}Bilan;

// functions code
FILE *  file_Admin(){

FILE * file =fopen("log_Admin.txt", "r");
if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(0);}
        return file ;
}
FILE *  file_Fournissuer(){

FILE * file =fopen("log_Fournisseur.txt", "r");
if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(0);}
        return file ;
}
FILE *  file_Client(){
FILE * file =fopen("Client.txt", "a+");
if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(0);}
        return file ;
}


FILE * file_categorie1(){
    FILE *file = fopen("categorie1.txt", "a+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
return file ;
}
FILE * file_categorie2(){
    FILE *file = fopen("categorie2.txt", "a+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
return file ;
}
FILE * file_categorie3(){
    FILE *file = fopen("categorie3.txt", "a+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
return file ;
}

FILE * choixCategories(int cat ){
    if(cat == 1 ){
        return file_categorie1() ;
}
if(cat == 2 ){
    return file_categorie2() ;
}
if(cat == 3 ){
    return file_categorie3() ;}

}

FILE * file_categorie1_v(){
    FILE *file = fopen("categorie1verif.txt", "w+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
return file ;
}
FILE * file_categorie2_v(){
    FILE *file = fopen("categorie2verif.txt", "w+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
return file ;
}
FILE * file_categorie3_v(){
    FILE *file = fopen("categorie3verif.txt", "w+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
return file ;
}

FILE * choixCategories_v(int cat ){
    if(cat == 1 ){
        return file_categorie1_v() ;
}
    if(cat == 2 ){
        return file_categorie2_v() ;
}
    if(cat == 3 ){
        return file_categorie3_v() ;}

}



FILE * file_stockf1(){
    FILE *file = fopen("f1s.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    return file ;
}
FILE * file_stockf2(){
    FILE *file = fopen("f2s.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    return file ;
}
FILE * file_stockf3(){
    FILE *file = fopen("f3s.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    return file ;
}

FILE * choixstockf(Fournisseur fournisseur ){
    if(strcmp(fournisseur.pseudo  , "fournisseur1" ) == 0 ){
        return file_stockf1() ;
}
    if(strcmp(fournisseur.pseudo  , "fournisseur2" ) == 0 ){
        return file_stockf2() ;
}
    if(strcmp(fournisseur.pseudo  , "fournisseur3" ) == 0){
        return file_stockf3() ;}

}


FILE * file_bilan1(){
    FILE *file = fopen("bilan_fournisseur1.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    return file ;
}
FILE * file_bilan2(){
    FILE *file = fopen("bilan_fournisseur2.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    return file ;
}
FILE * file_bilan3(){
    FILE *file = fopen("bilan_fournisseur3.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    return file ;
}

FILE * choixbilan(int cat ){
if(cat == 1 ){
    return file_bilan1() ;
}
if(cat == 2 ){
    return file_bilan1() ;
}
if(cat == 3 ){
    return file_bilan1() ;}

}
void afficherBordureTitre(int longueur) {
    printf("\t\t\t");
    for (int i = 0; i < longueur; i++) {
        printf("*");
    }
    printf("\n");
}
void afficherBordureTitre2(int longueur) {

    for (int i = 0; i < longueur-2; i++) {
        printf("-");
    }
    printf("\n");
}
void afficherBordureTitre3(int longueur) {

    for (int i = 0; i < longueur-2; i++) {
        printf("-");
    }
    printf("\n");
}
void afficherTitre(const char *titre) {
    afficherBordureTitre(strlen(titre) + 4);
    printf("\t\t\t* %s *\n", titre);
    afficherBordureTitre(strlen(titre) + 4);
}
void afficherTitre2(const char *titre) {
    printf(" %s \n", titre);
    afficherBordureTitre2(strlen(titre) + 4);
}

void afficherBordureNSpace(int longueur) {
    for (int i = 0; i < longueur; i++) {
        printf("*");
    }
    printf("\n");
}
void afficherBordureTexte(int longueur) {
    for (int i = 0; i < longueur; i++) {
        printf("-");
    }
    printf("\n");
}

void obtenirDateActu(char date[20]) {
    time_t tempsActuel;
    struct tm *infoTemps;
    time(&tempsActuel);
    infoTemps = localtime(&tempsActuel);
    strftime(date, 20, "%Y-%m-%d|%H:%M:%S", infoTemps);
}

int int_dd() {
    int valeur;
    char texte[64];
    int tmp=0;
    while (1) {
    if(tmp==1)
         printf(" ressaisi s'il veut plait :   ");
    if (fgets(texte, sizeof(texte), stdin) == NULL) {
            printf("Erreur de saisie. Veuillez r�essayer.\n");
            continue;
        }
    if (sscanf(texte, "%d", &valeur) == 1) {
            break;
        } else {
            printf("Erreur : Veuillez saisir un entier valide.\n");
        }
    tmp =1 ;
    }
    return valeur;
}
void sauvegarderProduit(int choice ,Produit p) {
    FILE *fichier = choixCategories(choice );
    fprintf(fichier, "%d %s %s %d %d %d %d\n", p.id, p.nom, p.prenom, p.prix, p.quantite_actuelle, p.quantite_minimale,p.topsales);
    fclose(fichier);
}
void afficherProduits(choix) {
    FILE *fichier = choixCategories(choix);
    Produit p ;
    printf("%-20s %-20s %-13s %-15s %-15s %-15s\n", "ID", "Nom", "Type", "Prix/unite (en $)   ", "Quantite_actuelle   ", "Quantite_minimale");
    afficherBordureNSpace(130);
    while (fscanf(fichier, "%d %s %s %d %d %d %d\n", &p.id, p.nom, p.prenom, &p.prix, &p.quantite_actuelle, &p.quantite_minimale,&p.topsales) != EOF) {
    printf("%-20d %-20s %-20s %-20d %-20d %-20d\n", p.id, p.nom, p.prenom, p.prix, p.quantite_actuelle, p.quantite_minimale);
    }
    printf("\n");
    getchar();
    getchar();
    fclose(fichier);
}
int articleExiste(int choice ,int id) {
    FILE *file = choixCategories(choice ) ;

    Produit p;
    while (fscanf(file, "%d %s %s %d %d %d %d\n", &p.id, p.nom, p.prenom, &p.prix, &p.quantite_actuelle, &p.quantite_minimale,&p.topsales) != EOF) {
        if (p.id == id) {
            fclose(file);
            return 1; // article existe
        }
    }

    fclose(file);
    return 0; // article existe pas
}
void ajouterQuantite(int choice ,int id, int quantite_ajoutee){

    if (quantite_ajoutee <= 0) {
        printf("Erreur : Veuillez saisir une quantite positive.\n");
        return;
    }

    if (!articleExiste( choice, id)) {
        printf("Erreur : L'article avec l'ID %d n'existe pas dans le depot.\n", id);
        return;
    }

    FILE *fichier = choixCategories(choice ) ;

    Produit p;
    FILE *temp = fopen("temp.txt", "a+");


    while (fscanf(fichier, "%d %s %s %d %d %d %d", &p.id, p.nom, p.prenom, &p.prix, &p.quantite_actuelle, &p.quantite_minimale,&p.topsales) != EOF) {
        if (p.id == id) {
            // Afficher la quantite actuelle avant l'ajout
            printf("Quantit� actuelle avant l'ajout : %d\n", p.quantite_actuelle);

            // Accumulation de la quantite actuelle avec la nouvelle quantite
            p.quantite_actuelle += quantite_ajoutee;
        }

        fprintf(temp, "%d %s %s %d %d %d %d\n", p.id, p.nom, p.prenom, p.prix, p.quantite_actuelle, p.quantite_minimale,p.topsales);
    }

    fclose(fichier);
    fclose(temp);
if(choice == 1 ){
    remove("categorie1.txt");
    rename("temp.txt", "categorie1.txt");}
else if(choice == 2 ){
    remove("categorie2.txt");
    rename("temp.txt", "categorie2.txt");}
else if(choice == 3 ){
    remove("categorie3.txt");
    rename("temp.txt", "categorie3.txt");}




    printf("Quantite ajoutee avec succes pour l'article avec l'ID %d.\n", id);
}



int obtenirDernierIndi(int choice) {
    FILE *fichier =  choixCategories( choice ) ;

    int dernierIndex = -1;
    Produit p;
    while (fscanf(fichier, "%d %s %s %d %d %d %d", &p.id, p.nom, p.prenom, &p.prix, &p.quantite_actuelle, &p.quantite_minimale,&p.topsales) != EOF) {
        dernierIndex = p.id;
    }

    fclose(fichier);
    return dernierIndex;
}

void afficherClient(Client client) {

    afficherBordureTexte(60);
    printf("CNI : %d\n", client.CNI);
    printf("Nom de famille : %s\n", client.nom);
    printf("Prenom : %s\n", client.prenom);
    printf("Adresse : %d %s, %s\n", client.adress.num_maison, client.adress.quartier, client.adress.ville);
    printf("Numero de telephone : %s\n", client.numero);
    afficherBordureTexte(60);
    getchar();

}
void lireEtAfficherDepuisClientFile(){
    FILE *file_c = file_Client() ;
    Client client;
 getchar();
    while (fscanf(file_c, "%d %s %s %d %s %s %s\n",&client.CNI,client.nom,client.prenom,&client.adress.num_maison,client.adress.quartier,client.adress.ville,client.numero) == 7) {
        afficherClient(client);
    }

    getchar();
    system("cls");
    fclose(file_c);
}
void verification(int choice) {
    FILE *verif = choixCategories_v(choice);
    FILE *file = choixCategories(choice);
    int veriff=0;
    Produit produit;

    while (fscanf(file, "%d %s %s %d %d %d %d\n", &produit.id, produit.nom, produit.prenom, &produit.prix, &produit.quantite_actuelle, &produit.quantite_minimale,&produit.topsales) != EOF) {
        if (produit.quantite_actuelle < produit.quantite_minimale) {
            veriff=1;
            printf("Le produit %s %s a depasse la quantite minimale %d\n", produit.nom, produit.prenom, produit.quantite_minimale);
            printf("La quantite actuelle du produit est : %d\n", produit.quantite_actuelle);
            printf("Saisissez la quantite que vous voulez ajouter par le fournisseur : ");
            scanf("%d", &produit.quantite_ajouter);

            while (1) {
                if (produit.quantite_ajouter > (produit.quantite_minimale - produit.quantite_actuelle)) {
                    break;
                } else {
                    printf("Erreur : Veuillez saisir une valeur qui est superieure a la quantite minimale\n");
                    printf("Ressaisissez s'il vous plait : ");
                    scanf("%d", &produit.quantite_ajouter);
                       }
            }

            char date[20];
            obtenirDateActu(date);
            snprintf(produit.date, sizeof(produit.date), "%s", date);

            fprintf(verif, "%d %s %s %d %s\n", produit.id, produit.nom, produit.prenom, produit.quantite_ajouter, produit.date);
           }

 }
            fclose(verif);
            fclose(file);
      if(veriff==0  ){
        afficherBordureTexte(30);
        printf("Votre stock est a jour \n");
        afficherBordureTexte(30);
}
      else{
        afficherBordureTexte(60);
        printf("NB : \n  ");
        printf("La liste des produits manquants sera envoyee a la boite \n de reception du fournisseur concerne.\n");
        afficherBordureTexte(60);

}
sleep(2);
system("cls");
}

void BoiteEmailAdminFournss(int choice) {
    FILE *file_bilan = choixbilan(choice);
    char partie1[20], partie2[20];
    if (file_bilan != NULL) {
        Bilan bilan;
        system("cls");
        fscanf(file_bilan, "%s %s %d %s %s %s\n", bilan.nom, bilan.prenom, &bilan.quantite_ajouter, bilan.four_asso, bilan.categorie_asso ,bilan.date);
        printf("\n");
        printf("\tSubject: Validation de fournissement des articles liee a  < %s > \n\nBonjour Monsieur Othman, Mademoiselle Hanae :\n\nVoici le bilan des articles que nous avons fournis :\n",bilan.categorie_asso);
        printf("\n");
        printf("%-20s %-20s %-13s\n", "Nom", "Prenom", "Quantite Ajouter");
        afficherBordureNSpace(58);

        rewind(file_bilan);

        while (fscanf(file_bilan, "%s %s %d %s %s %s\n", bilan.nom, bilan.prenom, &bilan.quantite_ajouter, bilan.four_asso, bilan.categorie_asso, bilan.date) == 6) {
            printf("%-20s %-20s %-15d\n", bilan.nom, bilan.prenom, bilan.quantite_ajouter);
    }

        printf("\n");
        printf("Cordialement,\n\t Envoyer Par:  %s \n",bilan.four_asso);
        printf("  \t\tLe :");

        if(sscanf(bilan.date, "%[^|]|%s", partie1, partie2) == 2) {
        printf(" %s   ", partie1);
        printf("%s\n", partie2);
    }
        getchar();
        getchar();
        fclose(file_bilan);
    }
}


 void Menu_Gestion(int choice){

  int choix;
    do {

        afficherTitre2("GESTION DE CATEGORIE");
        afficherBordureTexte(60);
        printf("1. Afficher les produits\n");
        printf("2. Ligne de Produits \n");
        printf("3. Verification du stock \n");
        printf("4. Boite Mail \n");
        printf("5. Revenir au Menu Admin \n");
        printf("6. Revenir au Menu Principal \n");
        printf("7. Quitter\n");
        afficherBordureTexte(60);
        printf("Veuillez entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                {
                system("cls");
                afficherProduits(choice);
                break;}
            case 2: {
                system("cls");
                int dernierIndex = obtenirDernierIndi(choice);
                printf("Le nombre des Article dans cette caategorie  est : %d\n", dernierIndex);
                printf("\n");
                break;}
             case 3:
                {
                system("cls");
                verification(choice);
                break;}
                case 5:
                {
                system("cls");
                menu_choix();

                break;}
             case 6:
                 {
                system("cls");
                Menu_acces();
                break;}
                 case 4:
                 {
                system("cls");
                BoiteEmailAdminFournss( choice );
                break;}
                case 7:
                system("cls");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 7);

 }

void lireFeedbacks() {
    // Ouverture du fichier "feedback.txt" en mode lecture
    FILE *fichierFeedback = fopen("feedback.txt", "r");
afficherTitre2("FEEDBACKS");
    if (fichierFeedback != NULL) {
        char feedback[1000], commentaire[500];
    Client client ;
        // Lire et afficher chaque ligne du fichier
        while (fscanf(fichierFeedback, "%s %s %s %[^\n]", client.nom, client.prenom, feedback, commentaire) == 4) {
            afficherBordureTitre2(40);
            printf("Nom Complet : %s %s\n", client.nom ,client.prenom );

            printf("Feedback: %s\n", feedback);

            // Vérifier si un commentaire est présent
            if (commentaire[0] != '\0') {
                printf("Commentaire: %s\n", commentaire);
            }
            afficherBordureTitre2(40);

            printf("\n");
            getchar();
            getchar();
        }

        fclose(fichierFeedback);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}


void afficherMenuCategorie() {
    afficherTitre("Menu");
    afficherBordureTexte(60);
    printf(" 1. Categorie 1: Electronique\n");
    printf(" 2. Categorie 2: Meuble\n");
    printf(" 3. Categorie 3: Vetement\n");
    printf(" 4. Liste des clients \n");
    printf(" 5. Historique des commandes \n");
    printf(" 6. Statistique sur les Achats \n");
    printf(" 7. Voir FEEDBACKS \n");
    printf(" 8. Courrier des Reclamations  \n");


    printf(" 9. Revenir au menu precedent\n");
    afficherBordureTexte(60);
}
int choisirCategorie() {
    int choix;
    printf("Choisissez une categorie (1-4): ");
    scanf("%d", &choix);
    return choix;
}



void afficherStatistique() {
     FILE* fileHC = fopen("historique_command.txt", "r");
    if (fileHC == NULL) {
        printf("Le fichier HC.txt n'existe pas ou ne peut pas être ouvert.\n");
        return;
    }
    int numeroCommandes=0 ;
    int numeroCommande;
    char dateHeure1[40], dateHeure2[20];
    int montant;
    Client client;
    int total = 0;
    float Net;

    char date_debut1[20], date_debut2[20];
    char date_fin1[20], date_fin2[20];
    fscanf(fileHC, "%d %s %s %s %s %d\n", &numeroCommande, client.prenom, client.nom, dateHeure1, dateHeure2, &montant);
    strcpy(date_debut1, dateHeure1);
    strcpy(date_debut2, dateHeure2);
    rewind(fileHC);


    while (fscanf(fileHC, "%d %s %s %s %s %d\n", &numeroCommande, client.prenom, client.nom, dateHeure1, dateHeure2, &montant) == 6) {
        total = total + montant;
        numeroCommandes++;
}
     strcpy(date_fin1, dateHeure1);
    strcpy(date_fin2, dateHeure2);

    printf("\n\n\t\t----------------------------- Statistique -----------------------------\n\n");
    printf("Nombre total de commandes : %d\n",numeroCommandes );
    printf("Periode  : De %s %s   A  %s %s\n", date_debut1, date_debut2, date_fin1,date_fin2);
    printf("Montant total de toutes les commandes : %d$\n", total);
    Net= total - 20*numeroCommandes;
    Net= Net*0.3;
    printf("Montant Net = ( Prix de Vente - Cout de Livraison ) x ( La Marge Beneficiare ) = %.2f$ \n",Net);
    printf("--------------------------------------------------------------------------------------------\n");
    getchar();
    getchar();
}





void HistoriqueCommande() {
    FILE* histo=fopen("historique_comm.txt","r");

    if (histo == NULL) {
        printf("Le fichier HC.txt n'existe pas ou ne peut pas être ouvert.\n");
        return;
    }
    historique his;
    char c ;
    printf("\n\t\t------------------------ HISTORIQUE DES COMMANDES -------------------------\n\n");
    printf("%-15s%-15s%-25s%-25s%-10s\n", "N Commande", "Nom Client", "Prenom Client ", "Date de Commande", "Montant");
    printf("---------------------------------------------------------------------------------------------------------------\n");

char ligne[255];
 while(fscanf(histo,"%c %d %d %d %s %s %s %s %s %s %d\n",&c,&his.id_com,&his.client.CNI,&his.prixtotal,his.client.nom,his.client.prenom,his.date_com1,his.date_com2,his.dat_final1,his.dat_final2,&his.nmbr_art)==11){
   int  i=0;
         printf("\n__________________________________________________________________________________________________________________\n");
           printf("ID de commande  :%d\n",his.id_com);
           printf(" Le nom complet du Client : %s %s  \n ",his.client.nom , his.client.prenom);
           printf("Prix Total:%d\n",his.prixtotal);
           printf("Le nombre des article achete par ce client : %d  \n",his.nmbr_art);
           printf("Date de commande : %s %s",his.date_com1,his.date_com2);

           printf("\n__________________________________________________________________________________________________________________\n");
  while(i<his.nmbr_art){
fgets(ligne,255,histo);
 i++ ;
 }
getchar();
getchar();

 }

    fclose(histo);
}

void lireReclamationsAdmin() {
    FILE *boiteReceptionAdmin = fopen("boite_reception_admin.txt", "r");

    if (boiteReceptionAdmin != NULL) {
        char nomUtilisateur[51];
        char objetReclamation[20];
        char reclamation[51];

        // Lire et afficher chaque ligne du fichier
        printf("Liste des reclamations dans la boite de reception de l'administrateur :\n");
        while (fscanf(boiteReceptionAdmin, "%50[^,], %19[^,], %50[^\n]", nomUtilisateur, objetReclamation, reclamation) == 3) {
            printf("Nom de l'utilisateur: %s\n", nomUtilisateur);
            printf("Objet de la réclamation: %s\n", objetReclamation);
            printf("Réclamation: %s\n\n", reclamation);
        }

        fclose(boiteReceptionAdmin);
    } else {
        printf("Erreur lors de l'ouverture du fichier de la boîte de réception de l'administrateur.\n");
    }
}


void menu_choix(){
    while (1) {
        afficherMenuCategorie();
        int choix = choisirCategorie();

        switch (choix) {
            case 1:
                 {
                system("cls");
                afficherTitre("Categorie Electronique");
                printf("\n");
                Menu_Gestion(choix);
                break;}

            case 2:
                 {
                system("cls");
                afficherTitre("Categorie Meuble");
                printf("\n");
                Menu_Gestion(choix);
                break;}

            case 3:
               {
                system("cls");
                afficherTitre("Categorie Vetement");
                printf("\n");
                Menu_Gestion(choix);
                break;}

            case 4: {
                system("cls");
                lireEtAfficherDepuisClientFile();
               break;
            }
            case 5:
                 {
               system("cls");
               HistoriqueCommande();
               break;
                  }
                   case 6:
                 {
                system("cls");
                afficherStatistique();
               break;
                  }
                   case 7:
                 {
                system("cls");
                lireFeedbacks();
               break;
                  }
                     case 8:
                 {
                system("cls");
               lireReclamationsAdmin();
               break;
                  }
                    case 9:
                 {
               system("cls");
               TopPRODUIT();
               getchar();
               getchar();
                  }
                    case 10:
                 {
                system("cls");
               Menu_acces();
                  }
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
                break;
        }
    }

    return 0;
}
void afficherStockFournisseur( Fournisseur fournisseur ) {
    FILE * file_fs = choixstockf(fournisseur);
   Fournisseurfs fs ;
    afficherTitre2("Votre stock");
    printf("\n");
    printf("%-4s%-20s%-20s%-10s\n", "ID", "Nom", "Prenom", "Quantite");
    afficherBordureNSpace(58);

  while (fscanf(file_fs, "%d %s %s %d\n", &fs.id, fs.nom, fs.prenom, &fs.quantite_stock_fournisseur) == 4) {
        printf("%-4d%-20s%-20s%-10d\n", fs.id, fs.nom, fs.prenom, fs.quantite_stock_fournisseur);
    }
printf("\n");
fclose(file_fs);
getchar();
getchar();

}
void   afficherMenu(Fournisseur fournisseur  ) {
   system("cls");
    printf("\t\t   ---------- WELCOME : %s  ------------\n\n",fournisseur.pseudo);

    afficherTitre2("Menu De Gestion ");
    printf(" 1. Voir Votre stock \n");
    printf(" 2. Boite de Reception \n");
    printf(" 3. Section de Fournissement \n");
    printf(" 4. Quitter\n");
}
FILE *choixstockf_2(Fournisseur fournisseur) {
    if (strcmp(fournisseur.pseudo, "fournisseur1") == 0) {
        return fopen("f1s.txt", "r");
    } else if (strcmp(fournisseur.pseudo, "fournisseur2") == 0) {
        return fopen("f2s.txt", "r");
    } else if (strcmp(fournisseur.pseudo, "fournisseur3") == 0) {
        return fopen("f3s.txt", "r");
    } else {
        return NULL;  // Fournisseur non pris en charge
    }
}
void lireFichierVerification(FILE *file_verification) {
    Produit produit;
    while (fscanf(file_verification, "%d %s %s %d %s\n", &produit.id, produit.nom, produit.prenom, &produit.quantite_actuelle, produit.date) == 5) {
        // Afficher les informations comme un email professionnel
        printf("Produit ID: %d\n", produit.id);
        printf("Nom: %s %s\n", produit.nom, produit.prenom);
        printf("Quantite ajoutee: %d\n", produit.quantite_actuelle);
        printf("Date: %s\n", produit.date);
        printf("------------------------------\n");
    }
}

void mettreAJourStock(Fournisseur fournisseur) {
        FILE *file_c = NULL;
        FILE *file_verif = NULL;
        FILE *file_bilan = NULL;
        FILE *file_fs = NULL;
        Bilan bilan;
  afficherTitre2(" Section de Founissage ");
        // Set the category based on the pseudo
        if (strcmp(fournisseur.pseudo, "fournisseur1") == 0) {
            file_verif = fopen("categorie1verif.txt", "r");
                } else if (strcmp(fournisseur.pseudo, "fournisseur2") == 0) {
            file_verif = fopen("categorie2verif.txt", "r");
                    } else if (strcmp(fournisseur.pseudo, "fournisseur3") == 0) {
            file_verif = fopen("categorie3verif.txt", "r");
                   }
 if(file_verif != NULL){




         int caractere = fgetc(file_verif);
 if (caractere != EOF) {

        if (strcmp(fournisseur.pseudo, "fournisseur1") == 0) {
                      file_bilan = fopen("bilan_fournisseur1.txt", "w");
        } else if (strcmp(fournisseur.pseudo, "fournisseur2") == 0) {
                    file_bilan = fopen("bilan_fournisseur2.txt", "w");
        } else if (strcmp(fournisseur.pseudo, "fournisseur3") == 0) {
            file_bilan = fopen("bilan_fournisseur3.txt", "w");
        }

rewind(file_verif);
        int id, quantite_ajouter;
        char nom[50], prenom[50], date[30];
        char dat_tmp[30];


          while (fscanf(file_verif, "%d %s %s %d %s\n", &id, nom, prenom, &quantite_ajouter, date) == 5){
            Produit produit;
            Fournisseurfs fournis;



        if (strcmp(fournisseur.pseudo, "fournisseur1") == 0) {
            file_c = fopen("categorie1.txt", "r");
            strcpy(bilan.categorie_asso, "Electronique");
            file_fs = fopen("f1s.txt", "r") ;
        } else if (strcmp(fournisseur.pseudo, "fournisseur2") == 0) {
            file_c = fopen("categorie2.txt", "r");
            strcpy(bilan.categorie_asso, "Vetement");
           file_fs = fopen("f2s.txt", "r") ;
        } else if (strcmp(fournisseur.pseudo, "fournisseur3") == 0) {
            file_c = fopen("categorie3.txt", "r");
            strcpy(bilan.categorie_asso, "Meuble");
            file_fs = fopen("f2s.txt", "r") ;
        }
        FILE *tmps = fopen("tmps.txt", "a+");
        FILE *tmpc = fopen("tmpc.txt", "a+");


            while (fscanf(file_fs, "%d %s %s %d\n", &fournis.id, fournis.nom, fournis.prenom, &fournis.quantite_stock_fournisseur) == 4) {

                if (id == fournis.id) {
                    fournis.quantite_stock_fournisseur -= quantite_ajouter;
                    fprintf(tmps, "%d %s %s %d\n", fournis.id, fournis.nom, fournis.prenom, fournis.quantite_stock_fournisseur);
                } else {
                    fprintf(tmps, "%d %s %s %d\n", fournis.id, fournis.nom, fournis.prenom, fournis.quantite_stock_fournisseur);
                }
            }

            while (fscanf(file_c, "%d %s %s %d %d %d %d\n", &produit.id, produit.nom, produit.prenom, &produit.prix, &produit.quantite_actuelle, &produit.quantite_minimale,&produit.topsales) == 6) {
                if (id == produit.id) {
                    produit.quantite_actuelle += quantite_ajouter;
                    fprintf(tmpc, "%d %s %s %d %d %d %d\n", produit.id, produit.nom, produit.prenom, produit.prix, produit.quantite_actuelle, produit.quantite_minimale,produit.topsales);

                    // �criture dans le fichier bilan


                    char date_act[20];
              obtenirDateActu(date_act);
              snprintf(date_act, sizeof(date_act), "%s", date_act);

                    strcpy(bilan.nom, produit.nom);
                    strcpy(bilan.prenom, produit.prenom);
                    bilan.quantite_ajouter = quantite_ajouter;
                    strcpy(bilan.date, date_act);
                    strcpy(bilan.four_asso, fournisseur.pseudo);
                    fprintf(file_bilan, "%s %s %d %s %s %s\n", bilan.nom, bilan.prenom, bilan.quantite_ajouter, bilan.four_asso, bilan.categorie_asso, bilan.date);
                } else {
                    fprintf(tmpc, "%d %s %s %d %d %d %d\n", produit.id, produit.nom, produit.prenom, produit.prix, produit.quantite_actuelle, produit.quantite_minimale,produit.topsales);
                }
            }


        // Fermer les fichiers
        fclose(file_c);

        fclose(tmpc);
        fclose(tmps);
        fclose(file_fs);


        // Remove and rename files based on pseudo
        if (strcmp(fournisseur.pseudo, "fournisseur1") == 0) {
            remove("categorie1.txt");
            rename("tmpc.txt", "categorie1.txt");
            remove("f1s.txt");
            rename("tmps.txt", "f1s.txt");
        } else if (strcmp(fournisseur.pseudo, "fournisseur2") == 0) {
            remove("categorie2.txt");
            rename("tmpc.txt", "categorie2.txt");
            remove("f2s.txt");
            rename("tmps.txt", "f2s.txt");
        } else if (strcmp(fournisseur.pseudo, "fournisseur3") == 0) {
            remove("categorie3.txt");
            rename("tmpc.txt", "categorie3.txt");
            remove("f3s.txt");
            rename("tmps.txt", "f3s.txt");
        }
    }


fclose(file_fs);
fclose(file_bilan);

        if (strcmp(fournisseur.pseudo, "fournisseur1") == 0) {
            file_verif = fopen("categorie1verif.txt", "w");
        } else if (strcmp(fournisseur.pseudo, "fournisseur2") == 0) {
            file_verif = fopen("categorie2verif.txt", "w");
        } else if (strcmp(fournisseur.pseudo, "fournisseur3") == 0) {
            file_verif = fopen("categorie3verif.txt", "w");
        }
 fclose(file_verif);
 printf("L'operation est en cours, veuillez patienter .");
 sleep(1);
 printf(".");
 sleep(1);
 printf(".");
 sleep(1);
 printf(".");
 sleep(1);
 printf(".");
 printf("\nUn email a ete envoyee automatiquement dans la boite email d'Admin \n");
 getchar();
 getchar();
 }
 else {

    printf(" Aucune operation n'a ete effectuee (la boite de reception est vide) !! \n ");
getchar();
getchar();
 }

 }

}


void VoirBesoin(Fournisseur fournisseur){

     afficherTitre2("Boite Mail");
     printf("Liste des Demandes :\n");

     printf("\n");
      FILE *file_verif = NULL;
              // Set the category based on the pseudo
           if (strcmp(fournisseur.pseudo, "fournisseur1") == 0) {
      file_verif = fopen("categorie1verif.txt", "r");
           } else if (strcmp(fournisseur.pseudo, "fournisseur2") == 0) {
      file_verif = fopen("categorie2verif.txt", "r");
           } else if (strcmp(fournisseur.pseudo, "fournisseur3") == 0) {
      file_verif = fopen("categorie3verif.txt", "r");
                   }


  if(file_verif != NULL){
     int caractere = fgetc(file_verif);
 if (caractere != EOF) {
rewind(file_verif);
        int id, quantite_ajouter;
        char nom[50], prenom[50], date[30];
        char dat_tmp[30];
        lireFichierVerification(file_verif);
 }
 else
    printf(" votre boite de reception est vide maintenant \n");
  }
  getchar();
  getchar();
 }

int Gestion_fournisseur(Fournisseur fournisseur ) {
    int choix;

    do {

       afficherMenu(fournisseur );
        printf(" Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                afficherStockFournisseur(fournisseur);
                break;
            case 2:
               system("cls");
               VoirBesoin(fournisseur);
                break;

            case 3:
                system("cls");
                mettreAJourStock(fournisseur);

                break;
             case 4:
                system("cls");
                Menu_acces();
                break;
            default:
                printf("Choix invalide. Veuillez choisir a nouveau.\n");
        }
    } while (choix != 4);
    return 0;
}

void afficherSectionAboutUs() {
    printf("\t*******************************************\n");
    printf("\t*            A PROPOS DE NOZAMA            *\n");
    printf("\t*******************************************\n");
    afficherBordureTexte(60);
    printf(" Nom de l'entreprise: NOZAMA\n");
    printf(" Fondateurs: Othman El Hadrati et Hanae Khayyi\n");
    printf(" Description: NOZAMA se specialise dans la vente en\n\t      ligne et la livraison .\n");
    printf(" Date de creation de l'entreprise: Le 12 Decembre 2023 \n");
    afficherBordureTexte(60);
}


//***************************************************************************************modif
void MasquerMotDePasse(char* motDePasse, int taille) {
    int i = 0;
    while (i < taille - 1) {
        char caractere = _getch(); // Utilise getch() pour lire un caractère sans l'afficher
        if (caractere == '\r' || caractere == '\n') { // Arrêt à l'entrée ou au retour chariot
            break;
        } else if (caractere == 8 && i > 0) { // Gestion de la touche Backspace
            printf("\b \b"); // Efface le dernier caractère affiché
            i--;
        } else {
            motDePasse[i] = caractere;
            printf("*");
            i++;
        }
    }
    motDePasse[i] = '\0'; // Ajoute le caractère de fin de chaîne
}
// Fonction pour saisir un client
Client SaisirClient() {
    Client client;
    char confirmationPasswd[20];
    getchar(); // Pour consommer le caractère de retour à la ligne précédent

    printf("CNI : ");
    while (1) {
        client.CNI = int_dd();
        if (client.CNI > 0) {
            break;
        } else {
            printf("Error: Please enter a positive integer for the ID.\n");
            printf("Please re-enter: Error, please provide a positive integer for the ID:");
        }
    }

    printf("Last name : ");
    scanf("%49s", client.nom);

    printf("First name : ");
    scanf("%49s", client.prenom);

    printf("Address:\n");
    getchar(); // Pour consommer le caractère de retour à la ligne
    printf(" House number : ");
    while (1) {
        client.adress.num_maison = int_dd();
        if (client.adress.num_maison > 0) {
            break;
        } else {
            getchar();
            printf("Please re-enter: Error, please provide a positive integer for the House number:\n");
            printf("Please re-enter: ");
        }
    }


    printf("Enter the name of the neighborhood :");
    scanf("%49s", client.adress.quartier);

    printf("Enter the name of the city : ");
    scanf("%49s", client.adress.ville);

    getchar(); // Pour consommer le caractère de retour à la ligne

    printf("Enter YOUR PHONE NUMBER : ");
    scanf("%19s", client.numero);

    do {
        printf("Password : ");
        MasquerMotDePasse(client.passwd, sizeof(client.passwd));

        printf("\nConfirm Password : ");
        MasquerMotDePasse(confirmationPasswd, sizeof(confirmationPasswd));

        // Vérification si le mot de passe et sa confirmation sont identiques
        if (strcmp(client.passwd, confirmationPasswd) != 0) {
            printf("\nError: Passwords do not match. Please try again.\n");
        } else {
            // Les mots de passe correspondent
            printf("\nConnexion succes !\n");
            break;
        }
    } while (1);

    return client;
}
//*******************************************************************
void EnregistrerClient(Client client) {
     FILE*file_c=fopen("Client.txt","a+"); // Assurez-vous de mettre le bon nom de fichier
    if (file_c == NULL) {
        printf("Erreur lors de l'ouverture du fichier client.\n");
        return;
    }

    fprintf(file_c, "%d %s %s %d %s %s %s %s \n", client.CNI, client.nom, client.prenom, client.adress.num_maison, client.adress.quartier, client.adress.ville, client.numero ,client.passwd);

    fclose(file_c);
}
//***********************************************************************
bool ClientExiste(int cni) {
    FILE *file_c = fopen("Client.txt", "r");
    if (file_c == NULL) {
        fclose(file_c);
        return false;
    }

    Client client;

    // Lire le fichier pour vérifier si le client existe
    while (fscanf(file_c, "%d", &client.CNI) == 1) {
        if (client.CNI == cni) {
            fclose(file_c);
            return true;  // Le client existe déjà
        }

        // Ignorer le reste de la ligne
        while (fgetc(file_c) != '\n');
    }

    fclose(file_c);
    return false;  // Le client n'existe pas
}
//***********************************************************************
// Fonction SignIn
void SignIn() {
    // Saisir les informations du client
    Client A=SaisirClient();

    // Vérifier si le client existe déjà
    if (ClientExiste(A.CNI)) {
        printf("\nThis client already has an account with the same information.\n");
        AccesClient();

    } else {
        // Enregistrer le nouveau client
        EnregistrerClient(A);
        Tmp(A.CNI,A.passwd);
        printf("Connexion succes\n");
        // Appeler la fonction MENU
        TraiterChoixUtilisateur();
    }
}
//**
//**************************************************************
bool VerifierConnexion(int CNI, const char *passwd) {
    FILE *file_c = fopen("Client.txt", "r");
    if (file_c == NULL) {
        printf("aucun client");
        return false;
    }

    Client client;

    // Lire le fichier pour vérifier les coordonnées de connexion
    while (fscanf(file_c, "%d %s %s %d %s %s %s %s", &client.CNI, client.nom, client.prenom, &client.adress.num_maison,
                  client.adress.quartier, client.adress.ville, client.numero, client.passwd) == 8) {
        if (client.CNI == CNI && strcmp(client.passwd, passwd) == 0) {
            fclose(file_c);
            return true;  // Les coordonnées de connexion sont valides
        }
    }

    fclose(file_c);
    return false;  // Les coordonnées de connexion ne sont pas valides
}
//****************************************************************************************
// Fonction pour le processus de connexion
void Login() {
    int CNI;
    char passwd[50];

    printf("Username(CNI) : ");
    scanf("%d",&CNI);

    printf("Entrez votre mot de passe : ");
    MasquerMotDePasse(passwd, sizeof(passwd));
    if (VerifierConnexion(CNI, passwd)) {
        printf("\nConnexion succes.\n");
        // Appeler la fonction MENU
        Tmp(CNI,passwd);
        TraiterChoixUtilisateur();
    } else {
        printf("\nUsername or password incorrect.\n");
        AccesClient();
    }

}
//*******************************************************************
void AccesClient() {
    printf("Bienvenu chez \"NOZAMA\"\n");
    printf("1 - Sign In\n");
    printf("2 - Login\n");
    printf("3 - Quitter\n");
    int choix;
    do {
        choix = getIntInput();
    } while (choix < 1 || choix > 3);

    switch (choix) {
        case 1:
            system("cls");
            SignIn();
            break;
        case 2:
            system("cls");
            Login();
            break;
        case 3:{
            system("cls");
            printf("\nMerci d'avoir utilise \"NOZAMA\". Au revoir !\n");
            getch();
            Menu_acces();
            // Ajoutez ici le code pour quitter l'application, si nécessaire.
            break;
            }
        default:
            printf("Choix invalide.\n");
            // Ajoutez ici le code pour gérer d'autres cas, si nécessaire.
            break;
    }
}

 void Menu_acces(){
  int choix;
    afficherTitre(" MENU GLOBAL");
    afficherBordureTexte(60);
    printf("\n 1 - Acces Admin");
    printf("\n 2 - Acces Fournisseur");
    printf("\n 3 - Acces Client");
    printf("\n 4 - A propos");
    printf("\n * - Qitter\n\n");
    afficherBordureTexte(60);

    printf("\n Entrez votre choix : ");
    scanf("%d", &choix);

char user_try[20];
char password[20];
int i ;


    //Admin
    if (choix == 1) {
    system("cls");
    Admin admin;
    int direction =0;
    printf("\n\n");
    afficherTitre(" LOGIN ADMIN");
    printf("\n");


     do {
            FILE *file_a = file_Admin();
            afficherBordureTexte(60);
        printf("\n Entrez votre pseudo : ");
        scanf("%s", user_try);
        i = 0;
        char ch1;
        printf(" Entrez le mot de passe : ");
        while (1) {
        ch1 = _getch();

        if (ch1 == 13) // 13 correspond à la touche "Entrée"
            break;
        else if (ch1 == 8) { // 8 correspond à la touche "Retour arrière"
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (i < sizeof(password) - 1) {
            password[i++] = ch1;
            printf("*");
        }
    }

    password[i] = '\0';
     printf("\n");
    afficherBordureTexte(60);





        while (fscanf(file_a, "%s %s", admin.pseudo, admin.password) != EOF) {
            if (strcmp(user_try, admin.pseudo) == 0 && strcmp(password, admin.password) == 0) {
                printf("Succes d'acces !!\n");
                fclose(file_a);
                system("cls");
                menu_choix();
                direction =1;

            }
        }
        fclose(file_a);
        if(direction==0);
        printf(" Acces refuse !!\nEssayez a nouveau.\n");

    } while (1);
}
//fournisseur
 else if (choix == 2) {

    system("cls");
    Fournisseur fourni;
    printf("\n\n");
    afficherTitre("LOGIN FOURNISSEUR");
    printf("\n");
    do {
          FILE *file_f = file_Fournissuer();
        afficherBordureTexte(60);
        printf("\nEntrez votre pseudo : ");
        scanf("%s", user_try);
        i = 0;
        char ch2;

    printf("Entrez le mot de passe : ");

    while (1) {
        ch2 = _getch();

        if (ch2 == 13) // 13 correspond à la touche "Entrée"
            break;
        else if (ch2 == 8) { // 8 correspond à la touche "Retour arrière"
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (i < sizeof(password) - 1) {
            password[i++] = ch2;
            printf("*");
        }
    }

    password[i] = '\0';
     printf("\n");
    afficherBordureTexte(60);
 while (fscanf(file_f, "%s %s", fourni.pseudo, fourni.password) != EOF) {
            if (strcmp(user_try, fourni.pseudo) == 0 && strcmp(password, fourni.password) == 0) {
                fclose(file_f);

               Gestion_fournisseur(fourni);
            }
        }
        fclose(file_f);

        printf("\nAcces refuse !!\nEssayez A nouveau.\n");
    } while (1);
}

// client
// client
else if (choix == 3){
  system("cls");
  AccesClient();
}

else if(choix ==4 ){
          system("cls");

afficherSectionAboutUs() ;
getchar();
getchar();
system("cls");
Menu_acces();
}
else {
        printf("\n Merci pour votre visite");
        exit(0);}

 }
///**************************************
void lireBoiteReceptionReclaAdmin() {
    FILE *boiteReceptionAdmin = fopen("boite_reception_admin.txt", "r");
    if (boiteReceptionAdmin != NULL) {
        printf("Contenu de la boite de réception de l'administrateur :\n");

        char nomUtilisateur[20];
        char prenomUtilisateur[20];
        char objet[100];
        char reclamation[100];

        while (fscanf(boiteReceptionAdmin, "%19s %19s %99s %99s",nomUtilisateur, prenomUtilisateur, objet, reclamation) == 4) {
            printf("Nom : %s\n", nomUtilisateur);
            printf("Prenom : %s\n", prenomUtilisateur);
            printf("Objet : %s\n", objet);
            printf("Réclamation : %s\n", reclamation);
            printf("\n");
        }

        fclose(boiteReceptionAdmin);
    } else {
        printf("Erreur lors de l'ouverture du fichier de la boite de reception de l'administrateur.\n");
    }
}
///********************************************************************************
void Triselection(Produit *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j].topsales > arr[maxIndex].topsales) {
                maxIndex = j;
            }
        }

        // Échanger les éléments
        Produit temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}


void afficherTableauTriee(const Produit *arr, int n, const char *nomFichier) {
    printf("\n=================================== Top Produits %s =========================================\n", nomFichier);

    // Affichage de l'en-tête
    printf("%-6s%-20s%-20s%-10s\n", "ID", "Nom", "Prenom", "TopSales");

    for (int i = 0; i < 3; i++) {
        printf("%-6d%-20s%-20s%-10d\t", arr[i].id, arr[i].nom, arr[i].prenom, arr[i].topsales);

        // Simple ASCII bar chart based on the topsales value
        for (int j = 0; j < arr[i].topsales/2 ; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("============================================================================================\n");
}


void topProd1(const char *nomFichier) {
    Produit A;
    int cont = 0;

    FILE *fichierc = fopen(nomFichier, "rt");
    if (fichierc == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    while (fscanf(fichierc, "%d%s%s%d%d%d%d", &A.id, A.nom, A.prenom, &A.prix, &A.quantite_actuelle, &A.quantite_minimale, &A.topsales) != EOF) {
        cont++;
    }

    rewind(fichierc);

    Produit P[cont];
    int i = 0;

    while (fscanf(fichierc, "%d%s%s%d%d%d%d", &A.id, A.nom, A.prenom, &A.prix, &A.quantite_actuelle, &A.quantite_minimale, &A.topsales) != EOF) {
        P[i] = A;
        i++;
    }

    // Tri du tableau par rapport à topsales en utilisant le tri par sélection
    Triselection(P, cont);

    // Affichage du tableau trié
    afficherTableauTriee(P, cont,nomFichier);

    fclose(fichierc);
}


//*************************************************************************
void TopPRODUIT(){
    int choix;
printf("\n=================================== Top Produits =========================================\n");
printf("       1- Electronique\n");
printf("       2- Meuble\n");
printf("       3- Vetement\n");
printf("       *- Sortir\n");
printf("================================================================================================\n");
printf(">>> ");
choix=getIntInput();
switch (choix) {
        case 1:
            topProd1("categorie1.txt");
            break;
        case 2:
            topProd1("categorie2.txt");
            break;
        case 3:
            topProd1("categorie3.txt");
            break;
        default:
            break;
}
}
///*******************************************************************************************
#endif // ANYTHING_H_INCLUDED
