/*
** EPITECH PROJECT, 2026
** Event
** File description:
** All the function to handle the action of the player
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

static int restart_game(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyR
        && game->game_over) {
        sfMusic_play(game->sounds.music);
        game->game_over = 0;
        game->live = 3;
        game->score = 0;
        update_score(game);
        for (int i = 0; i < NB_DUCKS; i++)
            reset_duck(&game->duck[i], 0);
        sfClock_restart(game->move_clock);
    }
    return 0;
}

int event_game(game_t *game)
{
    if ((game->event.type == sfEvtKeyPressed
            && game->event.key.code == sfKeyEscape)
        || (game->event.type == sfEvtClosed))
        sfRenderWindow_close(game->window);
    restart_game(game);
    if (game->event.type == sfEvtMouseButtonPressed
        && game->event.mouseButton.button == sfMouseLeft) {
        if (game->in_menu)
            menu_click(game, game->event.mouseButton.x,
                game->event.mouseButton.y);
        else
            check_clic(game, game->event.mouseButton.x,
                game->event.mouseButton.y);
    }
    return 0;
}

void check_clic(game_t *game, int x, int y)
{
    sfFloatRect rect;

    for (int i = 0; i < NB_DUCKS; i++) {
        rect = sfSprite_getGlobalBounds(game->duck[i].sprite);
        if (sfFloatRect_contains(&rect, x, y)) {
            game->score += 1;
            update_score(game);
            sfSound_play(game->sounds.hit);
            reset_duck(&game->duck[i], game->score);
            return;
        }
    }
}

void menu_click(game_t *game, int x, int y)
{
    sfFloatRect play = {680, 500, 560, 110};
    sfFloatRect quit = {680, 646, 560, 110};

    if (sfFloatRect_contains(&play, x, y)) {
        game->in_menu = 0;
        sfClock_restart(game->move_clock);
    }
    if (sfFloatRect_contains(&quit, x, y)) {
        sfRenderWindow_close(game->window);
    }
}
