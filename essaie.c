#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <winsock2.h>
#include <winsock.h>
#include<windows.h>

#include "game.h"
int main()
{
	int ctrlancepartie=0;// variable qui intervient et agit comme condition d'arret de jeu ou de relance du jeu
    int ctrarret=0;// variable qui intervient danns condition d'arret définitif de la partie
    int ctrarrett=0;// variable qui intervient danns condition d'arret définitif de la partie pour le mode contre la montre
    int xt=0;
    int prnonmj=0;// boucle condition de jeu
    int prnonmjt=0;// boucle condition de jeu contre le temps
    int diff=0; // objectif à atteindre
    int choix;// prend la valeur renvoyée par la fonction jeux
    int n=0;// taille du tableau
    int zz=0;// bintervient lorsque le jeu est en cours
    int mdj=0;// mode de jeux renvoyer menu principal
    char nom[50];// votre nom est enregistré en fin de partie
    char carac;// intervient dans la boucle dowhil pour afficher le tableau de score (carrac=fgetc(fichier))
    FILE*fich=NULL;// pointeur sur fichier qu'on utilisera plutard
    FILE*fiche=NULL;// pointeur sur fichier qu'on utilisera plutard
    FILE*f=NULL;// pointeur sur fichier qu'on utilisera plutard
    presentation();// pour accueil
    int kk=0;// pour getch
    int m=0;
    int x=0;
    int k=0;
    int a=0;
    int a1=0;
    int a2=0;
    int b=0;
    int b1=0;
    int b2=0;
    int e=0;
    int e1=0;
    int e2=0;
    int d=0;
    int d1=0;
    int d2=0;
    int q=0;
    int q1=0;
    int q2=0;
    int i=0;
    int j=0;
    int rp;
    int boucle_menu=0; // intervient dans la boucle menu princpal
    int vide;
    int ctr=0;
    int successif=0;// utilise operation_possible(verifie si on peut toujours jouer)
    int mscore=0;//meilleur score
    int ky;// pour getch() clavier
    int pret;// intervient pour valider le lancement d'une partie
    int boucle_temps;// intervient dans course contre le temps
    for(boucle_menu=0;boucle_menu<3;boucle_menu++)//boucle du menu
    {
    	mdj=modejeux();//choix du mode jeu
    if(mdj==49)//1 joueur
    {
    	boucle_menu=0;// pour pouvoir revenir au menu en cas d'arret de partie la boucle de menu devient comme infini
    	system("cls");
    	choix=jeux();// choix du jeux qui renvoie une valeur selon nouvelle partie sauvegarde etc elle renvoie la valeur de la touche du pc
    for(zz=0;zz<3;zz++)//boucle paramettrage jeu
    {
    	if(choix==49)
    {
    	system("cls");
    	n=4;
    	diff=6561;
	}
	else if(choix==50)
	{
		system("cls");
		diff=paramettre();
        n=taille();
        Beep(900,100);
		printf("appuyez sur une s deux fois pour retourner r deux fois pour valider\n");
		kk=getch();
		ky=getch();
		switch(ky)
		{
			case 's': zz=0;
			case 'r': zz=3;
		}
	}
	else if(choix==51)
	{
		Beep(900,100);
		system("cls");
		fiche=fopen("score.txt","r");
		do
           {
           carac = fgetc(fiche);
          printf("%c", carac);
           } while (carac != EOF);

        fclose(fiche);
        printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			Beep(900,100);
			system("cls");
			zz=0;
			choix=jeux();
		}
	}
	else if(choix==52)
	{
		system("cls");
		aide();
		printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			zz=0;
			choix=jeux();
		}

	}
	else
	{
			system("cls");
		printf("mauvaise manipulation\n");
		boucle_menu=0;
		zz=4;
	}
	}
    srand(time(NULL));// afin de generer un nombre aleatoire
    int t[n][n];
    if(choix==53) // ici 53 equi vaut à 5 à cause du getch
	{
		system ("cls");
		printf("continuer partie sauvegardée ?\n");
		n=lecture_taille();
		init(n,t);
		diff=lecture_diff();
		aff(n,t);
		printf("%d",diff);
		lire_sauvegarde(n,t);
	}
	if(choix==54)
	{
		system("cls");
		n=4;
		diff=243;
		init(n,t);
		lire_simula(n,t);
		choix=53;
	}
	if(choix==55)
	{
		n=4;
		diff=243;
		init(n,t);
		lire_simul3(n,t);
		choix=53;
	}
	if(choix==56)
	{
		n=4;
		diff=243;
		init(n,t);
		lire_simul4(n,t);
		choix=53;
	}
    ctrarret=0;
    x=0;
    prnonmj=0;
    int w=0;
    pret=lancerpartie();// fonction pour demander si on veut jouer ou retourner
    for(ctrlancepartie=ctr;ctrlancepartie<2;ctrlancepartie++)//boucle qui verifie une condition d'arret de la partie , elle varie suivant ctr et ctrlance ( controle lance partie
    {
    if(pret==49)
    {
    system("cls");
    if(choix!=53)
    {
    	init(n,t);
		rd(n,t);
	}
    aff(n,t);
    fich=fopen("test.txt", "r");// pointeur sur fichier qui lui demande d'ouvrir le fichier test en mode lecture
    fscanf(fich, "%d", &mscore);
    fclose(fich);
    for(prnonmj=0;prnonmj<2;prnonmj++)//boucle qui verifie une deuxieme condition d'arret de jeu suivant prnonmj;
     {
     	if(ctrarret==0)// condition d'arret de jeu qui varie ulterieurment selon que le joueur perde , gagne, ou quitte la partie en cours
     	{
     		x=gagne(n,t,diff);
		}
		else
		{
			x=ctrarret;
		}
    if(x==0)// condition gagnÃ© ou perdu
	{
	    vide=vcasevide(n,t);
        k=getch();
        switch (k)// cette partie permet au joueur de jouer en utilisant les touches directionnelles
        {
        	case 75: //system("cls");
			a=a+left(n,t);// voir la zonne des fonctions deplacements .
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 72: //system("cls");// idem
			b=b+up(n,t);
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 77: //system("cls");
			e=e+right(n,t);
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 80: //system("cls");
			d=d+down(n,t);
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 's':system("cls");
        	    ctrarret=50;
        		x=3;
        		q=0;
        		init(n,t);
        		break;
        	case 'e':
        		sauvegarde_enreg(n,t);
        		sauvegarde_taille(n);
        		sauvegarde_diff(diff);
		}
		aff(n,t);
		if(vide==0) // verifie apres l'action du joueur si il reste des caes vides; siil y en a alors la fonction retourne une valeur autre que 0
		{
			successif=operationpossible(n,t);// verifie si deux  case identique se suivent sur les lignes ou les colonnes et renvoie une valeur autre que 0 si il y en a
				if(successif==0)
				{
					printf(" vous n'avez plus de mouvement possible fin de partie\n");
					ctrarret=4;
			    }
		}
    q=a+b+e+d;
    printf("score:%d\n",q);
    printf("meilleur score : %d \n",mscore);
    prnonmj=0;
	}
	else// si le joueur perd
	{
		ctrarret=0;
		printf("bravo entrez votre nom\n");// zone enregistrement des score et noms en fin de partie
	scanf("%s",nom);
    if (a+b+e+d>mscore)
    {
    	fich=fopen("test.txt","w");
    if (fich != NULL)
   {
   	   	fprintf(fich,"%d",a+b+e+d);
   }
   fclose(fich);
	}
   fiche=fopen("score.txt","r+");
   if(fiche!= NULL)
   {
   	 carac=fgetc(fiche);
   	 while(carac != EOF)
   	 {
   	 	carac=fgetc(fiche);
	}
   	fprintf(fiche," %s  %d\n",nom,a+b+e+d);
   }
   fclose(fiche);
   q=0;
   a=0;
   b=0;
   e=0;
   d=0;
   ctrlancepartie=0;
   pret=lancerpartie();
   if(pret==49)
   {
   	ctrarret=0;
	boucle_menu=0;
   }
	if(pret==50)
	{
		ctrlancepartie=3;
	}
	}
	}
	// fin boucle prnonmj;
    }
    else
    {
    	ctrlancepartie=3;
    	system("cls");
	}
    }
	}//fin de boucle ctrlancepartie
    if(mdj==50)//deux joueurs
    {
    	zz=0;
    	Beep(900,100);
    	boucle_menu=0;
	system("cls");
	printf("mode multijoueur\n");
	char joueur1[30];
	char joueur2[30];
	printf("entrez nom du joueur1\n");
    scanf("%s",joueur1);
    Beep(900,100);
    printf("entrez nom du joueur2\n");
    scanf("%s",joueur2);
    system("cls");
	choix=jeux();
    for(zz=0;zz<3;zz++)
    {
    	int ky;
    	int kk;
    	if(choix==49)
    {
    	Beep(900,100);
    	system("cls");
    	n=4;
    	diff=6561;
	}
	else if(choix==50)
	{
		system("cls");
		diff=paramettre();
        n=taille();
		printf("appuyez sur r deux fois pour valider puis lancer la partie et sur deux fois sur une autre touche pour retour\n");
		kk=getch();
		ky=getch();
		switch(ky)
		{
			case 's': zz=0;
			case 'r': zz=3;
		}
	}
	else if(choix==51)
	{
		Beep(900,100);
		system("cls");
		fiche=fopen("scoremj.txt","r");
		do
           {
           carac = fgetc(fiche);
          printf("%c", carac);
           } while (carac != EOF);
        fclose(fiche);
        printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			zz=0;
			choix=jeux();
		}
	}
	else if(choix==52)
	{
		Beep(900,100);
		system("cls");
		aide();
		printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			zz=0;
			choix=jeux();
		}
	}
	else
	{
		Beep(900,100);
		zz=4;
	}
	}
	srand(time(NULL));
    int tmj[n][n];
    int tab[n][n];
    init(n,tmj);
    init(n,tab);
    int w=0;
    x=0;
    int prmj=0;
    int cs=0;
    int cs1=0;
    int ctrlancepartiemj=0;
    int ctrarretmj=0;
    pret=lancerpartie();
    for(ctrlancepartiemj=0;ctrlancepartiemj<2;ctrlancepartiemj++)
    {
	if(pret==49)
	{
		rd(n,tmj);
    rd (n,tab);
    affmj(n,tmj,tab,1);
    for(prmj=0;prmj<2;prmj++)
    {
    	if(ctrarretmj==0)
     	{
     		x=gagne(n,tmj,diff);
     		w=gagne(n,tab,diff);
		}
		else
		{
			x=ctrarretmj;
			w=ctrarretmj;
		}
    	prmj=cs+cs1;
    if(x+w==0)
    {
    	x=gagne(n,tmj,diff);
    	w=gagne(n,tab,diff);
    	if(x==0 && w==0)
	{
		color(12,0);
		printf("tour de %s: \n",joueur1);
        m=getch();
        k=getch();
        switch (k)
        {
        	case 75: system("cls");
			 a1=a1+left(n,tmj);
        	    break;
        	case 72: system("cls");
			 b1=b1+up(n,tmj);
        	    break;
        	case 77: system("cls");
			e1=e1+right(n,tmj);
        	    break;
        	case 80: system("cls");
			d1=d1+down(n,tmj);
        	    break;
        	case 's':
        	system("cls");
        	ctrarretmj=50;
        		x=3;
        	    w=3;
        		break;
		}
		vide=vcasevide(n,tmj);
		if(vide!=0)
		{
			rd(n,tmj);
		}
		else
		{
			successif=operationpossible(n,tmj);
				if(successif==0)
				{
					cs=1;
				}
		}
        printf("\n\n");
        affmj(n,tmj,tab,2);
        q1=a1+b1+e1+d1;
        printf("%s score: %d\t\t\t\t\t\t%s score: %d \n\n",joueur1,q1,joueur2,q);
        prmj=0;
	}
	else
	{
		if(x!=0)
		{
		printf("bravo %s ", joueur1);
	    }
		prmj=1;
	}
	if(x==0 && w==0)
	{
		color(3,0);
		printf("tour de %s:\n",joueur2);
        m=getch();
        k=getch();
        switch (k)
        {
        	case 75: system("cls");
			a=a+left(n,tab);
        	    break;
        	case 72: system("cls");
			b=b+up(n,tab);
        	    break;
        	case 77: system("cls");
			e=e+right(n,tab);
        	    break;
        	case 80: system("cls");
			d=d+down(n,tab);
        	    break;
        	case 's':
			system("cls");
			ctrarretmj=50;
        		x=3;
        		w=3;
        		break;
		}
		vide=vcasevide(n,tab);
		if(vide!=0)
		{
			rd(n,tab);
		}
		else
		{
			successif=operationpossible(n,tab);
				if(successif==0)
				{
					cs1=1;
				}
		}
		w=gagne(n,tab,diff);
        printf("\n\n");
        affmj(n,tmj,tab,1);
        q=a+e+b+d;
        printf("%s score: %d\t\t\t\t\t\t%s score: %d \n\n",joueur1,q1,joueur2,q);
        prmj=0;
    }
    }
    else
	{
		if(w!=0)
		{
		printf("bravo %s ",joueur2);
	    }
		prmj=1;
	}
}
    printf("\n votre match a ete enregistre\n");
	fiche=fopen("scoremj.txt","r+");
   if(fiche!= NULL)
   {
   	 carac=fgetc(fiche);
   	 while(carac != EOF)
   	 {
   	 	carac=fgetc(fiche);
	}
   	fprintf(fiche," %s(%d) contre %s(%d)  \n",joueur1,q1,joueur2,q);
   }
   fclose(fiche);
    ctrlancepartiemj=0;
   pret=lancerpartie();
   if(pret==49)
   {
   	ctrarretmj=0;
   }
	if(pret==50)
	{
		ctrlancepartiemj=3;
	}
    }
    }
	}
    if(mdj==51)//contre le temps
    {
    	ctrarrett=0;
    	xt=0;
    	prnonmjt;
    	boucle_menu=0;
    	float temps_de_jeu;
    	float tpsdebfinpartie=0;// temps debut find e partie
    	float tempsactu=0; // temps actuel renvoyé par le cpu
    	float difftemps=0;// temps ecoulé
    	float ecartemps=0;// ecart de temps entre fin d'une partie et la relance d'une nouvelle partie
    	float moment_rejouer_valider; // temps renvoyé par le cpu quand la touche rejouer est appuyé
    	system("cls");
    	temps_de_jeu=durer();// voir zone fonction - pour le choix de la durée de jeu
    	choix=jeux();
    	for(zz=0;zz<2;zz++)// toujours notre boucle de zz définie précédement
    	{
    	if(choix==49)
    {
    	system("cls");
    	n=4;
    	diff=6561;
	}
	else if(choix==50)
	{
		system("cls");
		diff=paramettre();
        n=taille();
        Beep(900,100);
		printf("appuyez sur une s deux fois pour retourner r deux fois pour valider\n");
		kk=getch();
		ky=getch();
		switch(ky)
		{
			case 's': zz=0;
			case 'r': zz=3;
		}
	}
	else if(choix==51)
	{
		Beep(900,100);
		system("cls");
		fiche=fopen("score course contre le temps.txt","r");
		do
           {
           carac = fgetc(fiche);
          printf("%c", carac);
           } while (carac != EOF);

        fclose(fiche);
        printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			Beep(900,100);
			system("cls");
			zz=0;
			choix=jeux();
		}
	}
	else if(choix==52)
	{
		system("cls");
		aide();
		printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			zz=0;
			choix=jeux();
		}
	}
	else
	{
			system("cls");
		printf("mauvaise manipulation\n");
		boucle_menu=0;
		zz=4;
	}
   }
    srand(time(NULL));
    int t[n][n];
    int rj=1;
    int w=0;
    int q;
    pret=lancerpartie();
    for (ctrlancepartie=0;ctrlancepartie<2;ctrlancepartie++)
    {
    if(pret==49)
    {
    	init(n,t);
    	rd(n,t);
    	aff(n,t);
    fich=fopen("meilleur score course contre le temps.txt", "r");
    fscanf(fich, "%d", &mscore);
    fclose(fich);
    boucle_temps=0;
    tpsdebfinpartie=clock();
    	for(boucle_temps=0;boucle_temps<2;boucle_temps++)
    	{
    		xt=gagne(n,t,diff);
    	    tempsactu=clock();
    	    if(xt==1)// ici xt a la valeur renvoyé par gagne()
    	    {
    	    	ctrlancepartie=5;
    	    	printf("bravo entrez votre nom\n");
	scanf("%s",nom);
    if (q>mscore)
    {
    	fich=fopen("meilleur score course contre le temps.txt","w");
    if (fich != NULL)
   {
   	   	fprintf(fich,"%d",q);
   }
   fclose(fich);
	}
   fiche=fopen("score course contre le temps.txt","r+");
   if(fiche!= NULL)
   {
   	 carac=fgetc(fiche);
   	 while(carac != EOF)
   	 {
   	 	carac=fgetc(fiche);
	}
   	fprintf(fiche," %s  %d\n",nom,q);
   }
   fclose(fiche);
   break;
			}
    if(difftemps<temps_de_jeu) // si temps ecoulé est inferieur au temps de jeu
    { boucle_temps=ctrarrett;
      for(prnonmjt=0;prnonmjt<2;prnonmjt++)
        {
     	if(ctrarrett==0)
     	{
     		xt=gagne(n,t,diff);
		}
		else
		{
			xt=ctrarrett;
		}
    if(xt==0)
	{
        k=getch();
        vide=vcasevide(n,t);
        switch (k)
        {
        	case 75: system("cls");
			a=a+left(n,t);
			if(vide!=0)
		{
			rd(n,t);
		}
        	    break;
        	case 72: system("cls");
			b=b+up(n,t);
			if(vide!=0)
		{
			rd(n,t);
		}
        	    break;
        	case 77: system("cls");
			e=e+right(n,t);
        	    break;
        	    if(vide!=0)
		{
			rd(n,t);
		}
        	case 80: system("cls");
			d=d+down(n,t);
			if(vide!=0)
		{
			rd(n,t);
		}
        	    break;
        	case 's':system("cls");
        	    prnonmjt=5;
        	    ctrarrett=50;
        	    boucle_menu=100;
        		xt=3;
        		break;
		}
		rj=1;
		if(vide!=0)
		{
			successif=operationpossible(n,t);

				if(successif==0)
				{
					xt=3;
					printf("perdu plus de mouvement possible\n");
					break;
			   }
		}
	}
	tempsactu=clock();
		difftemps=difftime(tempsactu,tpsdebfinpartie)+ecartemps;
        printf("\n\n");
        aff(n,t);
    q=a+b+e+d;
    printf("score:%d\n",q);
    printf("meilleur score : %d \n",mscore);
    printf("temps ecoule: %f minutes...\n temps de jeu: %f minutes\n temps restant %f minutes...\n",difftemps/60000,temps_de_jeu/60000,(temps_de_jeu-difftemps)/60000);

    prnonmj=0;
	}
	 if(difftemps<temps_de_jeu)
	{
		xt=0;
	}
	else
	{
		printf("perdu temps impartie fini\n");
		xt=3;
	}
	if(xt!=0 && xt!=1)
	{
		ctrlancepartie=5;
    	    	printf("bravo entrez votre nom\n");
	scanf("%s",nom);
    if (q>mscore)
    {
    	fich=fopen("meilleur score course contre le temps.txt","w");
    if (fich != NULL)
   {
   	   	fprintf(fich,"%d",q);
   }
   fclose(fich);
	}
   fiche=fopen("score course contre le temps.txt","r+");
   if(fiche!= NULL)
   {
   	 carac=fgetc(fiche);
   	 while(carac != EOF)
   	 {
   	 	carac=fgetc(fiche);
	}
   	fprintf(fiche," %s  %d\n",nom,q);
   }
   fclose(fiche);
   ctrlancepartie=0;
   tpsdebfinpartie=clock();
   break;
	}
	}
    }
	}
	//pret
    else
	{
		ctrlancepartie=3;
		system ("cls");
	}

	}
	}//mdj
	if(mdj==52)//obstacle
	{
		boucle_menu=0;
    	system("cls");
    	choix=jeux();
    for(zz=0;zz<3;zz++)//boucle paramettrage jeu
    {
    	if(choix==49)
    {
    	system("cls");
    	n=4;
    	diff=6561;
	}
	else if(choix==50)
	{
		system("cls");
		diff=paramettre();
        n=taille();
        Beep(900,100);
		printf("appuyez sur une s deux fois pour retourner r deux fois pour valider\n");
		kk=getch();
		ky=getch();
		switch(ky)
		{
			case 's': zz=0;
			case 'r': zz=3;
		}
	}
	else if(choix==51)
	{
		Beep(900,100);
		system("cls");
		fiche=fopen("scoreobstacle.txt","r");
		do
           {
           carac = fgetc(fiche);
          printf("%c", carac);
           } while (carac != EOF);

        fclose(fiche);
        printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			Beep(900,100);
			system("cls");
			zz=0;
			choix=jeux();
		}
	}
	else if(choix==52)
	{
		system("cls");
		aide();
		printf("ici un obstacle(4) sera present et fixe alors faites attention\n");
		printf("appuyez sur s deux fois pour retourner\n");
		ky=getch();
		kk=getch();
		if(ky='s')
		{
			zz=0;
			choix=jeux();
		}

	}
	else
	{
			system("cls");
		printf("mauvaise manipulation\n");
		boucle_menu=0;
		zz=4;
	}
	}
    srand(time(NULL));
    int t[n][n];
    if(choix==53)
	{
		system ("cls");
		printf("continuer partie\n");
	}
    ctrarret=0;
    x=0;
    prnonmj=0;
    int w=0;
    pret=lancerpartie();// fonction pour demander si on veut jouer ou retourner
    for(ctrlancepartie=ctr;ctrlancepartie<2;ctrlancepartie++)//boucle qui verifie une condition d'arret de la partie , elle varie suivant ctr
    {
    if(pret==49)
    {
    system("cls");
    init(n,t);
    printf("combien d'obstacle voulez vous?\n");
    int obstacle;
    int iob;//iob(i obstacle) pour faire apparaitre les obstacles
    scanf("%d",&obstacle);
    for(iob=0;iob<obstacle;iob++)
    {
    	rdob(n,t);
	}
    if(choix==53)// faire une sauvegrde (pas operationnel pour le  moment)
	{
		n=lecture_taille();
		init(n,t);
		printf("%d %d",n,diff);
		diff=lecture_diff();
		lire_sauvegarde(n,t);
	}
	else
	{
		rd(n,t);
	}
    aff(n,t);
    fich=fopen("testobstacle.txt", "r");
    fscanf(fich, "%d", &mscore);
    fclose(fich);
    for(prnonmj=0;prnonmj<2;prnonmj++)//boucle qui verifie une deuxieme condition d'arret de jeu suivant prnonmj;
     {
     	if(ctrarret==0)// condition d'arret de jeu qui varie ulterieurment selon que le joueur perd ou gagne
     	{
     		x=gagne(n,t,diff);
		}
		else
		{
			x=ctrarret;
		}
    if(x==0)// condition gagnÃ© ou perdu
	{
	    vide=vcasevide(n,t);
        k=getch();
        switch (k)
        {
        	case 75: system("cls");
			a=a+left_obstacle(n,t);
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 72: system("cls");
			b=b+up_obstacle(n,t);
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 77: system("cls");
			e=e+right_obstacle(n,t);
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 80: system("cls");
			d=d+down_obstacle(n,t);
			if(vide!=0)
		{
			rd(n,t);
			printf("\n\n");

		}
        	    break;
        	case 's':system("cls");
        	    ctrarret=50;
        		x=3;
        		q=0;
        		init(n,t);
        		break;
        	case 'e':
        		sauvegarde_enreg(n,t);
        		sauvegarde_taille(n);
        		sauvegarde_diff(diff);
		}

		aff(n,t);
		if(vide==0)
		{
			successif=operationpossible(n,t);

				if(successif==0)
				{
					ctrarret=4;
		     	}
		}

    q=a+b+e+d;
    printf("score:%d\n",q);
    printf("meilleur score : %d \n",mscore);
    prnonmj=0;
	}
	else// si le joueur perd
	{
		printf("bravo entrez votre nom\n");// zone enregistrement des score et noms en fin de partie
	scanf("%s",nom);
    if (a+b+e+d>mscore)
    {
    	fich=fopen("testobstacle.txt","w");
    if (fich != NULL)
   {
   	   	fprintf(fich,"%d",a+b+e+d);
   }
   fclose(fich);
	}
   fiche=fopen("scoreobstacle.txt","r+");
   if(fiche!= NULL)
   {
   	 carac=fgetc(fiche);
   	 while(carac != EOF)
   	 {
   	 	carac=fgetc(fiche);
	}
   	fprintf(fiche," %s  %d\n",nom,a+b+e+d);
   }
   fclose(fiche);
   q=0;
   a=0;
   b=0;
   e=0;
   d=0;
   ctrlancepartie=0;
   pret=lancerpartie();
   if(pret==49)
   {
   	ctrarret=0;
	boucle_menu=0;
   }
	if(pret==50)
	{
		ctrlancepartie=3;
	}
	}
	}// fin boucle prnonmj;
    }
    else
    {
    	ctrlancepartie=3;
    	system("cls");
	}
    }//fin de boucle ctrlancepartie
	}
	if(mdj==54)
	{
		boucle_menu=4;
	}
	else// renvoyer au menu si il y a mauvaise manipulation
	{
		system("cls");
		boucle_menu=0;
	}
	}
}
