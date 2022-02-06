#include <vector>
#include <cstring>
#include <string>
using namespace std;

struct person{
  int total_money;
  int puzzle_money;
};

string get_input(){
  string in_string;
  cout << "input phrase: ";
  getline(cin, in_string);
  return in_string;
}

void get_real(string in_string, char* real){
  for (int i = 0; i < in_string.length(); i++){
    real[i] = in_string[i];
  }
  for (int i = 0; i < strlen(real); i++){
    cout << real[i];
  }
  cout <<"\n";
}

void get_cov(string in_string, char* cov){
  for (int i = 0; i < in_string.length(); i++){
    cov[i] = in_string[i];
  }

  for (int i = 0; i < in_string.length(); i++){
    if ((cov[i] >= 65 && cov[i] <= 90) 
    || (cov[i] >= 97 && cov[i] <= 122)){
      cov[i] = '_'; 
    }
    cout << cov[i];
  }
  cout <<"\n";
}

int buy_vowel(char *real, char *cov, struct person *person){
  char vow;
  int count = 0;
  cout << "which vowel: ";
  cin >> vow;
  cin.clear();
  cin.ignore();
  while (vow != 97 && vow != 101 && vow != 105 && vow != 111 && vow != 117){
    cout << "enter a vowel: ";
    cin >> vow;
    cin.clear();
    cin.ignore();
  }
  for (int i = 0; i < strlen(real); i++){
    if (real[i] == vow){
      cov[i] = real[i];
      count += 1;
    }
    cout << cov[i];
  }
  cout << "\n";
  if (count == 0){
    return 1;
  }
  person->puzzle_money -= count;
  return 0;
}

int get_const(char *real, char *cov, struct person *person){
  char letter;
  int count = 0;
  cout << "which letter: ";
  cin >> letter;
  cin.clear();
  cin.ignore();
  while (letter == 97 || letter == 101 || letter == 105 || letter == 111 || letter == 117){
    cout << "enter a non-letterel: ";
    cin >> letter;
    cin.clear();
    cin.ignore();
  }
  for (int i = 0; i < strlen(real); i++){
    if (real[i] == letter){
      cov[i] = real[i];
      count += 1;
    }
    cout << cov[i];
  }
  cout << "\n";
  if (count == 0){
    return 1;
  }
  person->puzzle_money += count * 5;
  return 0;
}

int guess_soln(char *real){
  int solved = 1;
  string in_string;
  cout << "solution: ";
  getline(cin, in_string);
  int n = in_string.length();
  char solution[n+1];
  solution[n] = '\0';
  for (int i = 0; i < in_string.length(); i++){
    solution[i] = in_string[i];
  }


  for (int i = 0; i < strlen(real); i++){
    if (solution[i] != real[i]){
      solved = 0;
      break;
    }
  }
  return solved;


}

void play_puzzle(struct person *people, int N){
  int over = 0;
  string check;
  check = get_input();
  int n = check.length();
  char real[n+1];
  char covered[n+1];
  real[n] = '\0';
  covered[n] = '\0';
  get_real(check, real);
  get_cov(check, covered);
  int pick;
  int player = 0;

  while (over == 0){
    player = player % N;
    cout << "Player " << player + 1 << "'s turn" << endl;
    cout << "Player " << player + 1 << ": total: " << people[player].total_money << "$ puzzle: " << people[player].puzzle_money << "$\n";
    cout << "what would you like to do? (1) buy vowel, (2) guess letter, (3) solve: ";
    cin >> pick;
    cin.clear();
    cin.ignore();
    while (pick != 1 && pick != 2 && pick != 3){
      cout << "That isn't a valid option. Please pick 1,2, or 3: ";
      cin >> pick;
      cin.clear();
      cin.ignore();
    }
    if (pick == 1){
      player += buy_vowel(real, covered, &people[player]);
    }
    if (pick == 2){
      player += get_const(real, covered, &people[player]);
    }
    if (pick == 3){
      over = guess_soln(real);
      if (over != 1){
        player += 1;
      }
    }
    if (over == 1){
      cout << "puzzle has been solved by player " << player + 1 << endl;
      people[player].total_money += people[player].puzzle_money;
    }
  }
  for (int j = 0; j < N; j++){
      people[j].puzzle_money = 0;
  }
}

void wheel_of_fortune(struct person *people, int N){
  int play_game = 1;
  while (play_game == 1){
    play_puzzle(people, N);
    for (int i = 0; i < N; i++){
      cout << "player " << i + 1 << ": total: " << people[i].total_money << "$" << endl;
    }
    cout << "continue playing? (1) yes, (0) no: ";
    cin >> play_game;
    cin.clear();
    cin.ignore();
  }


}




