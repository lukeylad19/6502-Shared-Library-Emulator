#include <iostream>
#include <M6502.h>
#include <memory.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>


void ColorS(uint16_t select,uint8_t *R,uint8_t *G,uint8_t *B);

int main( int c, char** argv)
{
    /////////////////////////////////////////////////
    M6502_memory* mem = new M6502_memory(argv[1]);
    std::cout << "argv[1]: " << argv[1] << std::endl;
    M6502_core cpu = M6502_core(mem);
    ////////////////////////////////////////////////

    SDL_Init(SDL_INIT_EVERYTHING); //initiate every SDL component
    SDL_Window *window = nullptr; //creates an SDL_window type
    SDL_Renderer* renderer; //create a renderer
    SDL_Surface* screen;  //create a screen surface

    window = SDL_CreateWindow("6502-Snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN); //Draw the window 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    screen = SDL_GetWindowSurface( window ); //use the windows on the screen surface

    SDL_Rect rectArray[32][32];
    int x,y;
    for(x=0;x<32;x++){
        for(y=0;y<32;y++){
            rectArray[x][y].x = x*25;
            rectArray[x][y].y = y*25;
            rectArray[x][y].w = 25;
            rectArray[x][y].h = 25;
        }  
    }


    bool running = true;
    SDL_Event ev;
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 25;
    rect.h = 25;

    SDL_Rect rect2;
    rect.x = 75;
    rect.y = 25;
    rect.w = 25;
    rect.h = 25;

    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint16_t select;
    int rng;
    srand(time(NULL));
    

    while(running)
    {
        if (SDL_PollEvent(&ev)) {
		//If user tries to exit window, exit program
		    if (ev.type == SDL_QUIT) {
                running = false;
				exit(0);
			}    
        }
        cpu.run();//run the 6502
        rng = rand() % 255;
        mem->write(0xfe,rng);
        //select = 0x200;
            for(y=0;y<32;y++){
                for(x=0;x<32;x++){
                    select = 0x200+(y*32)+x;
                    ColorS(mem->read(select),&R,&B,&G); 
                    SDL_SetRenderDrawColor(renderer,R,B,G,255);
                    SDL_RenderFillRect(renderer,&rectArray[x][y]);

                }     
            }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
    mem->dump();
    SDL_DestroyWindow( window );// destroys window 
    SDL_Quit();//Quit SDL subsystems 
    return 0;
}


void ColorS(uint16_t select,uint8_t *R,uint8_t *G,uint8_t *B){
    uint16_t sel = select;
    
    if(sel == 0x00){
        *R = 0;
        *G = 0;
        *B = 0;
    }else if(sel == 0x01){
        *R = 255;
        *G = 255;
        *B = 255;
    }else if(sel == 0x02){
        *R = 255;
        *G = 0;
        *B = 0;
    }else{
        *R = 0;
        *G = 255;
        *B = 0;
    }

}