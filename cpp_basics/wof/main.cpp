#include <iostream>
#include "aux.h"
#include <vector>
#include <string>
using namespace std;
using std::vector;


int main(){
  std::cout << "hi!\n";
  std::string check;
  int Num_players;
  int over = 0;
  cout << "how many players: ";
  cin >> Num_players;
  cin.clear();
  cin.ignore();
  struct person people[Num_players];
  for (int i = 0; i < Num_players; i++){
    people[i].total_money = 0;
    people[i].puzzle_money = 0;
  }
  wheel_of_fortune(people, Num_players);
  /*
  play_puzzle(people, Num_players);
  for (int i = 0; i < Num_players; i++){
    cout << "player " << i + 1 << ": total: " << people[i].total_money << "$" << endl;
  }
  */

  return 0;
}
