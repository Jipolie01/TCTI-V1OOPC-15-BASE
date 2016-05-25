#include "victim.hpp"
#include "rectangle.hpp"

victim::victim(window & w, vector start,  vector  end ):
    drawable(w,start,end-start),
    obstacle(w,vector(start.x+1,start.y+1),vector(end.x-1,end.y-1),update_count),
    end(end),start(start)
{}

void victim::update(){
    if (hit ==true){
        obstacle.small_factor += 2;
    }}



void victim::draw(){
    obstacle.draw_smaller();
    }


void victim::interact( drawable & other,drawable * objects[] ){
    if( this != & other){
        if( overlaps( other )){
            hit = 1;
        }}}