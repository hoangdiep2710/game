#include "menu.h"
#include "setup.h"
using namespace std;

int show_menu(SDL_Surface * screen)
{
    SDL_Rect Back_scr = {0,0,840,600};
    // nut Play
    SDL_Rect Playbutton_dest = {360,240,120,60};
    SDL_Rect Playbutton_scr = {0,0,120,60};
    SDL_Rect Playbutton_bright_scr = {0,60,120,60};
    // nut Quit
    SDL_Rect Exitbutton_dest = {360,300,120,60};
    SDL_Rect Exitbutton_scr = {240,0,120,60};
    SDL_Rect Exitbutton_bright_scr = {240,60,120,60};

    SDL_Texture* back_Tex = IMG_LoadTexture(renderer, "D:/dinosaur/img/dinosaurs-5687815_1280.jpg");
    SDL_RenderCopy(renderer, back_Tex,&Back_scr,NULL);

    SDL_Texture* button = IMG_LoadTexture(renderer, "D:/dinosaur/img/Button.png");

    SDL_RenderCopy(renderer, button,&Playbutton_scr,&Playbutton_dest);
    SDL_RenderCopy(renderer, button,&Exitbutton_scr,&Exitbutton_dest);

    bool selected[2] = {0,0};
    int x, y;
    SDL_Rect Pos_menu[2];
    Pos_menu[0] = Playbutton_dest;
    Pos_menu[1] = Exitbutton_dest;
    SDL_Event event;
    while (1)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                return 1;
            }
            if (event.type == SDL_MOUSEMOTION)
            {
                x = event.motion.x;
                y = event.motion.y;
                if(check_click(Pos_menu[0],x,y))
                {
                    if(!selected[0])
                    {
                        selected[0] = 1;
                        SDL_RenderCopy(renderer,button,&Playbutton_bright_scr,&Playbutton_dest);
                    }
                }
                else
                {
                    if(selected[0])
                    {
                        selected[0] = 0;
                        SDL_RenderCopy(renderer,button,&Playbutton_scr,&Playbutton_dest);
                    }
                }
                if(check_click(Pos_menu[1],x,y))
                {
                    if(!selected[1])
                    {
                        selected[1] = 1;
                        SDL_RenderCopy(renderer,button,&Exitbutton_bright_scr,&Exitbutton_dest);
                    }
                }
                else
                {
                    if(selected[1])
                    {
                        selected[1] = 0;
                        SDL_RenderCopy(renderer,button,&Exitbutton_scr,&Exitbutton_dest);
                    }
                }
            }
            x = event.button.x;
            y = event.button.y;
            for (int i = 0; i <= 2; i++)
            {
                if (check_click(Pos_menu[i],x,y))
                    if(event.type == SDL_MOUSEBUTTONDOWN)
                        return i;
            }

        }
        SDL_RenderPresent(renderer);
    }
    return 1;
}
