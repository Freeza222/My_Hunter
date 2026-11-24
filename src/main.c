/*
** EPITECH PROJECT, 2026
** main
** File description:
** main function that assemble every piece
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include "my.h"
#include <string.h>

int print_h(void)
{
    char *help;

    help = "USAGE\n    ./my_hunter [-h]\n\nDESCRIPTION\n    Ducks fly across"
        " the screen: shoot them before they escape!\n    Each duck you hit"
        " gives you one point.\n\nOPTIONS\n    -h    display this help and"
        " quit\n\nCONTROLS\n    Left click    shoot\n"
        "    Escape        quit the game\n";
    write(1, help, strlen(help));
    return 0;
}

static int loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            event_game(game);
        if (!game->in_menu && !game->game_over) {
            update_sheet(game);
            move_duck(game);
        }
        move_mouse(game);
        draw_game(game);
    }
    return 0;
}

int main(int argc, char **argv)
{
    game_t game = {0};

    game.score = 0;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_h();
        return 0;
    }
    if (argc != 1)
        return 84;
    if (init_game(&game) == 84)
        return 84;
    loop(&game);
    destroy_game(&game);
    return 0;
}
