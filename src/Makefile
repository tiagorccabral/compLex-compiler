all: compLexLang

compLexLang: compLex_syntatical.y lexical.l
	@echo "Bison step"
	bison -d -Wall compLex_syntatical.y
	@echo "Lexical step"
	flex lexical.l
	@echo "Compile step"
	gcc compLex_syntatical.tab.c lex.yy.c -Wall -g -o out
	