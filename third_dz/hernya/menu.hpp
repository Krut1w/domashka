namespace bugaga {
    struct  MenuItem{
        const char* title;
        void (*func)();
    };
}