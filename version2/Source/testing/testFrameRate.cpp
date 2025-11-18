#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>


const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

SDL_Surface* gScreenSurface = NULL;

void close()
{
    //Destroy window    
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::printf( "SDL could not initialize! SDL_Error: %s\n",
        SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
        SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            std::printf( "Window could not be created! SDL_Error: %s\n",
            SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            //gScreenSurface = SDL_GetWindowSurface( gWindow );
            gRenderer = SDL_CreateRenderer( gWindow, -1,
            SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                std::printf( "Renderer could not be created! \
                SDL Error: %s\n",SDL_GetError() );
                success = false;
            }
            else
            {
            	if( !SDL_SetRenderVSync( gRenderer, 1 ) )
            	{
                  SDL_Log( "Could not enable VSync! SDL error: %s\n",
                  SDL_GetError() );
                  success = false;
                }
            }
            //Initialize renderer color
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

						//Initialize PNG loading
						int imgFlags = IMG_INIT_PNG;
						if( !( IMG_Init( imgFlags ) & imgFlags ) )
						{
								std::printf( "SDL_image could not initialize!\
								SDL_image Error: %s\n", IMG_GetError() );
								success = false;
						}
						if( !TTF_Init() )
					  {
								SDL_Log( "SDL_ttf could not initialize! SDL_ttf\
								error: %s\n", SDL_GetError() );
								success = false;
						}
					}
        }
    }
    return success;
}


int main() {
	init();
	//The quit flag
	bool quit{ false };

	//The event data
	SDL_Event e;
	SDL_zero( e );

	//VSync toggle
	bool vsyncEnabled{ true };

	//FPS cap toggle
	bool fpsCapEnabled{ false };

	//Timer to calculate FPS
	LTimer fpsTimer;

	//Timer to cap frame rate
	LTimer capTimer;

	//Frame counter
	Uint64 renderedFrames = 0;

	//Time spend rendering
	Uint64 renderingNS = 0;

	//Reset FPS calculation flag
	bool resetFps = true;
	//If the FPS calculation must be reset
	if( resetFps )
	{
			//Reset FPS variables
			fpsTimer.start();
			renderedFrames = 0;
			renderingNS = 0;
			resetFps = false;
	}

	//Start frame time
	capTimer.start();
	bool quit = false;
	while( !quit )
	{
		//Handle events on queue
		SDL_Event e;
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
					quit = true;
			}
			else if( e.type == SDL_EVENT_KEY_DOWN )
			{
					//VSync toggle
					if( e.key.key == SDLK_RETURN )
					{
							vsyncEnabled = !vsyncEnabled;
							SDL_SetRenderVSync( gRenderer, ( vsyncEnabled ) ? 1 : SDL_RENDERER_VSYNC_DISABLED );
							resetFps = true;
					}
					//FPS cap toggle
					else if( e.key.key == SDLK_SPACE )
					{
							fpsCapEnabled = !fpsCapEnabled;
							resetFps = true;
					}
			}
		}
		//Update text
		if( renderedFrames != 0 )
		{
				timeText.str("");
				timeText << "Frames per second " 
						<< ( vsyncEnabled ?  "(VSync) " :  "" )
						<< ( fpsCapEnabled ?  "(Cap) " :  "" )
						<< static_cast<double>( renderedFrames ) / ( static_cast<double>( renderingNS ) / 1000000000.0 ); 
				SDL_Color textColor = { 0x00, 0x00, 0x00, 0xFF };
				gFpsTexture.loadFromRenderedText( timeText.str().c_str(), textColor );
		}
	  //Clear screen
	  SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	  SDL_RenderClear( gRenderer );


	  //Update screen
	  SDL_RenderPresent( gRenderer );
				//Update text
		if( renderedFrames != 0 )
		{
				timeText.str("");
				timeText << "Frames per second " 
						<< ( vsyncEnabled ?  "(VSync) " :  "" )
						<< ( fpsCapEnabled ?  "(Cap) " :  "" )
						<< static_cast<double>( renderedFrames ) / ( static_cast<double>( renderingNS ) / 1000000000.0 ); 
				SDL_Color textColor = { 0x00, 0x00, 0x00, 0xFF };
				gFpsTexture.loadFromRenderedText( timeText.str().c_str(), textColor );
		}
	}
	close();
	return 0;
}
