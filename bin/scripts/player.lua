-- player.lua
local ld28 = require "scripts/ld28"

local keymap = {}
keymap["h"] = function() return move(ld28.move_directions[0]) end
keymap["j"] = function() return move(ld28.move_directions[1]) end
keymap["k"] = function() return move(ld28.move_directions[2]) end
keymap["l"] = function() return move(ld28.move_directions[3]) end
keymap["y"] = function() return move(ld28.move_directions[4]) end
keymap["u"] = function() return move(ld28.move_directions[5]) end
keymap["b"] = function() return move(ld28.move_directions[6]) end
keymap["n"] = function() return move(ld28.move_directions[7]) end
keymap["."] = function() return true end

function move(direction)
    if ld28.can_move(dungeon, spatial, direction) then
        turn_taker:set_action(direction.action)
        return true
    end

    return false
end

function handle_input(input)
    local action = keymap[input]
    if action == nil then
        return false
    end

    return action()
end

function think()
    return action.move_west
end
