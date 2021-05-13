.table
float num1
float num2
float resultadoFuncao
int i
int j
int k
float a
float b
float resultado
char string1 [] = "Informe dois numeros com casas decimais"
char string2 [] = "somando os numeros que voce informou e multiplicando por 10, temos: "
char string3 [] = "i == "
char string4 [] = "k == "
.code
funcao:
add $0, #0, #1
mov resultadoFuncao, $0
mul $1, resultadoFuncao, 10.0
mov resultadoFuncao, $1
return resultadoFuncao
fmain:
mov $6, 40
mov $2, 0
mov $3, &string1
whileWritelnStart1:
seq $5, $6, $2
brnz endWhileWriteln1, $5
mov $4, $3[$2]
print $4
add $2, $2, 1
jump whileWritelnStart1
endWhileWriteln1:
print '\n'
scanf a
scanf b
param a
param b
call funcao, 2
pop $7
mov resultado, $7
mov $12, 69
mov $8, 0
mov $9, &string2
whileWritelnStart2:
seq $11, $12, $8
brnz endWhileWriteln2, $11
mov $10, $9[$8]
print $10
add $8, $8, 1
jump whileWritelnStart2
endWhileWriteln2:
nop
println resultado
mov k, 10
mov i, 0
forLoop0:
sleq $13, i, 3
brz forLoop0Finish, $13
mov $19, 6
mov $15, 0
mov $16, &string3
whileWritelnStart3:
seq $18, $19, $15
brnz endWhileWriteln3, $18
mov $17, $16[$15]
print $17
add $15, $15, 1
jump whileWritelnStart3
endWhileWriteln3:
nop
println i
mov j, 10
forLoop1:
seq $20, k, 10
brz forLoop1Finish, $20
mov $26, 6
mov $22, 0
mov $23, &string4
whileWritelnStart4:
seq $25, $26, $22
brnz endWhileWriteln4, $25
mov $24, $23[$22]
print $24
add $22, $22, 1
jump whileWritelnStart4
endWhileWriteln4:
nop
println k
sub $27, k, 1
mov k, $27
add j, j, 1
jump forLoop1
forLoop1Finish:
mov k, 10
add i, i, 1
jump forLoop0
forLoop0Finish:
return 0
main:
call fmain
nop
