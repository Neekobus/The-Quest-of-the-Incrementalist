#ifndef INPUTMANAGERH
#define INPUTMANAGERH

#include <map>

class InputManager {
    protected: 
        std::map<int, bool> pressed;
        //history vector
    public:

        static int INPUT_DOWN_ARROW;
        static int INPUT_UP_ARROW;
        static int INPUT_LEFT_ARROW;
        static int INPUT_RIGHT_ARROW;
        static int INPUT_SHIFT;
        //all chars and keys later

        InputManager();
        ~InputManager();
        void inputPressed(int code);
        void inputReleased(int code);
        bool isPressed(int code);
};
#endif