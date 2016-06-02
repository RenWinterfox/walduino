#include <Arduboy.h>

Arduboy arduboy;

// Vars
byte circle_x = 0;
byte circle_y = 0;
byte circle_r = 8;
byte circle_spd = 2;
byte xrange_lo = circle_x - circle_r;
byte xrange_hi = circle_x + circle_r;
byte yrange_lo = circle_y - circle_r;
byte yrange_hi = circle_y + circle_r;
byte guy_x = random(127);
byte guy_y = random(63);
word score = 0;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;
    
  // Input
  if (arduboy.pressed(RIGHT_BUTTON))
    if (circle_x < 127)
      circle_x += circle_spd;
  if (arduboy.pressed(LEFT_BUTTON))
    if (circle_x > 0)
      circle_x -= circle_spd;
  if (arduboy.pressed(DOWN_BUTTON))
    if (circle_y < 63)
      circle_y += circle_spd;
  if (arduboy.pressed(UP_BUTTON))
    if (circle_y > 0)
      circle_y -= circle_spd;
  if (arduboy.pressed(B_BUTTON)){
    if ( guy_x < xrange_hi and guy_x > xrange_lo){
      if (guy_y < yrange_hi and guy_y > yrange_lo) {
        guy_x = random(127);
        guy_y = random(63);
        score ++;
      }
    }
  }
  if (arduboy.pressed(A_BUTTON)){
    Serial.println(xrange_lo);
    Serial.println(xrange_hi); 
  }

  // Update search range
  xrange_lo = circle_x - circle_r;
  xrange_hi = circle_x + circle_r;
  yrange_lo = circle_y - circle_r;
  yrange_hi = circle_y + circle_r;
  
  // Draw to screen buffer
  arduboy.clear();
  arduboy.fillCircle(circle_x, circle_y, circle_r, WHITE);
  arduboy.fillRect(guy_x,guy_y,2,4, BLACK);
  arduboy.setCursor(0,0);
  arduboy.print(score);

  // Draw screen buffer to display
  arduboy.display();
}
