## Analisador léxico

### 1 - Como rodar o flex

```bash
flex <nome_do_arquivo.l>
```

### 2 - Como executar arquivo gerado pelo flex (ex: lex.yy.c)

```bash
gcc -o out lex.yy.c -ll
```

### 3 - Como usar os arquivos de teste

- Entre na pasta 'src'

```bash
cd src
```

- Execute os passos de 1 e 2

- Rode o seguinte comando:

```bash
./out '../examples/working_input1.txt'
```
