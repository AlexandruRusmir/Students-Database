#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void antet(); ///Optiunile de operatii asupra listei de studenti
void meniu(int); ///Meniul de unde se alege operatia dorita asupra listei de studenti
void adaugare(); ///Adaugarea unui student nou in lista
void afisare(); ///Afisarea tuturor studentilor din lista la momentul respectiv
void afisare_student(); ///Afisarea unui anumit student din lista
void actualizare(); ///Modificarea datelor despre un anumit student
void stergere(); ///Stergerea tuturor datelor despre un anumit student
void restantieri(); ///Afisarea tuturor studentilor restantieri
void citire_fisier(char string[]); ///Citirea din fisierea pentru a vedea daca au ramas date de la apelari trecute ale programului
void scriere_fisier(char string[]); ///Scrierea tuturor studentilor in fisier

int nr_studenti=0; ///Numarul total de studenti aflati la un moment dat
struct studenti ///Structura pentru a memora organizat toti studentii
{
    char Nume[30]; ///Nume si eventual prenumele studentului
    char specializare[30]; ///Specializarea studentului
    char nr_matricol[30]; ///Numarul matricol al studentului(unic, cel mai important de aici)
    char varsta[5]; ///Varsta in ani
    char medie[5]; ///Media din semestrul trecut
}student[1000];

int main()
{
    int a;
    citire_fisier("date.txt");

    do
    {
        antet();
        printf("Selectati cifra operatiei dorite(1-6) sau orice alta cifra pentru a opri aplicatia: \n");
        scanf("%d", &a);
        meniu(a);
    }
    while (a>=1 && a<=6);

    printf("\nAplicatia se inchide...");

    scriere_fisier("date.txt");
    return 0;
}

