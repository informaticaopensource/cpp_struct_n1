#include <iostream>
#include <cstring>
#include "libreria.h"
using namespace std;
int main()
{
	struct alunno classe[35];
	int n_alunni;
	struct alunno incognito;
	float nuovo_voto;
	char mat[30];
	int scelta;
	cout << "\nBenevenuto nel Registro degli Alunni\n";
	cout << "Quanti alunni compongono la classe ?\n";
	do{
	cin >> n_alunni;
	if (n_alunni<2)
		cout << "\n Classe composta da pochi alunni in base alla Norma riprova\n";
	}
	while (n_alunni<2);
	carica_dati(classe,n_alunni);
	cout << "\nFine Primo inserimento dati\n";
	//cout << "\033[2J\033[1;1H"; Decimmentare per Linux OS
	while (1)
	{
	do {
	cout << "\nMenu di Scelta operazioni\n";
	cout << "--->1->Calcolo media di alunno specifico\n";
	cout << "--->2->Valutazione alunno specifico\n";
	cout << "--->3->Stampa prospetto voti alnno\n";
	cout << "--->4->Stampa dati anagrafici alunno\n";
	cout << "--->5->Uscita dal Programma\n";
	cout << "Effettua la tua scelta-->\t";
	cin >> scelta;
	if ((scelta<1)||(scelta>5))
		cout << "\n Scelta Errata riprova\n";
	}
	while ((scelta<1)||(scelta>5));
	//cout << "\033[2J\033[1;1H";
	switch (scelta)
	{
		case 1:
		{
			cout <<"\n---> Inserisci nome e cognome alunno\n";
			cin.ignore(1,'\n');
			cin.getline(incognito.nome,20);
			cin.getline(incognito.cognome,20);
			calcola_media(classe,incognito);
			break;
		}
		case 2:
		{
			cout << "\n-->Valutazione Alunni\n";
			cout << "\n-->Inserisci nome,cognome\n";
			cin.ignore(1,'\n');
			cin.getline(incognito.nome,20);
			cin.getline(incognito.cognome,20);
			cout << "\n-->Ora inserisci la materia e il voto\n";
			cin.ignore(1,'\n');
			cin.getline(mat,30);
			cin >> nuovo_voto;
			valuta(classe,incognito,nuovo_voto,mat);
			cout<< "\nPremi un tasto per continuare";
			getchar();
			break;
		}
		case 3:
			{
				cout << "\nStampa Prospetto degli Alunni\n";
				stampa(classe,n_alunni);
				cout<< "\nPremi un tasto per continuare";
				getchar();
				break;
			}
		case 4:
			{
				cout << "\nInserisci nome e cognome alunno\n";
				cin.ignore(1,'\n');
				cin.getline(incognito.nome,30);
				cin.getline(incognito.cognome,30);
				incognito=cerca2(classe,incognito.nome,incognito.cognome);
				if (!incognito.classe)
					cout << "Alunno con i dati inseriti non individuato\n";
				else{
					cout << "\n Dati Anagrafici Alunno:\n";
					cout << "\nNome:\t"<< incognito.nome;
					cout << "\nCognome:\t"<< incognito.cognome;
					cout << "\nClasse;\t"<<incognito.classe;
					cout<< endl;
				}
				cout<< "\nPremi un tasto per continuare";
				getchar();
				break;
			}
		case 5:
			{
				cout << "\nArrivderci e Grazie per aver utilizzato il programma\n";
				return 0;
			}
		}
}}
