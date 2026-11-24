/*
** EPITECH PROJECT, 2026
** update
** File description:
** To create movement in the game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"
#include <stdlib.h>

static int loop_many_ducks(game_t *game)
{
    for (int i = 0; i < NB_DUCKS; i++) {
        game->duck[i].rect.left += DUCK_FRAME_W;
        if (game->duck[i].rect.left >= 720) {
            game->duck[i].rect.left = 0;
        }
        sfSprite_setTextureRect(game->duck[i].sprite, game->duck[i].rect);
    }
    return 0;
}

int update_sheet(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > ANIM_DELAY) {
        loop_many_ducks(game);
        sfClock_restart(game->clock);
    }
    return 0;
}

int move_mouse(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    sfSprite_setPosition(game->assets.cross, (sfVector2f){mouse.x, mouse.y});
    return 0;
}

static int move_one_duck(game_t *game, duck_t *duck, float seconds)
{
    float x = 0;
    float frame = (duck->speed * seconds) * duck->direction;

    sfSprite_move(duck->sprite, (sfVector2f){frame, 0});
    x = sfSprite_getPosition(duck->sprite).x;
    if ((sfSprite_getPosition(duck->sprite).x > WIDTH
            && duck->direction == 1) ||
        (x < 0 && duck->direction == -1)) {
        game->live--;
        if (game->live <= 0) {
            game->game_over = 1;
            sfMusic_stop(game->sounds.music);
            sfSound_play(game->sounds.game_over);
        }
        reset_duck(duck, game->score);
    }
    return 0;
}

int move_duck(game_t *game)
{
    float seconds = sfTime_asSeconds(sfClock_restart(game->move_clock));

    for (int i = 0; i < NB_DUCKS; i++) {
        move_one_duck(game, &game->duck[i], seconds);
    }
    return 0;
}

static void choose_side(duck_t *duck)
{
    int y = rand() % 2;

    if (y == 0)
        duck->direction = 1;
    else
        duck->direction = -1;
    sfSprite_setScale(duck->sprite, (sfVector2f){duck->direction, 1});
}

void reset_duck(duck_t *duck, int score)
{
    float y = rand() % (HEIGHT - 300 + 1);
    int bonus = score * 4;

    if (bonus > 500)
        bonus = 500;
    duck->speed = 500 + rand() % 400 + bonus;
    choose_side(duck);
    if (duck->direction == 1)
        sfSprite_setPosition(duck->sprite, (sfVector2f){-180, y});
    else
        sfSprite_setPosition(duck->sprite, (sfVector2f){2048, y});
}

int update_score(game_t *game)
{
    char score[50] = "Score :";
    char numbers[15] = {0};
    int n = game->score;
    int i = 0;

    while (n > 0 || i == 0) {
        numbers[i] = '0' + n % 10;
        n /= 10;
        i++;
    }
    my_revstr(numbers);
    my_strcat(score, numbers);
    sfText_setString(game->score_text, score);
    return 0;
}
