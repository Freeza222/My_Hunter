/*
** EPITECH PROJECT, 2026
** init assets
** File description:
** to initialize all the assets we need in the game
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

int init_menu(game_t *game)
{
    game->in_menu = 1;
    game->assets.menu_text = sfTexture_createFromFile("img/menu.png", NULL);
    game->assets.menu = sfSprite_create();
    game->assets.over_text = sfTexture_createFromFile("img/gameover.png", NULL);
    game->assets.over = sfSprite_create();
    if (!game->assets.menu || !game->assets.menu_text || !game->assets.over_text
        || !game->assets.over)
        return 84;
    sfSprite_setTexture(game->assets.over, game->assets.over_text, sfTrue);
    sfSprite_setTexture(game->assets.menu, game->assets.menu_text, sfTrue);
    return 0;
}

int init_sound(game_t *game)
{
    game->sounds.music = sfMusic_createFromFile("sound/zelda.ogg");
    game->sounds.hit_buf = sfSoundBuffer_createFromFile("sound/death.wav");
    game->sounds.over_buf = sfSoundBuffer_createFromFile("sound/over.ogg");
    game->sounds.game_over = sfSound_create();
    game->sounds.hit = sfSound_create();
    if (!game->sounds.hit_buf || !game->sounds.hit || !game->sounds.music)
        return 84;
    sfMusic_setLoop(game->sounds.music, sfTrue);
    sfMusic_play(game->sounds.music);
    sfMusic_setVolume(game->sounds.music, 40);
    sfSound_setBuffer(game->sounds.game_over, game->sounds.over_buf);
    sfSound_setBuffer(game->sounds.hit, game->sounds.hit_buf);
    sfSound_setVolume(game->sounds.game_over, 30);
    sfSound_setVolume(game->sounds.hit, 30);
    return 0;
}

int init_score(game_t *game)
{
    game->font = sfFont_createFromFile("font/score2.ttf");
    game->score_text = sfText_create();
    if (!game->font || !game->score_text)
        return 84;
    sfText_setFont(game->score_text, game->font);
    sfText_setCharacterSize(game->score_text, 50);
    sfText_setColor(game->score_text, sfWhite);
    sfText_setPosition(game->score_text, (sfVector2f){60, 20});
    update_score(game);
    return 0;
}

int init_cross(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->assets.cross_text = sfTexture_createFromFile("img/crosshair.png",
        NULL);
    game->assets.cross = sfSprite_create();
    if (!game->assets.cross || !game->assets.cross_text)
        return 84;
    sfSprite_setTexture(game->assets.cross, game->assets.cross_text, sfTrue);
    sfSprite_setOrigin(game->assets.cross, (sfVector2f){31.5, 31.5});
    return 0;
}

int init_heart(game_t *game)
{
    game->assets.heart_text = sfTexture_createFromFile("img/heart.png", NULL);
    game->assets.heart = sfSprite_create();
    if (!game->assets.heart || !game->assets.heart_text)
        return 84;
    sfSprite_setTexture(game->assets.heart, game->assets.heart_text, sfTrue);
    return 0;
}
