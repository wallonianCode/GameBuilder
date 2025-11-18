#include "testColorKeying.hpp"


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Color getPixelColor(const SDL_Surface* pSurface, const int& X, 
const int& Y)
{
  // Bytes per pixel
  const Uint8 Bpp = pSurface->format->BytesPerPixel;

  /*
  Retrieve the address to a specific pixel
  pSurface->pixels  = an array containing the SDL_Surface' pixels
  pSurface->pitch       = the length of a row of pixels (in bytes)
  X and Y               = the offset on where on the image to retrieve 
  the pixel; (0, 0) is the upper left corner
  */
  Uint8* pPixel = (Uint8*)pSurface->pixels + Y * pSurface->pitch + X *
  Bpp;

  Uint32 PixelData = *(Uint32*)pPixel;

  SDL_Color Color = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};

  // Retrieve the RGB values of the specific pixel
  SDL_GetRGB(PixelData, pSurface->format, &Color.r, &Color.g, &Color.b);

  return Color;
}


//Scene textures
LTexture gFooTexture;
LTexture gBackgroundTexture;

LTexture::LTexture()
{
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    //Deallocate
    free();
}

bool LTexture::loadFromFile( std::string path )
{
    //Get rid of preexisting texture
    free();
        //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n",
        path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
				SDL_Color backgroundColor = getPixelColor(loadedSurface, 0, 0);
				std::printf("Background color: %d, %d, %d", 
				backgroundColor.r, backgroundColor.g, 
				backgroundColor.b);
        SDL_SetColorKey( loadedSurface, SDL_TRUE,
        SDL_MapRGB( loadedSurface->format, backgroundColor.r, 
				backgroundColor.g, backgroundColor.b ) );
                //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer,
        loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n",
            path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

void LTexture::free()
{
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render( int x, int y )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
}


int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}



bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load Foo' texture
    if( !gFooTexture.loadFromFile( "../TileSheets/trainerExample.png" ) )
    {
        std::printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }
    
    //Load background texture
    if( !gBackgroundTexture.loadFromFile( "background.png" ) )
    {
        std::printf( "Failed to load background texture image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    gFooTexture.free();
    gBackgroundTexture.free();

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
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF,  
                0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    std::printf( "SDL_image could not initialize!\
										SDL_image\
                    Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}




int main() {
    std::cout << "Message on screen" << std::endl;
    init();
    loadMedia();
    //While application is running
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
      }

       //Clear screen
       SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
       SDL_RenderClear( gRenderer );

       //Render background texture to screen
       gBackgroundTexture.render( 0, 0 );

       //Render Foo' to the screen
       gFooTexture.render( 240, 190 );

       //Update screen
       SDL_RenderPresent( gRenderer );
    }
		close();
    return 0;
}
