//РІР°СЂ 1, 1. СЂРµР°Р»РёР·РѕРІР°С‚СЊ РєР»Р°СЃСЃ РІСЂРµРјСЏ, РµСЃС‚СЊ С‡Р°СЃС‹ РјРёРЅСѓС‚С‹ СЃРµРєСѓРЅРґС‹, РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂС‹ СЃ РїСЂРѕРІРµСЂРєРѕР№ РєРѕСЂСЂРµРєС‚РЅРѕСЃС‚Рё, СЂРµР°Р»РёР·РѕРІР°С‚СЊ РёСЃРєР»СЋС‡РµРЅРёСЏ (РЅР°РїСЂ., 70 СЃРµРєСѓРЅРґ - РѕС€РёР±РєР°)
//РЎРґРµР»Р°С‚СЊ РїСѓСЃС‚РѕР№, РѕС‚ С‚СЂРµС… Р·РЅР°С‡РµРЅРёР№, РґР»СЏ РІСЂРµРјРµРЅРё РѕС‚ СЃРµРєСѓРЅРґ, РєРѕС‚РѕСЂС‹Рµ РЅР°РґРѕ Р±СѓРµС‚ РїРµСЂРµРІРѕРґРёС‚СЊ
//РћРїРµСЂР°С‚РѕСЂС‹ СЃР»РѕР¶РµРЅРёСЏ Рё РІС‹С‡РёС‚Р°РЅРёСЏ, РјРµС‚РѕРґ РІРѕР·РІСЂР°С‰Р°СЋС‰РёР№ С‡РёСЃР»Рѕ СЃРµРєСѓРЅРґ, С‡Р°СЃС‚СЊ РјРµС‚РѕРґРѕРІ СЃР»РµРґР°С‚СЊ РјРµС‚РѕРґР°РјРё РєР»Р°СЃСЃР°, С‡Р°СЃС‚СЊ С„СЂСЌРЅРґР°РјРё(Р°РЅР°Р»РѕРіРёС‡РЅРѕ С‡РёСЃР»Рѕ С‡Р°СЃРѕРІ Рё РјРёРЅСѓС‚)
//2. РљР»Р°СЃСЃ С„РёРіСѓСЂР° - Р°Р±СЃС‚СЂР°РєС‚РЅС‹Р№(РєРѕРѕСЂРґРёРЅР°С‚С‹ С… Сѓ, РјРµС‚РѕРґС‹ - РІС‹РІРѕРґ РєРѕРѕСЂРґРёРЅР°С‚, РїРµСЂРµРјРµС‰РµРЅРёРµ С„РёРіСѓСЂС‹, СѓРјРЅРѕР¶РµРЅРёРµ Р·РЅР°С‡РµРЅРёСЏ РєРѕРѕСЂРґРёРЅР°С‚ РЅР° РјР°СЃС‚Р°Р±РЅС‹Рµ РєРѕСЌС„С„, РїРѕРґСЃС‡РµС‚ РїР»РѕС‰Р°РґРё) 
//, РїСЂСЏРјРѕСѓРіРѕР»СЊРЅРёРє, С‚СЂРµСѓРіРѕР»СЊРЅРёРє Рё РєСЂСѓРі(РґРѕРїРѕР»РЅРёС‚РµР»СЊРЅРѕ: РїСЂРѕРІРµСЂРєР°, С‡С‚Рѕ С‚РѕС‡РєР° РІРЅСѓС‚СЂРё РєСЂСѓРіР°, РїСЂРѕРІРµСЂРєР°, С‡С‚Рѕ РґСЂСѓРіРѕР№ РєСЂСѓРі РІРЅСѓС‚СЂРё СЌС‚РѕРіРѕ РєСЂСѓРіР°)
//3. РЁР°Р±Р»РѕРЅ РєР»Р°СЃСЃР° РєРѕРјРїР»РµРєСЃРЅРѕРіРѕ С‡РёСЃР»Р°, РІ РєР°С‡РµСЃС‚РІРµ Р° Рё Р± РјРѕР¶РµС‚ Р±С‹С‚СЊ РІРµРєС‚РѕСЂ, РІРµС‰РµСЃС‚РІРµРЅРЅРѕРµ С‡РёСЃР»Рѕ, РґСЂРѕР±СЊ Рё С‚.Рґ. Р РµР°Р»РёР·РѕРІР°С‚СЊ СЃР»РѕР¶РµРЅРёРµ, РІС‹С‡РёС‚Р°РЅРёРµ, СѓРјРЅРѕР¶РµРЅРёРµ, СѓРјРЅРѕР¶РµРЅРёРµ РЅР°
// С‡РёСЃР»Рѕ, РјРѕРґСѓР»СЊ

#include <stdlib.h>
#include <glut.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <time.h>
 
