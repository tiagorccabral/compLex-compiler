float funcao(float num1, float num2) {
  float resultadoFuncao;
  resultadoFuncao = num1 + num2;
  resultadoFuncao = resultadoFuncao * 10.0;
  return resultadoFuncao;
}

int main () {
  int i;
  int j;
  int k;
  float a;
  float b;
  float resultado;
  writeln("Informe dois numeros com casas decimais");
  read(a);
  read(b);
  resultado = funcao(a, b);
  write("somando os numeros que voce informou e multiplicando por 10, temos: ");
  writeln(resultado);
  
  
  writeln("informe k: ");
  read(k);

  if (k==10) {
    writeln("k eh 10");
  } else {
    if (k > 10) {
      writeln("k eh maior que 10");
    } else {
      writeln("k eh menor que 10");
    }
  }

  if (k == 10) {
    writeln("voce eh mto bom em informar numeros");
  }
  return 0;
}