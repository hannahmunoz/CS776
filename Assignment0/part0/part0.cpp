#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Boat{
  public:
    Boat();
    Boat(const Boat &obj);
    ~Boat();
    void crossRiver();
    void setPort(bool);
    void setPassangers (char [2]);

  //private:
    //0 is left, 1 is right
    bool port;
    char boatMembers [2];
};

class stateSpace{
  public:
    stateSpace(Boat, char [],char [] );
    ~stateSpace();
//  private:
    Boat boat;
    char left [6];
    char right [6];
    stateSpace *next;

};

class problemSpace{
  public:
    problemSpace();
    ~problemSpace();
    void push (stateSpace *space );
    void pop ();
    void print ();

  private:
    stateSpace *front;
    stateSpace *rear;
    vector <stateSpace> endState();
};

Boat createBoat(bool l, char members [2]);

int main(int argc, char const *argv[]) {

  //fill the left
  char left [6] = {'M','M','M','C','C','C'};
  char right [6] = {'0','0','0','0','0','0'};

  // check for correct amount of arguemnts
  if (argc == 2){
    int size;
    sscanf (argv[1],"%d",&size);
    problemSpace problemSpace;

    char members [2] = {'0','0'};
    stateSpace *startSpace = new stateSpace  (createBoat (false, members) , left, right);
    problemSpace.push (startSpace);

    //okay! now breath first search
    search (startSpace, left, right);

    problemSpace.print();

  }
  else{
    cout << "Please put boat size\n";
  }


  return 0;
}

/*void search (stateSpace *space, char l [2], char r [2]){
  if (space->boat.port = false){
    choosePassangers (space, l);
  }
  else {
    choosePassangers (space, r);
  }
}

void choosePassangers(stateSpace *space, char s){
  for (int j = 1; j <= 2; j++){
    for (int i = 0; i < 6; i ++){

    }
  }
}*/

Boat createBoat(bool l, char members [2]){
  Boat temp;
  temp.setPort(l);
  temp.setPassangers (members);

  return temp;
}

Boat::Boat(){
}

Boat::Boat(const Boat &obj){
  port = obj.port;
  for (int i = 0; i < 2; i ++){
      boatMembers[i] = obj.boatMembers[i];
  }
}

Boat::~Boat(){

}
void Boat::setPassangers(char members [2]){
  boatMembers[0] = members [0];
  boatMembers [1] = members [1];
}

void Boat::setPort(bool l){
  port = l;
}

void Boat::crossRiver(){
  port = !port;
}

problemSpace::problemSpace(){
  front = NULL;
  rear = NULL;
}

problemSpace::~problemSpace(){
  delete front;
}
void problemSpace::print(){
  stateSpace *current;
  current = front;
  while (current != NULL){
    //print left
    for (int i = 0; i < 6; i ++){
      if (current->left [i] != '0'){
        cout << current->left [i] << " ";
      }
      else{
        cout << " ";
      }
    }

  cout << "     ";

    for (int i = 0; i < 2; i ++){
      if (current->boat.boatMembers [i] != '0'){
        cout << current->boat.boatMembers [i] << " ";
      }
      else{
        cout << " ";
      }
    }


    cout << "     ";

    for (int i = 0; i < 6; i ++){
      if (current->right [i] != '0'){
        cout << current->right [i] << " ";
      }
      else{
        cout << " ";
      }
    }

    cout << endl;

    current = current->next;
  }
}

void problemSpace::push (stateSpace *space ){
  if (front == NULL){
    front = space;
  }
  else{

  }
}

void problemSpace::pop (){
}

stateSpace::stateSpace(Boat newBoat, char  l[6], char  r[6]){
      next = NULL;
      boat = newBoat;
      for (int i = 0; i < 6; i++){
        left[i] = l[i];
        right[i]= r[i];
      }
};

stateSpace::~stateSpace(){

};