typedef struct Snake Snake;
typedef struct SnakeEat SnakeEat;
typedef struct Game Game;
 
#define SCALE 20				//Масштаб игры
#define TIME  200				//Время обновления движения змейки - скорость движения
/*
	Каждая часть змейки представляет из себя структуру: хранит свои координаты, указатель на спрайт, и указатели на соседние две части змейки
*/
struct Snake
{
    int posx, posy;
    Snake *next, *prev;
    GdkPixbuf *pSnakeTexture;
};
/*
    Структура, содержащая информацию о еде змейки: координаты расположения и указатель на спрайт
*/
struct SnakeEat
{
    int posx, posy;
    GdkPixbuf *pEatTexture;
};
/*
    Основная структура, содержит всю информацию для игры
*/
struct Game
{
    GtkWidget *window;                                              //окно, где играем
    GdkPixbuf *BackGroundTexture;                                   //спрайт основного фона
    GdkFont *ScoreFont;                                             //Шрифт для отображения очков
    Snake *SnakeHead;                                               //Указатель на голову змейки
    Snake *SnakeTail;                                               //На последнюю часть змейки
    SnakeEat *SnakeEat;                                             //На еду змейки
    unsigned int Score;                                             //Переменная для очков
    char StateHor, StateVer;                                        //переменные, отвечающие за направление движения змейки
    char ScoreString[10];                                           //Строка, для вывода очков на экран
    gboolean KeyState;                                              //Переменная, блокируящая многоразовое изменение направления движения змейки за одну итерацию, чтобы избежать глюков при движении змейки
};
 
//--- Функия инициализации игры: загружает необходимые изображения, устанавливает начальные данные ---//
void Init_Game(GtkWidget *wid, Game *game)
{
    game->window = wid;
    game->BackGroundTexture = gdk_pixbuf_new_from_file("img/BackGround.png", NULL);
    game->StateHor  = 0;
    game->StateVer = -SCALE;
    game->Score = 0;
    game->SnakeEat = (SnakeEat *) malloc(sizeof(SnakeEat));
    game->SnakeEat->pEatTexture = gdk_pixbuf_new_from_file("img/eat.png", NULL);
 
    Snake *hSnake = (Snake *) malloc(sizeof(Snake));
    hSnake->pSnakeTexture = gdk_pixbuf_new_from_file("img/head.png", NULL);
    hSnake->prev = NULL;
    hSnake->posx = 260;
    hSnake->posy = 260;
    game->SnakeHead = game->SnakeTail = hSnake;
    AddNewPartToSnake( game );
    AddNewPartToSnake( game );
    SetSnakeEatPos( game );
}
 
 
//--- Функция, удаляющая всю змейку змейки ---//
void DestroySnake(Game *cgame)
{
    if( cgame->SnakeHead ) {
        Snake *cur, *temp;
        cur = cgame->SnakeHead;
        while( cur ) {
            temp = cur->next;
            free( cur );
            cur = temp;
        }
    }
}
//--- Функция, удаляющая све данные игры ---//
void DestroyGame(Game *cgame)
{
    if( cgame ) {
        DestroySnake   ( cgame );
        DestroySnakeEat( cgame );
        free( cgame );
    }
}
//--- Функция, удаляющая объект еды--//
void DestroySnakeEat(Game *cgame)
{
    if( cgame->SnakeEat ) {
        free( cgame->SnakeEat );
    }
}
 
 
//--- Фунция, добавляющая новую часть к змейке ---//
void AddNewPartToSnake(Game *cgame)
{
    Snake *NewPart = (Snake *) malloc(sizeof(Snake));
    NewPart->pSnakeTexture = gdk_pixbuf_new_from_file("img/part.png", NULL);
    NewPart->prev = cgame->SnakeTail;
    NewPart->posx = NewPart->prev->posx;
    NewPart->posy = NewPart->prev->posy;
    NewPart->next = NULL;
    cgame->SnakeTail->next = NewPart;
    cgame->SnakeTail = NewPart;
}
 
//--- Установка новой позиции еды змейки
void SetSnakeEatPos(Game *cgame)
{
    cgame->SnakeEat->posx = rand() % 25 * SCALE;                                                //рендомно определяем координаты
    cgame->SnakeEat->posy = rand() % 25 * SCALE;
    //--- Ниже циклом проверяем, чтобы еда не создалась там, где сейчас находится змейка, в случае если находится - вызываем функцию опять ---//
    Snake *cSnake = cgame->SnakeHead;
    while( cSnake ) {
        if( ( cgame->SnakeEat->posx == cSnake->posx && cgame->SnakeEat->posy == cSnake->posy )
                            || cgame->SnakeEat->posy < 20 ) {
            SetSnakeEatPos( cgame );
            break;
        }
        cSnake = cSnake->next;
    }
}
 
