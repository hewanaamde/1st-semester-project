#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <mmsystem.h>
#include <bits/stdc++.h> //for tokenization
#include<fstream>
#include<string>
#include<wchar.h>
#define ID_BTNRESULT 0

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("TextEntry");
char textFetched(20);
using namespace std;
string name;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Welcome to Geez Teaching Program"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           760,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

static HWND button;
static HWND textBox;
static HWND welcomeLabel;
static HWND leftContainer, rightContainer, messageContainer, searchContainer, search2Container;
static HWND hearSound;
static HWND basicNumbersLearningLabel, basicCharactersLearningLabel;

//creating buttons
static HWND ha1_button, hu1_button, hi1_button, ha12_button, he1_button, h1_button, ho1_button, ha1_all_button;
static HWND le_button, lu_button, li_button, la_button, lee_button, l_button, lo_button, la_all_button;
static HWND ha2_button, hu2_button, hi2_button, ha22_button, he2_button, h2_button, ho2_button, ha2_all_button;
static HWND me_button, mu_button, mi_button, ma_button, mie_button, m_button, mo_button, me_all_button;
static HWND se1_button, su1_button, si1_button, sa1_button, sie1_button, s1_button, so1_button, se1_all_button;
static HWND re_button, ru_button, ri_button, ra_button, rie_button, r_button, ro_button, re_all_button;
static HWND se2_button, su2_button, si2_button, sa2_button, sie2_button, s2_button, so2_button, se2_all_button;
static HWND she_button, shu_button, shi_button, sha_button, shie_button, sh_button, sho_button, she_all_button;
static HWND qe_button, qu_button, qi_button, qa_button, qie_button, q_button, qo_button, qe_all_button;
static HWND be_button, bu_button, bi_button, ba_button, bie_button, b_button, bo_button, be_all_button;
static HWND te_button, tu_button, ti_button, ta_button, tie_button, t_button, to_button, te_all_button;
static HWND che_button, chu_button, chi_button, cha_button, chie_button, ch_button, cho_button, che_all_button;


//static HWND ha1_button, hu1_button, hi1_button, ha12_button, he1_button, h1_button, ho1_button, ha1_all_button;
//adding numbers button
static HWND one_button, two_button, three_button, four_button, five_button, six_button, seven_button, eight_button, nine_button, ten_button, numbers_all_button;
static HWND eleven_button, twelve_button, thirteen_button, fourteen_button, fifteen_button, sixteen_button, seventeen_button, eighteen_button, nineteen_button, twenty_button;
static HWND thirty_button, fourty_button, fifty_button, sixty_button, seventy_button, eighty_button, ninety_button, hundred_button, thousand_button;
//search windows,
static HWND numberSearchBox, numberSearchButton, characterSearchBox, characterSearchButton;

