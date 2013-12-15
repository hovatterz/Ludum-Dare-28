local move_directions = {}
move_directions[0] = { action=action.move_north, x=0, y=-1 }
move_directions[1] = { action=action.move_south, x=0, y=1 }
move_directions[2] = { action=action.move_west, x=-1, y=0 }
move_directions[3] = { action=action.move_east, x=1, y=0 }
move_directions[4] = { action=action.move_northwest, x=-1, y=-1 }
move_directions[5] = { action=action.move_northeast, x=1, y=-1 }
move_directions[6] = { action=action.move_southwest, x=-1, y=1 }
move_directions[7] = { action=action.move_southeast, x=1, y=1 }

function think()
    local turn_taken = false
    local direction = nil

    while (turn_taken == false) do
        direction = move_directions[math.random(0, 7)]
        local new_x = spatial:x() + direction.x
        local new_y = spatial:y() + direction.y
        local tile = dungeon:tile_at(new_x, new_y)
        if (tile ~= nil and tile:passable() == true) then
            turn_taken = true
        end
    end

    turn_taker:set_action(direction.action)
end
