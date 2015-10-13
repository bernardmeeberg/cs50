/**
 * breakout.c
 *
 * Bernard van de Meeberg
 * bernardmeeberg@gmail.com
 *
 * Implementation of a breakout game
 * cs50x fall 2014 pset 3
 */

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// define margin and spce between lines
#define MARGIN 50
#define LINESPACE 5

// define paddle size
#define PAD_WIDTH 50
#define PAD_HEIGHT 10

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;
    
    // define the velocity of the ball
    float BallVelX = 0;
    float BallVelY = 0;

    // number of points initially
    int points = 0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // update our scoreboard
        updateScoreboard(window, label, points);
        
        // check for some mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        // if an event is seen
        if (event != NULL)
        {
            // if movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // let the paddle follow the mouse
                double x = getX(event) - getWidth(paddle) / 2;
                if (x <= 0)
                {
                    x = 0;
                }
                else if (x >= WIDTH - PAD_WIDTH)
                {
                    x = WIDTH - PAD_WIDTH;
                }
                setLocation(paddle, x, HEIGHT - MARGIN);
            }
            
            // if click
            if (getEventType(event) == MOUSE_CLICKED && getX(ball) == WIDTH / 2 - RADIUS && getY(ball) == HEIGHT / 2 - RADIUS)
            {
                BallVelX = 0.1 * drand48();
                BallVelY = 0.2 * drand48();
            }
        }
        
        // move the ball
        move(ball, BallVelX, BallVelY);
        
        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            BallVelX = -BallVelX;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            BallVelX = -BallVelX;
        }
        
        // bounce off lower edge of window
        else if (getY(ball) >= HEIGHT - RADIUS)
        {
            // wait for click
            lives -= 1;
            removeGWindow(window, ball);
            ball = initBall(window);
            paddle = initPaddle(window);
            if (lives >= 0)
            {
                waitForClick();
            }
            else
            {
                break;
            }
        }   

        // bounce off upper edge of window
        else if (getY(ball) <= 0)
        {
            BallVelY = -BallVelY;
        }         
        
        // check for collision 
        GObject object = detectCollision(window, ball);
        if(object != NULL)
        {
            if (object == paddle)
            {
                if (BallVelY > 0)
                {
                    BallVelY = -BallVelY;
                }
            }            
            else if (strcmp(getType(object), "GRect") == 0)
            {  
                removeGWindow(window, object);
                points += 1;
                bricks -= 1;
                BallVelY = -BallVelY; 
            }
        }
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // let's use some fancy colors
    string colors[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE"};
    
    // for each row
    for (int i = 0; i < ROWS; i++)
    {
        // for each col
        for (int j = 0; j < COLS; j++)
        {
            // init a new brick
            // block is placed at: x = j * space per brick, y = margin + 2.5 * linespace * number of row
            GRect newrect = newGRect(j * WIDTH / COLS, MARGIN + 2.5 * LINESPACE * i, WIDTH / COLS - LINESPACE, 1.5 * LINESPACE);
            add(window, newrect);
            setColor(newrect, colors[i]);
            setFilled(newrect, true);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // let's place the ball exactly in the middle
    GOval ball = newGOval(WIDTH / 2 - RADIUS, HEIGHT / 2 - RADIUS, RADIUS, RADIUS);
    add(window, ball);
    setColor(ball, "Black");
    setFilled(ball, true);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // let's place the paddle in the south region
    GRect paddle = newGRect(WIDTH / 2 - (PAD_WIDTH / 2), HEIGHT - MARGIN, PAD_WIDTH, PAD_HEIGHT);
    add(window, paddle);
    setColor(paddle, "Black");
    setFilled(paddle, true);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    setLabel(label, "0");
    add(window, label);
    
    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
        // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x + 2, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
