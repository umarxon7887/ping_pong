#include <ncurses.h>

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

Game init_game(void) {
    Game game;

    game.left_y = HEIGHT / 2 - 1;
    game.right_y = HEIGHT / 2 - 1;
    game.ball_x = WIDTH / 2;
    game.ball_y = HEIGHT / 2;
    game.ball_dx = 1;
    game.ball_dy = 1;
    game.left_score = 0;
    game.right_score = 0;

    return game;
}

void draw_field(Game game) {
    int y;
    int x;

    clear();

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            char symbol = ' ';

            if (y == 0 || y == HEIGHT - 1)
                symbol = '-';
            else if (x == 0 || x == WIDTH - 1)
                symbol = '|';
            else if (x == WIDTH / 2)
                symbol = ':';

            if (x == 2 && y >= game.left_y && y < game.left_y + PADDLE_SIZE) symbol = '|';

            if (x == WIDTH - 3 && y >= game.right_y && y < game.right_y + PADDLE_SIZE) symbol = '|';

            if (x == game.ball_x && y == game.ball_y) symbol = 'O';

            mvaddch(y, x, symbol);
        }
    }

    mvprintw(HEIGHT - 1, 24, "%d : %d", game.left_score, game.right_score);
    refresh();
}

int move_paddle(int position, int direction) {
    int next = position + direction;

    if (next < 1) next = 1;
    if (next > HEIGHT - PADDLE_SIZE - 1) next = HEIGHT - PADDLE_SIZE - 1;

    return next;
}

Game process_input(Game game, int key) {
    if (key == 'a' || key == 'A')
        game.left_y = move_paddle(game.left_y, -1);
    else if (key == 'z' || key == 'Z')
        game.left_y = move_paddle(game.left_y, 1);
    else if (key == 'k' || key == 'K')
        game.right_y = move_paddle(game.right_y, -1);
    else if (key == 'm' || key == 'M')
        game.right_y = move_paddle(game.right_y, 1);

    return game;
}

int paddle_hit(Game game, int next_x, int next_y) {
    int hit = 0;

    if (next_x == 3 && next_y >= game.left_y && next_y < game.left_y + PADDLE_SIZE) hit = 1;

    if (next_x == WIDTH - 4 && next_y >= game.right_y && next_y < game.right_y + PADDLE_SIZE) hit = 1;

    return hit;
}

Game move_ball(Game game) {
    int next_x = game.ball_x + game.ball_dx;
    int next_y = game.ball_y + game.ball_dy;

    if (next_y <= 1 || next_y >= HEIGHT - 2) {
        game.ball_dy = -game.ball_dy;
        next_y = game.ball_y + game.ball_dy;
    }

    if (paddle_hit(game, next_x, next_y)) game.ball_dx = -game.ball_dx;

    game.ball_x += game.ball_dx;
    game.ball_y += game.ball_dy;

    return game;
}

int check_goal(Game game) {
    int goal = 0;

    if (game.ball_x <= 0)
        goal = 2;
    else if (game.ball_x >= WIDTH - 1)
        goal = 1;

    return goal;
}

Game reset_ball(Game game) {
    game.ball_x = WIDTH / 2;
    game.ball_y = HEIGHT / 2;
    game.ball_dx = -game.ball_dx;
    game.ball_dy = 1;

    return game;
}

Game update_score(Game game, int goal) {
    if (goal == 1)
        game.left_score++;
    else if (goal == 2)
        game.right_score++;

    if (goal != 0) game = reset_ball(game);

    return game;
}

int game_over(Game game) {
    int result = 0;

    if (game.left_score >= WIN_SCORE || game.right_score >= WIN_SCORE) result = 1;

    return result;
}

void print_winner(Game game) {
    clear();

    if (game.left_score >= WIN_SCORE)
        mvprintw(HEIGHT / 2, WIDTH / 2 - 10, "PLAYER 1 WINS!");
    else
        mvprintw(HEIGHT / 2, WIDTH / 2 - 10, "PLAYER 2 WINS!");

    mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 5, "%d : %d", game.left_score, game.right_score);
    refresh();
}

int main(void) {
    Game game = init_game();
    int key;
    int goal;

    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    while (!game_over(game)) {
        key = getch();

        if (key == 'q' || key == 'Q') break;

        game = process_input(game, key);
        game = move_ball(game);

        goal = check_goal(game);
        game = update_score(game, goal);

        draw_field(game);
        napms(100);
    }

    print_winner(game);
    napms(2000);
    endwin();

    return 0;
}
