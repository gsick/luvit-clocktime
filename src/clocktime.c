/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 gsick
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <time.h>

#define LUA_CLIENT_MT "lua.clocktime.client"

static int lua_client_time(lua_State *L) {

  struct timespec spec;
  
  clock_gettime(CLOCK_REALTIME, &spec);
  
  lua_pushinteger(L, spec.tv_sec);
  lua_pushinteger(L, spec.tv_nsec / 10e5);
  lua_pushinteger(L, spec.tv_nsec);

  return 3;
}

static const struct luaL_Reg functions[] = {
  {"time", lua_client_time},
  {NULL, NULL}
};

int luaopen_clocktime(lua_State *L) {

  luaL_newmetatable(L, LUA_CLIENT_MT);
  luaL_register(L, NULL, functions);
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");

  return 1;
}
