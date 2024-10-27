void color(int t,int f)// changer les couleur arriere plan
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}
void displayColor(int f,int c)// changer les couleur arriere plan des cases du tableau
    {
		color(c,f);
	}
void init(int n, int t[n][n]) // initialiser un tableau de taille n à 0
{
	 int i,j;
	 for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             t[i][j]=0;
         }
     }
}
void setColor(int valeur) // combine avec la fonction display colorchange la couleur des cases tableau selon les chiffres
{
	       if (valeur==3)
			color(15,1);
			if(valeur==9)
			color(15,2);
			if(valeur==27)
			color(15,11);
			if(valeur==81)
			color(15,12);
			if(valeur==243)
			color(15,5);
			if(valeur==729)
			color(15,6);
			if(valeur==2197)
			color(15,13);
			if(valeur==6561)
			color(15,8);
			if(valeur==19683)
			color(15,3);
			if(valeur==99049)
			color(15,10);
			if(valeur==177147)
			color(15,11);
			if(valeur==4)
			color(4,4);
			if(valeur==0)
			color(15,0);
}
void aff(int n, int t[n][n]) // afficher le tableau en mode un joueur
{

	system("cls");
	color(15,0);
	printf("jeux en cours\n");
	printf("taper s pour quitter la partie\n taper e pour sauvegarder la partie(uniquement en mode 1 joueur)");
    int i, j;
    printf("\n\n\n");
    for(i=0;i<n;i++)
	{
		printf("\t\t\t|");
		for(j=0;j<n;j++)
		{
			setColor(t[i][j]);
			printf("%8d",t[i][j]);
			color(15,0);
		}
		printf("|\n");
	}
}
void affmj(int n, int t[n][n], int a[n][n], int numJoueur) // afficher le tableau en mode multi joueur
{
	system("cls");
	color(15,0);
	printf("jeux en cours\ntapez s pour quitter la partie\n");
    int i, j,b;
    printf("\n\n\n");
    for(i=0;i<n;i++)
	{

		for(j=0;j<n;j++)
		{
			if(numJoueur==1)
			setColor(t[i][j]);
			printf("%8d",t[i][j]);
			color(15,0);
		}
		printf("|");
		printf("\t\t");
		for(b=0;b<n;b++)
		{
			if(numJoueur==2)
				setColor(a[i][b]);

			printf("%8d",a[i][b]);
			color(15,0);
		}
		printf("|");
		printf("\n");
	}
}
void rd( int n, int t[n][n])
{
    int a,b;
    a= rand() % (n);
    b= rand() % (n);
    if(t[a][b]==0)
    {
        t[a][b]=3;
    }
    else
    {
        while(t[a][b]!=0)
    {
        a= rand() % (n);
       b= rand() % (n);
    }
    t[a][b]=3;
    }

}
void rdob( int n, int t[n][n])
{
    int a,b;
    a= rand() % (n);
    b= rand() % (n);
    if(t[a][b]==0)
    {
        t[a][b]=4;
    }
    else
    {
        while(t[a][b]!=0)
    {
        a= rand() % (n);
       b= rand() % (n);
    }
    t[a][b]=4;
    }

}
void gauche(int n, int t[n][n])  // depalacer touts les cases du tableau à gauche
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		for(k=j+1;k<n;k++)
    		{
    			if(t[i][j]==0 && t[i][k]!=0)
    		      {
    				t[i][j]=t[i][k];
    				t[i][k]=0;
			}
		 }
      }
    }
}
void sdlgauche(int n, int t[n][n],SDL_Rect rect[n][n];)  // depalacer touts les cases du tableau à gauche
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		for(k=j+1;k<n;k++)
    		{
    			if(t[i][j]==0 && t[i][k]!=0)
    		      {
    				t[i][j]=t[i][k];
    				t[i][k]=0;
                        rect[i][j].x==rect[i][k].x
			}
		 }
      }
    }
}
void gauche_obstacle(int n, int t[n][n])  // depalacer touts les cases du tableau à gauche mode obstacle
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		for(k=j+1;k<n;k++)
    		{
    			if(t[i][j]==0 && t[i][k]!=0)
    		{
    				if(t[i][k]!=4)
    				{
    					t[i][j]=t[i][k];
    				    t[i][k]=0;
					}
					else
					{
						t[i][j]=t[i][j];
						j++;
						k++;
					}
			}
		    }
		}
	}
}
void droite(int n , int t[n][n])  // depalacer touts les cases du tableau à droite
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
				for(k=j-1;k>=0;k--)
				{
					if(t[i][j]==0 && t[i][k]!=0)
			       {
						t[i][j]=t[i][k];
						t[i][k]=0;
				   }
				}
		}
	}
}
void droite_obstacle(int n , int t[n][n]) // depalacer touts les cases du tableau à gauche mode obstacle
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
				for(k=j-1;k>=0;k--)
				{
					if(t[i][j]==0 && t[i][k]!=0)
			       {
						if(t[i][k]!=4)
						{
							t[i][j]=t[i][k];
						    t[i][k]=0;
						}
						else
						{
							t[i][j]=t[i][j];
							k--;
							j--;
						}
				   }
				}
		}
	}
}
void haut(int n, int t[n][n]) // depalacer touts les cases du tableau en haut
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			for(k=i+1;k<n;k++)
			{
				if(t[i][j]==0 && t[k][j]!=0)
				{
					t[i][j]=t[k][j];
					t[k][j]=0;
				}
			}
		}
	}
}
void haut_obstacle(int n, int t[n][n])  // depalacer touts les cases du tableau en haut mode obstacle
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			for(k=i+1;k<n;k++)
			{
				if(t[i][j]==0 && t[k][j]!=0)
				{
					if(t[k][j]!=4)
					{
					t[i][j]=t[k][j];
					t[k][j]=0;
				    }
				    else
				    {
				    	t[i][j]=t[i][j];
				    	k++;
				    	i++;
					}
				}
			}
		}
	}
}
void bas(int n, int t[n][n])  // depalacer touts les cases du tableau en bas
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		for(i=n-1;i>=0;i--)
		{
			for(k=i-1;k>=0;k--)
			{
				if(t[i][j]==0 && t[k][j]!=0)
				{
					t[i][j]=t[k][j];
					t[k][j]=0;
				}
			}
		}
	}
}
void sdlbas(int n, int t[n][n],SDL_Rect rect[n][n];)  // depalacer touts les cases du tableau en bas
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		for(i=n-1;i>=0;i--)
		{
			for(k=i-1;k>=0;k--)
			{
				if(t[i][j]==0 && t[k][j]!=0)
				{
					t[i][j]=t[k][j];
					t[k][j]=0;
                              rect[i][j].y==rect[k][j];

				}
			}
		}
	}
}
void bas_obstacle(int n, int t[n][n])// depalacer touts les cases du tableau en bas mode obstacle
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		for(i=n-1;i>=0;i--)
		{
			for(k=i-1;k>=0;k--)
			{
					if(t[i][j]==0 && t[k][j]!=0)
				{
					if(t[k][j]!=4)
					{
						t[i][j]=t[k][j];
					t[k][j]=0;
					}
					else
					{
						t[i][j]=t[i][j];
						k--;
						i--;
					}
				}
			}
		}
	}
}
int sg(int n, int t[n][n]) // faire le produit par trois des cases suivant les regles du jeu tableau en bas  pour la gauche
{
	int i, j,k;
	int c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			k=j+1;
			if(t[i][k]!=4)
			{
				if(t[i][j]==t[i][k])
			{
				t[i][j]=t[i][j]*3;
				t[i][k]=0;
				c=c+t[i][j];
			}
			}
		}
	}
	return c;// renvoie l'ensenbles des sommes effectuée qui servira au score
}

