#ifndef COLLITIONTERMINAL_TPP
#define COLLITIONTERMINAL_TPP

#include <std/collitionTerminal.hpp>

namespace EGE::STD::TERMINAL{

    template<typename mType>
    void collitionTerminal<mType>::update(mType *gameContext){

    }

    template<typename mType>
    bool collitionTerminal<mType>::updated(EGE::CORE::EntityId id,mType *gameContext){
        auto tm = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal();
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::Position>(id);

        int tall = tm -> getTall();
        int width = tm -> getWidth();
        int x;
        int y;

        auto vectorDePosicion = position -> getPosition();

        for(auto i : vectorDePosicion){
            x = std::get<0>(i);
            y = std::get<1>(i);

            if(y == 0 || y >= tall){
                return true;
            }

            if(x == 0 || x >= width){
                return true;
            }
        }
        return false;
    }
}
#endif