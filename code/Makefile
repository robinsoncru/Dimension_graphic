dimension.out: main.o handle_cache.o draw_geometric.o update.o
	gcc -g -Wall -o dimension.out *.o \
$$(sdl2-config --cflags --libs)

main.o: main.c
	gcc -g -c -Wall main.c

handle_cache.o: affichage/handle_cache.c
	gcc -g -c -Wall affichage/handle_cache.c

draw_geometric.o: affichage/draw_geometric.c
	gcc -g -c -Wall affichage/draw_geometric.c

update.o: update.c
	gcc -g -c -Wall update.c

