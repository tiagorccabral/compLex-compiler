int squareRoot(int a) {
  float ab;
  writeln(a);

  return a;
}

int main (int argc, int argv) {
  int varName;
  float ab;
  set s;
  int i;
  int b;
  elem x;

  {
    int inside_a;
    inside_a = b;

    {
      int inside_b;
      inside_b = inside_a + b;
    }
  }

  if (i<10) i = 10;

  if (i == 10) return i;

  if (i>10) {
    i = 1.5 + i;
  }

  read(varName);
  writeln(varName);
  write("ola mundo");

  writeln("programa simples");

  add(1 in s);
  add(2 in s);
  remove(2 in s);
  exists(1 in s);

  forall(x in s) {
    write(x);
  }

  for (i=0; i<10; i=i+1) {
    writeln(i);
  }

  return;
}