

double eval(int * vec){
  double fitness = 10;

  for (int i = 0; i < 100; i+=4 ){
    if (vec[i] == 1){
      fitness +=5;
    }
    else{
      fitness -=3;
    }
  }

  for (int i = 0; i < 100; i+=2 ){
    if (vec[i] == 1){
      fitness +=1;
    }
  }

 if (vec [49] == 0){
   fitness = 60;
 }

  return fitness;
}
