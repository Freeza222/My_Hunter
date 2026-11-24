/*
** EPITECH PROJECT, 2026
** my.h
** File description:
** All the function to use them in different file
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <my/my.h>

    #define WIDTH 1920
    #define HEIGHT 1080
    #define DUCK_FRAME_W 180
    #define DUCK_FRAME_H 128
    #define ANIM_DELAY 0.1
    #define NB_DUCKS 3

typedef struct duck_h {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int direction;
    float speed;
} duck_t;

typedef struct game_dog {
    sfTexture *texture;
    sfSprite *sprite;
} dog_t;

typedef struct sounds {
    sfMusic *music;
    sfSoundBuffer *hit_buf;
    sfSound *hit;
    sfSoundBuffer *over_buf;
    sfSound *game_over;
} sounds_t;

typedef struct assets {
    sfTexture *menu_text;
    sfSprite *menu;
    sfTexture *over_text;
    sfSprite *over;
    sfTexture *heart_text;
    sfSprite *heart;
    sfTexture *cross_text;
    sfSprite *cross;
} assets_t;

typedef struct game_duck {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfClock *move_clock;
    sfTexture *bg_text;
    sfSprite *bg;
    duck_t duck[NB_DUCKS];
    dog_t dog;
    sfFont *font;
    sfText *score_text;
    int live;
    sounds_t sounds;
    assets_t assets;
    int score;
    int in_menu;
    int game_over;
} game_t;

int init_game(game_t *game);
int init_window(game_t *game);
int init_duck(duck_t *duck);
int init_dog(dog_t *dog_hunt);
int init_cross(game_t *game);
int init_score(game_t *game);
int init_sound(game_t *game);
int init_menu(game_t *game);
int init_heart(game_t *game);
int event_game(game_t *game);
void check_clic(game_t *game, int x, int y);
int update_sheet(game_t *game);
int draw_heart(game_t *game);
int draw_game(game_t *game);
void menu_click(game_t *game, int x, int y);
int move_duck(game_t *game);
void reset_duck(duck_t *duck, int score);
int destroy_game(game_t *game);
int move_mouse(game_t *game);
int update_score(game_t *game);

#endif
