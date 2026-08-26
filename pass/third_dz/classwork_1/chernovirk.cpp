struct Level_menu{
    const char* title;

    const Level_menu* (*func)(const Level_menu* current);

     const Level_menu* parent;

    const Level_menu* const *children;
    const int children_count;
};



Level_menu main_menu = {"Главное меню",  };