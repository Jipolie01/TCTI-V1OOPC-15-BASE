// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end, int small_factor ):
   drawable( w, start, end - start ),
   end( end ),
   start( start),
   small_factor( small_factor),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
{}

void rectangle::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
}

void rectangle::draw_filled(){
    for(int r = start.x; r <= end.x ; r++){
        for(int t =start.y; t <= end.y; t++){
            w.draw(vector(start.x+(r-start.x),start.y+(t-start.y)));
        }
        
    }
    
}

void rectangle::draw_smaller(){
    for(int i = small_factor; i+start.x<=end.x;i++){
        for(int j = small_factor; (j+start.y)<=(end.y);j++){
            if  (i==small_factor  || (i+start.x)==end.x){ 
                w.draw(vector ((start.x+i),(start.y+j)));}
            else if((j==small_factor  || j ==(end.y-start.y) ) || (i+start.y)==(end.y)) { 
                w.draw(vector ((start.x+i),(start.y+j)));}
        }
    }
}