static HWND messageLabel, messageOutputLabel;

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE: {

            welcomeLabel = CreateWindowW(L"STATIC",
                                         L"የግእዝ ፊደላት እና ቁጥሮች መማሪያ ፕሮግራም (Geez Characters & Numbers Learning Program) ",
                                         WS_BORDER | WS_CHILD | WS_VISIBLE,
                                         180, 20, 480, 20,
                                         hwnd, NULL, NULL, NULL);

            //adding search box
            searchContainer = CreateWindowW(L"STATIC", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 70, 300, 70, hwnd, NULL, NULL, NULL);
            numberSearchBox = CreateWindowW(L"EDIT", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 80, 40, 20, hwnd, NULL, NULL, NULL);
            numberSearchButton = CreateWindowW(L"BUTTON",
                                               L"ፈልግ",
                                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                                               90, 80, 30, 20, hwnd, (HMENU) 100, NULL, NULL);

            basicNumbersLearningLabel = CreateWindowW(L"STATIC", L"የቁጥሮች መማሪያዎች (Basic Numbers Learning) ", WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 120, 300, 20, hwnd, NULL, NULL, NULL);
            leftContainer = CreateWindowW(L"STATIC",L"",WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 150, 300, 300,hwnd, NULL, NULL, NULL);

            //adding numbers buttons
            one_button = CreateWindowW(L"BUTTON", L"፩-1", WS_BORDER | WS_CHILD | WS_VISIBLE, 30, 160, 40, 20, hwnd, (HMENU) 1, NULL, NULL);
            two_button = CreateWindowW(L"BUTTON", L"፪-2", WS_BORDER | WS_CHILD | WS_VISIBLE, 80, 160, 40, 20, hwnd, (HMENU) 2, NULL, NULL);
            three_button = CreateWindowW(L"BUTTON", L"፫-3", WS_BORDER | WS_CHILD | WS_VISIBLE, 130, 160, 40, 20, hwnd, (HMENU) 3, NULL, NULL);
            four_button = CreateWindowW(L"BUTTON", L"፬-4", WS_BORDER | WS_CHILD | WS_VISIBLE, 180, 160, 40, 20, hwnd, (HMENU) 4, NULL, NULL);
            five_button = CreateWindowW(L"BUTTON", L"፭-5", WS_BORDER | WS_CHILD | WS_VISIBLE, 230, 160, 40, 20, hwnd, (HMENU) 5, NULL, NULL);

            six_button = CreateWindowW(L"BUTTON", L"፮-6", WS_BORDER | WS_CHILD | WS_VISIBLE, 30, 190, 40, 20, hwnd, (HMENU) 6, NULL, NULL);
            seven_button = CreateWindowW(L"BUTTON", L"፯-7", WS_BORDER | WS_CHILD | WS_VISIBLE, 80, 190, 40, 20, hwnd, (HMENU) 7, NULL, NULL);
            eight_button = CreateWindowW(L"BUTTON", L"፰-8", WS_BORDER | WS_CHILD | WS_VISIBLE, 130, 190, 40, 20, hwnd, (HMENU) 8, NULL, NULL);
            nine_button = CreateWindowW(L"BUTTON", L"፱-9", WS_BORDER | WS_CHILD | WS_VISIBLE, 180, 190, 40, 20, hwnd, (HMENU) 9, NULL, NULL);
            ten_button = CreateWindowW(L"BUTTON", L"፲-10", WS_BORDER | WS_CHILD | WS_VISIBLE, 230, 190, 40, 20, hwnd, (HMENU) 10, NULL, NULL);

            eleven_button = CreateWindowW(L"BUTTON", L"፲፩-11", WS_BORDER | WS_CHILD | WS_VISIBLE, 30, 220, 40, 20, hwnd, (HMENU) 11, NULL, NULL);
            twelve_button = CreateWindowW(L"BUTTON", L"፲፪-12", WS_BORDER | WS_CHILD | WS_VISIBLE, 80, 220, 40, 20, hwnd, (HMENU) 12, NULL, NULL);
            thirteen_button = CreateWindowW(L"BUTTON", L"፲፫-13", WS_BORDER | WS_CHILD | WS_VISIBLE, 130, 220, 40, 20, hwnd, (HMENU) 13, NULL, NULL);
            fourteen_button = CreateWindowW(L"BUTTON", L"፲፬-14", WS_BORDER | WS_CHILD | WS_VISIBLE, 180, 220, 40, 20, hwnd, (HMENU) 14, NULL, NULL);
            fifteen_button = CreateWindowW(L"BUTTON", L"፲፭-15", WS_BORDER | WS_CHILD | WS_VISIBLE, 230, 220, 40, 20, hwnd, (HMENU) 15, NULL, NULL);

            sixteen_button = CreateWindowW(L"BUTTON", L"፲፮-16", WS_BORDER | WS_CHILD | WS_VISIBLE, 30, 250, 40, 20, hwnd, (HMENU) 16, NULL, NULL);
            seventeen_button = CreateWindowW(L"BUTTON", L"፲፰-17", WS_BORDER | WS_CHILD | WS_VISIBLE, 80, 250, 40, 20, hwnd, (HMENU) 17, NULL, NULL);
            eighteen_button = CreateWindowW(L"BUTTON", L"፲፰-18", WS_BORDER | WS_CHILD | WS_VISIBLE, 130, 250, 40, 20, hwnd, (HMENU) 18, NULL, NULL);
            nineteen_button = CreateWindowW(L"BUTTON", L"፲፱-19", WS_BORDER | WS_CHILD | WS_VISIBLE, 180, 250, 40, 20, hwnd, (HMENU) 19, NULL, NULL);
            twenty_button = CreateWindowW(L"BUTTON", L"፳-20", WS_BORDER | WS_CHILD | WS_VISIBLE, 230, 250, 40, 20, hwnd, (HMENU) 20, NULL, NULL);

            thirty_button = CreateWindowW(L"BUTTON", L"፴-30", WS_BORDER | WS_CHILD | WS_VISIBLE, 30, 280, 40, 20, hwnd, (HMENU) 21, NULL, NULL);
            fourty_button = CreateWindowW(L"BUTTON", L"፵-40", WS_BORDER | WS_CHILD | WS_VISIBLE, 80, 280, 40, 20, hwnd, (HMENU) 22, NULL, NULL);
            fifty_button = CreateWindowW(L"BUTTON", L"፶-50", WS_BORDER | WS_CHILD | WS_VISIBLE, 130, 280, 40, 20, hwnd, (HMENU) 23, NULL, NULL);
            sixty_button = CreateWindowW(L"BUTTON", L"፷-60", WS_BORDER | WS_CHILD | WS_VISIBLE, 180, 280, 40, 20, hwnd, (HMENU) 24, NULL, NULL);
            seventy_button = CreateWindowW(L"BUTTON", L"፸-70", WS_BORDER | WS_CHILD | WS_VISIBLE, 230, 280, 40, 20, hwnd, (HMENU) 25, NULL, NULL);

            eighty_button = CreateWindowW(L"BUTTON", L"፹-80", WS_BORDER | WS_CHILD | WS_VISIBLE, 30, 310, 40, 20, hwnd, (HMENU) 26, NULL, NULL);
            ninety_button = CreateWindowW(L"BUTTON", L"፺-90", WS_BORDER | WS_CHILD | WS_VISIBLE, 80, 310, 40, 20, hwnd, (HMENU) 27, NULL, NULL);
            hundred_button = CreateWindowW(L"BUTTON", L"፻-100", WS_BORDER | WS_CHILD | WS_VISIBLE, 130, 310, 40, 20, hwnd, (HMENU) 28, NULL, NULL);
            thousand_button = CreateWindowW(L"BUTTON", L"፲፻-1000", WS_BORDER | WS_CHILD | WS_VISIBLE, 180, 310, 80, 20, hwnd, (HMENU) 29, NULL, NULL);



            numbers_all_button = CreateWindowW(L"BUTTON", L"LISTEN TO ALL - ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 30, 330, 200, 20, hwnd, (HMENU) 90, NULL, NULL);
            //adding search box
            search2Container = CreateWindowW(L"STATIC", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 400, 70, 330, 70, hwnd, NULL, NULL, NULL);
            characterSearchBox = CreateWindowW(L"EDIT", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 80, 40, 20, hwnd, NULL, NULL, NULL);
            characterSearchButton = CreateWindowW(L"BUTTON", L"ፈልግ", WS_BORDER | WS_CHILD | WS_VISIBLE, 470, 80, 30, 20, hwnd, NULL, NULL, NULL);

            basicCharactersLearningLabel = CreateWindowW(L"STATIC", L"የፊደላት መማሪያዎች (Basic Characters Learning) ", WS_BORDER | WS_CHILD | WS_VISIBLE, 400, 120, 330, 20, hwnd, NULL, NULL, NULL);
            rightContainer = CreateWindowW(L"STATIC",L"",WS_BORDER | WS_CHILD | WS_VISIBLE, 400, 150, 330, 400,hwnd, NULL, NULL, NULL);

            //adding buttons under right container
            ha1_button = CreateWindowW(L"BUTTON", L"ሀ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 160, 20, 20, hwnd, (HMENU) 11, NULL, NULL);
            hu1_button = CreateWindowW(L"BUTTON", L"ሁ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 160, 20, 20, hwnd, (HMENU) 12, NULL, NULL);
            hi1_button = CreateWindowW(L"BUTTON", L"ሂ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 160, 20, 20, hwnd, (HMENU) 13, NULL, NULL);
            ha12_button = CreateWindowW(L"BUTTON", L"ሃ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 160, 20, 20, hwnd, (HMENU) 14, NULL, NULL);
            he1_button = CreateWindowW(L"BUTTON", L"ሄ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 160, 20, 20, hwnd, (HMENU) 15, NULL, NULL);
            h1_button = CreateWindowW(L"BUTTON", L"ህ", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 160, 20, 20, hwnd, (HMENU) 16, NULL, NULL);
            ho1_button = CreateWindowW(L"BUTTON", L"ሆ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 160, 20, 20, hwnd, (HMENU) 17, NULL, NULL);
            ha1_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 160, 80, 20, hwnd, (HMENU) 18, NULL, NULL);

            le_button = CreateWindowW(L"BUTTON", L"ለ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 190, 20, 20, hwnd, (HMENU) 19, NULL, NULL);
            lu_button = CreateWindowW(L"BUTTON", L"ሉ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 190, 20, 20, hwnd, (HMENU) 20, NULL, NULL);
            li_button = CreateWindowW(L"BUTTON", L"ሊ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 190, 20, 20, hwnd, (HMENU) 21, NULL, NULL);
            la_button = CreateWindowW(L"BUTTON", L"ላ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 190, 20, 20, hwnd, (HMENU) 22, NULL, NULL);
            lee_button = CreateWindowW(L"BUTTON", L"ሌ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 190, 20, 20, hwnd, (HMENU) 23, NULL, NULL);
            l_button = CreateWindowW(L"BUTTON", L"ል", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 190, 20, 20, hwnd, (HMENU) 24, NULL, NULL);
            lo_button = CreateWindowW(L"BUTTON", L"ሎ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 190, 20, 20, hwnd, (HMENU) 25, NULL, NULL);
            la_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 190, 80, 20, hwnd, (HMENU) 26, NULL, NULL);

            ha2_button = CreateWindowW(L"BUTTON", L"ሐ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 220, 20, 20, hwnd, (HMENU) 27, NULL, NULL);
            hu2_button = CreateWindowW(L"BUTTON", L"ሑ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 220, 20, 20, hwnd, (HMENU) 28, NULL, NULL);
            hi2_button = CreateWindowW(L"BUTTON", L"ሒ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 220, 20, 20, hwnd, (HMENU) 29, NULL, NULL);
            ha22_button = CreateWindowW(L"BUTTON", L"ሓ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 220, 20, 20, hwnd, (HMENU) 30, NULL, NULL);
            he2_button = CreateWindowW(L"BUTTON", L"ሔ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 220, 20, 20, hwnd, (HMENU) 31, NULL, NULL);
            h2_button = CreateWindowW(L"BUTTON", L"ሕ", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 220, 20, 20, hwnd, (HMENU) 32, NULL, NULL);
            ho2_button = CreateWindowW(L"BUTTON", L"ሖ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 220, 20, 20, hwnd, (HMENU) 33, NULL, NULL);
            ha2_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 220, 80, 20, hwnd, (HMENU) 34, NULL, NULL);


            me_button = CreateWindowW(L"BUTTON", L"መ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 250, 20, 20, hwnd, (HMENU) 35, NULL, NULL);
            mu_button = CreateWindowW(L"BUTTON", L"ሙ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 250, 20, 20, hwnd, (HMENU) 36, NULL, NULL);
            mi_button = CreateWindowW(L"BUTTON", L"ሚ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 250, 20, 20, hwnd, (HMENU) 37, NULL, NULL);
            ma_button = CreateWindowW(L"BUTTON", L"ማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 250, 20, 20, hwnd, (HMENU) 38, NULL, NULL);
            mie_button = CreateWindowW(L"BUTTON", L"ሜ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 250, 20, 20, hwnd, (HMENU) 39, NULL, NULL);
            m_button = CreateWindowW(L"BUTTON", L"ም", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 250, 20, 20, hwnd, (HMENU) 40, NULL, NULL);
            mo_button = CreateWindowW(L"BUTTON", L"ሞ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 250, 20, 20, hwnd, (HMENU) 41, NULL, NULL);
            me_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 250, 80, 20, hwnd, (HMENU) 42, NULL, NULL);


            se1_button = CreateWindowW(L"BUTTON", L"ሠ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 280, 20, 20, hwnd, (HMENU) 43, NULL, NULL);
            su1_button = CreateWindowW(L"BUTTON", L"ሡ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 280, 20, 20, hwnd, (HMENU) 44, NULL, NULL);
            si1_button = CreateWindowW(L"BUTTON", L"ሢ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 280, 20, 20, hwnd, (HMENU) 45, NULL, NULL);
            sa1_button = CreateWindowW(L"BUTTON", L"ሣ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 280, 20, 20, hwnd, (HMENU) 46, NULL, NULL);
            sie1_button = CreateWindowW(L"BUTTON", L"ሤ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 280, 20, 20, hwnd, (HMENU) 47, NULL, NULL);
            s1_button = CreateWindowW(L"BUTTON", L"ሥ", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 280, 20, 20, hwnd, (HMENU) 48, NULL, NULL);
            so1_button = CreateWindowW(L"BUTTON", L"ሦ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 280, 20, 20, hwnd, (HMENU) 49, NULL, NULL);
            se1_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 280, 80, 20, hwnd, (HMENU) 50, NULL, NULL);

            re_button = CreateWindowW(L"BUTTON", L"ረ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 310, 20, 20, hwnd, (HMENU) 50, NULL, NULL);
            ru_button = CreateWindowW(L"BUTTON", L"ሩ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 310, 20, 20, hwnd, (HMENU) 51, NULL, NULL);
            ri_button = CreateWindowW(L"BUTTON", L"ሪ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 310, 20, 20, hwnd, (HMENU) 52, NULL, NULL);
            ra_button = CreateWindowW(L"BUTTON", L"ራ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 310, 20, 20, hwnd, (HMENU) 53, NULL, NULL);
            rie_button = CreateWindowW(L"BUTTON", L"ሬ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 310, 20, 20, hwnd, (HMENU) 54, NULL, NULL);
            r_button = CreateWindowW(L"BUTTON", L"ር", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 310, 20, 20, hwnd, (HMENU) 55, NULL, NULL);
            ro_button = CreateWindowW(L"BUTTON", L"ሮ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 310, 20, 20, hwnd, (HMENU) 56, NULL, NULL);
            re_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 310, 80, 20, hwnd, (HMENU) 57, NULL, NULL);


            se2_all_button = CreateWindowW(L"BUTTON", L"ሰ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 340, 20, 20, hwnd, (HMENU) 58, NULL, NULL);
            su2_button = CreateWindowW(L"BUTTON", L"ሱ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 340, 20, 20, hwnd, (HMENU) 59, NULL, NULL);
            si2_button = CreateWindowW(L"BUTTON", L"ሲ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 340, 20, 20, hwnd, (HMENU) 60, NULL, NULL);
            sa2_button = CreateWindowW(L"BUTTON", L"ሳ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 340, 20, 20, hwnd, (HMENU) 61, NULL, NULL);
            sie2_button = CreateWindowW(L"BUTTON", L"ሴ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540,340, 20, 20, hwnd, (HMENU) 62, NULL, NULL);
            s2_button = CreateWindowW(L"BUTTON", L"ስ", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 340, 20, 20, hwnd, (HMENU) 63, NULL, NULL);
            so2_button = CreateWindowW(L"BUTTON", L"ሶ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 340, 20, 20, hwnd, (HMENU) 64, NULL, NULL);
            se2_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 340, 80, 20, hwnd, (HMENU) 65, NULL, NULL);

            she_button = CreateWindowW(L"BUTTON", L"ሸ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 370, 20, 20, hwnd, (HMENU) 66, NULL, NULL);
            shu_button = CreateWindowW(L"BUTTON", L"ሹ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 370, 20, 20, hwnd, (HMENU) 67, NULL, NULL);
            shi_button = CreateWindowW(L"BUTTON", L"ሺ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 370, 20, 20, hwnd, (HMENU) 68, NULL, NULL);
            sh_button = CreateWindowW(L"BUTTON", L"ሻ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 370, 20, 20, hwnd, (HMENU) 69, NULL, NULL);
            shie_button = CreateWindowW(L"BUTTON", L"ሼ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 370, 20, 20, hwnd, (HMENU) 70, NULL, NULL);
            sh_button = CreateWindowW(L"BUTTON", L"ሽ", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 370, 20, 20, hwnd, (HMENU) 71, NULL, NULL);
            sho_button = CreateWindowW(L"BUTTON", L"ሾ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 370, 20, 20, hwnd, (HMENU) 72, NULL, NULL);
            she_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 370, 80, 20, hwnd, (HMENU) 73, NULL, NULL);

            qe_button = CreateWindowW(L"BUTTON", L"ቀ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 400, 20, 20, hwnd, (HMENU) 74, NULL, NULL);
            qu_button = CreateWindowW(L"BUTTON", L"ቁ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 400, 20, 20, hwnd, (HMENU) 75, NULL, NULL);
            qi_button = CreateWindowW(L"BUTTON", L"ቂ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 400, 20, 20, hwnd, (HMENU) 76, NULL, NULL);
            qa_button = CreateWindowW(L"BUTTON", L"ቃ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 400, 20, 20, hwnd, (HMENU) 77, NULL, NULL);
            qie_button = CreateWindowW(L"BUTTON", L"ቄ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 400, 20, 20, hwnd, (HMENU) 78, NULL, NULL);
            q_button = CreateWindowW(L"BUTTON", L"ቅ", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 400, 20, 20, hwnd, (HMENU) 79, NULL, NULL);
            qo_button = CreateWindowW(L"BUTTON", L"ቆ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 400, 20, 20, hwnd, (HMENU) 80, NULL, NULL);
            qe_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 400, 80, 20, hwnd, (HMENU) 81, NULL, NULL);


            be_button = CreateWindowW(L"BUTTON", L"በ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 430, 20, 20, hwnd, (HMENU) 82, NULL, NULL);
            bu_button = CreateWindowW(L"BUTTON", L"ቡ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 430, 20, 20, hwnd, (HMENU) 83, NULL, NULL);
            bi_button = CreateWindowW(L"BUTTON", L"ቢ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 430, 20, 20, hwnd, (HMENU) 84, NULL, NULL);
            ba_button = CreateWindowW(L"BUTTON", L"ባ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 430, 20, 20, hwnd, (HMENU) 85, NULL, NULL);
            bie_button = CreateWindowW(L"BUTTON", L"ቤ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 430, 20, 20, hwnd, (HMENU) 86, NULL, NULL);
            b_button = CreateWindowW(L"BUTTON", L"ብ", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 430, 20, 20, hwnd, (HMENU) 87, NULL, NULL);
            bo_button = CreateWindowW(L"BUTTON", L"ቦ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 430, 20, 20, hwnd, (HMENU) 88, NULL, NULL);
            be_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 430, 80, 20, hwnd, (HMENU) 89, NULL, NULL);

            te_button = CreateWindowW(L"BUTTON", L"ተ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 460, 20, 20, hwnd, (HMENU) 90, NULL, NULL);
            tu_button = CreateWindowW(L"BUTTON", L"ቱ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 460, 20, 20, hwnd, (HMENU) 91, NULL, NULL);
            ti_button = CreateWindowW(L"BUTTON", L"ቲ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 460, 20, 20, hwnd, (HMENU) 92, NULL, NULL);
            ta_button = CreateWindowW(L"BUTTON", L"ታ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 460, 20, 20, hwnd, (HMENU) 93, NULL, NULL);
            tie_button = CreateWindowW(L"BUTTON", L"ቴ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 460, 20, 20, hwnd, (HMENU) 94, NULL, NULL);
            t_button = CreateWindowW(L"BUTTON", L"ት", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 460, 20, 20, hwnd, (HMENU) 95, NULL, NULL);
            to_button = CreateWindowW(L"BUTTON", L"ቶ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 460, 20, 20, hwnd, (HMENU) 96, NULL, NULL);
            te_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 460, 80, 20, hwnd, (HMENU) 97, NULL, NULL);

            che_button = CreateWindowW(L"BUTTON", L"ቸ", WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 490, 20, 20, hwnd, (HMENU) 98, NULL, NULL);
            chu_button = CreateWindowW(L"BUTTON", L"ቹ", WS_BORDER | WS_CHILD | WS_VISIBLE, 450, 490, 20, 20, hwnd, (HMENU) 99, NULL, NULL);
            chi_button = CreateWindowW(L"BUTTON", L"ቺ", WS_BORDER | WS_CHILD | WS_VISIBLE, 480, 490, 20, 20, hwnd, (HMENU) 100, NULL, NULL);
            cha_button = CreateWindowW(L"BUTTON", L"ቻ", WS_BORDER | WS_CHILD | WS_VISIBLE, 510, 490, 20, 20, hwnd, (HMENU) 101, NULL, NULL);
            chie_button = CreateWindowW(L"BUTTON", L"ቼ", WS_BORDER | WS_CHILD | WS_VISIBLE, 540, 490, 20, 20, hwnd, (HMENU) 102, NULL, NULL);
            ch_button = CreateWindowW(L"BUTTON", L"ች", WS_BORDER | WS_CHILD | WS_VISIBLE, 570, 490, 20, 20, hwnd, (HMENU) 103, NULL, NULL);
            cho_button = CreateWindowW(L"BUTTON", L"ቾ", WS_BORDER | WS_CHILD | WS_VISIBLE, 600, 490, 20, 20, hwnd, (HMENU) 104, NULL, NULL);
            che_all_button = CreateWindowW(L"BUTTON", L"ሁሉንም ስማ", WS_BORDER | WS_CHILD | WS_VISIBLE, 640, 490, 80, 20, hwnd, (HMENU) 105, NULL, NULL);



            //adding status bar
            messageContainer = CreateWindowW(L"STATIC", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 460, 300, 80, hwnd, NULL, NULL, NULL);

           break;
        }
        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
                case 90:
                    PlaySound(TEXT("recordings/numericals/numericals-all.wav"), NULL, SND_SYNC);
                    break;
                case 1:
                    PlaySound(TEXT("recordings/numericals/1.wav"), NULL, SND_SYNC);
                    break;
                case 2:
                    PlaySound(TEXT("recordings/numericals/2.wav"), NULL, SND_SYNC);
                    break;
                case 3:
                    PlaySound(TEXT("recordings/numericals/3.wav"), NULL, SND_SYNC);
                    break;
                case 4:
                    PlaySound(TEXT("recordings/numericals/4.wav"), NULL, SND_SYNC);
                    break;
                case 5:
                    PlaySound(TEXT("recordings/numericals/5.wav"), NULL, SND_SYNC);
                    break;
                case 6:
                    PlaySound(TEXT("recordings/numericals/6.wav"), NULL, SND_SYNC);
                    break;
                case 7:
                    PlaySound(TEXT("recordings/numericals/7.wav"), NULL, SND_SYNC);
                    break;
                case 8:
                    PlaySound(TEXT("recordings/numericals/8.wav"), NULL, SND_SYNC);
                    break;
                case 9:
                    PlaySound(TEXT("recordings/numericals/9.wav"), NULL, SND_SYNC);
                    break;
                case 10:
                    PlaySound(TEXT("recordings/numericals/10.wav"), NULL, SND_SYNC);
                    break;

                case 11: //ha1
                    PlaySound(TEXT("recordings/ha1/1Ha1.wav"), NULL, SND_SYNC);
                    break;
                case 12: //hu1
                    PlaySound(TEXT("recordings/ha1/2Hu1.wav"), NULL, SND_SYNC);
                    break;
                case 13: //hi1
                    PlaySound(TEXT("recordings/ha1/3Hi1.wav"), NULL, SND_SYNC);
                    break;
                case 14: //hi1
                    PlaySound(TEXT("recordings/ha1/4Ha12.wav"), NULL, SND_SYNC);
                    break;
                case 15: //hi1
                    PlaySound(TEXT("recordings/ha1/5He1.wav"), NULL, SND_SYNC);
                    break;
                case 16: //hi1
                    PlaySound(TEXT("recordings/ha1/6H1.wav"), NULL, SND_SYNC);
                    break;
                case 17: //h1
                    PlaySound(TEXT("recordings/ha1/7Ho1.wav"), NULL, SND_SYNC);
                    break;
                case 18: //all ha's
                    PlaySound(TEXT("recordings/ha1/Ha1-full.wav"), NULL, SND_SYNC);
                    break;

                case 19: //le
                    PlaySound(TEXT("recordings/le/1le.wav"), NULL, SND_SYNC);
                    break;
                case 20: //li
                    PlaySound(TEXT("recordings/le/2lu.wav"), NULL, SND_SYNC);
                    break;
                case 21: //li
                    PlaySound(TEXT("recordings/le/3li.wav"), NULL, SND_SYNC);
                    break;
                case 22: //la
                    PlaySound(TEXT("recordings/le/4la.wav"), NULL, SND_SYNC);
                    break;
                case 23: //le
                    PlaySound(TEXT("recordings/le/5le.wav"), NULL, SND_SYNC);
                    break;
                case 24: //l
                    PlaySound(TEXT("recordings/le/6l.wav"), NULL, SND_SYNC);
                    break;
                case 25: //lo
                    PlaySound(TEXT("recordings/le/7lo.wav"), NULL, SND_SYNC);
                    break;
                case 26: //all le's
                    PlaySound(TEXT("recordings/le/le-full.wav"), NULL, SND_SYNC);
                    break;

                case 27: //le
                    PlaySound(TEXT("recordings/ha2/1Ha2.wav"), NULL, SND_SYNC);
                    break;
                case 28: //li
                    PlaySound(TEXT("recordings/ha2/2Hu2.wav"), NULL, SND_SYNC);
                    break;
                case 29: //li
                    PlaySound(TEXT("recordings/ha2/3hi2.wav"), NULL, SND_SYNC);
                    break;
                case 30: //la
                    PlaySound(TEXT("recordings/ha2/4ha22.wav"), NULL, SND_SYNC);
                    break;
                case 31: //le
                    PlaySound(TEXT("recordings/ha2/5he2.wav"), NULL, SND_SYNC);
                    break;
                case 32: //l
                    PlaySound(TEXT("recordings/ha2/6h2.wav"), NULL, SND_SYNC);
                    break;
                case 33: //lo
                    PlaySound(TEXT("recordings/ha2/7ho2.wav"), NULL, SND_SYNC);
                    break;
                case 34: //all le's
                    PlaySound(TEXT("recordings/ha2/ha2-full.wav"), NULL, SND_SYNC);
                    break;

                case 100: //if input from textbox (number)
                {
                    //adding status bar
                    messageLabel = CreateWindowW(L"STATIC", L"Your Input (ያስገቡት መረጃ)", WS_CHILD | WS_VISIBLE, 40, 470, 300, 20, hwnd, NULL, NULL, NULL);

                    wchar_t input[] = L"";
                    GetWindowTextW(numberSearchBox, ((wchar_t*)input), 100);
                    wchar_t data[] = L"፩";

                    if(wcscmp(input, data) == 0){
                        messageOutputLabel = CreateWindowW(L"STATIC", input, WS_CHILD | WS_VISIBLE, 40, 500, 20, 30, hwnd, NULL, NULL, NULL);
                        messageOutputLabel = CreateWindowW(L"STATIC", L"The writing is - 'AND'", WS_CHILD | WS_VISIBLE, 80, 500, 200, 30, hwnd, NULL, NULL, NULL);
                    }

                    vector<wstring> vLines;
                    wifstream is("dictionary.txt");
                      while(!is.eof()) {
                        wstring sLine;
                        getline(is,sLine);
                        vLines.push_back(sLine);
                      }

                      size_t szLines = vLines.size();
                      for (size_t i = 0; i < szLines; ++i) {
                        wcout << L"Line " << i << L" is " << vLines[i] << endl;
                        vector<wstring> vTokens;
                        //wchar_t * pwc;
                        //vTokens = wcstok(vLines[i], L",");
                        //for (size_t j = 0; j < vTokens; ++j) {
                            //wcout << L"Token " << j << L" is " << vTokens[j] << endl;
                        //}
                      }

                    break;
                }
                default:
                    break;
            }

            break;
        }
        case WM_DESTROY:
        {
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        }
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
