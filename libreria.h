#include <iostream>
#include <cstring>
using namespace std;
struct v
{
	float voto;
	char materia[30];
};
struct alunno
{
	char nome[30];
	char cognome[30];
	char classe[6];
	struct v voti[10];
	int n_valutazioni;
};
int cerca(struct alunno x[], alunno a);
void carica_dati(struct alunno x[],int l);
void calcola_media(struct alunno x[], struct alunno a);
alunno cerca2(alunno x[],char nome[30],char cognome[30]);
void valuta(struct alunno x[],struct alunno a, float voto, char materia[30]);
void stampa(struct alunno x[],int l);
int cerca(struct alunno x[], alunno a)
{
	int flag=-1;
	int k=0;
	while ((x[k].nome[0])&&(flag==-1))
	{
		if (strcmp(a.nome,x[k].nome)==0)
			flag=k;
		k++;
	}
	return flag;}
void carica_dati(struct alunno x[],int l)
{
	int k;
	cout << "\n Procedura di inserimento dati\n";
	for (k=0;k<l;k++)
	{			cin.ignore(1,'\n');
				cout <<"\n---> Inserisci nome e cognome alunno\n";
				cin.getline(x[k].nome,20);
				cin.getline(x[k].cognome,20);
				cout << "\n-->Inserisci la classe\n";
				cin >> x[k].classe;
				cout << "\n";
				x[k].n_valutazioni=0;
	}
}
void calcola_media(struct alunno x[], struct alunno a)
{
	int pos=-1;
	int j=9;
	float media=0;
	float somma=0;
	pos=cerca(x,a);
	//cout << "\n Posizione k\n";
	if (pos==-1)
	{
		cout << "\n Alunno con i criteri di ricerca non trovato\n"	;
		return;
	}
	if (x[pos].n_valutazioni==0)
	cout << "\n L'alunno non ha valutazioni\n";
	else{
		for (j=0;j<x[pos].n_valutazioni;j++)
		somma=x[pos].voti[j].voto+somma;
	media=somma/x[pos].n_valutazioni;
	cout << "\nAlunno Cognome e Nome:--->"<<x[pos].cognome<<" ; "<<x[pos].nome;
	cout << "\nLa sua media è:"<< media<< endl;}
}
void valuta(struct alunno x[],struct alunno a, float voto, char materia[30])
{
	int pos=-1;
	pos=cerca(x,a);
	if (pos==-1)
	{
		cout << "\n Alunno con i criteri di ricerca non trovato\n"	;
	}
	else
		{
			x[pos].voti[x[pos].n_valutazioni].voto=voto;
			strcpy(x[pos].voti[x[pos].n_valutazioni].materia,materia);
			x[pos].n_valutazioni++;
			cout << "\n Valutazione Aggiunta con Successo\n";
		}
}
void stampa(struct alunno x[],int l)
{
	int k=0;
	int j=0;
	cout << "\n Stampa del Prospetto di tutti gli alunni\n";
	for (k=0;k<l;k++)
	{
		cout << "\nAlunno Cognome e Nome:--->"<<x[k].cognome<<" ; "<<x[k].nome;
		cout << "\n Classe:--->"<<x[k].classe<<endl;
		cout << "\nProspetto Valutazioni:\n";
		for (j=0;j<x[k].n_valutazioni;j++)
		{
			cout << "\nMateria:"<< x[k].voti[j].materia;
			cout << "\n Voto:"<< x[k].voti[j].voto;
			cout << endl;
		}
		j=0;
	}
	cout << "Fine Valutazioni:\n";
}
alunno cerca2(alunno x[],char nome[30],char cognome[30])
{
	int flag=0;
	alunno y;
	int k=0;;
	while ((flag==0)&&(x[k].nome[0]))
	{
		if (strcmp(x[k].nome,nome)==0)
				if (strcmp(x[k].cognome,cognome)==0)
				{
					flag=1;
					y=x[k];
					return y;
				}
		k++;
	}	
	return y;
}
