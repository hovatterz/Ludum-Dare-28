-- goblin.lua
local ld28 = require "scripts/ld28"

function think()
    local turn_taken = false
    local direction = nil

    while (turn_taken == false) do
        direction = ld28.move_directions[math.random(0, 7)]
        turn_taken = ld28.can_move(dungeon, spatial, direction)
    end

    turn_taker:set_action(direction.action)
end
