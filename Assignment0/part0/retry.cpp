#include <iostream>
#include <stdio.h>
using namespace std;


bool sendBoat (int source[2], int dest[2], int size, bool finish);
void sendCannibal (int numberCannibal, int numberMissonary, int source[2], int dest [2], int size, int side);
void sendMissionary (int numberCannibal, int numberMissonary, int source[2], int dest [2], int size, int side);
void loadBoat (int (&source)[2], int (&dest)[2], int cannibals, int missonary);
bool eatMissonary ( int cannibals, int missonary);
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
  //  bool check = sendBoat(left, right, size, 0);
    sendCannibal (0, 0, left, right, size, 0);

    /*if (!check){
      cout << "no solution found." << endl;
    }*/

  }else{
    cout << "Please put in a boat size" << endl;
  }


  return 0;
}


bool sendBoat (int source[2], int dest[2], int size, bool finish){
  //check for ending condition
  /*if (finish){
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
        if (send){
          cout << "side" << finish <<endl;
          sendBoat (dest, source, size, !finish);
          //return true;
        }
      }

    }
    return false;*/
 if (finish){
   if (source [0] + source [1] == 6){
     return true;
   }
   sendCannibal (0, 0, source, dest, size, finish);
 }
 else {
   if (source [0] + source [1] != 6){
     sendCannibal (0, 0, source, dest, size, finish);
   }
 }
}

void sendCannibal (int numberCannibal, int numberMissonary, int source[2], int dest [2], int size, int side){
  if (numberCannibal <= source[0]){
    cout <<"cannibals";
    sendMissionary (numberCannibal, numberMissonary, source, dest, size, side);
    sendCannibal (numberCannibal+1, numberMissonary, source, dest, size, side);
  }
  cout << "end condition met" << endl;
}

void sendMissionary(int numberCannibal, int numberMissonary, int source[2], int dest [2], int size, int side){
  cout << "try: " <<endl;
  cout << numberCannibal << " " << numberMissonary << endl;

  print (source, dest, side);
  if (numberMissonary <= source [1]){
    cout << "missonary";
    if ( numberMissonary + numberCannibal <= size
          && numberMissonary + numberCannibal > 0){
            cout << "size";
            cout << side << endl;
           //check if valid condition
             if (eatMissonary (source[0] -numberCannibal, source [1] - numberMissonary) || eatMissonary (dest[0] + numberCannibal, dest [1] +numberMissonary) ){
               cout <<"eaten";
               cout << numberCannibal << " " << numberMissonary << endl;
               if (numberCannibal <= source [0]
                  && numberMissonary <= source[1]){
                    cout <<"here";
                     int sourcetemp[2] = {source[0] - numberCannibal, source[1] - numberMissonary};
                     int desttemp [2] = {dest [0] + numberCannibal, dest [1] + numberMissonary};
                     cout << desttemp[0] << " " <<desttemp [1] << (desttemp [0] + desttemp [1] != 6
                          && !side);
                     //if (desttemp [0] + desttemp [1] != 6 && !side){
                    //  loadBoat (source, dest, numberCannibal, numberMissonary);
                    cout << "sent" << endl;
                      print (sourcetemp, desttemp, side);
                      sendBoat (desttemp, sourcetemp, size, !side);
                    //}
                    //else if (){

                    //}
              }
             }
             sendMissionary (numberCannibal, numberMissonary+1, source, dest, size, side);
           }
  }
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

bool eatMissonary ( int cannibals, int missonary){
  if ( cannibals > missonary && missonary != 0){
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
