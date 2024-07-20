dimension.out: main.o handle_cache.o draw_geometric.o update.o boite_a_outils_des_matrices.o \
boite_a_outils_des_vecteurs.o operations_internes_matrices.o operation_interne_espace_vectoriel.o \
assert_functions.o display.o linear_form.o on_input.o
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

boite_a_outils_des_matrices.o: structure_espace_vectorielle/matrices/boite_a_outils_des_matrices.c
	gcc -g -c -Wall structure_espace_vectorielle/matrices/boite_a_outils_des_matrices.c

operations_internes_matrices.o: structure_espace_vectorielle/matrices/operations_internes_matrices.c
	gcc -g -c -Wall structure_espace_vectorielle/matrices/operations_internes_matrices.c

boite_a_outils_des_vecteurs.o: structure_espace_vectorielle/vecteurs/boite_a_outils_des_vecteurs.c
	gcc -g -c -Wall structure_espace_vectorielle/vecteurs/boite_a_outils_des_vecteurs.c

operation_interne_espace_vectoriel.o: structure_espace_vectorielle/vecteurs/operation_interne_espace_vectoriel.c
	gcc -g -c -Wall structure_espace_vectorielle/vecteurs/operation_interne_espace_vectoriel.c

assert_functions.o: debug_function/assert_functions.c
	gcc -g -c -Wall debug_function/assert_functions.c

display.o: display_vectorial_space/display.c
	gcc -g -c -Wall display_vectorial_space/display.c

linear_form.o: structure_espace_vectorielle/forme_lineaire/linear_form.c
	gcc -g -c -Wall structure_espace_vectorielle/forme_lineaire/linear_form.c

on_input.o: control/on_input.c
	gcc -g -c -Wall control/on_input.c
