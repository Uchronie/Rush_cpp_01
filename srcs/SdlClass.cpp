//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "../incs/SdlClass.hpp"
#include "../incs/IMonitorModule.hpp"

#define WIN_WIDTH 140
#define WIN_HEIGHT 480
#define NBR_MODULE 1
#define FONT_SIZE 65
#define MIN_SIZE_MODULE (WIN_HEIGHT / NBR_MODULE)
#define FONT_R 255
#define FONT_G 0
#define FONT_B 0

SdlClass::SdlClass() : _screen(NULL), _running(true) {
    _surfaces = std::list<SDL_Surface*>();
    try {
        _screen = initSdl();
        _surfaces.push_back(SDL_GetWindowSurface(_screen));
        initSurfaces(NBR_MODULE);
    }
    catch (BadSdlInitException &e) { std::cout << e.what() << std::endl; _running = false; }
    catch (BadTtfInitException &e) { std::cout << e.what() << std::endl; _running = false; }
    catch (BadWindowCreationException &e) { std::cout << e.what() << std::endl; _running = false; }
    return ;
}
SdlClass::~SdlClass() {
//    std::for_each(_surfaces.begin(), _surfaces.end(), );
    exitSdl();
    return ;
}
SdlClass::SdlClass(SdlClass const &src) : _screen(src.getScreen()), _running(src.isRunning()), _surfaces(src.getSurfaces()) {return ;}
SdlClass &SdlClass::operator=(SdlClass const &src){
    _screen = src.getScreen();
    _running = src.isRunning();
    _surfaces = src.getSurfaces();
    initScrValue();
    return *this;
}

SDL_Window *SdlClass::initSdl() {
    SDL_Window *ret;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw BadSdlInitException();
    if (TTF_Init() < 0)
        throw BadTtfInitException();
    _police = TTF_OpenFont("font.ttf", FONT_SIZE);
    initScrValue();
    initSurfaces(NBR_MODULE);
    if (!(ret = SDL_CreateWindow("ft_gkrellm",(_scrWidth - WIN_WIDTH) / 2 , (_scrHeight - WIN_HEIGHT) / 2, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS)))
        throw BadWindowCreationException();
    return ret;;
}

void SdlClass::exitSdl() {
    SDL_DestroyWindow(_screen);
    TTF_CloseFont(_police);
    TTF_Quit();
    SDL_Quit();
}

void SdlClass::initScrValue() {
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    _scrWidth = DM.w;
    _scrHeight = DM.h;
}

void SdlClass::printInfo(SDL_Rect pos) {
    SDL_Color fontColor = {FONT_R, FONT_G, FONT_B, SDL_ALPHA_OPAQUE};
    SDL_Surface *text;

    pos.y = 0;
    pos.w = 0;
    text = TTF_RenderText_Solid(_police, "Test", fontColor);
    SDL_BlitScaled(text, &pos, _surfaces.front(), NULL);
}

void SdlClass::initSurfaces(unsigned int nbr) {
    SDL_Rect tmp;
    unsigned int    i = 0;

    while (i < nbr) {
        _surfaces.push_back(SDL_GetWindowSurface(_screen));
        i++;
    }
    i = 0;
    for (std::list<SDL_Surface *>::iterator it = _surfaces.begin(); it != _surfaces.end(); ++it) {
        if (*it != _surfaces.front()) {
            tmp.x = 0;
            tmp.y = (i++ * MIN_SIZE_MODULE);
            tmp.w = WIN_WIDTH;
            tmp.h = MIN_SIZE_MODULE;
            SDL_BlitScaled(*it, &tmp, _surfaces.front(), NULL);
            SDL_FillRect(*it, &tmp, SDL_MapRGB((*it)->format, 0xFF - (0xFF / (i + 1)), 0xFF - (0xFF / (i + 1)), 0xFF - (0xFF / (i + 1))));
            printInfo(tmp);
        }
    }
    SDL_UpdateWindowSurface(_screen);
}

void SdlClass::update() {
    SDL_Event event;

    if (_screen) {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                setRunning(false);
        }
        SDL_UpdateWindowSurface(_screen);
//        if (!_surfaces.empty())
//        std::for_each(_surfaces.begin(), _surfaces.end(), IMonitorModule::update()); //try and catch update error
    }
}

SDL_Window *SdlClass::getScreen() const { return _screen; }
void SdlClass::setScreen(SDL_Window *screen) { _screen = screen; }
bool SdlClass::isRunning() const { return _running; }
void SdlClass::setRunning(bool running) { _running = running; }
const std::list<SDL_Surface *> &SdlClass::getSurfaces() const { return _surfaces; }
unsigned int SdlClass::getScrWidth() const { return _scrWidth; }
void SdlClass::setScrWidth(unsigned int scrWidth) { _scrWidth = scrWidth; }
unsigned int SdlClass::getScrHeight() const { return _scrHeight; }
void SdlClass::setScrHeight(unsigned int scrHeight) { _scrHeight = scrHeight; }

SdlClass::BadWindowCreationException::BadWindowCreationException() {return ;}
SdlClass::BadWindowCreationException::BadWindowCreationException(const SdlClass::BadWindowCreationException &) {return ;}
SdlClass::BadWindowCreationException::~BadWindowCreationException() throw() {return ;}
SdlClass::BadWindowCreationException &
SdlClass::BadWindowCreationException::operator=(const SdlClass::BadWindowCreationException &) {return *this;}

const char *SdlClass::BadWindowCreationException::what() const throw() {
    return SDL_GetError();
}

SdlClass::BadSdlInitException::BadSdlInitException() {return ;}
SdlClass::BadSdlInitException::BadSdlInitException(const SdlClass::BadSdlInitException &) {return ;}
SdlClass::BadSdlInitException::~BadSdlInitException() throw() {return ;}
SdlClass::BadSdlInitException &SdlClass::BadSdlInitException::operator=(const SdlClass::BadSdlInitException &) {return *this;}

const char *SdlClass::BadSdlInitException::what() const throw() {
    return SDL_GetError();
}

SdlClass::BadTtfInitException::BadTtfInitException() {return ;}
SdlClass::BadTtfInitException::BadTtfInitException(const SdlClass::BadTtfInitException &) {return ;}
SdlClass::BadTtfInitException::~BadTtfInitException() throw() {return ;}
SdlClass::BadTtfInitException &SdlClass::BadTtfInitException::operator=(const SdlClass::BadTtfInitException &) {return *this;}

const char *SdlClass::BadTtfInitException::what() const throw() {
    return TTF_GetError();
}
