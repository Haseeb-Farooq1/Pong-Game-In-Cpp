#include <iostream>
#include <Windows.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")
#define BLACK 0
#define BROWN 6
#define WHITE 15
#define GREEN 2
#define RED 4
#define LBLUE 9
int bgc=0;

using namespace std;

void SetClr(int tcl, int bcl)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
}
void BackgroundSelect()
{
    cout << "Enter the background colour" << endl;
    cout << "  1.  2.  3.  4.  5." << endl;
    char s = -37;
    SetClr(4,0);
    cout << "  " << s << "   ";
    SetClr(9, 0);
    cout << s << "   ";
    SetClr(15, 0);
    cout << s << "   ";
    SetClr(6, 0);
    cout << s << "   ";
    SetClr(2, 0);
    cout << s << "   " << endl;
    SetClr(15, 0);
    cin >> bgc;
    system("CLS");
}
void Background()
{
    if (bgc == 1)
    {
        SetClr(0, 4);
    }
    else if (bgc == 2)
    {
        SetClr(0,9);
    }
    else if (bgc == 3)
    {
        SetClr(0,15);
    }
    else if (bgc == 4)
    {
        SetClr(0,6);
    }
    else if (bgc == 5)
    {
        SetClr(0,2);
    }
}
void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void boxPrint()
{
    Background();
    int a = 140, b = 35;
    char y = -37;
    cout << "   " << endl;
    SetClr(11, 244);
    for (int i = 0; i < a; i++)
    {
        cout << y;
    }
    Background();
    cout << endl;
    for (int i = 0; i < b - 2; i++)
    {
        SetClr(14, 148);
        cout << y;
        Background();
        for (int j = 1; j < a - 1; j++)
        {
            cout << " ";
        }
        SetClr(14, 148);
        cout << y << endl;
        Background();
    }
    SetClr(11, 244);
    for (int i = 0; i < a; i++)
    {
        cout << y;
    }
    Background();
    cout << endl;
}
void clearBall(int x, int y)
{
    Background();
    for (int i = 0; i < 5; i++)
    {
        gotoRowCol(x + i, y);
        cout << "         ";
    }
}
void barPrint(int x, int y)
{
    SetClr(0, 4);
    char z = -37;
    for (int i = x; i < x + 9; i++)
    {
        for (int j = y; j < y + 1; j++)
        {
            gotoRowCol(i, j);
            cout << z;
        }
    }
    SetClr(15, 4);
}
void scorePrint(int& sco1, int& sco2)
{
    SetClr(4, 15);
    int x = 10, y = 144;
    gotoRowCol(x, y);
    cout << "  Score  ";
    gotoRowCol(x + 2, y - 3);
    cout << "Player1 Player2";
    gotoRowCol(x + 4, y - 3);
    cout << "  " << sco1 << "        " << sco2 << "  ";
    SetClr(15, 2);
}
void ballMove(int& x, int& y, int& direction, int x1, int y1, int x2, int y2, int& sco1, int& sco2)
{
    {
        if (x == 2 && direction == 2)
        {
            direction = 1;
        }
        if (x + 3 == 33 && y + 7 == 136 && direction == 1)
        {
            //direction = 3;
            x = 17;
            y = 65;
            Sleep(300);
            sco1++;
        }
        if (x == 2 && y == 2 && direction == 3)
        {
            // direction = 1;
            x = 17;
            y = 65;
            Sleep(1500);
            sco2++;
        }
        if (x + 3 == 33 && y == 2 && direction == 4)
        {
            // direction = 2;
            x = 17;
            y = 65;
            Sleep(300);
            sco2++;
        }
        if (x == 2 && y + 7 == 136 && direction == 2)
        {
            //direction = 4;
            x = 17;
            y = 65;
            Sleep(300);
            sco1++;
        }
        if (y + 7 == 136 && direction == 2)
        {
            // direction = 3;
            x = 17;
            y = 65;
            Sleep(300);
            sco1++;
        }
        if (x + 3 == 33 && direction == 1)
        {
            direction = 2;
        }
        if (y + 7 == 136 && direction == 1)
        {
            // direction = 4;
            x = 17;
            y = 65;
            Sleep(300);
            sco1++;
        }
        if (x + 3 == 33 && direction == 4)
        {
            direction = 3;
        }
        if (x == 2 && direction == 3)
        {
            direction = 4;
        }
        if (y == 2 && direction == 4)
        {
            // direction = 1;
            x = 17;
            y = 65;
            Sleep(300);
            sco2++;
        }
        if (y == 2 && (direction == 3 || direction == 5 || direction == 6))
        {
            // direction = 2;   
            x = 17;
            y = 65;
            Sleep(300);
            sco2++;
        }
        if (y + 7 == 136 && direction == 5)
        {
            // direction = 6;
            x = 18;
            y = 65;
            Sleep(300);
            sco1++;
        }
    }
    if (direction == 1)
    {
        x++;
        y++;
    }
    if (direction == 2)
    {
        x--;
        y++;
    }
    if (direction == 3)
    {
        y--;
        x--;
    }
    if (direction == 4)
    {
        y--;
        x++;
    }
    if (direction == 5)
    {
        y++;
    }
    if (direction == 6)
    {
        y--;
    }

}
void ballMoveBarCollision(int& x, int& y, int& direction, int x1, int y1, int x2, int y2)
{

    if ((x >= x1 - 3 && x <= x1) && (y == y1))
    {
        direction = 2;
    }
    if ((x >= x1 + 1 && x <= x1 + 2) && (y == y1))
    {
        direction = 5;
    }
    if ((x >= x1 + 3 && x <= x1 + 6) && (y == y1))
    {
        direction = 1;
    }



    if ((x >= x2 - 3 && x <= x2) && (y == y2 - 9))
    {
        direction = 3;
    }
    if ((x >= x2 + 1 && x <= x2 + 2) && (y == y2 - 9))
    {
        direction = 6;
    }
    if ((x >= x2 + 3 && x <= x2 + 6) && (y == y2 - 9))
    {
        direction = 4;
    }


}
void moveBars(int& x1, int& y1, int& x2, int& y2)
{
    if (_kbhit())
    {
        char c = _getch();
        if (c == 'w' && x1 > 2)
        {
            x1--;
        }
        else if (c == 's' && x1 + 7 < 33)
        {
            x1++;
        }
        else if (c == 72 && x2 > 2)
        {
            x2--;
        }
        else if (c == 80 && x2 + 7 < 33)
        {
            x2++;
        }
    }
}
void clearBars(int x, int y, int l)
{
    char s = ' ';
    if (x >= 2 && x + 6 < 33)
    {
        for (int i = x; i < x + l; i++)
        {
            for (int j = y; j < y + 1; j++)
            {
                gotoRowCol(i, j);
                cout << s;
            }
        }
    }
}
int ballShape()
{
    system("CLS");
    cout << "Enter the design of ball you want to play with " << endl;
    cout << "1 for" << endl;
    cout << "    --    " << endl;
    cout << "  /----\\  " << endl;
    cout << " |------| " << endl;
    cout << "  \\----/  " << endl;
    cout << "    --    " << endl;

    cout << "2 for" << endl;
    cout << "    --    " << endl;
    cout << "  /    \\  " << endl;
    cout << " |      | " << endl;
    cout << "  \\    /  " << endl;
    cout << "    --    " << endl;

    cout << "3 for" << endl;
    cout << "    ..    " << endl;
    cout << "  /....\\  " << endl;
    cout << " |......| " << endl;
    cout << "  \\..../  " << endl;
    cout << "    ..    " << endl;
    int x;
    cin >> x;
    system("CLS");
    return x;
}
void Ballselected(int x, int y, int select)
{
    Background();
    if (select == 1)
    {

        gotoRowCol(x, y);
        cout << "    --    " << endl;
        gotoRowCol(x + 1, y);
        cout << "  /----\\  " << endl;
        gotoRowCol(x + 2, y);
        cout << " |------| " << endl;
        gotoRowCol(x + 3, y);
        cout << "  \\----/  " << endl;
        gotoRowCol(x + 4, y);
        cout << "    --    " << endl;
    }
    else if (select == 2)
    {

        gotoRowCol(x, y);
        cout << "    --    " << endl;
        gotoRowCol(x + 1, y);
        cout << "  /    \\  " << endl;
        gotoRowCol(x + 2, y);
        cout << " |      | " << endl;
        gotoRowCol(x + 3, y);
        cout << "  \\    /  " << endl;
        gotoRowCol(x + 4, y);
        cout << "    --    " << endl;
    }
    else if (select == 3)
    {

        gotoRowCol(x, y);
        cout << "    ..    " << endl;
        gotoRowCol(x + 1, y);
        cout << "  /....\\  " << endl;
        gotoRowCol(x + 2, y);
        cout << " |......| " << endl;
        gotoRowCol(x + 3, y);
        cout << "  \\..../  " << endl;
        gotoRowCol(x + 4, y);
        cout << "    ..    " << endl;
    }
    else
        cout << "Invalid input ;(";
}
int sleepBall(int speed)
{
    int x;
    if (speed == 1)
        return x = 50;
    else if (speed == 2)
        return x = 35;
    else if (speed == 3)
        return x = 20;
    else if (speed == 4)
        return x = 10;
    else if (speed == 5)
        return x = 5;
    else
        cout << "You entered Wrong Speed";
}

