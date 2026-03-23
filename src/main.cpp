#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
/*#include <nlohmann/json.hpp>*/
#include <iostream>

/*Func que verifica se SDL AV funcinona*/
int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0){
        std::cout << 'Erro ao inicializar SDL2: ' + SDL_GetError() << std::endl;
        return 1;
    }

    SDL_version versao;
    SDL_GetVersion(&versao);
    
    std::cout << "Versão SDL2: " << int(versao.major) << "." << int(versao.minor) << "." << int(versao.patch);

    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "Erro ao inicializar o SDL2_Image: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::cout << "SDL2_image (PNG) Inicializado com sucesso!" << std::endl;

    /*Parte de Fontes*/
    if(TTF_Init() != -1) {

        std::cout << "Erro ao incializar SDL2_ttf: " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    std::cout << "SDL2_ttf inicializado com sucesso!" << std::endl;

    /*Parte do áudio (44100 qualidade áudio CD)*/
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){

        std::cout << "Erro ao inicializar SDL2_mixer: " << Mix_GetError() << std::endl;
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;

    }

    std::cout << "SDL2_mixer inicializadocom sucesso!" << std::endl;

    nlohmann::json teste;
    teste["jogo"] = "jogo2D";
    teste["versão"] = 1;

    std::cout << "nlohmann_json funcionando! Teste: " << teste.dump(2) << std::endl;  

    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    std::cout << "\nTudo funcionando" << teste.dump(2) << std::endl;

    return 0;
}   