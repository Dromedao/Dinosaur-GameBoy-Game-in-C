#include <gb/gb.h>
#include "background.c"
#include "simplebackground.c"
#include <stdio.h>
#include "Dinosaurio.c"

void main(){
    UINT8 currentspriteindex = 0;
	
	//To calculate the position of the character
	int xAxis = 40, yAxis = 120;
	
	//Show the sprite of the Dinosaur
	set_sprite_data(0, 2, Dinosaurio);
    set_sprite_tile(0, 0);
    move_sprite(0, 40, 120);
    SHOW_SPRITES;
    
    //Show background
    set_bkg_data(0, 12, backgroundtiles);
    set_bkg_tiles(0, 0, 40, 18, backgroundmap);
    
    SHOW_BKG;         
    DISPLAY_ON;
	
	//Principal loop
    while(1){
        scroll_bkg(1,0);

        if(currentspriteindex==0){
            currentspriteindex = 1;
        }
        else{
            currentspriteindex = 0;
        }
        set_sprite_tile(0, currentspriteindex);

        switch(joypad()){
            case J_LEFT:
            	if (xAxis > 12){
                scroll_sprite(0,-5,0);
                xAxis -= 5;
           	}
                break;
            case J_RIGHT:
            	if (xAxis < 155){
               scroll_sprite(0,5,0);
               xAxis += 5;
           }
               break;
            case J_UP:
            	if (yAxis > 65){
                scroll_sprite(0,0,-5);
                yAxis -= 5;
            }
				break;
            case J_DOWN:
            	if (yAxis < 150){
                scroll_sprite(0,0,5);
                yAxis += 5;
            }
				break;
        }
        delay(100);
    }
}
