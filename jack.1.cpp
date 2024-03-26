#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int koniec = 0;
  cout << "Zaczac grac?" << endl;
  cout << "1 - TAK" << endl;
  cout << "2- Nie" << endl;
  cin >> koniec;
  if (koniec == 1) {
    srand(unsigned(time(0)));
    //dzia³a w innym pliku
    vector<int> card = {2,  2,  2,  2,  3,  3,  3,  3,  4,  4,  4,  4,  5,
                        5,  5,  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,
                        8,  8,  9,  9,  9,  9,  10, 10, 10, 10, 10, 10, 10,
                        10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11};
    int wybor;
    int bot = 0;
    int punkt = 0;
    int play;
    int win =0;
    int bot_win =0;

    while (true) {
      cout << "Czy potzebyjesz karty? " << endl;
      cout << "1 - Tak" << endl;
      cout << "0 - Nie" << endl;
      cin >> wybor;

      if (wybor == 1) {
        random_shuffle(card.begin(), card.end());
        play = card[card.size() - 1];
        punkt += play;

        random_shuffle(card.begin(), card.end());
        play = card[card.size() - 1];
        bot += play;

        if (punkt > 21) {
          cout << "Za duzo kart, przegralasz: " << punkt << endl;
          bot_win++;

          cout << "Zaczac nowa gre?" << endl;
          cout << "1 - TAK" << endl;
          cout << "2- Nie" << endl;
          cin >> koniec;
          punkt = 0;
          bot = 0;

          if (koniec == 2) {
            cout<<"wasze zwyciestwa: "<<win<< endl;
            cout<<"zwyciestwa bota: "<<bot_win<< endl;
            cout << "Dziekuje za gre" << endl;
            break;
          }
        } else {
          cout << "Twoje punkty: " << punkt << endl;
        }
      } else if (wybor == 0) {

        if (bot > 21) {
          cout << "Twoj wynik: " << punkt << endl;
          cout << "Bot wynik: " << bot << endl;
          cout << "wygrales" << endl;
          win++;

          cout << "Zaczac nowa gre?" << endl;
          cout << "1 - TAK" << endl;
          cout << "2- Nie" << endl;
          cin >> koniec;
          punkt = 0;
          bot = 0;
          if (koniec == 2) {
            cout<<"wasze zwyciestwa: "<<win<< endl;
            cout<<"zwyciestwa bota: "<<bot_win<< endl;
            cout << "Dziekuje za gre" << endl;
            break;
          }
        } else if (bot > punkt) {
          cout << "Twoj wynik: " << punkt << endl;
          cout << "Bot wynik: " << bot << endl;
          cout << "Prezgralasz" << endl;
          bot_win++;

          cout << "Zaczac nowa gre?" << endl;
          cout << "1 - TAK" << endl;
          cout << "2- Nie" << endl;
          cin >> koniec;
          punkt = 0;
          bot = 0;

          if (koniec == 2) {
            cout<<"wasze zwyciestwa: "<<win<< endl;
            cout<<"zwyciestwa bota: "<<bot_win<< endl;
            cout << "Dziekuje za gre" << endl;
            break;
          }
        } else if (bot < punkt) {
          cout << "Twoj wynik: " << punkt << endl;
          cout << "Bot wynik: " << bot << endl;
          cout << "wygrales" << endl;
          win++;

          cout << "Zaczac nowa gre?" << endl;
          cout << "1 - TAK" << endl;
          cout << "2- Nie" << endl;
          cin >> koniec;
          punkt = 0;
          bot = 0;
          if (koniec == 2) {
            cout<<"wasze zwyciestwa: "<<win<< endl;
            cout<<"zwyciestwa bota: "<<bot_win<< endl;
            cout << "Dziekuje za gre" << endl;
            break;
          }
        }
      }
    }
  }
}

