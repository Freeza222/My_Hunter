/*
** EPITECH PROJECT, 2026
** Init entities
** File description:
** to initialize all the characters in the game
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

int init_duck(duck_t *duck)
{
    duck->texture = sfTexture_createFromFile("img/canard_4frames.png", NULL);
    duck->sprite = sfSprite_create();
    if (!duck->sprite || !duck->texture)
        return 84;
    duck->speed = 690;
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    duck->rect.left = 0;
    duck->rect.top = 0;
    duck->rect.height = DUCK_FRAME_H;
    duck->rect.width = DUCK_FRAME_W;
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    reset_duck(duck, 0);
    return 0;
}

int init_dog(dog_t *dog_hunt)
{
    dog_hunt->texture = sfTexture_createFromFile("img/chien.png", NULL);
    dog_hunt->sprite = sfSprite_create();
    if (!dog_hunt->texture || !dog_hunt->sprite)
        return 84;
    sfSprite_setTexture(dog_hunt->sprite, dog_hunt->texture, sfTrue);
    sfSprite_setOrigin(dog_hunt->sprite, (sfVector2f){156, 272});
    sfSprite_setScale(dog_hunt->sprite, (sfVector2f){1.25, 1.25});
    sfSprite_setPosition(dog_hunt->sprite, (sfVector2f){WIDTH / 2, HEIGHT});
    return 0;
}
