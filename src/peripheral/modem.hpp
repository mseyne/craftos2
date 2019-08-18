/*
 * peripheral/modem.hpp
 * CraftOS-PC 2
 * 
 * This file defines the class for the modem peripheral.
 * 
 * This code is licensed under the MIT License.
 * Copyright (c) 2019 JackMacWindows. 
 */

#include "peripheral.hpp"
#include <unordered_set>

class modem: public peripheral {
private:
    std::unordered_set<uint16_t> openPorts;
    Computer * comp;
    std::string side;
    int isOpen(lua_State *L);
    int open(lua_State *L);
    int close(lua_State *L);
    int closeAll(lua_State *L);
    int transmit(lua_State *L);
    int isWireless(lua_State *L);
    void receive(uint16_t port, uint16_t replyPort, lua_State *param);
public:
    static library_t methods;
    library_t getMethods() {return methods;}
    modem(lua_State *L, const char * side);
    ~modem();
    int call(lua_State *L, const char * method);
    void update() {}
};