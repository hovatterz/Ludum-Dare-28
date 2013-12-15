local ld28 = {}

ld28.move_directions = {}
ld28.move_directions[0] = { action=action.move_west, x=-1, y=0 }
ld28.move_directions[1] = { action=action.move_south, x=0, y=1 }
ld28.move_directions[2] = { action=action.move_north, x=0, y=-1 }
ld28.move_directions[3] = { action=action.move_east, x=1, y=0 }
ld28.move_directions[4] = { action=action.move_northwest, x=-1, y=-1 }
ld28.move_directions[5] = { action=action.move_northeast, x=1, y=-1 }
ld28.move_directions[6] = { action=action.move_southwest, x=-1, y=1 }
ld28.move_directions[7] = { action=action.move_southeast, x=1, y=1 }

function ld28.can_move(dungeon, spatial, direction)
    local new_x = spatial:x() + direction.x
    local new_y = spatial:y() + direction.y
    local tile = dungeon:tile_at(new_x, new_y)
    if (tile ~= nil and tile:passable() == true) then
        return true
    end

    return false
end

return ld28
