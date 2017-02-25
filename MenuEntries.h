#define MENUENTRIES 4
struct menuItem{
  byte x;
  byte y;
  byte width;
  int to;
};
struct menuText{
  char text[3][21];
};
struct menuProperty{
  struct menuText menuText;
  byte id;
  byte menuLength;
  struct menuItem menuItems[10];
};

menuProperty menuProperties[MENUENTRIES] = {
//"12345678901234567890",
// Entry screen
  "   DMX Controller   ",
  " Lamps  Color  Prog ",
  " Test               ",
  1,   4, {
    //X,Y, to
    { 0,1,5,  2},  // Lamps
    { 7,1,5,  3},  // Color
    {14,1,4,  0},  // Prog
    { 0,2,4,  4}}, // Test
//
//"12345678901234567890",
  " < Lamp selection   ",
  " 1 2 3 4 5 6 7 8 <- ",
  "          ",
  2, 10, {
    {0,0,1,  1}, // Back
    {0,1,1,  0},
    {2,1,1,  0},
    {4,1,1,  0},
    {6,1,1,  0},
    {8,1,1,  0},
    {10,1,1,  0},
    {12,1,1,  0},
    {14,1,1,  0},
    {16,1,2,  1}},
//
//"12345678901234567890",
  " <  Color chooser   ",
  " 1 2 3 4 5 6 7 8 <- ",
  "          ",
  3, 10, {
    {0,0,2,  1}, // Back
    {0,1,1,  0},
    {2,1,1,  0},
    {4,1,1,  0},
    {6,1,1,  0},
    {8,1,1,  0},
    {10,1,1,  0},
    {12,1,1,  0},
    {14,1,1,  0},
    {16,1,2,  1}},
//"12345678901234567890",
  " <   DMX Tester     ",
  " Addr:     Channels ",
  "                    ",
  4, 3, {
    {0,0,2,  1}, // Back
    {0,1,5, -1}, // Address selection
    {10,1,8,-2}} // channel carousel
};
