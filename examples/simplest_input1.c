float calculo(int number, float floatNumber, float constParam) {
  float calculoNumber;
  int resultado;
  float resultadoFloat;
  writeln("dentro da funcao");
  calculoNumber = floatNumber + 2.3;
  writeln("somando 10 ao valor b informado");
  resultado = 10 + number;
  write("resultado fica: ");
  writeln(resultado);
  writeln("somando 10.25 ao valor parametro constante informado");
  resultadoFloat = constParam + 10.25;
  write("resultado fica: ");
  writeln(resultadoFloat);
  return calculoNumber;
}

int main () {
  int a;
  int b;
  int c;
  int d;
  float ab;
  ab = 1.5;
  d = 2;
  write("o resultado de 1+2+3*4 eh: ");
  a = 1+2+3*4;
  writeln(a);
  writeln("informe b e c (inteiros): ");
  read(b);
  read(c);
  write("o resultado de b*c + 1 eh: ");
  c = b*c;
  c = c + 1;
  writeln(c);
  write("valor de ab antes da funcao calculo: ");
  writeln(ab);
  write("enviando b e ab para funcao, valor de b: ");
  write(b);
  write(" valor de ab: ");
  writeln(ab);
  ab = calculo(b, ab, 3.14);
  write("valor de ab depois da funcao calculo: ");
  writeln(ab);
  return 0;
}