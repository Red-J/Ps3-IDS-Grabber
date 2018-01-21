
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define BUFFER1 16
#define BUFFER2 16 
#define BUFFER3 6
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

main(){
	system("Title PS3 IDS GRABBER v1.0");
	
	unsigned char SIZE;
	int lecture = 0;
	int lecture2 = 0;
    FILE* fichier = NULL;
	
    int caracterereverse1 = fseek(fichier,0x200,SEEK_SET);
	int caracterereverse12 = fseek(fichier,0x201,SEEK_SET);
	int caracterereverse13 =fseek(fichier,0x202,SEEK_SET);

    FILE* idps = NULL;
	FILE* psid = NULL;
	FILE* mac = NULL;

	
    fichier=fopen("dump.bin", "rb");
  
char buffer1[BUFFER1];
char buffer2[BUFFER2];
char buffer3[BUFFER3];


int taille;
	
	
const char *hex_digits1 = "0";
const char *hex_digits2 = "9";
const char *hex_digits3 = "1";
const char *hex_digits4 = "4";//+0
const char *hex_digits5 = "0";//+1
const char *hex_digits6 = "CF";
const char *hex_digits7 = "6A";
const char *hex_digits8 = "08";//OK
const char *hex_digits9 = "8A";
const char *hex_digits10 = "19";
const char *hex_digits11 = "03";
const char *hex_digits12 = "8A";
const char *hex_digits13 = "08";
const char *hex_digits14 = "4A";
const char *hex_digits15 = "7C";
const char *hex_digits16 = "47";
const char *hex_digits17 = "5D";//ok
const char *hex_digits18 = "0F";//ok
	 
	 unsigned char i;
	 unsigned char i2;
	 unsigned char i3;
	 unsigned char i4;
	 unsigned char i5;
	 unsigned char i6;
	 unsigned char i7;
	 unsigned char i8;
	 unsigned char i9;
	 unsigned char i10;
	 unsigned char i11;
	 unsigned char i12;
	 unsigned char i13;
	 unsigned char i14;
	 unsigned char i15;
	 unsigned char i16;
	 unsigned char i17;
	 unsigned char i18;

unsigned char ar[SIZE];
unsigned char br[SIZE];
unsigned char cr[SIZE];
unsigned char dr[SIZE];
unsigned char er[SIZE];
unsigned char fr[SIZE];
unsigned char gr[SIZE];
unsigned char hr[SIZE];
unsigned char ir[SIZE];
unsigned char jr[SIZE];
unsigned char kr[SIZE];
unsigned char lr[SIZE];
unsigned char mr[SIZE];
unsigned char nr[SIZE];
unsigned char or[SIZE];
unsigned char pr[SIZE];
unsigned char qr[SIZE];
unsigned char rr[SIZE];

int option;
FILE* log = NULL;
log = fopen("idpslist.txt", "a");

SYSTEMTIME Time; 
  
GetLocalTime(&Time); 

   while (option != 11)
    {system("mode con lines=25 cols=72");
color(10, 0);
printf("\n");		
printf("   -=========================================================-\n");	
printf("		.__________ __________  ________\n");
printf("		!   \\______\\\\______   \\/   _____/ \n");
printf("		!   !!    ! \\!     ___/\\_____  / \n");
printf("        	!   !!    `  \\    !    /       \\ \n");
printf("		!___!/_______/____!   /_______ /  By Red-J\n");




printf("   -=========================================================-\n");
printf("\n");
color(15, 0);
      printf("\n");
            printf("           	PS3 IDS GRABBER v1.0   \n ");
      printf("               ---------    \n");
	   printf("		1. Verifier la compatibilite du dump\n");
      printf("		2. Dumper IDPS\n");
      printf("		3. Dumper PSID\n");
      printf("		4. Dumper MAC adress \n\n");
	  printf("	   Instructions: mettre dump.bin dans le dossier\n\n ");
	   printf("		5. Generer des IDPS (BETA) \n");
      
color(10, 0);
	  printf("=================================================================\n");
color(15, 0); 
 printf("		Choississez votre option:");
      scanf("%d",&option);

	    if (option == 1)
       {
          if(fichier!=NULL)
		{ 
	
	/////
	

        // Boucle de lecture des caractères un à un
fseek(fichier,0x200,SEEK_SET);

        do

        {
         
            caracterereverse1 = fgetc(fichier); // On lit le caractère
			caracterereverse12 = fgetc(fichier);
			caracterereverse13 = fgetc(fichier);
			
			 //printf("%c", caractereActuel); // on affiche sur ces trois ligne IFI ou FII 
			//printf("%c", caractereActuel2);
			//printf("%c\n\n", caractereActuel3);
        } while (caracterereverse1 == 0x204);
		
if (caracterereverse1 == caracterereverse13) // Si chaînes identiques

    {

        printf("\n		Dump normal\n");
		  printf("		Vous pouvez continuer \n");
   printf("		Choississez votre option:");
 scanf("%d",&option);
    }

	else

    {

        printf("\n		Dump Reverse!! \n\n");
		 printf("	Attention:Vous devez reverser votre dump avant de continuer \n\n");
		 printf("	Vous pouvez utiliser flowrebuilder pour reverser le dump\n \n");
   printf("		Choississez votre option:");
 scanf("%d",&option);
    }
}
	
	}
	  
      if (option == 2)
       {
          if(fichier!=NULL)
		{ 

	      fseek(fichier,0,SEEK_SET);
		  idps=fopen("idps.BIN", "wb");
          fseek(fichier,0x2f070,SEEK_SET);
          lecture = fread(buffer1, sizeof(char), BUFFER1, fichier);
 
          while(fseek(fichier,0x2f070,SEEK_SET) == 0x2f07f)
          {   
          fwrite(buffer1, sizeof(char), BUFFER1, idps);
          lecture = fread(buffer1, sizeof(char), BUFFER1, fichier);
          }
    fwrite(buffer1, sizeof(char), lecture, idps);
       
    
    fclose(idps);
	printf("\n		Copie de l'idps OK\n\n ");
    printf("		Choississez votre option:");
 scanf("%d",&option);
         }
              
		else
	   {	
   printf("		Ouverture du Dump impossible\n");
   printf("\n");
   printf("		Choississez votre option:");
 scanf("%d",&option);
       }
	    }
		
 if (option == 3)
       {
          if(fichier!=NULL)
		{ 

	      fseek(fichier,0,SEEK_SET);
		  psid=fopen("psid.bin", "wb");
          fseek(fichier,0x2f080,SEEK_SET);
          lecture = fread(buffer2, sizeof(char), BUFFER2, fichier);
 
          while(fseek(fichier,0x2f080,SEEK_SET) == 0x2f090)
          {   
          fwrite(buffer2, sizeof(char), BUFFER2, psid);
          lecture = fread(buffer2, sizeof(char), BUFFER2, fichier);
          }
    fwrite(buffer2, sizeof(char), lecture, psid);
       
    
    fclose(psid);
	printf("\n		Copie du psid OK\n\n ");
    printf("		Choississez votre option:");
 scanf("%d",&option);
         }
              
		else
	   {	
   printf("		Ouverture du Dump impossible\n");
   printf("\n");
   printf("		Choississez votre option:");
 scanf("%d",&option);
       }
	    }

if (option == 4)
       {
          if(fichier!=NULL)
		{ 

	      fseek(fichier,0,SEEK_SET);
		  mac=fopen("mac.BIN", "wb");
          fseek(fichier,0x3f040,SEEK_SET);
          lecture = fread(buffer3, sizeof(char), BUFFER3, fichier);
 
          while(fseek(fichier,0x3f040,SEEK_SET) == 0x3f045)
          {   
          fwrite(buffer3, sizeof(char), BUFFER3, psid);
          lecture = fread(buffer3, sizeof(char), BUFFER3, fichier);
          }
    fwrite(buffer3, sizeof(char), lecture, psid);
       
    
    fclose(mac);
	printf("\n		Copie de l'adresse Mac OK\n\n ");
    printf("		Choississez votre option:");
 scanf("%d",&option);
         }
              
		else
	   {	
   printf("		Ouverture du Dump impossible\n");
   printf("\n");
   printf("		Choississez votre option:");
 scanf("%d",&option);
       }
	    }
		
      if (option == 5)
       { 
   printf("\n		Cette option est un Proof of Concept");
   printf("\n		Ne vous attendez pas a un miracle");
   printf("\n	Choisir le nombre d'IDPS voulu (de 1 a 50) :");
      scanf("%d",&SIZE);
	  if (SIZE<=50)
		  {
   

									
								
										
	fprintf(log,"----------------------ATTENTION LA PROBABILITE DE VALIDITE EST FAIBLE ----------------------\n %02d/%02d/%04d %02d:%02d\n\n",Time.wDay, Time.wMonth, Time.wYear,Time.wHour,Time.wMinute);								

    srand((unsigned)time(NULL));
    for(i=0;i<SIZE;i++)
    {

      ar[i] =  hex_digits1[ ( rand() % 1 ) ];// ok 	
	  br[i2] = hex_digits2[ ( rand() % 1) ];//		
	  cr[i3] = hex_digits3[ ( rand() % 1 ) ];//		
	  dr[i4] = hex_digits4[ ( rand() % 1 ) ];//		
	  er[i5] = hex_digits5[ ( rand() % 1) ];//ok
	  fr[i6] = hex_digits6[ ( rand() % 2 ) ];
	  gr[i7] = hex_digits7[ ( rand() % 2 ) ];//4
	  hr[i8] = hex_digits8[ ( rand() % 2) ];
	  ir[i9] = hex_digits9[ ( rand() % 2) ];
	  jr[i10] =hex_digits10[ ( rand() % 2 ) ];
	  kr[i11] = hex_digits11[ ( rand() % 2 ) ];
	  lr[i12] = hex_digits12[ ( rand() % 2 ) ];
	  mr[i13] = hex_digits13[ ( rand() % 2 ) ];
	  nr[i14] = hex_digits14[ ( rand() % 2 ) ];
	  or[i15] = hex_digits15[ ( rand() % 2 ) ];
	  pr[i16] = hex_digits16[ ( rand() % 2 ) ];
	  qr[i17] = hex_digits17[ ( rand() % 2 ) ];//ok
	  rr[i18] = hex_digits18[ ( rand() % 2 ) ];//ok
	  

	  printf("IDPS:%d\n",i+1);
      printf("        00 00 00 01 00 85 00 %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c \n",ar[i],br[i2],cr[i3],dr[i4],er[i5],fr[i6],gr[i7],hr[i8],ir[i9],jr[i10],kr[i11],lr[i12],mr[i13],nr[i14],or[i15],pr[i16],qr[i17],rr[i18]);
printf("\n");

fprintf(log,"00000001008500%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",ar[i],br[i2],cr[i3],dr[i4],er[i5],fr[i6],gr[i7],hr[i8],ir[i9],jr[i10],kr[i11],lr[i12],mr[i13],nr[i14],or[i15],pr[i16],qr[i17],rr[i18]);

	  //system("pause");
	  	
    }	fprintf(log,"\n--------------------------------------------------------------------------------------------\n\n");
	fclose(log);
	system("start idpslist.txt");
	system("pause");
	return 0;} 
	else
	{ printf("	Operation impossible, nombre superieur a 50 !!!\n");
	system("pause");}
	
	}
	 


}}