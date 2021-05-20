int squareRootToPower(int num, int save) {
  return save*num;
}

int main (int argc) {
  int a;
  int i;
  float b;

  set s;
  elem el;

  add(1 in add(2 in s));

  remove (2 in s);

  exists (1 in s);

  is_set(s);

  // comentarios devem ser ignorados

  a = 1;
  b = 2;
  a = a + b;
  a = a - b;
  a = a * b;
  a = a / b;

  a != b;
  a == b;

  if (i<10 && a==b || a>=10) {
    int a;
    a = -1;
    a = squareRootToPower(i, a);
  }

  return a;
}