int sd(int n, int t[n][n])  // faire le produit par trois des cases suivant les regles du jeu tableau en bas  pour la droite
{
	int i, j,k;
	int c=0;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			k=j-1;
			if(t[i][k]!=4)
			{
			if(t[i][j]==t[i][k])
			{
				t[i][j]=t[i][j]*3;
				t[i][k]=0;
				c=c+t[i][j];
			}
		    }
		}
	}
	return c;// renvoie l'ensenbles des sommes effectuée qui servira au score
}
int sh(int n, int t[n][n])  // faire le produit par trois des cases suivant les regles du jeu tableau en bas  pour le haut
{
	int i, j,k;
	int c=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			k=i+1;
			if(t[k][j]!=4)
			{
			if(t[i][j]==t[k][j])
			{
				t[i][j]=t[i][j]*3;
				t[k][j]=0;
				c=c+t[i][j];
			}
		    }
		}
	}
	return c;// renvoie l'ensenbles des sommes effectuée qui servira au score
}
int sb(int n, int t[n][n])  // faire le produit par trois des cases suivant les regles du jeu tableau en bas  pour le bas
{
	int i, j,k;
	int c=0;
	for(j=0;j<n;j++)
	{
		for(i=n-1;i>=0;i--)
		{
			k=i-1;
			if(t[k][j]!=4)
			{
			if(t[i][j]==t[k][j])
			{
				t[i][j]=t[i][j]*3;
				t[k][j]=0;
				c=c+t[i][j];
			}
		    }
		}
	}
	return c;// renvoie l'ensenbles des sommes effectuée qui servira au score
}
int left(int n,int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	gauche(n,t);
	c=sg(n,t);
	gauche(n,t);
	return c;
}
int left_obstacle(int n,int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	gauche_obstacle(n,t);
	c=sg(n,t);
	gauche_obstacle(n,t);
	return c;
}
int right(int n, int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	droite(n,t);
	c=sd(n,t);
	droite(n,t);
	return c;
}
int right_obstacle(int n, int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	droite_obstacle(n,t);
	c=sd(n,t);
	droite_obstacle(n,t);
	return c;
}
int up(int n, int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	haut(n,t);
	c=sh(n,t);
	haut(n,t);
	return c;
}
int up_obstacle(int n, int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	haut_obstacle(n,t);
	c=sh(n,t);
	haut_obstacle(n,t);
	return c;
}
int down(int n, int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	bas(n,t);
	c=sb(n,t);
	bas(n,t);
	return c;
}
int down_obstacle(int n, int t[n][n])// fait le deplacement des cases , fait la somme , renvoie le score pour ce deplacement, puis refait le deplacement
{
	int c;
	bas_obstacle(n,t);
	c=sb(n,t);
	bas_obstacle(n,t);
	return c;
}
int gagne(int n, int t[n][n],int c)// vrifie si une case contient l'objectif à atteindre et renvoie la valeur 1 si oui ,0 si non
{
    int i ,j,k ;
    k=0;
    for (i=0;i<n; i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[i][j]>=c)
            {
                printf("gagne");
                k=1;
                j=100;
                i=100;
            }
        }
    }
    return k;
}
int paramettre() // pour choisir et personnaliser la diffculé du jeux
{
	Beep(900,100);
	int c,a;
	printf(" \n1 facile(objectif:2187)\n2--moyen(objectif:6561)\n3--personnaliser\n");
	c=getch();
	 if(c==49)
	{
		Beep(900,100);
		a=2187;
	}
	if (c==50)
	{
		Beep(900,100);
		a=6561;
	}
	if(c==51)
	{
		Beep(900,100);
		system("cls");
		printf("entrez le nombre a atteindre \n");
		scanf("%d",&a);
	}
	return a;
}
int taille() // demande la taille du tableau et la renvoie comme valeur , cette valeur sera affecte à une variable plus tard
{
    system("cls");
	printf("taille du tableau de jeux\n");
	int t;
	scanf("%d",&t);
	return t;
}
void presentation()// pour la presentation du jeux
{

	printf("\t\t\tBonjour et Bienvenue\n\t\t******cree par: Daniel****** \n\ntaper deux fois s pour sortir d'une partie en cours\n\n");
	printf("choisissez votre mode de jeux\n\n");
}
int modejeux() // choisir le mode jeux
{
	Beep(900,100);
	printf("menu principal\n1-jouer seul\n2- multijoueur\n3-course contre la montre\n4-mode obstacle\n5-changer la couleur du texte\n6-quitter\n");
	int k;
	k=getch();
	return k;
}
int jeux() // menu du jeux
{
	system("cls");
	Beep(900,100);
	int c;
	printf("\n1-nouvelle partie (par defaut, le plateau de jeux est de taille 4 , l'objectif est 6561) \n2-paramettre (choisissez la difficulte du jeux)\n3-tableau de score\n4-aide\n5-continuer partie sauvegardée(diponible uniquement en mode 1 joueur\n)");
	c=getch();
	return c;
}
int lancerpartie()
{
	Beep(900,100);
	printf("1-continuer\n(si vous etes en pleine partie) recommencer ?\n2-retour\n");
	int k;
	k=getch();
	return k;
}
float durer()//choisir la durée de jeux
{
	Beep(900,100);
	printf("choisissez la difficulte\n1- 3 minutes de jeux\n2- 5minutes de jeux\n\n");
	int k;
	k=getch();
	float a;
	switch(k)
	{
		case 49: return 180000;
		case 50: return 600000;
		case 51: return 30000;
	}
}
void sauvegarde_enreg(int n, int t[n][n]) // pour sauvegarder le plateau de la parties en cours
{
int i ,j ;
	FILE*ff=NULL;
	ff=fopen("sauvegarde.txt","w");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(ff,"%d ",t[i][j]);
		}
	}
	fclose(ff);
}
void sauvegarde_taille(int n) // pour sauvegarder la taille
{
	FILE*a=NULL;
	a=fopen("taille.txt","w");
	fprintf(a,"%d",n);
	fclose(a);
}
void sauvegarde_diff(int n)// pour sauvegarder la diffcultée
{
	FILE*a=NULL;
	a=fopen("diff.txt","w");
	fprintf(a,"%d",n);
	fclose(a);
}
int lecture_diff() // pour lire la sauvegarde
{
	int n;
	FILE*a=NULL;
	a=fopen("diff.txt","r");
	fscanf(a,"%d",&n);
	fclose(a);
	return n;
}
int lecture_taille() // pour lire la sauvegarde
{
	int n;
	FILE*a=NULL;
	a=fopen("taille.txt","r");
	fscanf(a,"%d",&n);
	fclose(a);
	return n;
}
void lire_sauvegarde(int n,int t[n][n]) // pour lire la sauvegarde
{
	int i ,j ;
	FILE *fff=NULL;
	fff=fopen("sauvegarde.txt","r");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fff,"%d",&t[i][j]);
		}
	}
	fclose(fff);
}
void lire_simula(int n,int t[n][n]) // pour lire la sauvegarde
{
	int i ,j ;
	FILE *fa=NULL;
	fa=fopen("simulationgagne.txt","r");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fa,"%d",&t[i][j]);
		}
	}
	fclose(fa);
}
void lire_simul3(int n,int t[n][n]) // pour lire la sauvegarde
{
	int i ,j ;
	FILE *fff=NULL;
	fff=fopen("simulationperdu.txt","r");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fff,"%d",&t[i][j]);
		}
	}
	fclose(fff);
}
void lire_simul4(int n,int t[n][n]) // pour lire la sauvegarde
{
	int i ,j ;
	FILE *fff=NULL;
	fff=fopen("simulationreste2case.txt","r");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fff,"%d",&t[i][j]);
		}
	}
	fclose(fff);
}
void aide()
{
	Beep(900,100);
	printf("1-la grille de jeux est constitue de cases vides et de cases contenant des nombres\nau debut de chaque tours, un 3 apparait dans une case\n");
	printf("2-le joueur peut utiliser les touches directionnelles pour deplacer toute les cases de la grille dans la direction choisie\nsi deux cases successive contiennent des valeurs identique\nelles se combinent pour donner le produit par 3 de cette valeur\n");
	printf("3-le joueur gagne si il reussi a creer une case cantenant le nombre 6561\n le joueur perd si il n' a plus de mouvement valide\n");
}
int vcasevide(int n ,int t[n][n]) // verifie si il y a une case vide sur le plateau s'il y en a pas ellerenvoie
{
	int i,j,k;
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(t[i][j]==0)
			{
				k++;
			}
		}
	}
	return k;
}
int consecutifligne(int n, int t[n][n])// verifie si il y a decse identique successive sur le plateau renvoie  si non
{
	int i,j;
	int k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(t[i][j]==t[i][j+1])
			{
				k++;
			}
		}
	}
	return k;
}
int consecutifcolonne(int n, int t[n][n])// verifie si il y a des cases identiques successives sur le plateau et renvoie 0 si non
{
	int i,j;
	int k=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(t[i][j]==t[i+1][j])
			{
				k++;
			}
		}
	}
	return k;
}
int operationpossible(int n, int t[n][n]) // verifie si il y a  un mouvement possible si non elle renvoie 0
{
	int a,b;
	a=consecutifligne(n,t);
	b=consecutifcolonne(n,t);
	return a+b;
}
