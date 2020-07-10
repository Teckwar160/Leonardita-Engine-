#ifndef SYSTEM_HPP
#define SYSTEM_HPP

/**Alias*/
#include "alias.hpp"

namespace EGE{

    class SystemBase{
        public:
            /**Atributo que identifica el tipo de sistema*/
            inline static SystemType nextType = 0;

            /**
             *@brief Método constructor.
             */
            SystemBase();

            /**
             *@brief Método destructor.
             */
            virtual ~SystemBase() = 0;

    };
    
    /**
     *@brief Interface de cualquier sistema que se necesite del motor.
     */
    template<class Type>
    class System : public SystemBase{
        private:
            SystemType type = 0;
        public:
        /**
         *@brief Método constructor vacío.
         */
        System();

        /**
         *@brief Método constructor.
         *
         *@param type identificador del tipo de sistema.
         */
        System(SystemType type);

        /**
         *@brief Método destructor.
         */
        virtual ~System() = 0;

        /**
         *@brief Método que nos regresa el identificador del tipo de sistema.
         *@return SystemType
         */
        static SystemType getSystemType();
    };
}

#endif