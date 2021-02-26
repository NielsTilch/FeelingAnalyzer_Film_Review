HashProg_main_test : HashProg.c HashProg.o HashProg_main_test.c HashProg_main_test.o tableHachage.o tableHachage.c listSimpleChain.o HashProg_main_test.o fonctionHachage.o
	gcc -o HashProg_main_test HashProg.o HashProg_main_test.o listSimpleChain.o tableHachage.o fonctionHachage.o

testHashProg : tableHachage.o listSimpleChain.o HashProg.o testHashProg.c
	#export LD_LIBRARY_PATH=../criterion-v2.3.3/lib
	gcc -Wall -I../criterion-v2.3.3/include/ -L../criterion-v2.3.3/lib/ -lcriterion tableHachage.o listSimpleChain.o HashProg.o testHashProg.c -o testHashProg

testHashProg_collision : tableHachage_collision.o listSimpleChain_collision.o HashProg_collision.o testHashProg_collision.c
	#export LD_LIBRARY_PATH=../criterion-v2.3.3/lib
	gcc -Wall -I../criterion-v2.3.3/include/ -L../criterion-v2.3.3/lib/ -lcriterion tableHachage_collision.o listSimpleChain_collision.o HashProg_collision.o testHashProg_collision.c -o testHashProg_collision

listSimpleChain.o : listSimpleChain.c listSimpleChain.h
	gcc -Wall -Wextra -c listSimpleChain.c

HashProg_main_test.o : HashProg_main_test.c
	gcc -Wall -Wextra -c HashProg_main_test.c

tableHachage.o : tableHachage.c tableHachage.h listSimpleChain.h fonctionHachage.h
	gcc -Wall -Wextra -c tableHachage.c

HashProg.o : HashProg.c HashProg.h 
	gcc -Wall -Wextra -c HashProg.c

score_commentaire.o : score_commentaire.c score_commentaire.h
	gcc -Wall -Wextra -c score_commentaire.c

test_score_commentaire : main_score_commentaire.o score_commentaire.c tableHachage_collision.c listSimpleChain_collision.c HashProg_collision.c fonctionHachage.c analyseTable.c analyseTable.h
	gcc -Wall -Wextra -c HashProg_collision.c
	gcc -Wall -Wextra -c tableHachage_collision.c
	gcc -Wall -Wextra -c fonctionHachage.c
	gcc -Wall -Wextra -c analyseTable.c
	gcc -Wall -Wextra -c score_commentaire.c
	gcc -Wall -Wextra -c main_score_commentaire.c
	gcc -Wall -Wextra -c listSimpleChain_collision.c
	gcc -o test_score_commentaire main_score_commentaire.o score_commentaire.o tableHachage_collision.o listSimpleChain_collision.o HashProg_collision.o fonctionHachage.o analyseTable.o

testScore : testScore.c main_score_commentaire.o score_commentaire.o HashProg_collision.o tableHachage_collision.o listSimpleChain_collision.o 
	#export LD_LIBRARY_PATH=../criterion-v2.3.3/lib
	gcc -Wall -I../criterion-v2.3.3/include/ -L../criterion-v2.3.3/lib/ -lcriterion testScore.c main_score_commentaire.o score_commentaire.o HashProg_collision.o tableHachage_collision.o listSimpleChain_collision.o -o testScore

testAnalyseTable : testAnalyseTable.c fonctionHachage.h fonctionHachage.c listSimpleChain_collision.h listSimpleChain_collision.c HashProg_collision.h HashProg_collision.c tableHachage_collision.h tableHachage_collision.c analyseTable.h analyseTable.c analyseFonctionsHachage.c analyseFonctionsHachage.h
	#export LD_LIBRARY_PATH=../criterion-v2.3.3/lib
	gcc -Wall -Wextra -c fonctionHachage.c
	gcc -Wall -Wextra -c listSimpleChain_collision.c
	gcc -Wall -Wextra -c analyseTable.c
	gcc -Wall -Wextra -c HashProg_collision.c
	gcc -Wall -Wextra -c tableHachage_collision.c
	gcc -Wall -Wextra -c analyseTable_main.c
	gcc -Wall -Wextra -c analyseFonctionsHachage.c
	gcc -Wall -I../criterion-v2.3.3/include/ -L../criterion-v2.3.3/lib/ -lcriterion testAnalyseTable.c HashProg_collision.o fonctionHachage.o tableHachage_collision.o listSimpleChain_collision.o -o testAnalyseTable