//--- Функция коллизии, проверяет на столконовение головы со своими частями тела ---//
//--- Возвращает TRUE - если врезалась, FALSE - если нет
gboolean Collision(Game *cgame)
{
    Snake *CurSnake = cgame->SnakeHead->next;
    while( CurSnake ) {
        if( CurSnake->posx == cgame->SnakeHead->posx
                    && CurSnake->posy == cgame->SnakeHead->posy )
            return TRUE;
        CurSnake = CurSnake->next;
    }
    return FALSE;
}
 
//--- Функция прорисовки текста, в данном случае очков, на определённых координатах x, y ---//
void DrawScoreText(Game *game, int x, int y)
{
    GdkColor Color;                                                                             //структура, содержит в себе описание цвета (RGBA)
    /*
        Ниже создаём указатель на текущий стиль виджета с целью его преобразования для вывода очков на экран
    */
    GdkGC *GC = game->window->style->fg_gc[ GTK_WIDGET_STATE (game->window) ];
    gdk_color_parse("#FF6600", &Color);                                                         //Закидываем RGB-Цвет в структуру Color
    gdk_gc_set_rgb_fg_color(GC, &Color);														//Устанавливаем новый цвет в наш стиль
 
    sprintf(game->ScoreString, "SCORE: %d", game->Score );                                      //Формируем в строку текст с нашими очками
    gdk_draw_string(game->window->window, game->ScoreFont, GC, x, y, game->ScoreString);        //выводим на экран в опр. координатах с выше полученным стилей строку с очками
}
 
//--- Функция, в которой идёт прорисовка всей графической части игры
gboolean Draw_Field(GtkWidget *win, GdkEventExpose *event, gpointer data)
{
    Game *game = (Game *) data;
    Snake *cSnake = game->SnakeTail;
    gdk_draw_pixbuf(win->window,                                                                 //Задний фон рисуем
                    win->style->black_gc,
                    game->BackGroundTexture,
                    0, 0,
                    0, 0,
                    500, 500,
                    GDK_RGB_DITHER_NONE,
                    0, 0);
 
    gdk_draw_pixbuf(win->window,                                                                //еда
                    win->style->black_gc,
                    game->SnakeEat->pEatTexture,
                    0, 0,
                    game->SnakeEat->posx, game->SnakeEat->posy,
                    20, 20,
                    GDK_RGB_DITHER_NONE,
                    0, 0);
 
 
    while( cSnake ) {                                                                           //Все части змейки
        gdk_draw_pixbuf(win->window,
                        win->style->black_gc,
                        cSnake->pSnakeTexture,
                        0, 0,
                        cSnake->posx, cSnake->posy,
                        20, 20,
                        GDK_RGB_DITHER_NONE,
                        0, 0);
        cSnake = cSnake->prev;
    }
    DrawScoreText(game, 10, 16);                                                                //Вывод очков
    gtk_widget_queue_draw(game->window);														//Стираем то, что выводили выше для обновления
    return TRUE;																				//TRUE - продолжать обрабатывать события прорисовки виджета FALSE - закончить
}
//---   ---//
 
