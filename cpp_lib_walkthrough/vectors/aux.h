using namespace std;

void print(vector<int> q){
  // print vector using vector iterator
  for(auto i = q.begin(); i != q.end(); i++){
    cout << *i << " ";
  }
  cout << endl;
  
  // alternative print on vector
  int qsize = q.size();
  for(int i = 0; i < qsize; i++){
    //cout << q[i] << " ";
  }
  //cout << endl;
}

vector<int> elementAdd(vector<int> A, vector<int> B){
  vector<int> C;
  if (A.size() != B.size()){
    cout << "cannot add. Shape mismatch" << endl;
    exit(1);
  }

  int size = A.size();
  for(int i = 0; i < size; i++){
    C.push_back(A[i] + B[i]);
  }
  return C;
}

vector<int> elementMult(vector<int> A, vector<int> B){
  vector<int> C;
  if (A.size() != B.size()){
    cout << "cannot add. Shape mismatch" << endl;
    exit(1);
  }

  int size = A.size();
  for(int i = 0; i < size; i++){
    C.push_back(A[i] * B[i]);
  }
  return C;
}

vector<vector<int>> mat_mul(){
  vector<vector<int>> A{
    {3,6,9},
    {2,5,8},
    {1,4,7}
  };

  vector<vector<int>> B{
    {1,2,3,4},
    {4,5,6,7},
    {7,8,9,10}
  };

  cout << "initializing vector A:" << endl;
  for (int i = 0; i < A.size(); i++){
      for (int j = 0; j < A[i].size(); j++){
        cout << A[i][j] << " ";
      }
      cout << endl;
  }
  cout << endl;

  cout << "initializing vector B:" << endl;
  for (int i = 0; i < B.size(); i++){
      for (int j = 0; j < B[i].size(); j++){
        cout << B[i][j] << " ";
      }
      cout << endl;
  }
  cout << endl;
  cout << "vector A shape: (" << A.size() << "," << A[0].size() << ")" << endl;
  cout << "vector B shape: (" << B.size() << "," << B[0].size() << ")" << endl;

  cout << "output vector shape (A x B): (" << A.size() << "," << B[0].size() << ")" << endl;
  vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));

  for (int i = 0; i < C.size(); i++){
    for (int j = 0; j < C[0].size(); j++){
      int sum = 0;
      for (int x = 0; x < A[i].size(); x++){
        sum += (int(A[i][x]) * int(B[x][j]));
      }
      C[i][j] = sum;
    } 
  }
  return C;
}
