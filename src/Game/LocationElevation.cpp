/*
 * Copyright 2012-2016 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// Related headers
#include "../Game/LocationElevation.h"

// C++ standard includes

// Falltergeist includes

// Third party includes

namespace Falltergeist
{
    namespace Game
    {
        LocationElevation::LocationElevation()
        {
        }

        LocationElevation::~LocationElevation()
        {
        }

        /**
         * @brief Returns if player can rest on this elevation
         * @return bool
         */
        bool LocationElevation::canRestHere() const
        {
            return _canRestHere;
        }

        /**
         * @brief Sets if player can rest on this elevation
         * @param[in] value
         */
        void LocationElevation::setCanRestHere(bool value)
        {
            _canRestHere = value;
        }

        /**
         * @brief Returns array of ids of floor tiles
         * @return Floor tiles
         */
        std::vector<unsigned>* LocationElevation::floorTiles()
        {
            return &_floorTiles;
        }

        /**
         * @brief Returns array of ids of roof tiles
         * @return Roof tiles
         */
        std::vector<unsigned>* LocationElevation::roofTiles()
        {
            return &_roofTiles;
        }

        /**
         * @brief Returns array of game objects
         * @return Game objects
         */
        std::vector<Game::Object*>* LocationElevation::objects()
        {
            return &_objects;
        }
    }
}