//--- Функция, обрабатывающая нажатие клавиш
gboolean KeyPress(GtkWidget *wid, GdkEventKey *event, gpointer data)
{
    Game *cgame = (Game *) data;
    if( cgame->KeyState )                                                                       //Если клавишу уже нажали многократно, то просто выходим
        return TRUE;
    switch( event->keyval ) {                                                                   //Проверяем что за клавиша была нажата
        case GDK_Right:                                                                         //Вправо
            if( !cgame->StateHor ) {
                cgame->StateHor = SCALE;
                cgame->StateVer = 0;
            }
            break;
        case GDK_Left:                                                                          //Влево
            if( !cgame->StateHor ) {
                cgame->StateHor = -SCALE;
                cgame->StateVer = 0;
            }
            break;
        case GDK_Up:                                                                            //Вверх
            if( !cgame->StateVer ) {
                cgame->StateVer = -SCALE;
                cgame->StateHor = 0;
            }
            break;
        case GDK_Down:                                                                          //Вниз
            if( !cgame->StateVer ) {
                cgame->StateVer = SCALE;
                cgame->StateHor = 0;
            }
            break;
        case GDK_Return:                                                                        //И ентер, чтобы начать играть заного
            DestroyGame(cgame);																	//Удаляем предыдущую игры, чтобы не было утечки памяти
            Init_Game(wid, cgame);																//Создаём новую
            break;
    }
    cgame->KeyState = TRUE;																		//Устанавливаем флаг, что клавишу уже нажимали
    return TRUE;
}
 
 
//--- Функция обрабатывает все действия змейки, обрабатывает устанавку позиции еды
gboolean Engine(gpointer data)
{
    Game *cgame = (Game *) data;
    Snake *CurSnake = cgame->SnakeTail;
    while( CurSnake != cgame->SnakeHead ) {                                                 //Изменяет позицию каждой части змейки начиная с хвоста, на место элемента который перед текущим
        CurSnake->posx = CurSnake->prev->posx;
        CurSnake->posy = CurSnake->prev->posy;
        CurSnake = CurSnake->prev;
    }
    cgame->KeyState = FALSE;																//Обнуляем флаг нажатия клавиши
    //--- Изменяем позицию головы змейки, исходя из параметров, полученных при нажатии клавиши ---//
    CurSnake->posx += cgame->StateHor;
    CurSnake->posy += cgame->StateVer;
    //--- Здесь проверка на границы окна, чтобы она перемещалась с одного конца на другой ---//
    if( CurSnake->posx < 0 )
        CurSnake->posx = 480;
    if( CurSnake->posx > 480 )
        CurSnake->posx = 0;
    if( CurSnake->posy > 480 )
        CurSnake->posy = 20;
    if( CurSnake->posy < 20 )
        CurSnake->posy = 480;
    //--- Проверяем если змейка врезалась в свою часть - начинаем заного игру ---//
    if( Collision( cgame ) ) {
		DestroyGame(cgame);
        Init_Game( cgame->window, cgame );
	}
    //--- Проверка, если голова змеи на тех же координатах, что и еда, то меняем позицию еды и наращиваем змейку, увеличиваем очки ---//
    if(CurSnake->posx == cgame->SnakeEat->posx &&
                    CurSnake->posy == cgame->SnakeEat->posy) {
        AddNewPartToSnake( cgame );
        SetSnakeEatPos( cgame );
        //!!
        cgame->Score++;
    }
    return TRUE;																			//TRUE - продолжить работу таймеры по вызову функции Engine(), FALSE - удалить таймер
}
 
int main (int argc, char *argv[])
{
    srand( time( 0 ) );                                                                 //запускаем генератор случайных чисел
    GtkWidget *win = NULL;                                                              //Создаём виджет, в котором будет хранится наше окно
    Game *cgame = (Game *) malloc(sizeof( Game ));                                      //выделяем динамически gfvznm под структуру игры
    gtk_init (&argc, &argv);                                                            //Инициализация GTK
 
    //--- Создание окна ---//
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);                                         //создаём окно поверх всех запущенных окон, за это отвечает макрос GTK_WINDOW_TOPLEVEL
    gtk_window_set_title (GTK_WINDOW (win), "Snake");                                   //Выставляем заголов окна на "Snake"
    gtk_widget_set_size_request (win, 500, 500);                                         //устанавливаем фиксированные размеры окна
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);                     //устанавливаем окно на мониторе по центру, опять-таки макрос GTK_WIN_POS_CENTER за это отвечает
    //---   Функция выставляет свойство окна, при которых, окно можно либо растягивать, TRUE - можно растягивать, FALSE - нет  ---//
    gtk_window_set_resizable (GTK_WINDOW(win), FALSE);
	//--- В Linux и Windows разные принципы загрузки шрифтов, и чтобы игра могла скомпилироваться без ошибок на обоих системах - использую препроцессорные команды для проверки ОС ---//
#if defined _WIN32
    cgame->ScoreFont = gdk_font_load ("Arial");
#else
    cgame->ScoreFont = gdk_font_load ("-*-helvetica-bold-r-*-*-*-160-*-*-*-*-*-*");    
#endif                                                                              //конец команды препроцессора
 
    Init_Game(win, cgame);                                                              //Инициализируем игру, функция расписана выше
	//--- Создание событий обработки окна, перерисовки окна, нажатия клавиш ---//
    g_signal_connect_data (win, "destroy", gtk_main_quit, NULL, NULL, 0);
 
    g_signal_connect_data (win, "expose_event", Draw_Field, (gpointer)cgame, NULL, 0);
 
    g_signal_connect_data (win, "key_press_event", KeyPress, (gpointer)cgame, NULL, 0);
 
	//--- Создаём таймер для вызова функции обновления позиций змейки, еды ---//
    g_timeout_add( TIME, Engine, (gpointer) cgame );
 
    gtk_widget_realize (win);                                                            //Уже расписывал фунцию
    gtk_widget_show_all (win);                                                          //Отображает все виджеты на экран
    //--- Запускаем бесконечный цикл GTK, который будет обрабатывать все описанные выше события, и отображать виджет окна и всё что в нём
    gtk_main ();
    //--- После завершения бесконечного цикла, в результате выполнения события destroy, очищаем оперативную память от структур игры
    DestroyGame ( cgame );
    //              ---         //
    return 0;
}
