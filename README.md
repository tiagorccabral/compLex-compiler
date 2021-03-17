## Compilador de linguagem baseada em C

---

### Flex & Bison - Como rodar flex e bison

### Flex & Bison 1 - Mover para pasta src

```bash
cd src
```

### Flex & Bison 2 - Gerar arquivos

```bash
make
```

### Flex & Bison 3 - Rodar algum arquivo de exemplo

```bash
./out '../examples/simple_input1.txt'
```

---

### Flex: 1 - Como rodar somente o flex

```bash
flex <nome_do_arquivo.l>
```

### Flex: 2 - Como executar arquivo gerado pelo flex (ex: lex.yy.c)

```bash
gcc -o out lex.yy.c -ll
```

### 3 - Como usar os arquivos de teste

- Entre na pasta 'src'

```bash
cd src
```

- Execute os passos de Flex: 1 e Flex: 2

- Rode o seguinte comando:

```bash
./out '../examples/working_input1.txt'
```
