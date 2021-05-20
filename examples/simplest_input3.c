int main () {
  set s;
  elem x;
  int i;
  int num1;
  int num2;
  int num3;
  s = EMPTY;

  writeln("informe tres inteiros para colocar no set: ");
  for (i=0; i<3; i=i+1) {
    if (i==0) {
      write("Informe um numero: ");
      read(num1);
    }
    if (i==1) {
      write("Informe um segundo numero inteiro: ");
      read(num2);
    }
    if (i==2) {
      write("Informe um terceiro numero inteiro: ");
      read(num3);
    }
  }

  add(num1 in s);
  add(num2 in s);
  add(num3 in s);


  forall(x in s) {
    write("valores dentro do set: ");
    writeln(x);
  }
  return 0;
}