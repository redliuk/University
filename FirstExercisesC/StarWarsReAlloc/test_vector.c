#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

main(){
    vector_type vi1, vd1, vc1, vc2;
    char c1;
    int i1;
    float d1;

    vi1 = v_create_empty(V_INT);
    vd1 = v_create_empty(V_FLOAT);
    vc1 = v_create_empty(V_CHAR);
    vc2 = v_create_empty(V_CHAR);

    c1 = 'c'; v_push_back(vc1,(void*)&c1);
    c1 = 'i'; v_push_back(vc1,(void*)&c1);
    c1 = 'a'; v_push_back(vc1,(void*)&c1);
    c1 = 'o'; v_push_back(vc1,(void*)&c1);
    c1 = 0; v_push_back(vc1,(void*)&c1);

    printf("Vector vc1 now contains %d characters (capacity=%1d): %s\n",
           vector_size(vc1),vector_capacity(vc1),vector_string(vc1));

    for ( i1 = 0, c1 = vector_char_at(vc1,i1) ; c1 ; i1++, c1 = vector_char_at(vc1,i1) )
        v_push_back(vc2,(void*)&c1);
    for ( i1 = 0, c1 = vector_char_at(vc1,i1) ; c1 ; i1++, c1 = vector_char_at(vc1,i1) )
        v_push_back(vc2,(void*)&c1);
    v_insert_n(vc2,iterator_end,1,(void*)&c1); /*** inserting 0 at the end ***/

    printf("Vector vc2 now contains %d characters (capacity=%1d): %s\n",
           vector_size(vc2),vector_capacity(vc2),vector_string(vc2));

    c1 = '-'; v_insert_n(vc2,vector_size(vc1)-1,2,(void*)&c1);

    printf("Vector vc2 now contains %d characters (capacity=%1d): %s\n",
           vector_size(vc2),vector_capacity(vc2),vector_string(vc2));

    for ( i1 = 0 ; i1 < 10 ; i1++ )
        v_push_back(vi1,(void*)&i1);

    printf("Vector vi1 now contains %d integers: ",vector_size(vi1));
    for ( i1 = 0 ; i1 < vector_size(vi1) ; i1++ )
        printf(" %1d",vector_int_at(vi1,i1));
    printf("\n");

    for ( i1 = 0 ; i1 < vector_size(vi1) ; i1++ ) {
        c1 = '0' + vector_int_at(vi1,i1); /*** converting decimal number to char ***/
        v_insert_n(vc2,5+i1,1,(void*)&c1);
      }

    printf("Vector vc2 now contains %d characters (capacity=%1d): %s\n",
           vector_size(vc2),vector_capacity(vc2),vector_string(vc2));

    v_erase_range(vc2,2,3+vector_size(vc1)+vector_size(vi1));

    printf("Vector vc2 now contains %d characters (capacity=%1d): %s\n",
           vector_size(vc2),vector_capacity(vc2),vector_string(vc2));

    for ( i1 = vector_size(vi1)-1 ; i1 >= 0 ; i1-- ) {
        d1 = 0.5 + (float)(vector_int_at(vi1,i1));
        v_push_back(vd1,(void*)&d1);
      } 
    d1 = 3.14159192; /*** approximation of Pi ***/
    v_insert_n(vd1,5,1,(void*)&d1);
    v_erase_range(vd1,2,3);

    printf("Vector vd1 now contains %d float (capacity=%1d): ",
           vector_size(vd1),vector_capacity(vd1));
    for ( i1 = 0 ; i1 < vector_size(vd1) ; i1++ )
        printf(" %lg",vector_float_at(vd1,i1));
    printf("\n");

    d1 = vector_float_at(vd1,8) + vector_float_at(vd1,9); /*** d1 = 1.5+0.5 = 2.0 ***/
    v_erase_range(vd1,0,4); /*** erase first 4 elements **/
    vector_float_at(vd1,0) *= d1; /*** 2*Pi at index 0 ***/
    v_erase_range(vd1,1,iterator_end); /*** erase all elements but the first ***/

    printf("Vector vd1 now contains %d float (capacity=%1d): ",
           vector_size(vd1),vector_capacity(vd1));
    for ( i1 = 0 ; i1 < vector_size(vd1) ; i1++ )
        printf(" %lg",vector_float_at(vd1,i1));
    printf("\n");

    v_erase_range(vi1,1,9); /*** erase elements 1,...,8 ***/
    printf("Vector vi1 now contains %d integers (capacity=%1d): ",
           vector_size(vi1),vector_capacity(vi1));
    for ( i1 = 0 ; i1 < vector_size(vi1) ; i1++ )
        printf(" %1d",vector_int_at(vi1,i1));
    printf("\n");

    v_destroy(vc1); v_destroy(vc2);
    v_destroy(vd1);
    v_destroy(vi1);

    exit(0);
}