HashProg_collision : tableHachage_collision.c fonctionHachage.c tableHachage_collision.o HashProg_collision.c HashProg_collision.o listSimpleChain_collision.c listSimpleChain_collision.o HashProg_collision_main_test.c HashProg_collision_main_test.o fonctionHachage.o
	gcc -Wall -Wextra -c tableHachage_collision.c
	gcc -Wall -Wextra -c HashProg_collision.c
	gcc -Wall -Wextra -c fonctionHachage.c
	gcc -Wall -Wextra -c listSimpleChain_collision.c
	gcc -Wall -Wextra -c HashProg_collision_main_test.c
	gcc -o HashProg_collision HashProg_collision_main_test.o fonctionHachage.o tableHachage_collision.o HashProg_collision.o listSimpleChain_collision.o

analyseTable : fonctionHachage.h fonctionHachage.c listSimpleChain_collision.h listSimpleChain_collision.c HashProg_collision.h HashProg_collision.c tableHachage_collision.h tableHachage_collision.c analyseTable.h analyseTable.c analyseTable_main.c analyseFonctionsHachage.c
	gcc -Wall -Wextra -c fonctionHachage.c
	gcc -Wall -Wextra -c listSimpleChain_collision.c
	gcc -Wall -Wextra -c analyseTable.c
	gcc -Wall -Wextra -c HashProg_collision.c
	gcc -Wall -Wextra -c tableHachage_collision.c
	gcc -Wall -Wextra -c analyseTable_main.c
	gcc -Wall -Wextra -c analyseFonctionsHachage.c
	gcc -o analyseTable tableHachage_collision.o HashProg_collision.o analyseTable.o listSimpleChain_collision.o fonctionHachage.o analyseTable_main.o analyseFonctionsHachage.o

analyseFonctionHachage: fonctionHachage.c fonctionHachage.h listSimpleChain_collision.c listSimpleChain_collision.h tableHachage_collision.c tableHachage_collision.h analyseFonctionsHachage.c HashProg_collision.c HashProg_collision.h analyseTable.h analyseTable.c
	gcc -Wall -Wextra -c fonctionHachage.c
	gcc -Wall -Wextra -c listSimpleChain_collision.c
	gcc -Wall -Wextra -c HashProg_collision.c
	gcc -Wall -Wextra -c tableHachage_collision.c
	gcc -Wall -Wextra -c analyseTable.c
	gcc -Wall -Wextra -c analyseFonctionsHachage.c
	gcc -o analyseFonctionHachage listSimpleChain_collision.o tableHachage_collision.o HashProg_collision.o analyseFonctionsHachage.o fonctionHachage.o analyseTable.o

testFonctionHachage : fonctionHachage.c fonctionHachage.h 
	#export LD_LIBRARY_PATH=../criterion-v2.3.3/lib
	gcc -Wall -Wextra -c fonctionHachage.c
	gcc -Wall -I../criterion-v2.3.3/include/ -L../criterion-v2.3.3/lib/ -lcriterion fonctionHachage.o testSha1.c -o testSha1

statistics : statistics_main.c statistics.h statistics.c fonctionHachage.o HashProg_collision.o tableHachage_collision.o listSimpleChain_collision.o listSimpleChain_float.o listSimpleChain_str.o listSimpleChain_int.o arbresFloat.o arbres.o 
	gcc -Wall -Wextra -c statistics_main.c
	gcc -Wall -Wextra -c statistics.c
	gcc -Wall -Wextra -c HashProg_collision.c
	gcc -Wall -Wextra -c tableHachage_collision.c
	gcc -Wall -Wextra -c listSimpleChain_collision.c
	gcc -o statistics statistics_main.o statistics.o fonctionHachage.o HashProg_collision.o tableHachage_collision.o listSimpleChain_collision.o listSimpleChain_float.o listSimpleChain_str.o listSimpleChain_int.o arbresFloat.o arbres.o

