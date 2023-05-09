/*
 * vector.c: implementazione della libreria vector.
 *
 * versione 1.3 del 31/03/2017
 *
 * Programma sviluppato a supporto del laboratorio di
 * Sistemi di Elaborazione dell'Informazione del corso di laurea
 * in Informatica classe L-31 presso l'Universita` degli Studi di
 * Genova, anno accademico 2015/2016.
 *
 * Copyright (C) 2013-2017 by Giovanni Chiola <chiolag@acm.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include "vector.h"


//#define DEBUG



inline void fail(const char* msg){
    fprintf(stderr,"\nERROR: %s\n\n",msg);
    exit(1);
}


inline void * check_a(void*p){
    if ( p == NULL )
        fail("check_a(): NULL pointer");
    return p;
}


vector_type v_create_empty(char type){
    vector_type my_v = (vector_type)check_a(malloc(sizeof(struct vector_struct)));

/*** TO BE OPTIONALLY CHANGED START ***/

    /*** add proper handling of V_FLOAT type ***/

    my_v->e_sz = (type == V_INT ? sizeof(int) : type == V_DOUBLE ? sizeof(double) : type == V_FLOAT ? sizeof(float) : 1);

/*** TO BE OPTIONALLY CHANGED END ***/

    my_v->e_type = type;
    my_v->no_e = my_v->cur_cap = 0;
    my_v->e_array = NULL;
    return my_v;
}


void v_destroy(vector_type my_v){
    if ( my_v == NULL )
    	return;

/*** TO BE DONE START ***/

    free(my_v->e_array);

/*** TO BE DONE END ***/

    free((void*)my_v);
}


void* v_at(vector_type v, iterator i){
    if ( v == NULL )
    	fail("v_at() Error: no such vector");
    if ( i == iterator_end )
    	i = v->no_e -1;
    if ( i < 0 || i >= v->no_e )
    	fail("v_at() Error: no such element in this vector");

/*** TO BE DONE START ***/

    return v->e_array+i*v->e_sz; //ritorna l'elemento

/*** TO BE DONE END ***/

}


void v_push_back(vector_type v, void* new_val){
    if ( v->no_e >= v->cur_cap ) {
    	/*** reallocate a larger array ***/
    	v->cur_cap += (v->cur_cap)? v->cur_cap : 2;	//se cap=0 la pongo a 2 altrimenti la raddoppio

/*** TO BE DONE START ***/

    v->e_array=check_a(realloc(v->e_array,v->cur_cap*v->e_sz));

/*** TO BE DONE END ***/

      }
    /*** copy new_val in the array at index v->no_e ***/

/*** TO BE DONE START ***/

      memcpy(v->e_array+v->no_e*v->e_sz, new_val, v->e_sz);	//posiziono il nuovo puntatore affianco all'ultimo

/*** TO BE DONE END ***/

    (v->no_e)++;
}


void v_pop_back(vector_type v){
    if ( v == NULL )
    	fail("v_pop_back(): no such vector");
    if ( v->no_e == 0 )
    	return;
    if ( --(v->no_e) < ((v->cur_cap)>>1) ) { //se il num di elementi-1 è minore di metà della capacità
    	/*** reallocate a smaller array ***/
    	(v->cur_cap) >>= 1;		//dimezzo la capacità

/*** TO BE DONE START ***/

    v->e_array=realloc(v->e_array,v->cur_cap*v->e_sz);

/*** TO BE DONE END ***/

      }
}


void v_insert_n(vector_type v,iterator start_i,unsigned n,void* new_val){
    char null[v->e_sz];
    int inserted, moved, to_insert, to_move;

    if ( n==0 ) /*** nothing to insert ***/
    	return;
    if ( v == NULL )
    	fail("v_insert_n(): no such vector");
    if ( start_i == iterator_end )
    	start_i = v->no_e;
    if ( start_i < 0 )
    	fail("v_insert_n(): bad iterator");
    if ( start_i >= v->no_e ) {
    	memset((void*)null,0,v->e_sz);
        while ( start_i > v->no_e ) /*** fill-in the gap with zero elements ***/
            v_push_back(v,(void*)null);
        /*** insert new elements at index >= v->no_e ***/
        for ( inserted=0 ; inserted < n ; inserted++ )
            v_push_back(v,new_val);
        return;
      }
    /*** otherwise, we have to move some elements first, in order to make space ***/
    moved = (v->no_e);
    to_move = moved - start_i;
    to_insert = n;
#ifdef DEBUG
    printf(" ... v_insert_n(%1d): moved=%1d, to_move=%1d, start_i=%1d\n",
           n,moved,to_move,start_i);
#endif
    for ( inserted = 0 ; (to_move+inserted) < n ; inserted++, to_insert-- )
        v_push_back(v,new_val);
#ifdef DEBUG
    printf(" ... v_insert_n(%1d): inserted=%1d\n",n,inserted);
#endif
    for ( to_move = moved ; to_move >= start_i && inserted < n ; inserted++, to_move-- );
    for ( inserted = 0 ; to_move < moved ; inserted++, to_move++ ) {
#ifdef DEBUG
        printf("    ... v_insert_n(%1d): pushing_back %1d\n",n,to_move);
#endif
        v_push_back(v, v->e_array + (v->e_sz) * to_move );
      }

    /*** move possibly remaining elements and then add the new ones ***/
    for ( moved -= inserted ; moved-- > start_i ; ) {
#ifdef DEBUG
        printf("    ... v_insert_n(%1d): moving %1d to %1d\n",n,moved,moved+n);
#endif

/*** TO BE DONE START ***/
	
        	memcpy(v->e_array+(moved+n)*v->e_sz, v->e_array+(moved)*v->e_sz, v->e_sz);

/*** TO BE DONE END ***/

      }

    while ( to_insert-- > 0 ) {
#ifdef DEBUG
        printf("    ... v_insert_n(%1d): inserting %1d\n",n,start_i+to_insert);
#endif

/*** TO BE DONE START ***/

		memcpy(v->e_array+(start_i+to_insert)*v->e_sz, new_val, v->e_sz);

/*** TO BE DONE END ***/

      }
}


void v_erase_range(vector_type v,iterator start_i,iterator end_i){
    int i, j;
    if ( v == NULL )
    	fail("v_erase_range(): no such vector");
    if ( start_i == iterator_end )
    	start_i = v->no_e-1;
    if ( end_i == iterator_end )
    	end_i = v->no_e;
    if ( start_i < 0 || start_i >= v->no_e || end_i < 0 )
    	fail("v_erase_range(): bad iterator");
    if ( start_i >= end_i ) /*** nothing to erase ***/
    	return;
#ifdef DEBUG
    printf(" ... v_erase_range(%1d,%1d): no_e=%1d, e_sz=%1d, e_type=%1d\n",
           start_i,end_i,v->no_e,(int)(v->e_sz),v->e_type);
#endif
    for ( i = start_i, j = end_i ; j < v->no_e ; i++, j++ ) {
#ifdef DEBUG
        printf("    ... v_erase_range(%1d,%1d): moving %1d to %1d\n",start_i,end_i,j,i);
#endif
    	memcpy(v->e_array + (v->e_sz) * i, v->e_array + (v->e_sz) * j, v->e_sz);
      }

    /*** call v_pop_back() to actually erase elements ***/

/*** TO BE DONE START ***/

	for(int a=start_i;a<end_i;a++)	v_pop_back(v);
	
/*** TO BE DONE END ***/

}

