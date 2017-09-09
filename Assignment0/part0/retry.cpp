#include <iostream>
#include <stdio.h>
using namespace std;


bool sendBoat (int (&source)[2], int (&dest)[2], int size, bool finish);
void loadBoat (int (&source)[2], int (&dest)[2], int cannibals, int missonary);
bool eatMissonary (int source[2], int cannibals, int missonary);
void print (int source[2], int dest [2], bool side);

int main(int argc, char const *argv[]) {

  // left
  if (argc == 2){
    int size;
    sscanf (argv[1],"%d",&size);

    // 0 is cannibals and 1 is missonary
    int left [2] = {3,3};
    int right [2] = {0,0};

    // 0 is left 1 is right
    bool check = sendBoat(left, right, size, 0);
    if (!check){
      cout << "no solution found." << endl;
    }

  }else{
    cout << "Please put in a boat size" << endl;
  }


  return 0;
}


bool sendBoat (int (&source)[2], int (&dest)[2], int size, bool finish){
  //check for ending condition
  if (finish){
    if (source [0] == 3 && source [1] ==3){
      return true;
    }
  }
  else{
    if (dest [0] == 3 && dest [1] == 3 ){
      return true;
    }
  }
 bool send;
  for (int takeCannibal = 0; takeCannibal <= source [0]; takeCannibal ++){
    for (int takeMissonary = 0; takeMissonary <= source [1]; takeMissonary ++){
     send = false;
      if ( takeMissonary + takeCannibal <= size
           && takeCannibal + takeMissonary > 0){

          //check if valid condition
            if (eatMissonary (source, takeCannibal, takeMissonary)){
              cout << takeCannibal << " " << takeMissonary << endl;

              loadBoat (source, dest, takeCannibal, takeMissonary);
              print (source, dest, finish);
              send = true;
            }
        }
      }
      if (send){
        sendBoat (dest, source, size, !finish);
        //return true;
      }
    }
    return false;
}

void print (int source[2], int dest [2], bool side){
  //cout << takeCannibal << " " << takeMissonary << endl;
  if (!side){
    cout << source [0] << " "<< source [1] << "    " << dest [0]  << " " << dest [1] << endl << endl;
  }
  else{
    cout << dest [0] << " "<< dest [1] << "    " << source [0]  << " " << source [1] << endl << endl;

  }
  char t;
  cin >> t;
}

bool eatMissonary (int source[2], int cannibals, int missonary){
  if (source [0] - cannibals > source [1] - missonary){
    return false;
  }
  return true;
}

void loadBoat (int (&source)[2], int (&dest)[2], int cannibals, int missonary){
  source [0] -= cannibals;
  source [1] -= missonary;

  dest [0] += cannibals;
  dest [1] += missonary;

}
