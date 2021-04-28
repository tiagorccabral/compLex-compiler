## Compilador de linguagem baseada em C

---

### Versões das bibliotecas/pacotes utilizados para desenvolvimento

**GCC/Clang:** Apple clang version 12.0.0 (clang-1200.0.32.29)

**Flex:** flex 2.5.35 Apple(flex-32)

**Bison:** bison (GNU Bison) 3.7.4

---

### Rodando com Docker

Caso tenha Docker instalado na sua máquina, basta utilizar os seguintes passos para rodar o projeto:

### 1 - Criar imagem e subir container

```bash
docker-compose up -d
```

### 2 - Entrar no modo bash desse container criado

```bash
docker attach gcc
```

### 3 - Navegue até a pasta do projeto

```bash
cd code/src/
```

### 4 - Rodar o programa para qualquer um dos exemplos na pasta *examples* (no exemplo está o arquivo simple_input2.c)

```bash
make && ./out '../examples/simple_input2.c'
```

---

### Flex & Bison - Como rodar flex e bison

### 1 - Mover para pasta src

```bash
cd src
```

### 2 - Gerar arquivos

```bash
make
```

### 3 - Rodar algum arquivo de exemplo

```bash
./out '../examples/simple_input1.txt'
```

---
### Flex - Como rodar somente o flex
### 1 - Como rodar somente o flex

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

- Execute os passos de Flex: 1 e Flex: 2

- Rode o seguinte comando:

```bash
./out '../examples/working_input1.txt'
```
