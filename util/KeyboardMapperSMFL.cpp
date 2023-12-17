//
// Created by Егор Федоров on 07.12.2023.
//

#include "KeyboardMapperSMFL.h"

#define addKey(x) \
    string2key[#x] = sf::Keyboard::Key::x; \
    key2string[sf::Keyboard::Key::x] = #x

KeyboardMapperSMFL::KeyboardMapperSMFL() {
    addKey(A);
    addKey(B);
    addKey(C);
    addKey(D);
    addKey(E);
    addKey(F);
    addKey(G);
    addKey(H);
    addKey(I);
    addKey(J);
    addKey(K);
    addKey(L);
    addKey(M);
    addKey(N);
    addKey(O);
    addKey(P);
    addKey(Q);
    addKey(R);
    addKey(S);
    addKey(T);
    addKey(U);
    addKey(V);
    addKey(W);
    addKey(X);
    addKey(Y);
    addKey(Z);

    addKey(Num0);
    addKey(Num1);
    addKey(Num2);
    addKey(Num3);
    addKey(Num4);
    addKey(Num5);
    addKey(Num6);
    addKey(Num7);
    addKey(Num8);
    addKey(Num9);

    addKey(Escape);
    addKey(LControl);
    addKey(LShift);
    addKey(LAlt);
    addKey(LSystem);
    addKey(RControl);
    addKey(RShift);
    addKey(RAlt);
    addKey(RSystem);
    addKey(Menu);
    addKey(LBracket);
    addKey(RBracket);
    addKey(Semicolon);
    addKey(Comma);
    addKey(Period);
    addKey(Apostrophe);
    addKey(Slash);
    addKey(Backslash);
    addKey(Grave);
    addKey(Equal);
    addKey(Hyphen);
    addKey(Space);
    addKey(Enter);
    addKey(Backspace);
    addKey(Tab);
    addKey(PageUp);
    addKey(PageDown);
    addKey(End);
    addKey(Home);
    addKey(Insert);
    addKey(Delete);
    addKey(Add);
    addKey(Subtract);
    addKey(Multiply);
    addKey(Divide);
    addKey(Left);
    addKey(Right);
    addKey(Up);
    addKey(Down);
    addKey(Numpad0);
    addKey(Numpad1);
    addKey(Numpad2);
    addKey(Numpad3);
    addKey(Numpad4);
    addKey(Numpad5);
    addKey(Numpad6);
    addKey(Numpad7);
    addKey(Numpad8);
    addKey(Numpad9);
    addKey(F1);
    addKey(F2);
    addKey(F3);
    addKey(F4);
    addKey(F5);
    addKey(F6);
    addKey(F7);
    addKey(F8);
    addKey(F9);
    addKey(F10);
    addKey(F11);
    addKey(F12);
    addKey(F13);
    addKey(F14);
    addKey(F15);
    addKey(Pause);
    addKey(Unknown);
}

sf::Keyboard::Key KeyboardMapperSMFL::stringToKey(const std::string &keyString) {
    if (string2key.contains(keyString))
        return string2key.at(keyString);
    else
        return sf::Keyboard::Unknown;
}

std::string KeyboardMapperSMFL::keyToString(sf::Keyboard::Key key) {
    return key2string.at(key);
}