int main()
{
    int restart = 1;
    while (restart == 1)
    {
        SetClr(15, 0);
        int speed = 0, sco1 = 0, sco2 = 0, sleep;
        int x = 10, y = 7, direction = 4;
        int x1 = 10, y1 = 3;
        int x2 = 10, y2 = 136;
        int Shapenum = ballShape();
        BackgroundSelect();
        cout << endl << "Enter the speed of the ball in the game range 1 to 5 ,5 means the most difficult (first to five wins) "<<endl;
        cin >> speed;

        sleep = sleepBall(speed);
        int cor1 = 15, cor2 = 65;
        system("CLS");
        boxPrint();
        PlaySound(L"Messi1.wav", NULL, SND_ASYNC);
        while (true)
        {

            int a = sco1, b = sco2;

            clearBall(x, y);

            clearBars(x1, y1, 9);
            clearBars(x2, y2, 9);



            ballMove(x, y, direction, x1, y1, x2, y2, sco1, sco2);
            moveBars(x1, y1, x2, y2);
            Ballselected(x, y, Shapenum);

            ballMoveBarCollision(x, y, direction, x1, y1, x2, y2);
            scorePrint(sco1, sco2);
            if (a != sco1 || b != sco2)
            {
                gotoRowCol(cor1, cor2);
                Background();
                PlaySound(L"Goal.wav", NULL, SND_ASYNC);
                cout << "Gooaaallll!!!";
                Background();
                Sleep(1500);
                gotoRowCol(cor1, cor2);
                cout << "             ";
                PlaySound(L"Messi1.wav", NULL, SND_ASYNC);
            }
            if (sco1 == 5)
            {
                system("ClS");
                gotoRowCol(cor1, cor2);
                SetClr(0, 4);
                cout << "Player 1 Won !!! ";
                gotoRowCol(cor1 + 2, cor2);
                cout << "Congratulation ;)";
                PlaySound(nullptr, nullptr, 0);
                break;
            }

            if (sco2 == 5)
            {
                system("ClS");
                gotoRowCol(cor1, cor2);
                SetClr(0, 4);
                cout << "Player 2 Won !!!";
                gotoRowCol(cor1 + 2, cor2);
                cout << "Congratulation ;)";
                PlaySound(nullptr, nullptr, 0);
                break;
            }
            barPrint(x1, y1);
            barPrint(x2, y2);
            Sleep(sleep);

        }
        gotoRowCol(27, 2);
        SetClr(0, 4);
        cout << "Press 1 to restart and 0 to finish ";
        cin >> restart;
        system("CLS");
    }

    return 0;
}