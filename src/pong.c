#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define WIN_SCORE 21

typedef struct {
    int left_y;
    int right_y;
    int ball_x;
    int ball_y;
    int ball_dx;
    int ball_dy;
    int left_score;
    int right_score;
} Game;

void init_game(Game *game) {
    game->left_y = HEIGHT / 2 - 1;
    game->right_y = HEIGHT / 2 - 1;
    game->ball_x = WIDTH / 2;
    game->ball_y = HEIGHT / 2;
    game->ball_dx = 1;
    game->ball_dy = 1;
    game->left_score = 0;
    game->right_score = 0;
}

void print_field(const Game *game) {
    int y, x;

    printf("\033[H\033[J");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            char c = ' ';

            if (x == 0 || x == WIDTH - 1) c = '|';

            if (y == 0 || y == HEIGHT - 1) c = '-';

            if (x == WIDTH / 2 && y > 0 && y < HEIGHT - 1) c = ':';

            if (x == 2 && y >= game->left_y && y < game->left_y + PADDLE_SIZE) c = '|';

            if (x == WIDTH - 3 && y >= game->right_y && y < game->right_y + PADDLE_SIZE) c = '|';

            if (x == game->ball_x && y == game->ball_y) c = 'O';

            putchar(c);
        }
        putchar('\n');
    }

    printf("Player 1: %d    Player 2: %d\n", game->left_score, game->right_score);
}

void move_paddle(int *y, int direction) {
    int next = *y + direction;

    if (next >= 1 && next <= HEIGHT - PADDLE_SIZE - 1) *y = next;
}

void move_ball(Game *game) {
    int next_x = game->ball_x + game->ball_dx;
    int next_y = game->ball_y + game->ball_dy;

    if (next_y <= 1 || next_y >= HEIGHT - 2) {
        game->ball_dy = -game->ball_dy;
        next_y = game->ball_y + game->ball_dy;
    }

    if (next_x == 3 && next_y >= game->left_y && next_y < game->left_y + PADDLE_SIZE) game->ball_dx = 1;

    if (next_x == WIDTH - 4 && next_y >= game->right_y && next_y < game->right_y + PADDLE_SIZE)
        game->ball_dx = -1;

    game->ball_x += game->ball_dx;
    game->ball_y += game->ball_dy;
}

int check_goal(Game *game) {
    int goal = 0;

    if (game->ball_x <= 0) {
        game->right_score++;
        goal = 1;
    } else if (game->ball_x >= WIDTH - 1) {
        game->left_score++;
        goal = 1;
    }

    return goal;
}

void reset_ball(Game *game) {
    game->ball_x = WIDTH / 2;
    game->ball_y = HEIGHT / 2;
    game->ball_dx = -game->ball_dx;
    game->ball_dy = 1;
}

int game_over(const Game *game) {
    int result = 0;

    if (game->left_score >= WIN_SCORE || game->right_score >= WIN_SCORE) result = 1;

    return result;
}

void print_winner(const Game *game) {
    if (game->left_score >= WIN_SCORE)
        printf("Player 1 wins!\n");
    else
        printf("Player 2 wins!\n");
}

int read_command(void) {
    int command = getchar();
    int extra = command;

    while (extra != '\n' && extra != EOF) extra = getchar();

    return command;
}

void process_command(Game *game, int command) {
    if (command == 'a' || command == 'A')
        move_paddle(&game->left_y, -1);
    else if (command == 'z' || command == 'Z')
        move_paddle(&game->left_y, 1);
    else if (command == 'k' || command == 'K')
        move_paddle(&game->right_y, -1);
    else if (command == 'm' || command == 'M')
        move_paddle(&game->right_y, 1);

    move_ball(game);
}

int main(void) {
    Game game;
    int command = 0;

    init_game(&game);

    while (!game_over(&game)) {
        print_field(&game);

        command = read_command();

        if (command == ' ' || command == 'a' || command == 'A' || command == 'z' || command == 'Z' ||
            command == 'k' || command == 'K' || command == 'm' || command == 'M') {
            process_command(&game, command);

            if (check_goal(&game)) reset_ball(&game);
        }
    }

    print_field(&game);
    print_winner(&game);

    return 0;
}
