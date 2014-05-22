local Clock = require('clocktime')
local os = require('os')
local string = require('string')

local s, ms, ns = Clock.time()

print('seconds: ' .. s)
print('milliseconds: ' .. ms)
print('nanoseconds: ' .. ns)
print('date: ' .. os.date("!%c", s))
print('date: ' .. os.date('!%Y-%m-%dT%H:%M:%SZ%z', s))
print('date: ' .. os.date('![%Y-%m-%d][%H:%M:%S.' .. string.format("%03.0f", ms) .. ']', s))
