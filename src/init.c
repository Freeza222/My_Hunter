/*
** EPITECH PROJECT, 2026
** Init
** File description:
** File to initialize everything for the game
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

static int init_all(game_t *game)
{
    init_menu(game);
    init_cross(game);
    init_sound(game);
    init_score(game);
    init_heart(game);
    init_dog(&game->dog);
    return 0;
}

int init_game(game_t *game)
{
    srand(time(NULL));
    game->bg_text = sfTexture_createFromFile("img/duck_futur.png", NULL);
    game->bg = sfSprite_create();
    game->clock = sfClock_create();
    game->move_clock = sfClock_create();
    game->live = 3;
    if (!game->bg || !game->bg_text || !game->clock || !game->move_clock)
        return 84;
    if (init_window(game) == 84)
        return 84;
    sfSprite_setTexture(game->bg, game->bg_text, sfTrue);
    init_all(game);
    for (int i = 0; i < NB_DUCKS; i++) {
        if ((init_duck(&game->duck[i])) == 84)
            return 84;
    }
    return 0;
}

int init_window(game_t *game)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, "my_hunter", sfClose, NULL);
    if (!game->window)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return 0;
}
