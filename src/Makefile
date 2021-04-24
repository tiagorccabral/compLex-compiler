all: compLexLang

compLexLang: compLex_syntatical.y lexical.l
	@echo "Bison step"
	bison -d -Wall compLex_syntatical.y
	@echo "Lexical step"
	flex lexical.l
	@echo "Compile step"
	gcc compLex_syntatical.tab.c parser_ast.c symbol_table.c semantic_analyzer.c lex.yy.c -Wall -fsanitize=address -g -o out
	
memCheck: compLex_syntatical.y lexical.l
	@echo "Valgrind mem leak check"
	bison -d -Wall compLex_syntatical.y
	flex lexical.l
	gcc compLex_syntatical.tab.c parser_ast.c symbol_table.c semantic_analyzer.c lex.yy.c -Wall -g -o out
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="logfile.out" ./out '../examples/simple_input1.txt'