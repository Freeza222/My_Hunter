/*
** EPITECH PROJECT, 2026
** Draw
** File description:
** to draw all the necessary ressource
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"
#include <stdlib.h>

int draw_heart(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(game->assets.heart,
            (sfVector2f){250 + i * 65, 30});
        if (i < game->live)
            sfSprite_setColor(game->assets.heart, sfWhite);
        else
            sfSprite_setColor(game->assets.heart, sfColor_fromRGBA(255, 255,
                    255, 60));
        sfRenderWindow_drawSprite(game->window, game->assets.heart, NULL);
    }
    return 0;
}

static int draw_menu(game_t *game)
{
    if (game->in_menu) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->assets.menu, NULL);
        sfRenderWindow_drawSprite(game->window, game->assets.cross, NULL);
        sfRenderWindow_display(game->window);
        return 1;
    }
    return 0;
}

int draw_game(game_t *game)
{
    if (draw_menu(game))
        return 0;
    sfRenderWindow_clear(game->window, sfWhite);
    sfRenderWindow_drawSprite(game->window, game->bg, NULL);
    for (int i = 0; i < NB_DUCKS; i++)
        sfRenderWindow_drawSprite(game->window, game->duck[i].sprite, NULL);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    sfRenderWindow_drawSprite(game->window, game->dog.sprite, NULL);
    if (game->game_over) {
        sfRenderWindow_drawSprite(game->window, game->assets.over, NULL);
        sfRenderWindow_drawText(game->window, game->score_text, NULL);
    }
    sfRenderWindow_drawSprite(game->window, game->assets.cross, NULL);
    draw_heart(game);
    sfRenderWindow_display(game->window);
    return 0;
}
