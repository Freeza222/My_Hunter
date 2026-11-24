/*
** EPITECH PROJECT, 2026
** Destroy
** File description:
** Destroy everything initialize
*/

#include "my.h"
#include <SFML/Graphics.h>

static int destroy_sprite(game_t *game)
{
    sfSprite_destroy(game->assets.cross);
    sfSprite_destroy(game->dog.sprite);
    sfSprite_destroy(game->assets.heart);
    sfSprite_destroy(game->assets.menu);
    sfSprite_destroy(game->assets.over);
    sfSprite_destroy(game->bg);
    return 0;
}

static int destroy_texture(game_t *game)
{
    sfTexture_destroy(game->assets.cross_text);
    sfTexture_destroy(game->dog.texture);
    sfFont_destroy(game->font);
    sfTexture_destroy(game->assets.heart_text);
    sfTexture_destroy(game->assets.menu_text);
    sfTexture_destroy(game->assets.over_text);
    sfTexture_destroy(game->bg_text);
    return 0;
}

int destroy_game(game_t *game)
{
    sfClock_destroy(game->clock);
    sfClock_destroy(game->move_clock);
    for (int i = 0; i < NB_DUCKS; i++) {
        sfTexture_destroy(game->duck[i].texture);
        sfSprite_destroy(game->duck[i].sprite);
    }
    sfSoundBuffer_destroy(game->sounds.hit_buf);
    sfMusic_destroy(game->sounds.music);
    sfSound_destroy(game->sounds.hit);
    sfText_destroy(game->score_text);
    destroy_texture(game);
    destroy_sprite(game);
    sfRenderWindow_destroy(game->window);
    return 0;
}