void antet()
{
    system("cls");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("1. Afisarea tuturor studentilor\n2. Afisare unui anumit student\n3. Adaugarea unui student\n4. Actualizarea unui student\n5. Stergerea unui student\n6. Afisarea studentilor restantieri\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void meniu(int a)
{
    if (a==1)
        afisare();

    else if (a==2)
        afisare_student();

    else if (a==3)
        adaugare();

    else if (a==4)
        actualizare();

    else if (a==5)
        stergere();

    else if (a==6)
        restantieri();

}

void adaugare()
{
    char Nume[30];
    char specializare[30];
    char nr_matricol[30];
    char varsta[5];
    char medie[5];
    int  sw=0, i;

    printf("Introduceti datele studentului ce va fi adaugat(sau 0 la nume in cazul in care doriti sa va intoarceti)\n");
    printf("\tNume Prenume: ");
    fflush(stdin);
    printf("\t");
    fgets(Nume, sizeof(Nume), stdin);
    Nume[strlen(Nume)-1]=NULL;
    if(strcmp(Nume, "0")==0)
    {
        printf("\tSe revine la meniu!\n");
        return;
    }

    printf("\tSpecializare: ");
    fflush(stdin);
    printf("\t");
    fgets(specializare, sizeof(specializare), stdin);
    specializare[strlen(specializare)-1]=NULL;

    printf("\tNumar matricol: ");
    fflush(stdin);
    fgets(nr_matricol, sizeof(nr_matricol), stdin);
    nr_matricol[strlen(nr_matricol)-1]=NULL;
    for(i=0; i<nr_studenti; i++)
        if(strcmp(nr_matricol, student[i].nr_matricol) == 0)
            {
                printf("Un student cu acest numar matricol este deja inregistrat!");
                sw = 1;
            }

    if(!sw)
    {
        printf("\tVarsta: ");
        fflush(stdin);
        printf("\t");
        fgets(varsta, sizeof(varsta), stdin);
        varsta[strlen(varsta)-1]=NULL;

        printf("\tMedia: ");
        fflush(stdin);
        printf("\t\t");
        fgets(medie, sizeof(medie), stdin);
        medie[strlen(medie)-1]=NULL;

        strcpy(student[nr_studenti].Nume, Nume);
        strcpy(student[nr_studenti].specializare, specializare);
        strcpy(student[nr_studenti].nr_matricol, nr_matricol);
        strcpy(student[nr_studenti].varsta, varsta);
        strcpy(student[nr_studenti].medie, medie);
        nr_studenti++;
    }

    printf("\nApasati tasta ENTER pentru a continua");
    fgets(Nume, sizeof(Nume), stdin);
    Nume[strlen(Nume)-1]=NULL;

    scriere_fisier("date.txt");
}

void afisare()
{
    printf("Afisarea tutor studentilor aflati in lista:\n");
    int i;
    for(i=0; i<nr_studenti; i++)
        printf("\tStudent numarul %d: \n\t\tNume Prenume:%s\n\t\tSpecializare:%s\n\t\tNumar matricol:%s\n\t\tVarsta:%s\n\t\tMedie:%s\n", i+1, student[i].Nume, student[i].specializare, student[i].nr_matricol, student[i].varsta, student[i].medie);

    printf("Lista tuturor studentilor a fost afisata!\n");

    char Nume[30];
    printf("\nApasati tasta ENTER pentru a continua");
    fgets(Nume, sizeof(Nume), stdin);
    Nume[strlen(Nume)-1]=NULL;
    fgets(Nume, sizeof(Nume), stdin);
    Nume[strlen(Nume)-1]=NULL;
}

void afisare_student()
{
    char nr_matricol[30];
    int i, sw=0;
    printf("Afisarea unui anumit student din lista\n");
    fflush(stdin);
    printf("\tIntroduceti numarul matricol exact al studentului: ");
    fgets(nr_matricol, sizeof(nr_matricol), stdin);
    nr_matricol[strlen(nr_matricol)-1]=NULL;
    printf("\n");

    for(i=0; i<nr_studenti; i++)
        if(strcmp(nr_matricol, student[i].nr_matricol) == 0)
            {
                printf("\tStudentul a fost gasit:\n\t\tNume Prenume:%s\n\t\tSpecializare:%s\n\t\tNumar matricol:%s\n\t\tVarsta:%s ani\n\t\tMedie:%s\n", student[i].Nume, student[i].specializare, student[i].nr_matricol, student[i].varsta, student[i].medie);
                sw = 1;
            }
    if(!sw)
        printf("\tStudentul nu a fost gasit!\n");

    printf("\nApasati tasta ENTER pentru a continua");
    fgets(nr_matricol, sizeof(nr_matricol), stdin);
    nr_matricol[strlen(nr_matricol)-1]=NULL;
}

void actualizare()
{
    char nr_matricol[30];
    int i, sw=0;
    printf("Actualizarea unui anumit student din lista\n");
    fflush(stdin);
    printf("\tIntroduceti numarul matricol exact al studentului: ");
    fgets(nr_matricol, sizeof(nr_matricol), stdin);
    nr_matricol[strlen(nr_matricol)-1]=NULL;

    printf("\n");

    for(i=0; i<nr_studenti; i++)
        if(strcmp(nr_matricol, student[i].nr_matricol) == 0)
            {
                char Nume[30];
                char specializare[30];
                char nr_matricol[30];
                char varsta[5];
                char medie[5];
                printf("\tIntroduceti noile date ale studentului(sau 0 la nume in cazul in care doriti sa va intoarceti)\n");
                printf("\t\tNume Prenume: ");
                fflush(stdin);
                printf("\t");
                fgets(Nume, sizeof(Nume), stdin);
                Nume[strlen(Nume)-1]=NULL;
                if(strcmp(Nume, "0")==0)
                {
                    printf("\t\tSe revine la meniu!\n");
                    return;
                }

                printf("\t\tSpecializare: ");
                fflush(stdin);
                printf("\t");
                fgets(specializare, sizeof(specializare), stdin);
                specializare[strlen(specializare)-1]=NULL;

                printf("\t\tNumar matricol: ");
                fflush(stdin);
                fgets(nr_matricol, sizeof(nr_matricol), stdin);
                nr_matricol[strlen(nr_matricol)-1]=NULL;

                printf("\t\tVarsta: ");
                fflush(stdin);
                fgets(varsta, sizeof(varsta), stdin);
                varsta[strlen(varsta)-1]=NULL;

                printf("\tMedia: ");
                fflush(stdin);
                printf("\t");
                fgets(medie, sizeof(medie), stdin);
                medie[strlen(medie)-1]=NULL;

                strcpy(student[i].Nume, Nume);
                strcpy(student[i].specializare, specializare);
                strcpy(student[i].nr_matricol, nr_matricol);
                strcpy(student[i].varsta, varsta);
                strcpy(student[nr_studenti].medie, medie);
                sw = 1;
            }
    if(!sw)
        printf("\tStudentul nu a fost gasit!\n");


    printf("\nApasati tasta ENTER pentru a continua");
    fgets(nr_matricol, sizeof(nr_matricol), stdin);
    nr_matricol[strlen(nr_matricol)-1]=NULL;
}

void stergere()
{
    char nr_matricol[30];
    int i, sw=0, j;
    printf("Stergerea unui anumit student din lista\n");
    fflush(stdin);
    printf("\tIntroduceti numarul matricol exact al studentului: ");
    fgets(nr_matricol, sizeof(nr_matricol), stdin);
    nr_matricol[strlen(nr_matricol)-1]=NULL;
    printf("\n");

    for(i=0; i<nr_studenti; i++)
        if(strcmp(nr_matricol, student[i].nr_matricol) == 0)
            {
                for(j=i; j<nr_studenti; j++)
                    student[j]=student[j+1];

                nr_studenti--;
                sw = 1;
                printf("Studentul a fost sters din lista!\n");
                break;
            }
    if(!sw)
        printf("\tStudentul nu a fost gasit!\n");

    printf("\nApasati tasta ENTER pentru a continua");
    fgets(nr_matricol, sizeof(nr_matricol), stdin);
    nr_matricol[strlen(nr_matricol)-1]=NULL;
}

void restantieri()
{
    int i;
    unsigned sw=0;
    for(i=0; i<nr_studenti; i++)
        if((int)(student[i].medie[0]-'0') < 5 && (student[i].medie[1]<'0' || student[i].medie[1]>'9'))
            {
                printf("\tStudentul:\n\t\tNume Prenume:%s\n\t\tSpecializare:%s\n\t\tNumar matricol:%s\n\t\tVarsta:%s ani\n\t\tMedie:%s\n\n", student[i].Nume, student[i].specializare, student[i].nr_matricol, student[i].varsta, student[i].medie);
                sw = 1;
            }
    if(!sw)
        printf("\tNu exista studenti restantieri!\n");

    char string;
    printf("\nApasati tasta ENTER pentru a continua");
    scanf("%c", &string);
    scanf("%c", &string);
}

void citire_fisier(char path[])
{
    FILE * f;
    if ((f = fopen(path,"r+")) == NULL)
    {
       printf("Eroare! Fisierul nu exista! Va rugam sa il creati");
       return;
    }

    f = fopen ("date.txt", "r");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, f);
    fclose(f);

    string[fsize] = 0;

    if(fsize > 1)
    {
        char A[5][30];
        int k=0;
        char * token = strtok(string, "/");
        while(token != NULL)
        {
            strcpy(A[k++], token);
            if(k == 5)
            {
                strcpy(student[nr_studenti].Nume, A[0]);
                strcpy(student[nr_studenti].specializare, A[1]);
                strcpy(student[nr_studenti].nr_matricol, A[2]);
                strcpy(student[nr_studenti].varsta, A[3]);
                strcpy(student[nr_studenti].medie, A[4]);
                nr_studenti++;
                k = 0;
            }
            token = strtok(NULL, "/");
        }
    }
}

void scriere_fisier(char path[])
{
    int i;
    FILE * file;
    if (file = fopen(path, "w"))
        for(i=0; i<nr_studenti; i++)
            fprintf(file, "%s/%s/%s/%s/%s/", student[i].Nume, student[i].specializare, student[i].nr_matricol, student[i].varsta, student[i].medie);

    else
        printf("Error!");

   fclose(file);
}
