/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_image.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed image
SDL_Surface* gStretchedSurface = NULL;

SDL_Surface* Sann = NULL;
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load stretching surface
	gStretchedSurface = loadSurface( "C:/Users/HP 840 G3/Downloads/01_hello_SDL/bg2.bmp" );
	if( gStretchedSurface == NULL )
	{
		printf( "Failed to load stretching image!\n" );
		success = false;
	}

	Sann = IMG_Load( "C:/Users/HP 840 G3/Downloads/01_hello_SDL/gammm.png" );
	if( gStretchedSurface == NULL )
	{
		printf( "Failed to load stretching image!\n" );
		success = false;
	}

	SDL_SetColorKey( Sann , SDL_TRUE, SDL_MapRGB( Sann->format, 255, 255, 255 ) );

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface( gStretchedSurface );
	gStretchedSurface = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
				//Handle events on queue
		

			//Apply the image stretched
			SDL_Rect stretchRect;
			stretchRect.x = 0;
			stretchRect.y = 0;
			stretchRect.w = SCREEN_WIDTH;
			stretchRect.h = SCREEN_HEIGHT;
			SDL_BlitScaled( gStretchedSurface, NULL, gScreenSurface, &stretchRect );

			SDL_Rect stretchRec;
			stretchRec.x = 60;
			stretchRec.y = 350;
			stretchRec.w = 40;
			stretchRec.h = 60;	
			
			SDL_BlitScaled( Sann, NULL,gScreenSurface, &stretchRec );

			SDL_UpdateWindowSurface( gWindow );
			while( !quit )
			{
				//User requests quit
				if(SDL_PollEvent(&e)==0) SDL_Delay(100);
				else{
				    if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else if( e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
						    for(int i=0;i<30;i++){
								stretchRec.y -=2;
								SDL_BlitScaled(gStretchedSurface, NULL, gScreenSurface, &stretchRect);
				                SDL_BlitScaled( Sann, NULL,gScreenSurface, &stretchRec );
				                SDL_UpdateWindowSurface( gWindow );
								SDL_Delay(8);
							}
							for(int i=0;i<30;i++){
								stretchRec.y +=2;
								SDL_BlitScaled(gStretchedSurface, NULL, gScreenSurface, &stretchRect);
				                SDL_BlitScaled( Sann, NULL,gScreenSurface, &stretchRec );
				                SDL_UpdateWindowSurface( gWindow );
								SDL_Delay(8);
							}
							break;
						case SDLK_LEFT:
						    stretchRec.x -=10;
							break;
						case SDLK_RIGHT:
						    stretchRec.x +=10;
							break;
						}						
					}
				}
				SDL_BlitScaled(gStretchedSurface, NULL, gScreenSurface, &stretchRect);
				SDL_BlitScaled( Sann, NULL,gScreenSurface, &stretchRec );
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
//g++ test5.cpp -I"C:\Users\HP 840 G3\Downloads\SDL2-devel-2.26.3-mingw\SDL2-2.26.3\i686-w64-mingw32\include\SDL2" -L"C:\Users\HP 840 G3\Downloads\SDL2-devel-2.26.3-mingw\SDL2-2.26.3\i686-w64-mingw32\lib" -w "-Wl,-subsystem,windows" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o test5