testStatistics : statistics.o fonctionHachage.o HashProg_collision.o tableHachage_collision.o listSimpleChain_collision.o listSimpleChain_float.o listSimpleChain_int.o listSimpleChain_str.o arbresFloat.o arbres.o
	gcc -Wall -Wextra -c statistics.c 
	gcc -Wall -Wextra -c HashProg_collision.c 
	gcc -Wall -Wextra -c tableHachage_collision.c
	gcc -Wall -Wextra -c listSimpleChain_collision.c
	gcc -Wall -I/usr/local/Cellar/criterion/2.3.3/include/ -L/usr/local/Cellar/criterion/2.3.3/lib/ -lcriterion statistics.o fonctionHachage.o HashProg_collision.o tableHachage_collision.o listSimpleChain_collision.o listSimpleChain_float.o listSimpleChain_int.o listSimpleChain_str.o arbresFloat.o arbres.o testStatistics.c -o testStatistics

fonctionHachage : fonctionHachage.o fonctionHachage.h 
	gcc -o fonctionHachage fonctionHachage.o

fonctionHachage.o : fonctionHachage.c fonctionHachage.h
	gcc -Wall -Wextra -c fonctionHachage.c

analyseFonctionsHachage.o : analyseFonctionsHachage.c analyseFonctionsHachage.h listSimpleChain.h fonctionHachage.h tableHachage.h
	gcc -Wall -Wextra -c analyseFonctionsHachage.c

listSimpleChain_int.o : listSimpleChain_int.c listSimpleChain_int.h
	gcc -Wall -Wextra -c listSimpleChain_int.c

testListInt : listSimpleChain_int.o
	gcc -Wall -I/usr/local/Cellar/criterion/2.3.3/include/ -L/usr/local/Cellar/criterion/2.3.3/lib/ -lcriterion listSimpleChain_int.o testListInt.c -o testListInt
	
listSimpleChain_float.o : listSimpleChain_float.c listSimpleChain_float.h
	gcc -Wall -Wextra -c listSimpleChain_float.c

testListFloat : listSimpleChain_float.o 
	gcc -Wall -I/usr/local/Cellar/criterion/2.3.3/include/ -L/usr/local/Cellar/criterion/2.3.3/lib/ -lcriterion listSimpleChain_float.o testListFloat.c -o testListFloat 

listSimpleChain_str.o : listSimpleChain_str.c listSimpleChain_str.h
	gcc -Wall -Wextra -c listSimpleChain_str.c

testListStr : listSimpleChain_str.o
	gcc -Wall -I/usr/local/Cellar/criterion/2.3.3/include/ -L/usr/local/Cellar/criterion/2.3.3/lib/ -lcriterion listSimpleChain_str.o testListStr.c -o testListStr

arbres.o : arbres.c arbres.h
	gcc -Wall -Wextra -c arbres.c

testArbres : arbres.o
	gcc -Wall -I/usr/local/Cellar/criterion/2.3.3/include/ -L/usr/local/Cellar/criterion/2.3.3/lib/ -lcriterion arbres.o testArbres.c -o testArbres

arbresFloat.o : arbresFloat.c arbresFloat.h
	gcc -Wall -Wextra -c arbresFloat.c

testArbresFloat : arbresFloat.o
	gcc -Wall -I/usr/local/Cellar/criterion/2.3.3/include/ -L/usr/local/Cellar/criterion/2.3.3/lib/ -lcriterion arbresFloat.o testArbresFloat.c -o testArbresFloat

main: main.o main_sub.o fonctionHachage.o score_commentaire.o tableHachage_collision.o listSimpleChain_collision.o HashProg_collision.o listSimpleChain_str.o listSimpleChain_int.o arbresFloat.o
	gcc -Wall -Wextra -c main.c
	gcc -Wall -Wextra -c main_sub.c
	make HashProg_collision
	make analyseFonctionsHachage.o
	make listSimpleChain_float.o
	make listSimpleChain_str.o
	make HashProg_collision
	make statistics
	gcc -o main main.o main_sub.o fonctionHachage.o tableHachage_collision.o listSimpleChain_collision.o HashProg_collision.o listSimpleChain_str.o listSimpleChain_float.o arbresFloat.o

clean : 
	rm -f *.o
	rm -f testHashProg test_score_commentaire HashProg_main_test fonctionHachage testSha1 testStatistics HashProg_collision analyseTest analyseFonctionHachage analyseTable testStatisticsScore testListInt testListFloat testListStr testArbres testArbresFloat

