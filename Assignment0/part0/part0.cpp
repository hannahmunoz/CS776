#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Boat{
  public:
    Boat();
    ~Boat();
    void crossRiver();

  private:
    //0 is left, 1 is right
    bool port;
    vector <char>  boatMembers;
};

class problemSpace{
  public:
    problemSpace();
    ~problemSpace();
    push ();
    pop ();

  private:
    boat *front;
    boat *rear;
};

class stateSpace{
  public:
    stateSpace(Boat, vector <char> , vector <char> );
    ~stateSpace();
  private:
    Boat boat;
    vector <char>  left [6];
    vector <char>  right [6];

}

int main(int argc, char const *argv[]) {

  //fill the left
  vector <char> left = {'M','M','M','C','C','C'};
  vector <char> right;

  // check for correct amount of arguemnts
  if (argc == 2){
    int size;
    sscanf (argv[1],"%d",&size);
    problemSpace problemSpace();
    stateSpace startSpace ()
    //boat* startBoat = new boat(size);
  }
  else{
    cout << "Please put boat size\n";
  }


  return 0;
}

Boat::Boat(){
  //start on the left
  port = 0;
}

Boat::Boat(const Boat &obj){
  port = obj.port;
  boatMembers = obj.boatMembers;
}

Boat::~Boat(){

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

problemSpace::push (){
  if (front == NULL){
 }
}

stateSpace::stateSpace(Boat newBoat, vector <char> l, vector <char> r){
      boat = newBoat;
      left = l;
      right = r;
};

stateSpace::~stateSpace(){

};
