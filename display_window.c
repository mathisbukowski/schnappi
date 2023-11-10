/*
** EPITECH PROJECT, 2023
** bs_csfml
** File description:
** display_window.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

int music_play(sfMusic* music)
{
    music = sfMusic_createFromFile("music.ogg");
    if (!music)
        exit(EXIT_FAILURE);
}

int display_window(void)
{
    sfEvent event;
    sfRenderWindow* window;
    sfVideoMode mode = {2880, 1800, 32};
    sfMusic* music = music_play(music);
    // DECOR
    sfImage* image_decor = sfImage_createFromFile("4253805.jpg");
    sfTexture* texture_decor = sfTexture_createFromImage(image_decor, NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_decor, sfTrue);
    // Perso
    sfImage* image_perso = sfImage_createFromFile("oklm.png");
    sfTexture* texture_perso = sfTexture_createFromImage(image_perso, NULL);
    sfSprite* character = sfSprite_create();
    sfSprite_setTexture(character, texture_perso, sfTrue);
    sfVector2f characterPosition = {400.0f, 300.0f};
    sfSprite_setPosition(character, characterPosition);

    window = sfRenderWindow_create(mode, "Schnappi Das Kleine Krokodil",
    sfResize | sfClose, NULL);

    sfMusic_play(music);
    if (!window)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        float speed = 2.0f;
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            characterPosition.x -= speed;
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            characterPosition.x += speed;
        }
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            characterPosition.y -= speed;
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            characterPosition.y += speed;
        }
        sfSprite_setPosition(character, characterPosition);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, character, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfSprite_destroy(character);
    sfRenderWindow_destroy(window);

    return 0;
}

int main(void)
{
    display_window();
}
