/*
 * Copyright 2012-2015 Falltergeist Developers.
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
#include "../UI/ImageButton.h"

// C++ standard includes
#include <string>

// Falltergeist includes
#include "../Audio/Mixer.h"
#include "../Exception.h"
#include "../Game/Game.h"
#include "../Lua/Script.h"
#include "../ResourceManager.h"

// Third party includes

namespace Falltergeist
{

ImageButton::ImageButton(Type type, int x, int y) : ActiveUI(x, y)
{
    switch (type)
    {
        case Type::SMALL_RED_CIRCLE:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/lilredup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/lilreddn.frm"));
            _downSnd = "sound/sfx/ib1p1xx1.acm";
            _upSnd = "sound/sfx/ib1lu1x1.acm";
            break;
        case Type::BIG_RED_CIRCLE:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/bigredup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/bigreddn.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::MENU_RED_CIRCLE:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/menuup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/menudown.frm"));
            _downSnd = "sound/sfx/nmselec0.acm";
            _upSnd = "sound/sfx/nmselec1.acm";
            break;
        case Type::SKILL_TOGGLE:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/tgskloff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/tgsklon.frm"));
            break;
        case Type::PLUS:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/splsoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/splson.frm"));
            break;
        case Type::MINUS:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/snegoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/snegon.frm"));
            break;
        case Type::LEFT_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/slu.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/sld.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::RIGHT_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/sru.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/srd.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::CHECKBOX:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/prfxout.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/prfxin.frm"));
            _upSnd = "sound/sfx/ib2p1xx1.acm";
            _checkboxMode = true;
            break;
        case Type::PLAYER_NAME:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/nameoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/nameon.frm"));
            break;
        case Type::PLAYER_AGE:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/ageoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/ageon.frm"));
            break;
        case Type::PLAYER_GENDER:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/sexoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/sexon.frm"));
            break;
        case Type::PANEL_INVENTORY:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/invbutup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/invbutdn.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::PANEL_OPTIONS:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/optiup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/optidn.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::PANEL_ATTACK:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/sattkbup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/sattkbdn.frm"));
            _downSnd = "sound/sfx/ib3p1xx1.acm";
            _upSnd = "sound/sfx/ib3lu1x1.acm";
            break;
        case Type::PANEL_MAP:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/mapup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/mapdn.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::PANEL_CHA:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/chaup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/chadn.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::PANEL_PIP:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/pipup.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/pipdn.frm"));
            _downSnd = "sound/sfx/ib2p1xx1.acm";
            _upSnd = "sound/sfx/ib2lu1x1.acm";
            break;
        case Type::OPTIONS_BUTTON:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/opbtnoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/opbtnon.frm"));
            _downSnd = "sound/sfx/ib3p1xx1.acm";
            _upSnd = "sound/sfx/ib3lu1x1.acm";
            break;
        case Type::SKILLDEX_BUTTON:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/skldxoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/skldxon.frm"));
            _downSnd = "sound/sfx/ib2lu1x1.acm";
            _upSnd = "sound/sfx/ib1p1xx1.acm";
            break;
        case Type::INVENTORY_UP_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/invupout.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/invupin.frm"));
            break;
        case Type::INVENTORY_DOWN_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/invdnout.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/invdnin.frm"));
            break;
        case Type::PIPBOY_ALARM_BUTTON:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/alarmout.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/alarmin.frm"));
            break;
        case Type::DIALOG_RED_BUTTON:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_rdbt2.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_rdbt1.frm"));
            break;
        case Type::DIALOG_REVIEW_BUTTON:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_rest1.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_rest2.frm"));
            break;
        case Type::DIALOG_DONE_BUTTON:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_done1.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_done2.frm"));
            break;
        case Type::DIALOG_BIG_UP_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_bgup1.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_bgup2.frm"));
            break;
        case Type::DIALOG_BIG_DOWN_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_bgdn1.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_bgdn2.frm"));
            break;
        case Type::DIALOG_UP_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_up1.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_up2.frm"));
            break;
        case Type::DIALOG_DOWN_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_down1.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/di_down2.frm"));
            break;
        case Type::SMALL_UP_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/uparwoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/uparwon.frm"));
            break;
        case Type::SMALL_DOWN_ARROW:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/dnarwoff.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/dnarwon.frm"));
            break;
        case Type::MAP_HOTSPOT:
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/hotspot1.frm"));
            _textures.push_back(ResourceManager::getInstance()->texture("art/intrface/hotspot2.frm"));
            break;
        default:
            throw Exception("ImageButton::Imagebutton() - wrong button type");
    }
    addEventHandler("mouseleftclick", [this](Event* event){ this->_onLeftButtonClick(dynamic_cast<MouseEvent*>(event)); });
    addEventHandler("mouseleftdown", [this](Event* event){ this->_onLeftButtonDown(dynamic_cast<MouseEvent*>(event)); });
    addEventHandler("mouseout", [this](Event* event){ this->_onMouseOut(dynamic_cast<MouseEvent*>(event)); });
}

ImageButton::~ImageButton()
{
}

void ImageButton::export_to_lua_script(Lua::Script* script)
{
    luabridge::getGlobalNamespace(script->luaState())
        .beginNamespace("game")
            .beginNamespace("ui")
                .deriveClass<ImageButton, ActiveUI>("ImageButton")
                    .addConstructor<void(*)(Type, int, int)>()
                .endClass()
            .endNamespace()
        .endNamespace();
}

Texture* ImageButton::texture() const
{
    if (_checkboxMode && _checked) return _textures.at(1);

    if (_hovered && _leftButtonPressed) return _textures.at(1);

    return _textures.at(0);
}

void ImageButton::_onLeftButtonClick(MouseEvent* event)
{
    auto sender = dynamic_cast<ImageButton*>(event->emitter());
    if (sender->_checkboxMode)
    {
        sender->_checked = !sender->_checked;
    }
    if (!sender->_upSnd.empty())
    {
        Game::getInstance()->mixer()->playACMSound(sender->_upSnd);
    }
}

void ImageButton::_onLeftButtonDown(MouseEvent* event)
{
    auto sender = dynamic_cast<ImageButton*>(event->emitter());
    if (!sender->_downSnd.empty())
    {
        Game::getInstance()->mixer()->playACMSound(sender->_downSnd);
    }
}


void ImageButton::_onMouseOut(MouseEvent* event)
{
    auto sender = dynamic_cast<ImageButton*>(event->emitter());
    if (_leftButtonPressed && !sender->_upSnd.empty())
    {
        Game::getInstance()->mixer()->playACMSound(sender->_upSnd);
    }
}


bool ImageButton::checked()
{
    return _checked;
}

void ImageButton::setChecked(bool _checked)
{
    this->_checked = _checked;
}

}
